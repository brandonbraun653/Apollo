#include <xdc/std.h>
#include <ti/sysbios/io/IOM.h>
#include <xdc/runtime/Memory.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <mcasp_drv.h>
#include "mcasp_osal.h"
#include "mcasp_cfg.h"
#include "MCASP_log.h"
#include "stdio.h"
#include "string.h"
#include <audioEQ_biquad.h>
#include <audioEQ.h>

#include <audioEQ_biquad.h>
#include <math.h>
BIQUAD_T filter;
BIQUAD_T *low_LShelf_Filter = &filter;
BIQUAD_T filter1;
BIQUAD_T *high_HShelf_Filter = &filter1;
BIQUAD_T filter2;
#ifdef BANDPASS
BIQUAD_T *mid_BPass_Filter = &filter2;
#else
BIQUAD_T *mid_HShelf_Filter = &filter2;
BIQUAD_T filter3;
BIQUAD_T *mid_LShelf_Filter = &filter3;
#endif
/* Filter default configuration*/
static double low_Fc  = 250.0;
static double high_Fc = 1000.0;
#ifdef BANDPASS
static double mid_Fc = 600.0; // Only used for bandpass filter
#endif
static double sampleRate = 44100.0;
static double defaultGain = 6.0;
static double Qfactor = 0.707;

//Control Flags
static int controlFilterUpdate;
static int filterSwitch;

static int i2a(char *s, int n);
static char* itoa(int num, char *buff);


#define NUM_BANDS              (3)   /* Number of frequency Bands */
static Ptr scratch[NUM_BANDS];

void audioEQ_allocate_bufs(IHeap_Handle iheap, uint32_t bufsize,uint32_t align) {
    int count;
	Error_Block  eb;

	Biquad_initParams(low_LShelf_Filter);	// create a Biquad, low_LShelf_Filter;
	Biquad_setBiquad(low_LShelf_Filter, bq_type_lowshelf, low_Fc/sampleRate , Qfactor, defaultGain);

	Biquad_initParams(high_HShelf_Filter);	// create a Biquad, low_LShelf_Filter;
	Biquad_setBiquad(high_HShelf_Filter, bq_type_highshelf, high_Fc/sampleRate , Qfactor, defaultGain);

#ifdef BANDPASS
	Biquad_initParams(mid_BPass_Filter);	// create a Biquad, low_LShelf_Filter;
	Biquad_setBiquad(mid_BPass_Filter, bq_type_bandpass, mid_Fc/sampleRate , Qfactor, defaultGain);
#else
	Biquad_initParams(mid_HShelf_Filter);	// create a Biquad, low_LShelf_Filter;
	Biquad_setBiquad(mid_HShelf_Filter, bq_type_highshelf, low_Fc/sampleRate , Qfactor, defaultGain);
	Biquad_initParams(mid_LShelf_Filter);	// create a Biquad, low_LShelf_Filter;
	Biquad_setBiquad(mid_LShelf_Filter, bq_type_lowshelf, high_Fc/sampleRate , Qfactor, (-1.0*defaultGain));
#endif
	controlFilterUpdate = 0;
	filterSwitch = 1;


	/* Allocate buffers for the SIO buffer exchanges                          */
           for(count = 0; count < (NUM_BANDS); count ++)
           {
              scratch[count] = Memory_calloc(iheap, bufsize,align,&eb);
               if(NULL == scratch[count])
               {
                   System_printf("\r\nMEM_calloc failed.\n");
               }
               else
            	   memset((uint8_t *)scratch[count], 0xFF, bufsize);
           }
}


void audioEQ_process_samples(void *tx_buf, void *rx_buf,uint32_t len_32)
{

	    if (filterSwitch == 0) {
		   memcpy(tx_buf,rx_buf,len_32*sizeof(uint32_t));
        }  else {
        	// filter a buffer of input samples, in-place
       	    controlFilterUpdate = 0;
#ifdef SOC_K2G
   	        Biquad_applyFilter16(low_LShelf_Filter, (short *)rx_buf, (short *)scratch[0], len_32*2);

#ifdef BANDPASS
   	        Biquad_applyFilter16(high_HShelf_Filter, (short *)scratch[0], (short *)scratch[1], len_32*2);
   	        Biquad_applyFilter16(mid_BPass_Filter, (short *)scratch[1], (short *)tx_buf, len_32*2);
  #else
    	    Biquad_applyFilter16(mid_HShelf_Filter, (short *)scratch[0], (short *)scratch[1], len_32*2);
       	    Biquad_applyFilter16(mid_LShelf_Filter, (short *)scratch[1], (short *)scratch[2], len_32*2);
       	    Biquad_applyFilter16(high_HShelf_Filter, (short *)scratch[2], (short *)tx_buf, len_32*2);
  #endif
#else
    	    Biquad_applyFilter32(low_LShelf_Filter, (int *)rx_buf, (int *)scratch[0], len_32);

  #ifdef BANDPASS
    	    Biquad_applyFilter32(high_HShelf_Filter, (int *)scratch[0], (int *)scratch[1], len_32);
    	    Biquad_applyFilter32(mid_BPass_Filter, (int *)scratch[1], (int *)tx_buf, len_32);
  #else
       	    Biquad_applyFilter32(mid_HShelf_Filter, (int *)scratch[0], (int *)scratch[1], len_32);
       	    Biquad_applyFilter32(mid_LShelf_Filter, (int *)scratch[1], (int *)scratch[2], len_32);
       	    Biquad_applyFilter32(high_HShelf_Filter, (int *)scratch[2], (int *)tx_buf, len_32);
  #endif
#endif
       	    controlFilterUpdate = 1;
       }
}



/*
 * Mcasp init function called when creating the driver.
 */
/* Task that would call the appropriate demo after reading user's choice */
Void ReadInputTask(UArg arg0, UArg arg1)
{
	int			selection;
	char Response[10];
	BIQUAD_T *selectFilter;

		UART_printf ("\n\n======================================================\n\r\n", -1);
		UART_printf (" Currently playing Audio effect Demo. \n Make sure a stereo input is connected to Line In and\n", -1);
		UART_printf (" Connect an headphone or a speaker to LineOut. ", -1);
		UART_printf ("\n\n======================================================\n\r\n", -1);
		UART_printf (" Demo currently shows 3 band equalization using shelving biquad filters\n ", -1);
		UART_printf ("* low band = 0Hz to 250Hz\n * mid band = 250Hz to 1000Hz,\n * high band = 1000Hz to 22000Hz\n ", -1);
		UART_printf (" All bands are boosted with a 8db Peak Gain\n ", -1);

	while(1)
		{
		 if (filterSwitch)
				   UART_printf ("\n\nDo you wish to keep the equalization ON ? (y or n)\r\n\r", -1);
		 else
				   UART_printf ("\n\nDo you wish turn ON the equalization? (y or n)\r\n\r", -1);

		 UART_scanFmt("%c", Response);
		 UART_printf ("", -1);


		 if (Response[0] == 'y') {
			 filterSwitch = 1;
			 UART_printf ("\n======================================================\n\r\n", -1);
			 UART_printf ("Press 0 and hit Enter to print current gain settings\r\n\r\n", -1);
			 UART_printf ("OR  \r\n\r\n", -1);
			 UART_printf ("Select the Frequency Band to adjust the gain\r\n\r\n", -1);
			 UART_printf ("*   Press 1 for Low  and hit Enter\r\n", -1);
			 UART_printf ("*   Press 2 for High  and hit Enter\r\n", -1);
			 UART_printf ("*   Press 3 for Mid and hit Enter\r\n", -1);
			 UART_printf ("All other input will not have any effect \r\n\r\n", -1);
			 UART_printf ("======================================================\n\r\n", -1);
			 UART_scanFmt("%s", Response);
			 UART_printf ("\n",-1);

			 selection = atoi(Response);

			 switch (selection) {
			 	 case 0:
			 		 UART_printf ("\n",-1);
			 		 UART_printf ("  Current gain settings :\n",-1);
			 		 UART_printf ("  Low: %sdb", itoa((int)low_LShelf_Filter->peakGain,Response));
			 		 UART_printf ("  Mid: %sdb", itoa((int)mid_HShelf_Filter->peakGain,Response));
			 		 UART_printf ("  High: %sdb", itoa((int)high_HShelf_Filter->peakGain,Response));
			 		 UART_printf ("\n",-1);
			 	    break;
		  	 	 case 1:
					 selectFilter= low_LShelf_Filter;
					 break;
				 case 2:
					 selectFilter= high_HShelf_Filter;
					 break;
				 case 3:
#ifdef BANDPASS
					selectFilter= mid_BPass_Filter;
#else
					selectFilter= mid_LShelf_Filter;
#endif

					 break;
				 default:
					 UART_printf ("Incorrect input \r\n", -1);
			 }

#ifdef BANDPASS
			 if (selection > 0 && selection <=3){
			 			   UART_printf ("Enter the value of gain(Recommendation -8 to 8)\r\n", -1);
			 			   UART_scanFmt("%s", Response);
			 			  // UART_printf ("%s", Response);

			 			   while(!controlFilterUpdate);
			 			   selection = atoi(Response);
			 			   Biquad_setPeakGain(selectFilter, (double)selection);
			 			   UART_printf ("Filter updated\r\n", -1);

			 }
#else

			 if (selection > 0 && selection <3){
			   UART_printf ("Enter the value of gain in dB (Recommendation -8 to 8)\r\n", -1);
			   UART_scanFmt("%s", Response);

			   while(!controlFilterUpdate);
			   selection = atoi(Response);
			   Biquad_setPeakGain(selectFilter, (double)selection);
			   UART_printf ("Gain updated\r\n", -1);
			 }
			 else if (selection == 3){
	      	    UART_printf ("Enter the value of gain in dB (Recommendation -8 to 8)\r\n", -1);
				UART_scanFmt("%s", Response);

    			while(!controlFilterUpdate);
				selection = atoi(Response);
				Biquad_setPeakGain(mid_HShelf_Filter, (double)selection);
				Biquad_setPeakGain(mid_LShelf_Filter, (double)(-1*selection));
				UART_printf ("Gain updated\r\n", -1);

			 }
#endif

		 }
         else if (Response[0] == 'n'){
        	filterSwitch = 0;
        	UART_printf ("Equalization OFF\r\n", -1);
         }
         else
        	 UART_printf ("Please select 'y' or 'n' \r\n", -1);

	}
}


int i2a(char *s, int n){
    div_t qr;
    int pos;

    if(n == 0) return 0;

    qr = div(n, 10);
    pos = i2a(s, qr.quot);
    s[pos] = qr.rem + '0';
    return pos + 1;
}

char* itoa(int num, char *buff){
    char *p = buff;
    if(num < 0){
        *p++ = '-';
        num *= -1;
    } else if(num == 0)
        *p++ = '0';
    p[i2a(p, num)]='\0';
    return buff;
}

