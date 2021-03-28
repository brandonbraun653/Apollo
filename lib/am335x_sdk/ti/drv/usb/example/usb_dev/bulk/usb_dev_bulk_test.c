/*
* Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/* ==========================================================================
 * This C program  communicates with our PRSDK USB LLD bulk example
 * and directs it to perform an "echo" test, write, and read benchmark tests
 * It is compiled under Ubuntun 16.04 with libusb installed.
 *
 * gcc usb_dev_bulk_test.c -o bulk_test `pkg-config --libs --cflags libusb-1.0` 
 *
 *  Run it with:
 *  ./bulk_test [--size 5000] (the size is optional. Default is 10MB)
 * ========================================================================== */


#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>

#include <libusb.h>

#define BULK_DEV_VID    (0x1CBE)
#define BULK_DEV_PID    (0x0003)
#define BULK_OUT_EP     (0x2)
#define BULK_IN_EP      (0x1)
#define BULK_TIMEOUT    (0)

#define TEST_SIZE       (10*1024*1024)
#define BLOCK_SIZE      (512)

typedef struct run_opt_s 
{
    int block_size;
    int test_size;
} RUN_OPT_S;

RUN_OPT_S g_options = {BLOCK_SIZE, TEST_SIZE};


/*
 *Use this define to calibrate the delta value 
 */
#define BASE_NUM_TRIALS 10

/*
 *Delta in microseconds to be adjusted 
 */
static int delta_time = 0;


/* Initialize Timer module */
void init_timer_module(void);

/* Get the current time, update the ptimer_handle */
void get_time(struct timeval * ptimer_handle);

/* Start the timer and update the ptimer_handle */
void start_timer(struct timeval * ptimer_handle);

/* Stop the Timer and return the elapsed usecs  */
unsigned long stop_timer(struct timeval * ptimer_handle);

static long elapsed_time(struct timeval *ptime_start,
                         struct timeval *ptime_end);

static long diff_time(struct timeval *ptime_start,
                      struct timeval *ptime_end);


/*
 * Function             : init_timer_module
 * Functionality        : Initialize the Timer module  
 * Input Params         : None
 * Return Value         : None
 */
void init_timer_module(void)
{
    struct timeval start_time;
    struct timeval end_time;
    int i = 0;

    /* Already calibrated */
    if (0 != delta_time)
        return;

    /* We need to average delta_time out */
    for (i = 0; i < BASE_NUM_TRIALS; i++) {
        start_timer(&start_time);
        start_timer(&end_time);

        delta_time += diff_time(&start_time, &end_time);
    }

    delta_time = delta_time / BASE_NUM_TRIALS;

}


/*
 * Function             : start_timer
 * Functionality        : Start the timer and update the ptimer_handle 
 * Input Params         : ptimer_handle 
 * Return Value         : None
 */
void start_timer(struct timeval *ptimer_handle)
{
    struct timeval *pstart_timeval = ptimer_handle;

    gettimeofday(pstart_timeval, NULL);

#if LOG_TIME
    printf("timeVal.sec %ld\n", pstart_timeval->tv_sec);
    printf("timeVal.usec %ld\n", pstart_timeval->tv_usec);
#endif
}

/*
 * Function             : stop_timer
 * Functionality        : Stop the Timer and return the elapsed usecs  
 * Input Params         : ptimer_handle 
 * Return Value         : elapsed time in usecs
 */
unsigned long stop_timer(struct timeval *ptimer_handle)
{
    struct timeval *pstart_timeval = ptimer_handle;
    struct timeval stop_time_val;
    gettimeofday(&stop_time_val, NULL);

    return ((unsigned long)elapsed_time(pstart_timeval, &stop_time_val));
}

/*
 * Function                 : diff_time
 * Functionality            : Return the difference between 2 timeval struct 
 *                  : in microseconds
 * Input Params             : ptime_start    - start time 
 *                              : ptime_end - end time
 * Return Value             : difference between 2 timeval structs  in microseconds
 */
static long diff_time(struct timeval *ptime_start,
                      struct timeval *ptime_end)
{
    return ((ptime_end->tv_sec - ptime_start->tv_sec) * 1000000u
        + ptime_end->tv_usec - ptime_start->tv_usec);
}



/*
 * Function                 : elapsed_time
 * Functionality            : Return the time elapsed between 2 timeval structs
 *                  : in microseconds
 * Input Params             : ptime_start    - start time 
 *                              : ptime_end - end time
 * Return Value             : elapsed tim between 2 timeval structs  in microseconds
 */
static long elapsed_time(struct timeval *ptime_start,
                         struct timeval *ptime_end)
{
    return (diff_time(ptime_start, ptime_end) - delta_time);
}



/*
 * Function                 : delay_ms
 * Functionality            : halt the code for number of milliseconds/ 
 */
static void delay_ms(int ms)
{
    struct timespec delay;
    struct timespec remain;
    int    nanosec = 0;
    
    nanosec = ms*1000000;

    delay.tv_sec = 0;
    delay.tv_nsec = nanosec;

    nanosleep(&delay, &remain);
}


/*
 * Function                 : get_options
 * Functionality            : find the options passed in from command line arguments
 */
int get_options(int argc, char** argv)
{
    int i;
    for (i=1; i<argc;i++)
    {
        if (strcmp(argv[i], "--help")==0)
        {
            printf("usage: %s [--bs blocksize] [--size testsize]\n", argv[0]);
            return -1;
        }
        if (strcmp(argv[i], "--bs")==0)
        {
           g_options.block_size=atoi(argv[i+1]); 
           i = i + 1;
        }

        if (strcmp(argv[i], "--size")==0)
        {
           g_options.test_size=atoi(argv[i+1]); 
           i = i + 1;
        }
    }
    return 0;
}

/*
 * Perform write throughput benchmarking from USB host.
 * It sends a string "WRITE_THROUGHPUT=transfer_size;" to the remote USB device.
 * Waits a bit for the device to print debug info on UART then
 * writing many bulk OUT packet back to back then measure the throughput
 *
 * transfer_size: is the amount of bytes we want to send to USB device
 * block_size: each USB bulk transfer = USB max packet size. 
 *
 * TODO: trying to make sending large block of multiple max packet size (says 1024 or 2048 bytes)
 *       to improve throughtput.  Currently the device doesn't work well with this yet.
 */
int bm_write(libusb_device_handle* dev_handle, int transfer_size, int block_size)
{
    int   num_blocks = 0;
    int   num_remain = 0;

    int   actual_len;
    int   text_len;
    int   i, r;

    char  cmd_str[80];

    struct timeval start_time;
	unsigned long elapsed_usecs = 0;
    float throughput = 0;

    char* send_buf = NULL;

    send_buf = malloc(block_size);

    if ((send_buf == NULL))
    {
        fprintf(stderr, "failed to allocate memory for test\n");
        return -1;
    }

    sprintf(cmd_str, "WRITE_THROUGHPUT=%d;", transfer_size);
    text_len = strlen(cmd_str);
    

    printf("\nStarting write perf test\n");
        
    /* tell the device we will doing write throughput so that the device
       will keep reading (for a total of transfer_size bytes which we (USB host) 
       tell the device via this command string. */
    r = libusb_bulk_transfer(dev_handle, 
                             (BULK_OUT_EP | LIBUSB_ENDPOINT_OUT),
                             cmd_str, text_len, &actual_len, 
                             BULK_TIMEOUT); 

    if ((r<0) || (actual_len != text_len)) 
    {
        printf("failed to send command string to the USB device\n");
        return r;
    }

    /* wait for the device to print debug info (which tells which test it is doing) */
    delay_ms(100);

    printf("Writing %d bytes of data with blocksize=%d bytes to bulk device ...\n", 
            transfer_size, block_size);

    num_blocks = transfer_size / block_size;
    num_remain = transfer_size % block_size;

    memset(send_buf, 0xBB, block_size);

    start_timer(&start_time);

    for (i = 0; i<num_blocks; i++)
    {
        /* sync write */
        r = libusb_bulk_transfer(dev_handle, 
                                 (BULK_OUT_EP | LIBUSB_ENDPOINT_OUT),
                                 send_buf, block_size, &actual_len, 
                                 BULK_TIMEOUT); 
        if (r < 0) 
        {
            printf("failed to send to bulk device. error=%d\n", r);
            return r;
        }
    }

    /* sync write */
    if (num_remain > 0)
    {
        r = libusb_bulk_transfer(dev_handle, 
                (BULK_OUT_EP | LIBUSB_ENDPOINT_OUT),
                send_buf, num_remain, &actual_len, 
                BULK_TIMEOUT); 
        if (r < 0) 
        {
            printf("failed to send remaining of block to bulk device. error=%d\n", r);
            return r;
        }
    }

    /* Stop the Timer and get the usecs elapsed */
    elapsed_usecs = stop_timer(&start_time);
    throughput = (float)(((float)transfer_size / (float)elapsed_usecs));

    printf("test takes: %4.3f seconds\n", (float)elapsed_usecs/(float)1000000);
    printf("throughput: %4.3f MB/s\n", throughput);

    /* wait for the device to print debug info (which tells which test it is doing) */
    delay_ms(100);

    /* done with the test, free memory */
    free(send_buf);

    return r;
}

/*
 * Perform read throughput benchmarking from USB host (Bulk IN)
 * It sends a string "READ_THROUGHPUT=transfer_size;" to the remote USB device.
 * Waits a bit for the device to print debug info on UART then
 * Read many bulk IN packet back to back then measure the throughput
 *
 * transfer_size: is the amount of bytes we want to send to USB device
 * block_size: each USB bulk transfer = USB max packet size. 
 *
 * TODO: trying to make sending large block of multiple max packet size (says 1024 or 2048 bytes)
 *       to improve throughtput.  Currently the device doesn't work well with this yet.
 */
int bm_read(libusb_device_handle* dev_handle, int transfer_size, int block_size)
{
    int   num_blocks = 0;
    int   num_remain = 0;

    int   actual_len;
    int   text_len;
    int   i, r;

    char  cmd_str[80];

    struct timeval start_time;
	unsigned long elapsed_usecs = 0;
    float throughput = 0;

    char* read_buf = NULL;

    read_buf = malloc(g_options.block_size);

    if ((read_buf == NULL))
    {
        fprintf(stderr, "failed to allocate memory for test\n");
        return -1;
    }

    printf("Starting read perf test\n");

    sprintf(cmd_str, "READ_THROUGHPUT=%d;", transfer_size);
    text_len = strlen(cmd_str);

    /* tell the device we will doing read throughput so that the device
       will keep writing (for a total of transfer_size bytes which we (USB host) 
       tell the device via this command string. */
    r = libusb_bulk_transfer(dev_handle, 
                             (BULK_OUT_EP | LIBUSB_ENDPOINT_OUT),
                             cmd_str, text_len, &actual_len, 
                             BULK_TIMEOUT); 

    if ((r<0) || (actual_len != text_len)) 
    {
        printf("failed to send command string to the USB device\n");
        return r;
    }

    /* wait for the USB device to print debug info (which tells which test it is doing) on UART */
    delay_ms(100);

    printf("Reading %d bytes of data with blocksize=%d bytes from bulk device ...\n", 
            transfer_size, block_size);

    num_blocks = transfer_size / block_size;
    num_remain = transfer_size % block_size;

    start_timer(&start_time);
    for (i = 0; i<num_blocks; i++)
    {
        /* sync read */
        r = libusb_bulk_transfer(dev_handle, 
                                 (BULK_IN_EP | LIBUSB_ENDPOINT_IN),
                                 read_buf, block_size, &actual_len, 
                                 BULK_TIMEOUT); 
        if (r < 0) 
        {
            printf("failed to read from bulk device. error=%d\n", r);
            return r;
        }
    }

    if (num_remain > 0)
    {
        /* sync read */
        r = libusb_bulk_transfer(dev_handle, 
                (BULK_IN_EP | LIBUSB_ENDPOINT_IN),
                read_buf, num_remain, &actual_len, 
                BULK_TIMEOUT); 
        if (r < 0) 
        {
            printf("failed to read the remaining %d bytes of data from bulk device. error=%d\n", 
                    num_remain, r);

            return r;
        }
    }

    /* Stop the Timer and get the usecs elapsed */
    elapsed_usecs = stop_timer(&start_time);
    throughput = (float)(((float)transfer_size / (float)elapsed_usecs));

    printf("test takes: %4.3f seconds\n", (float)elapsed_usecs/(float)1000000);
    printf("throughput: %4.3f MB/s\n", throughput);

    /* done with the test, free memory */
    free(read_buf);

    /* delay a bit for the DUT to be ready with the test since we know it needs to 
     * print some information via UART */
    delay_ms(100);

    return r;
}


/*
 * Perform an echo test
 *
 * It sends a command as a string "DEMO" to the USB device. Waits a bit for the device to be ready
 * It sends a test string to the remote USB device
 * It then expects the device to swap the letter case of the test string then send back to the host.
 * It ends the test by sending string "ENDDEMO" to the device.
 *
 */
int bulk_echo_test(libusb_device_handle* dev_handle )
{
    int   r = 0;
    int   actual_len;
    int   text_len;

    char* send_buf = NULL;
    char* read_buf = NULL;

    send_buf = malloc(g_options.block_size);
    read_buf = malloc(g_options.block_size);

    if ((send_buf == NULL) || (read_buf == NULL))
    {
        fprintf(stderr, "failed to allocate memory for test\n");
        return -1;
    }

    strcpy(send_buf, "DEMO");
    text_len = strlen(send_buf);

    /* sync write */
    r = libusb_bulk_transfer(dev_handle, 
            (BULK_OUT_EP | LIBUSB_ENDPOINT_OUT),
            send_buf, text_len, &actual_len, 
            BULK_TIMEOUT); 

    if (r < 0) 
    {
        printf("failed to send to bulk device. error=%d\n", r);
        return r;
    }

    /* delay a bit for the DUT to be ready with the test since we know it needs to 
     * print some information via UART - note that this delay is just specific to the 
     * behavior of the test code that runs on DUT */
    delay_ms(100);

    /* send one small string and check result to see if we have a good communication */
    strcpy(send_buf,"Hello this is a test message being sent via USB");
    text_len = strlen(send_buf);

    printf("\nWriting \"%s\" to USB bulk device and wait for its inverted echo\n", send_buf);

    /* sync write */
    r = libusb_bulk_transfer(dev_handle, 
            (BULK_OUT_EP | LIBUSB_ENDPOINT_OUT),
            send_buf, text_len, &actual_len, 
            BULK_TIMEOUT); 

    if (r < 0) 
    {
        printf("failed to send to bulk device. error=%d\n", r);
        return r;
    }

    if (actual_len != text_len)
    {
        printf("Fail to send the whole test string\n");
        r = -1;
        return r;
    }

    /* read sync. USB DUT will echo back the data */
    r = libusb_bulk_transfer(dev_handle, 
            (BULK_IN_EP | LIBUSB_ENDPOINT_IN),
            read_buf, g_options.block_size, &actual_len, 
            BULK_TIMEOUT); 

    if (r < 0) 
    {
        printf("failed to read from bulk device. error=%d\n", r);
    }

    if (actual_len != text_len)
    {
        printf("received string length is not same as sent string length\n");
    }
    else
    {
        printf("received string: %s\n", (char*)read_buf);
    }

    strcpy(send_buf, "ENDDEMO");
    text_len = strlen(send_buf);

    /* sync write */
    r = libusb_bulk_transfer(dev_handle, 
            (BULK_OUT_EP | LIBUSB_ENDPOINT_OUT),
            send_buf, text_len, &actual_len, 
            BULK_TIMEOUT); 

    if (r < 0) 
    {
        printf("failed to send to bulk device. error=%d\n", r);
        return r;
    }


    /* done with the test, free memory */
    free(send_buf);
    free(read_buf);


    /* delay a bit for the DUT to be ready with the test since we know it needs to 
     * print some information via UART */
    delay_ms(100);
}

int main(int argc, char** argv)
{
	int r;
	int i;
	libusb_device **list;
	libusb_device *device = NULL;
    libusb_context *ctx = NULL; 
    libusb_device_handle *dev_handle; 

	uint32_t device_count = 0;
	struct libusb_device_descriptor dd;
	uint8_t reg;
	ssize_t cnt;


    int   num_blocks = 0;
    int   num_remain = 0;

    
    printf("bulk usb client\n");

    if (get_options(argc, argv) == -1)
    {
        return 0;
    }

	r = libusb_init(&ctx);
	if(r < 0)
    {
		fprintf(stderr, "lib_usb_init error %d\n", r);
		return -1;
	}

    libusb_set_debug(ctx, 3); /* set verbosity level to 3 */

    dev_handle = libusb_open_device_with_vid_pid(ctx, BULK_DEV_VID, BULK_DEV_PID);
    if (dev_handle == NULL)
    {
        fprintf(stderr, "\nFail to open USB device\n ");        
    }

	libusb_free_device_list(list, 1);

    if (dev_handle != NULL)
    {
        if (libusb_kernel_driver_active(dev_handle, 0) == 1) 
        {
            fprintf(stderr, "\nKernel driver is active\n ");
            goto err;
        }

    	r = libusb_claim_interface(dev_handle, 0);
	    if (r < 0) 
        {
	    	fprintf(stderr, "usb_claim_interface error %d\n", r);
		    goto err;
    	}

        //print_usb_device_info(dev_handle);


        /* simple USB bulk demo in which we send the USB device a 
           message and waits for its echo */
        bulk_echo_test(dev_handle);
        
        printf("\nDoing write throughput\n");
        r = bm_write(dev_handle,  g_options.test_size,  g_options.block_size);

        printf("\nDoing read throughput\n");
        r = bm_read(dev_handle,  g_options.test_size,  g_options.block_size);

err:    
        libusb_release_interface(dev_handle, 0);
        libusb_close(dev_handle);
    }

    libusb_exit(ctx);
}






