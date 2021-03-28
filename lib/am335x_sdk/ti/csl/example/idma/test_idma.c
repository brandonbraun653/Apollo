/** 
 * @file test_idma.c
 *
 * @brief 
 *  Sample application to test IDMA CSL-FL APIs.
 *  
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2008, 2009, Texas Instruments, Inc.
 * 
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
#include <stdio.h>
#include <stdlib.h>
#include <ti/csl/csl_idma.h>
#include <ti/csl/csl_idmaAux.h>

#define MASK    0xFFFFFF0F

/* Align various arrays to a word address, in internal L2    */
#pragma DATA_SECTION(src, "ISRAM");
#pragma DATA_ALIGN(src,      32);
#pragma DATA_ALIGN(dst2,     32);

/*  Static 128 byte array of data in "src" with known test pattern.   */
unsigned int src[32] = {
    0xDEADBEEF, 0xFADE0003, 0x5AA51C3A, 0x03036BA3,
    0x0000ABCD, 0x00001234, 0x00005670, 0x00005678,
    0x000003BE, 0x0000760F, 0x9675A800, 0xABCDEF12,
    0xEEEECDEA, 0x01234567, 0x00000000, 0xFEEDFADE,
    0x0, 0x0,   0x0, 0x0,   0x0, 0x0,   0x0, 0x0,
    0x0, 0x0,   0x0, 0x0,   0x0, 0x0,   0x0, 0x0        
} ;

unsigned int * dst2 = (unsigned int *)0x02704000;
unsigned int * src2 = (unsigned int *)0x00820000;

#define DATA_COUNT_BYTES   80
#define DATA_COUNT_WORDS  (DATA_COUNT_BYTES/4) 
#define DATA_FILL_COUNT    32

/* Align various arrays to a double word address, in internal L2 */
#pragma DATA_SECTION(src1,   "ISRAM");
#pragma DATA_SECTION(dst0,  "ISRAM1");
#pragma DATA_SECTION(dst1,  "ISRAM1");
#pragma DATA_ALIGN(src1,      8);
#pragma DATA_ALIGN(dst0,     8);
#pragma DATA_ALIGN(dst1,     8);

/*  Static 80 byte array of data in "src1" with known test pattern */
Uint32 src1[20] =
{
    0xDEADBEEF, 0xFADEBABE, 0x5AA51C3A, 0xD4536BA3,
    0x5E69BA23, 0x4884A01F, 0x9265ACDA, 0xFFFF0123,
    0xBEADDABE, 0x234A76B2, 0x9675ABCD, 0xABCDEF12,
    0xEEEECDEA, 0x01234567, 0x00000000, 0xFEEDFADE,
    0x0A1B2C3D, 0x4E5F6B7C, 0x5AA5ECCE, 0xFABEFACE
};

/*  Static 80 byte array of data in "dst0" with known test pattern */
Uint32 dst0[20] =
{
    0x00010203, 0x04050607, 0x08090A0B, 0x10111213,
    0x14151617, 0x18191A1B, 0x1C1D1E1F, 0x20212123,
    0x24252627, 0x28292A2B, 0x2C2D2E2F, 0x30313233,
    0x34353637, 0x38393A3B, 0x3C3D3E3F, 0x40414243,
    0x44454647, 0x48494A4B, 0x4C4D4E4F, 0x50515253
};

/*  Array in which results will be copied over */
Uint32      dst1[20];


/** ============================================================================
 *   @n@b dump_idma0_status
 *
 *   @b Description
 *   @n API to dump out the status of IDMA Channel 0.
 *
 *   @b Arguments
 *   @n None
 * 
 *   <b> Return Value </b>
 *   @n None
 *
 * =============================================================================
 */
void dump_idma0_status()
{
    CSL_IDMA_STATUS     idma0Status;
    
    CSL_IDMA_chan0GetStatus (&idma0Status);
    
    printf("IDMA Channel 0 Status :- isPending: %u isActive: %u \n", 
            idma0Status.isPending, idma0Status.isActive
          );

    return;
}

/** ============================================================================
 *   @n@b dump_idma1_status
 *
 *   @b Description
 *   @n API to dump out the status of IDMA Channel 1.
 *
 *   @b Arguments
 *   @n None
 * 
 *   <b> Return Value </b>
 *   @n None
 *
 * =============================================================================
 */
void dump_idma1_status()
{
    CSL_IDMA_STATUS     idma1Status;
    
    CSL_IDMA_chan1GetStatus (&idma1Status);
    
    printf("IDMA Channel 1 Status :- isPending: %u isActive: %u \n", 
            idma1Status.isPending, idma1Status.isActive
          );

    return;
}

/** ============================================================================
 *   @n@b test_idma_chan0
 *
 *   @b Description
 *   @n API to run external CFG configuration transfer tests using IDMA Channel 0.
 *      
 *      The example shows how to use the idma to transfer data between the 
 *      peripheral configuration space (CFG)and any local memories 
 *      (L1P, L1D, and L2).    
 *      This example test the following operations.
 *       -  Configure IDMA channel 0 with interrupt on to perform copy of 
 *          data from src to CFG space of EDMA ParamSet Registers
 *       -  Wait until copying is completed  
 *       -  Comparing the data from source and destination addresses   
 *
 *   @b Arguments
 *   @n None
 * 
 *   <b> Return Value </b>
 *   @n None
 *
 * =============================================================================
 */
int test_idma_chan0 (void)
{
    Uint32                  i, mask;
    Uint32                  idmaChan0TestFailed = 0;
    CSL_IDMA_IDMA0CONFIG    idmaChan0Config;
    Uint32                  bWaitEnable = 1;
    
    memcpy(src2, src, sizeof(unsigned int) * 32);
    
    /* Configure IDMA Channel 0 Transfer */
    mask = MASK;
    idmaChan0Config.mask        =   mask;
    idmaChan0Config.source      =   src2;
    idmaChan0Config.destn       =   dst2;
    idmaChan0Config.count       =   0;  /* transfer one 32-byte window */
    idmaChan0Config.intEnable   =   1;  /* Enable CPU interrupt on completion. */
    CSL_IDMA_chan0TransferData (&idmaChan0Config, bWaitEnable);
    
    printf("Src Address: 0x%X dst: 0x%X \n", src2, dst2);
    
    for (i = 0; i < 32; i++) 
    {
        /* Check as per the mask we configured if the 
         * data was transferred to CFG MMR space.
         */
        if(!(mask & 0x1))   
        {
            if (src2[i] != dst2[i]) 
            {
                printf("IDMA Channel 0: configuring the MMRs  FAILED.\n");
                idmaChan0TestFailed++;
                return idmaChan0TestFailed;
            }
            else 
            {
                printf("IDMA Channel 0: src[%d] is: 0x%X  dst2[%d] is: 0x%X\n", \
                       i,src2[i],i,dst2[i]);
            }
        } 
        else 
        {
            printf("\tIDMA Channel 0: Performing transfer of this data src[%d]: \
                    0x%X is blocked off by the mask.\n",i,src2[i]); 
        }
        mask = mask >> 1;
    }
    
    return idmaChan0TestFailed;
}

/** ============================================================================
 *   @n@b test_idma_chan1
 *
 *   @b Description
 *   @n API to run block/fill transfer tests using IDMA Channel 1.
 *      
 *      This example shows how idma csl performs the data transfer between 
 *      source and destination buffers which both reside in local memories 
 *      (L1P, L1D, and L2).    
 *      This example test the following operations.
 *       -  Configure IDMA channel 1 with interrupt on to perform copy of 
 *          data between 2 buffers in L2.
 *       -  Wait until copying is completed  
 *       -  Comparing the data from source and destination addresses   
 *
 *   @b Arguments
 *   @n None
 * 
 *   <b> Return Value </b>
 *   @n None
 *
 * =============================================================================
 */
int test_idma_chan1 (void)
{
    Uint32        count;
    CSL_IDMA_IDMA1CONFIG    idmaChan1Config;
    Uint32                  bWaitEnable = 1;
    Uint32                  idmaChan1TestFailed = 0;

    printf("IDMA Channel 1 Data Transfer Test\n");
    /* Initialize IDMA Channel 1                               
     * Set Chan 1 to have Priority 7 and Interrupt Event Gen On 
     */
    idmaChan1Config.source = src1;
    idmaChan1Config.destn = dst1;
    idmaChan1Config.intEnable = 1;
    idmaChan1Config.priority = IDMA_PRI_7;
    idmaChan1Config.count = DATA_COUNT_BYTES;

    /* Clear dst1 array */
    memset(dst1, 0, sizeof(dst1));

    /* Copy src to dst1 - 80 bytes - 20 words */
    /* Wait until copying is completed */
    CSL_IDMA_chan1TransferData (&idmaChan1Config, bWaitEnable);

    /* Comparing the source and destination buffers */
    if (memcmp(src1, dst1, sizeof(src1))) 
    {
        printf("IDMA Channel 1: data copy using IDMA Chan 1 FAILED \n");
        idmaChan1TestFailed++;
        return idmaChan1TestFailed;
    }
    else 
    {
        /* IDMA Chan 1 Data transfer successful */
        for(count = 0; count < DATA_COUNT_WORDS; count++)
        {
             printf("value of src[%d]: 0x%x,value of dst[%d]: 0x%x\n", \
                          count, src[count], count, dst1[count]);
        }
        printf("IDMA Channel 1: data copy using IDMA Chan 1 PASSED \n ");
    }
    
    /*
     * The following test tests out the fill capability of Channel   
     * 1. First fill the dst1 array with the value "0xAAAABABA".     
     * 2. Now copy dst1 into dst0.                                   
     *                                                               
     * This is an example of a backward transfer where address of    
     * "dst0" is less than "dst1".                                   
     */

    printf("\n IDMA Channel 1 Data Fill Test\n");
    
    printf("Source Address that will be used for Fill: 0x%X \n", src);
    
    idmaChan1Config.source = src;
    idmaChan1Config.destn = dst1;
    idmaChan1Config.intEnable = 1;
    idmaChan1Config.priority = IDMA_PRI_7;
    idmaChan1Config.count = DATA_COUNT_BYTES;
    CSL_IDMA_chan1FillData (&idmaChan1Config, bWaitEnable);
        
    for(count = 0; count < DATA_COUNT_WORDS; count++)
    {
        printf("value of dst[%d]: 0x%x\n",count,dst1[count]);
    }
       
    
    /* Perform the transfer from "dst1" to "dst0". Recall that    
     * "dst1" was just filled with a constant pattern 0xAAAABABA.   
     * Also verify that getStatus function is working by checking if
     * IDMA1 status is ACTV after the submission for the transfer   
     */
    idmaChan1Config.source = dst1;
    idmaChan1Config.destn = dst0;
    idmaChan1Config.intEnable = 1;
    idmaChan1Config.priority = IDMA_PRI_7;
    idmaChan1Config.count = DATA_COUNT_BYTES;  
    CSL_IDMA_chan1TransferData (&idmaChan1Config, 1);
       
    if (memcmp(dst0, dst1, sizeof(dst0))) 
    {
        printf("IDMA Channel 1: data fill using IDMA Chan 1 FAILED \n ");
        idmaChan1TestFailed++;
        return idmaChan1TestFailed;
    }
    else 
    {
        printf("IDMA Channel 1: data fill using IDMA Chan 1 PASSED \n ");
    }

    return idmaChan1TestFailed;
}

/** ============================================================================
 *   @n@b main
 *
 *   @b Description
 *   @n Entry point for the IDMA test application.
 *
 *   @b Arguments
 *   @n None
 * 
 *   <b> Return Value </b>
 *   @n None
 *
 * =============================================================================
 */
void main ()
{
    int                     idmaChan0TestFailed, idmaChan1TestFailed;
    
    /* Run tests on IDMA Channel 0. */
    printf("Runnning IDMA Channel 0 Example \n");
    printf("===============================================================\n");
        
    idmaChan0TestFailed = test_idma_chan0 ();
    if (idmaChan0TestFailed > 0) 
    {
        printf ("\nIDMA: Channel 0 Tests FAILED. \
                [Tests failed: %d]\n", idmaChan0TestFailed);        
    }
    else 
    {
        printf ("\nIDMA: Channel 0 Tests PASSED.\n");
    } 
    
    dump_idma0_status ();          
    
    printf("===============================================================\n");    

    /* Run tests on IDMA Channel 1. */
    printf("\n\n Runnning IDMA Channel 1 Example \n");
    printf("===============================================================\n");
        
    idmaChan1TestFailed = test_idma_chan1 ();
    if (idmaChan1TestFailed > 0) 
    {
        printf ("\nIDMA: Channel 1 Tests FAILED. \
                [Tests failed: %d]\n", idmaChan1TestFailed);        
    }
    else 
    {
        printf ("\nIDMA: Channel 1 Tests PASSED.\n");
    }       
    
    dump_idma1_status ();
        
    printf("===============================================================\n");    
     
    return;
}
