#include  <stdio.h>

#include  "ti/csl/csl_chipAux.h"
#include  "ti/csl/csl_cacheAux.h"

/* Declare a counters in MAR12 memory region */
#pragma DATA_SECTION (counter, ".sharedMEM");
#pragma DATA_ALIGN (counter, 128);
int counter[128];

void csl_CacheWriteThroughTest(void)
{
    uint32_t coreId = CSL_chipReadDNUM();
    int      numberOfTries = 0, result = 1;
    Uint8    writeThruMode;

    printf ("Entering csl_CacheWriteThroughTest \n");
  /* Initialize the counter */
   counter[coreId] = 0;

   /* start the test with no write through mode */
   CACHE_setMemRegionWritethrough(12, FALSE);


   /* Increment the counter, if no cache write through enabled, the counter would never reach 10 */
   while (counter[coreId] < 10)
   {
      /* When write - through mode is enabled, the increment is write through external memory */
      counter[coreId] ++;

      /* Now invalidate the Cache line so that the next increment gets the value from external memory */
  	  CACHE_invL1d(counter, 128, CACHE_WAIT);

  	  numberOfTries ++;
  	  /* This condition implies that the write loss happened since the write through did not happen */
  	  if (numberOfTries > 10) {

  		  CACHE_getMemRegionWritethrough(12, &writeThruMode);
  		  if (writeThruMode == 1) {
  			  result = 0;
  			  break;
  		  }

  	      /* Set MAR12 region to write-through mode */
  	      CACHE_setMemRegionWritethrough(12, TRUE);

  	      /* Reset number of tries */
  	      numberOfTries = 0;
  	  }
   }

   if (result == 1)
	   printf ("     csl_CacheWriteThroughTest: passed \n");
   else
	   printf ("     csl_CacheWriteThroughTest: failed \n");

   printf ("Exiting csl_CacheWriteThroughTest \n");
 }

