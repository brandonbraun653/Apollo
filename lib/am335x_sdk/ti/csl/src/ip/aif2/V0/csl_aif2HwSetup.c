/*  ===========================================================================
 *   Copyright (c) Texas Instruments Incorporated 2008, 2009
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

/** ===========================================================================
 *   @file  csl_aif2HwSetup.c
 *
 *   @path  $(CSLPATH)\src\aif2
 *
 *   @brief  AIF2 HW setup CSL 3.x function 
 *
 */
 
/* =============================================================================
 * Revision History
 * ===============
 *  02-June-2009  Albert   File Created.
 *  
 *
 * =============================================================================
 */

#include <ti/csl/csl_aif2.h>
#include <ti/csl/csl_utils.h>

/** ============================================================================
 *   @n@b CSL_aif2HwSetup
 *
 *   @b Description       
 *   @n It configures the AIF2 instance registers as per the values passed
 *      in the hardware setup structure.
 *
 *   @b Arguments
 *   @verbatim
            hAif2        Handle to the AIF2 instance

            aif2Setup       Pointer to hardware setup structure
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - Hardware setup successful.
 *   @li                    CSL_ESYS_BADHANDLE  - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS  - Hardware structure is not
 *                                                properly initialized
 *
 *   <b> Pre Condition </b>
 *   @n  Both @a CSL_aif2Init() and @a CSL_aif2Open() must be called successfully
 *   in that order before CSL_aif2HwSetup() can be called. The user has to
 *   allocate space for & fill in the main setup structure appropriately before
 *   calling this function.
 *
 *   <b> Post Condition </b>
 *   @n  The specified instance will be setup according to value passed.
 *
 *   @b Writes
 *   @n The hardware registers of AIF2.
 *
 *   @b Example                  
 *   @verbatim
          CSL_Aif2Handle handleAif2;
          
          CSL_Aif2Obj Aif2Obj;
          //AIF module specific parameters
          CSL_Aif2Param  aif2Param;
          // CSL status
          CSL_Status status;
          // global config for AIF2 
          CSL_Aif2GlobalSetup gblCfg = {…};

          // Setup objects for global configuring  
          CSL_Aif2GlobalSetup GlobalConfig;
          // Setup for common params  
          CSL_Aif2CommonSetup commoncfg= {CSL_AIF2_LINK_0};
          // Setup for link 
          CSL_Aif2Setup Config = {…};
   
          // Open handle - for use 
          handleAif2 = CSL_aif2Open(&Aif2Obj, CSL_AIF2, &aif2Param, &status);

          if ((handleAif2 == NULL) || (status != CSL_SOK)) 
          {
             printf ("\nError opening CSL_AIF2");
             exit(1);
          }

          // Do config 
          Config.globalSetup = &gblCfg;
          Config.commonSetup = &commoncfg;
          Config.linkSetup = &linkCfg;
       
          //Do setup 
          CSL_aif2HwSetup(handleAif2, &Config);
     @endverbatim
 * =============================================================================
 */ 
#if defined(_TMS320C6X)
CSL_SET_CSECT  (CSL_aif2HwSetup, ".text:csl_section:aif2")
#endif
CSL_Status  CSL_aif2HwSetup(
    /** Pointer to the object that holds reference to the
     *  instance of AIF2 link requested after the call
    */
    CSL_Aif2Handle             hAif2,
    /** Pointer to setup structure which contains the
     *  information to program AIF2 to a useful state
    */
    const CSL_Aif2Setup        *aif2Setup
)

{
    int32_t i;
    CSL_Status status = CSL_SOK;

    if (hAif2 == NULL)
    {
        status = CSL_ESYS_BADHANDLE;
    }
    else if (aif2Setup == NULL)
    {
        status = CSL_ESYS_INVPARAMS;
    }
    else
    {
        /* SERDES Common setup to activate byte clock */
        if (aif2Setup->commonSetup->pSdCommonSetup != NULL) {
            CSL_aif2SetupSdCommonRegs(hAif2, aif2Setup->commonSetup);
        }
        
        /*  link setup*/    
        for(i = 0; i < 6; i++) /* while  loop to repeatively setup each link */
        {
            if(aif2Setup->globalSetup->ActiveLink[i] == TRUE)
            {         
                /* link common setup */
                if (aif2Setup->linkSetup[i]->pComLinkSetup != NULL) {
                    CSL_aif2SetupLinkRegs(hAif2, aif2Setup->linkSetup[i]);
                }

                /* SERDES link setup */
                if (aif2Setup->linkSetup[i]->pSdLinkSetup != NULL) {
                    CSL_aif2SetupSdLinkRegs(hAif2, aif2Setup->linkSetup[i]);
                }

                /* TM setup*/
                if (aif2Setup->linkSetup[i]->pTmLinkSetup != NULL) {
                    CSL_aif2SetupTmLinkRegs(hAif2, aif2Setup->linkSetup[i]);
                }

                 /* RM setup*/
                if (aif2Setup->linkSetup[i]->pRmLinkSetup != NULL) {
                    CSL_aif2SetupRmLinkRegs(hAif2, aif2Setup->linkSetup[i]);
                }

                /* Retransmitter Configuration */
                if (aif2Setup->linkSetup[i]->pRtLinkSetup != NULL) {
                    CSL_aif2SetupRtLinkRegs(hAif2, aif2Setup->linkSetup[i]);
                }

                /* Protocol Decoder Setup */
                if (aif2Setup->linkSetup[i]->pPdLinkSetup != NULL) {
                    CSL_aif2SetupPdLinkRegs(hAif2, aif2Setup->linkSetup[i]);
                }

                /* Protocol Encoder Setup */
                if (aif2Setup->linkSetup[i]->pPeLinkSetup != NULL) {
                    CSL_aif2SetupPeLinkRegs(hAif2, aif2Setup->linkSetup[i]);
                }

                /* AT link Configuration */
                if (aif2Setup->linkSetup[i]->pAtLinkSetup != NULL) {
                    CSL_aif2SetupAtLinkRegs(hAif2, aif2Setup->linkSetup[i]);
                }        
            }
        }
    
        /* Common setup */
    
        /* Protocol Decoder Setup */
        if (aif2Setup->commonSetup->pPdCommonSetup != NULL) {
            CSL_aif2SetupPdCommonRegs(hAif2, aif2Setup->commonSetup);
        }

        /* Protocol Encoder Setup */
        if (aif2Setup->commonSetup->pPeCommonSetup != NULL) {
            CSL_aif2SetupPeCommonRegs(hAif2, aif2Setup->commonSetup);
        }

         /* Ingress DB setup */
        if (aif2Setup->commonSetup->pIngrDbSetup != NULL)
        {
            CSL_aif2SetupIngrDbRegs(hAif2, aif2Setup->commonSetup);
        }

        /* Egress DB  setup */
        if (aif2Setup->commonSetup->pEgrDbSetup != NULL)
        {
            CSL_aif2SetupEgrDbRegs(hAif2, aif2Setup->commonSetup);
        }
    
         /* AD(Aif Dma) common setup */
        if (aif2Setup->commonSetup->pAdCommonSetup != NULL)
        {
            CSL_aif2SetupAdCommonRegs(hAif2, aif2Setup->commonSetup);
        }

        /* AD DIO  setup */
        if (aif2Setup->commonSetup->pAdDioSetup != NULL)
        {
            CSL_aif2SetupAdInDioRegs(hAif2, aif2Setup->commonSetup);
            CSL_aif2SetupAdEDioRegs(hAif2, aif2Setup->commonSetup);
        }
      
         /* Aif2 Timer common setup */
        if (aif2Setup->commonSetup->pAtCommonSetup!= NULL)
        {
            CSL_aif2SetupAtCommonRegs(hAif2, aif2Setup->commonSetup);
        }

        /* AT Event  setup */
        if (aif2Setup->commonSetup->pAtEventSetup!= NULL)
        {
            CSL_aif2SetupAtEventRegs(hAif2, aif2Setup->commonSetup);
        }
     
        /* Global setup */
        if(aif2Setup->globalSetup !=NULL) {
            CSL_aif2SetupGlobalRegs(hAif2, aif2Setup->globalSetup);                                                       
        }
    }
    return status;
}

