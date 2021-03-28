/**  
 * @file cpsw_singlecore.c
 *
 * @brief 
 *  Example to illustrate the usage of EMAC CPSW3G switch using CPPI, QMSS
 * 	low level drivers and CSL.
 *
 * 	This example application does the following:
 * 	    (1) Initializes:
 * 	            (a) Queue Manager (QM) Subsystem 
 * 	            (b) Packet Accelerator (PA) CPPI DMA 
 * 	            (c) Ethernet Subsystem (Ethernet switch + SGMII + MDIO) - (Note: Applicable only for NO_BOOT mode)
 * 	            (d) PA Subsystem + PDSP - (Note: PDSP is initialized only during NO_BOOT mode)
 *
 * 	    (2) Sets up the CPPI descriptors and Queues required for sending and
 * 	        receiving data using Ethernet.
 * 	            (a) Uses Host descriptors
 * 	            (b) Uses High Priority Accumulation interrupts
 *
 * 	    (3) Sets up the example application's configuration (MAC address
 * 	        it uses to send/recv data; IP address and port number it's listening
 * 	        on) in PA Subsystem so as to enable the PASS to forward all packets
 * 	        matching this configuration onto the application for processing.
 * 	            (a) Switch MAC address configured   =   0x10:0x11:0x12:0x13:0x14:0x15
 * 	            (b) Example's IP address            =   192.168.1.10
 * 	            (c) Example App's listening port    =   0x5678
 *
 * 	    (4) Sends packets onto wire 
 * 	        (constructed manually in code here with following settings):
 * 	            (a) Source MAC      =   0x00:0x01:0x02:0x03:0x04:0x05
 * 	                Destination MAC =   0x10:0x11:0x12:0x13:0x14:0x15
 *              (b) Source IP       =   192.168.1.1
 *                  Destination IP  =   192.168.1.10
 *              (c) Source Port     =   0x1234
 *                  Destination Port=   0x5678
 *              (d) Payload Data (80 bytes)
 *
 *          The packets sent by the application are sent onto wire and 
 *          since the destination MAC on the packet is the Ethernet Switch 
 *          MAC address, the packets are received by simulator and passed 
 *          back up to the example application for processing.
 *      
 *      (5) Application receives all packets using QM High priority interrupt
 *          registered; Validates received packet against data sent.
 *
 *  Example application Setup:
 *
 *          PC Running Simulator using CCS connected to a
 *          Switch/Hub. You could put another PC on the Hub to observe packets 
 *          being sent onto wire. 
 *
 *          Please consult the Readme.txt packaged with the example to 
 *          setup the CCS simulator configuration required to run this example 
 *          succesfully.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2009, Texas Instruments, Inc.
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
#include <cpsw_singlecore.h>
#include <stdio.h>

/**************************************************************
************************** DEFINITIONS ************************
***************************************************************/
/* Number of packets to be used for testing the example. */
#define                     MAX_NUM_PACKETS                         10u

#define                     MAX_RETRIES                             20u

/* Counters to track number of packets sent/received by this application */
extern volatile uint32_t				gRxCounter, gTxCounter;

/*
 * Default test configuration for the silicon
 *
 * To run test at the CCS simulator
 *    cpswSimTest = 1
 *    cpswLpbkMode = CPSW_LOOPBACK_INTERNAL
 */
#ifdef  SIMULATOR_SUPPORT
int cpswSimTest = 1;
int cpswLpbkMode = CPSW_LOOPBACK_INTERNAL;
#else
int cpswSimTest = 0;
int cpswLpbkMode = CPSW_LOOPBACK_INTERNAL;
#endif

void mdebugHaltPdsp (int pdspNum);
volatile int mdebugWait = 1;

#ifdef __LINUX_USER_SPACE
uint32_t no_bootMode = FALSE;
/* Linux Specific global variables per process */
sock_h                      rmClientSocket;
sem_t                       mutex;
#else
uint32_t no_bootMode = TRUE;
#endif

/**************************************************************
**************** EXAMPLE APP FUNCTIONS ************************
***************************************************************/

/** ============================================================================
 *   @n@b Cpsw_SingleCoreApp
 *
 *   @b Description
 *   @n Example application that sets up the application, sends, receives
 *      data.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return
 *   @n None
 *
 * =============================================================================
 */
static  CSL_CPSW_STATS  stats [CSL_CPSW_NUMSTATBLOCKS];

#ifdef __LINUX_USER_SPACE
void* Cpsw_SingleCoreApp (void *args)
#else
void Cpsw_SingleCoreApp (void)
#endif
{
	extern void view_ale_table(void);
	int32_t			i;
	int				ct_show_ale = 0;
    int             fPass = 1;

    System_printf ("**************************************************\n");
    System_printf ("******* Ethernet Single Core Example Start *******\n");
    System_printf ("**************************************************\n");
    System_flush();

#if RM
    if (setupRm ())
    {
      System_printf ("Function setupRm failed\n");
      System_flush();
      return;
    }
#endif
    /* Initialize the components required to run the example:
     *  (1) QMSS
     *  (2) CPPI
     *  (3) Ethernet switch subsystem + MDIO + SGMII
     */
    
    /* Initialize QMSS */
    if (Init_Qmss () != 0)
    {
        System_printf ("QMSS init failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("QMSS successfully initialized \n");
        System_flush();
    }

    /* Initialize CPPI */
    if (Init_Cppi () != 0)
    {
        System_printf ("CPPI init failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("CPPI successfully initialized \n");
        System_flush();
    }

#ifndef NSS_LITE
    /* Init PA LLD */
    if (Init_PASS () != 0)
    {
        System_printf ("PASS init failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("PASS successfully initialized \n");
        System_flush();
    }
#endif    
#ifndef __LINUX_USER_SPACE
    if (no_bootMode == TRUE)
    {
        /* Initialize the CPSW switch */
        if (Init_Cpsw () != 0)
        {
            System_printf ("Ethernet subsystem init failed \n");
            System_flush();
            APP_exit (-1);
        }
        else
        {
            System_printf ("Ethernet subsystem successfully initialized \n");
            System_flush();
        }
    }
#endif

    /* Setup Tx */
    if (Setup_Tx () != 0)
    {
        System_printf ("Tx setup failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("Tx setup successfully done \n");
        System_flush();
    }

    /* Setup Rx */
    if (Setup_Rx () != 0)
    {
        System_printf ("Rx setup failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("Rx setup successfully done \n");
        System_flush();
    }

#ifndef NSS_LITE
    /* Setup PA */
    if (Setup_PASS () != 0)
    {
        System_printf ("PASS setup failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("PASS setup successfully done \n");
        System_flush();
    }
#endif    

    if (no_bootMode == TRUE)
    {
        System_printf("Following is the ALE table before transmits.\n");
        view_ale_table();	// Added by Atsushi
        System_flush();
    }

#ifndef __LINUX_USER_SPACE
    System_printf ("CSL_CPSW_getStats before Packet Transmission ...\n");
    memset(stats, 0, sizeof(stats));
    cpsw_getStats(stats, 0);
    System_flush();
#endif
    
    /* Run some data through and verify transfer worked */
    System_printf ("Packet Transmission Start ... \n");
#ifndef __LINUX_USER_SPACE
    for (dest_emac_port_id = 0; dest_emac_port_id < (NUM_MAC_PORTS);  dest_emac_port_id ++)
    {
#endif
	    for (i = 0; i < MAX_NUM_PACKETS; i ++)
	    {
#ifdef __LINUX_USER_SPACE
	    	if (SendPacket () != 0)
#else
	    	if (SendPacket (dest_emac_port_id) != 0)
#endif
	        {
	            System_printf ("Packet %d send failed \n", i);
	            System_flush();
	            APP_exit (-1);
	        }
	    }
	    
	    if (no_bootMode == TRUE)
	    {
	        System_printf("Following is the ALE table after transmits.\n");
	        view_ale_table();
	        System_flush();
	    }
	    
	    /* Wait until all packet reception is done */
#ifdef __LINUX_USER_SPACE
	    System_printf ("Packet Transmission Done.\nWait for all packets to be Received ... \n");
	    System_flush();
#else
	    System_printf ("Packet Transmission Done.\nWait for all packets to be Received from EMAC port %d... \n", dest_emac_port_id);
	    System_flush();
#endif
	    i = 0;
	    while ((gRxCounter != gTxCounter) && (i < MAX_RETRIES)) {
#if defined( __LINUX_USER_SPACE) || defined(NSS_LITE)
	        if(ReceivePacket() == -1)
	        {
	            System_printf("Verififcation Failed for Received %d packets so far...\n", gRxCounter);
	        }
#endif		
	        CycleDelay (10000);
	        
	        if (!cpswSimTest)
	        {
	    	    if (++ ct_show_ale >= 10) {
	    		    view_ale_table();
	    		    ct_show_ale = 0;
	    	    }
	        }
	        i++;
	    	System_printf("Received %d packets so far...\n", gRxCounter);
	        System_flush();
	    }
	    
	    System_printf ("Packets Sent\t\t=\t%d \nPackets Received\t=\t%d\n", gTxCounter,  gRxCounter);
	    System_flush();
        if(gRxCounter != gTxCounter)fPass = 0;
	    gTxCounter = gRxCounter = 0;
#ifndef __LINUX_USER_SPACE
    }
#endif

#ifndef NSS_LITE
    System_printf ("PA Stats After Packet Transmission BEGIN ********* ... \n");
    if (getPaStats ())  {
        System_printf ("Function getPaStats failed\n");
        System_flush();
    }
#endif    

#ifndef __LINUX_USER_SPACE
    System_printf ("CSL_CPSW_getStats after Packet Transmission ...\n");
    cpsw_getStats(stats, 1);
#endif
    if(fPass)
        System_printf("All tests have passed!\n");
    System_printf ("**************************************************\n");
    System_printf ("******** Ethernet Single Core Example End ********\n");
    System_printf ("**************************************************\n");
    System_flush();

    /* Clear framework */
	if (clearFramework() < 0) 
	{
        System_printf ("Failed to Clean the example application \n");
        System_flush();
	}

#if (RM) && !defined(__LINUX_USER_SPACE)
    {
        int32_t rmResult;

        if ((rmResult = Rm_resourceStatus(rmHandle, FALSE)) != 0)
        {
            System_printf ("Error : Number of unfreed resources : %d\n", rmResult);
            System_flush();
        }
        else
        {
            System_printf ("All resources freed successfully\n");
            System_flush();
        }
    }
#endif
    /* Example application done. Return success */
    APP_exit (0);
    
}

/* Nothing past this point */

