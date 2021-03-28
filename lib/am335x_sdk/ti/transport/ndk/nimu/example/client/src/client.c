/**
 * @file   client.c
 *
 * @brief  TCP/IP Network Client example 
 */
/*
 * Copyright (c) 2015-2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/



#include <stdio.h>

/* BIOS6 include */
#include <ti/sysbios/BIOS.h>


#include <ti/ndk/inc/netmain.h>
//#include <ti/transport/ndk/nimu/example/client/src/nimu_cppi_qmss_iface.h>

#ifdef _TMS320C6X
#include <ti/csl/csl_chipAux.h>
#endif
#include <ti/csl/csl_psc.h>
#include <ti/csl/csl_pscAux.h>
#include <ti/ndk/inc/_stack.h>
#include <ti/ndk/inc/tools/console.h>
#include <ti/ndk/inc/tools/servers.h>
#ifdef __ARM_ARCH_7A__
#include <ti/csl/cslr_msmc.h>
#include <ti/csl/csl_bootcfgAux.h>
#endif

//#include <ti/ndk/inc/netmain.h>
#include <ti/transport/ndk/nimu/example/client/src/nimu_cppi_qmss_iface.h>
#include "ti/transport/ndk/nimu/example/client/src/client.h"

#ifdef _TMS320C6X
#include <ti/sysbios/family/c64p/Hwi.h>
#include <ti/sysbios/family/c64p/EventCombiner.h>
#else
#include <ti/sysbios/family/arm/gic/Hwi.h>
#include <ti/sysbios/family/arm/a15/Mmu.h>
#endif


// When USE_OLD_SERVERS set to zero, server daemon is used
//#define USE_OLD_SERVERS 0

//---------------------------------------------------------------------------
// Title String
//
char *VerStr = "\nTCP/IP Stack Example Client\n";

// Our NETCTRL callback functions
static void   NIMU_testNetworkOpen();
static void   NIMU_testNetworkClose();
static void   NIMU_testNetworkIpAddr( uint32_t IPAddr, uint32_t IfIdx, uint32_t fAdd );

// Fun reporting function
static void   NIMU_testServiceReport( uint32_t Item, uint32_t Status, uint32_t Report, void * hCfgEntry );

/* Platform Information - we will read it form the Platform Library */
//platform_info    gPlatformInfo;


//---------------------------------------------------------------------------
// Configuration
//

char *HostName    = "tidsp";
char *LocalIPAddr = "192.168.1.4";
char *LocalIPMask = "255.255.255.0";    // Not used when using DHCP
char *GatewayIP   = "192.168.1.1";    // Not used when using DHCP
char *DomainName  = "demo.net";         // Not used when using DHCP
char *DNSServer   = "0.0.0.0";          // Used when set to anything but zero




uint8_t DHCP_OPTIONS[] = { DHCPOPT_SERVER_IDENTIFIER, DHCPOPT_ROUTER };

#undef        TEST_RAW_NC
#undef        TEST_RAW_SEND
#undef        TEST_RAW_RECV

#define     PACKET_SIZE     1000
#define     PACKET_COUNT    1

#ifdef      TEST_RAW_SEND
static void * hSendRaw = 0;
static void Nimu_testSendRawEth();
#endif

#ifdef      TEST_RAW_RECV
static void * hRecvRaw = 0;
static void Nimu_testRecvRawEth();
#endif


//---------------------------------------------------------------------
// Main Entry Point
//---------------------------------------------------------------------
int main()
{
 /* Start the BIOS 6 Scheduler */
    BIOS_start ();
}

//
// Main Thread
//
//
int StackTest()
{
    int               rc;
    int                  i;
    void *            hCfg;
    CI_SERVICE_TELNET telnet;
    CI_SERVICE_HTTP   http;
    NIMU_QMSS_CFG_T      qmss_cfg;
    NIMU_CPPI_CFG_T      cppi_cfg;


    if (setupRm ())
    {
      NIMU_testLog ("Function setupRm failed\n");
      System_flush();
      goto main_exit;
    }

    /* Initialize the components required to run this application:
     *  (1) QMSS
     *  (2) CPPI
     *  (3) Packet Accelerator
     */

#ifdef _TMS320C6X
    if (CSL_chipReadDNUM() == 0)
    {
        qmss_cfg.master_core        = 1;
    }
#else
   qmss_cfg.master_core =1;
#endif

    qmss_cfg.max_num_desc       = MAX_NUM_DESC;
    qmss_cfg.desc_size          = MAX_DESC_SIZE;
    qmss_cfg.mem_region         = Qmss_MemRegion_MEMORY_REGION0;
    if (NIMU_initQmss (&qmss_cfg) != 0)
    {
        NIMU_testLog ("Failed to initialize the QMSS subsystem \n");
        goto main_exit;
    }
    else
    {
        NIMU_testLog ("QMSS successfully initialized \n");
    }

#ifdef _TMS320C6X
    if (CSL_chipReadDNUM() == 0)
    {
        cppi_cfg.master_core        = 1;
    }
#else
    cppi_cfg.master_core        = 1;
#endif


    cppi_cfg.dma_num            = Cppi_CpDma_PASS_CPDMA;
    cppi_cfg.num_tx_queues      = NUM_PA_TX_QUEUES;
    cppi_cfg.num_rx_channels    = NUM_PA_RX_CHANNELS;
    if (NIMU_initCppi (&cppi_cfg) != 0)
    {
        NIMU_testLog ("Failed to initialize CPPI subsystem \n");
        goto main_exit;
    }
    else
    {
        NIMU_testLog ("CPPI successfully initialized \n");
    }


    if (Nimu_testInitPASS()!= 0) {
        NIMU_testLog ("Failed to initialize the Packet Accelerator \n");
        goto main_exit;
    }
    else
    {
        NIMU_testLog ("PA successfully initialized \n");
    }

    //
    // THIS MUST BE THE ABSOLUTE FIRST THING DONE IN AN APPLICATION before
    //  using the stack!!
    //
    rc = NC_SystemOpen( NC_PRIORITY_LOW, NC_OPMODE_INTERRUPT );
    if( rc )
    {
        NIMU_testLog("NC_SystemOpen Failed (%d)\n",rc);
        for(;;);
    }

    // Print out our banner
    NIMU_testLog(VerStr);

    //
    // Create and build the system configuration from scratch.
    //

    // Create a new configuration
    hCfg = CfgNew();
    if( !hCfg )
    {
        NIMU_testLog("Unable to create configuration\n");
        goto main_exit;
    }

    // We better validate the length of the supplied names
    if( strlen( DomainName ) >= CFG_DOMAIN_MAX ||
        strlen( HostName ) >= CFG_HOSTNAME_MAX )
    {
        NIMU_testLog("Names too long\n");
        goto main_exit;
    }

    // Add our global hostname to hCfg (to be claimed in all connected domains)
    CfgAddEntry( hCfg, CFGTAG_SYSINFO, CFGITEM_DHCP_HOSTNAME, 0,
                 strlen(HostName), (uint8_t *)HostName, 0 );

    // If the IP address is specified, manually configure IP and Gateway
#if defined(_SCBP6618X_) || defined (DEVICE_C6678) || defined(_EVMTCI6614_) || defined(DEVICE_K2H) || defined(DEVICE_K2K) || defined(DEVICE_K2L) || defined(DEVICE_K2E)
    /* SCBP6618x, EVMTCI6614, EVMK2H, EVMK2K always uses DHCP */
    if (0)
#else
    if (!platform_get_switch_state(1))
#endif
    {
        CI_IPNET NA;
        CI_ROUTE RT;
        uint32_t      IPTmp;

        NIMU_testLog("StackTest: using localIp\n");
        // Setup manual IP address
        bzero( &NA, sizeof(NA) );
        NA.IPAddr  = inet_addr(LocalIPAddr);
        NA.IPMask  = inet_addr(LocalIPMask);
        strcpy( NA.Domain, DomainName );
        NA.NetType = 0;

        // Add the address to interface 1
        CfgAddEntry( hCfg, CFGTAG_IPNET, 1, 0,
                           sizeof(CI_IPNET), (uint8_t *)&NA, 0 );

        // Add the default gateway. Since it is the default, the
        // destination address and mask are both zero (we go ahead
        // and show the assignment for clarity).
        bzero( &RT, sizeof(RT) );
        RT.IPDestAddr = 0;
        RT.IPDestMask = 0;
        RT.IPGateAddr = inet_addr(GatewayIP);

        // Add the route
        CfgAddEntry( hCfg, CFGTAG_ROUTE, 0, 0,
                           sizeof(CI_ROUTE), (uint8_t *)&RT, 0 );

        // Manually add the DNS server when specified
        IPTmp = inet_addr(DNSServer);
        if( IPTmp )
            CfgAddEntry( hCfg, CFGTAG_SYSINFO, CFGITEM_DHCP_DOMAINNAMESERVER,
                         0, sizeof(IPTmp), (uint8_t *)&IPTmp, 0 );
    }
    // Else we specify DHCP
    else
    {
        NIMU_testLog("Configuring DHCP client\n");
        CI_SERVICE_DHCPC dhcpc;


        // Specify DHCP Service on IF-1
        bzero( &dhcpc, sizeof(dhcpc) );
        dhcpc.cisargs.Mode   = CIS_FLG_IFIDXVALID;
        dhcpc.cisargs.IfIdx  = 1;
        dhcpc.cisargs.pCbSrv = &NIMU_testServiceReport;
        dhcpc.param.pOptions = DHCP_OPTIONS;
        dhcpc.param.len = 2;

        CfgAddEntry( hCfg, CFGTAG_SERVICE, CFGITEM_SERVICE_DHCPCLIENT, 0,
                     sizeof(dhcpc), (uint8_t *)&dhcpc, 0 );
    }

    // Specify TELNET service for our Console example
    bzero( &telnet, sizeof(telnet) );
    telnet.cisargs.IPAddr = INADDR_ANY;
    telnet.cisargs.pCbSrv = &NIMU_testServiceReport;
    telnet.param.MaxCon   = 2;
    telnet.param.Callback = &ConsoleOpen;
    CfgAddEntry( hCfg, CFGTAG_SERVICE, CFGITEM_SERVICE_TELNET, 0,
                 sizeof(telnet), (uint8_t *)&telnet, 0 );

    // Create RAM based WEB files for HTTP
    AddWebFiles();

    // HTTP Authentication
    {
        CI_ACCT CA;

        // Name our authentication group for HTTP (Max size = 31)
        // This is the authentication "realm" name returned by the HTTP
        // server when authentication is required on group 1.
        CfgAddEntry( hCfg, CFGTAG_SYSINFO, CFGITEM_SYSINFO_REALM1,
                     0, 30, (uint8_t *)"DSP_CLIENT_DEMO_AUTHENTICATE1", 0 );

        // Create a sample user account who is a member of realm 1.
        // The username and password are just "username" and "password"
        strcpy( CA.Username, "username" );
        strcpy( CA.Password, "password" );
        CA.Flags = CFG_ACCTFLG_CH1;  // Make a member of realm 1
        rc = CfgAddEntry( hCfg, CFGTAG_ACCT, CFGITEM_ACCT_REALM,
                          0, sizeof(CI_ACCT), (uint8_t *)&CA, 0 );
    }

    // Specify HTTP service
    bzero( &http, sizeof(http) );
    http.cisargs.IPAddr = INADDR_ANY;
    http.cisargs.pCbSrv = &NIMU_testServiceReport;
    CfgAddEntry( hCfg, CFGTAG_SERVICE, CFGITEM_SERVICE_HTTP, 0,
                 sizeof(http), (uint8_t *)&http, 0 );

    //
    // Configure IPStack/OS Options
    //

    // We don't want to see debug messages less than WARNINGS
    rc = DBG_INFO;
    CfgAddEntry( hCfg, CFGTAG_OS, CFGITEM_OS_DBGPRINTLEVEL,
                 CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );

    //
    // This code sets up the TCP and UDP buffer sizes
    // (Note 8192 is actually the default. This code is here to
    // illustrate how the buffer and limit sizes are configured.)
    //

    // TCP Transmit buffer size
    rc = 8192;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPTXBUF,
                 CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );

    // TCP Receive buffer size (copy mode)
    rc = 8192;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPRXBUF,
                 CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );

    // TCP Receive limit (non-copy mode)
    rc = 8192;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPRXLIMIT,
                 CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );

    // UDP Receive limit
    rc = 8192;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKUDPRXLIMIT,
                 CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );



    //
    // Boot the system using this configuration
    //
    // We keep booting until the function returns 0. This allows
    // us to have a "reboot" command.
    //
    do
    {
        rc = NC_NetStart( hCfg, NIMU_testNetworkOpen, NIMU_testNetworkClose, NIMU_testNetworkIpAddr );
    } while( rc > 0 );

    // Free the WEB files
    RemoveWebFiles();

    // Delete Configuration
    CfgFree( hCfg );

    // Close the OS
main_exit:
    NC_SystemClose();
    return(0);
}


typedef void* HANDLE;

//
// System Task Code [ Server Daemon Servers ]
//
static HANDLE hEcho=0,hEchoUdp=0,hData=0,hNull=0,hOob=0;

#ifdef _INCLUDE_IPv6_CODE
static void * hEcho6=0, hEchoUdp6=0, hTelnet6=0, hOob6=0, hWeb6=0;
#endif

//
// NIMU_testNetworkOpen
//
// This function is called after the configuration has booted
//
static void NIMU_testNetworkOpen()
{
    // Create our local servers
    hEcho = DaemonNew( SOCK_STREAMNC, 0, 7, dtask_tcp_echo,
                       OS_TASKPRINORM, OS_TASKSTKNORM, 0, 3 );
    hEchoUdp = DaemonNew( SOCK_DGRAM, 0, 7, dtask_udp_echo,
                          OS_TASKPRINORM, OS_TASKSTKNORM, 0, 1 );
    hData = DaemonNew( SOCK_STREAM, 0, 1000, dtask_tcp_datasrv,
                       OS_TASKPRINORM, OS_TASKSTKNORM, 0, 3 );
    hNull = DaemonNew( SOCK_STREAMNC, 0, 1001, dtask_tcp_nullsrv,
                       OS_TASKPRINORM, OS_TASKSTKNORM, 0, 3 );
    hOob  = DaemonNew( SOCK_STREAMNC, 0, 999, dtask_tcp_oobsrv,
                       OS_TASKPRINORM, OS_TASKSTKNORM, 0, 3 );

    // Create the IPv6 Local Servers.
#ifdef _INCLUDE_IPv6_CODE
    hEcho6    = Daemon6New (SOCK_STREAM, IPV6_UNSPECIFIED_ADDRESS, 7, dtask_tcp_echo6,
                            OS_TASKPRINORM, OS_TASKSTKNORM, 0, 3 );
    hEchoUdp6 = Daemon6New (SOCK_DGRAM, IPV6_UNSPECIFIED_ADDRESS, 7, dtask_udp_echo6,
                            OS_TASKPRINORM, OS_TASKSTKNORM, 0, 1 );
    hTelnet6  = Daemon6New (SOCK_STREAM, IPV6_UNSPECIFIED_ADDRESS, 23,
                            (int(*)(SOCKET,uint32_t))telnetClientProcess, OS_TASKPRINORM, OS_TASKSTKLOW,
                            (uint32_t)ConsoleOpen, 2 );
    hOob6     = Daemon6New (SOCK_STREAM, IPV6_UNSPECIFIED_ADDRESS, 999, dtask_tcp_oobsrv,
                            OS_TASKPRINORM, OS_TASKSTKNORM, 0, 3 );
    hWeb6     = Daemon6New (SOCK_STREAM, IPV6_UNSPECIFIED_ADDRESS, HTTPPORT, httpClientProcess,
                            OS_TASKPRINORM, OS_TASKSTKHIGH, 0, 4);
#endif
}

//
// NIMU_testNetworkClose
//
// This function is called when the network is shutting down,
// or when it no longer has any IP addresses assigned to it.
//
static void NIMU_testNetworkClose()
{
    DaemonFree( hOob );
    DaemonFree( hNull );
    DaemonFree( hData );
    DaemonFree( hEchoUdp );
    DaemonFree( hEcho );

#ifdef _INCLUDE_IPv6_CODE
    Daemon6Free (hEcho6);
    Daemon6Free (hEchoUdp6);
    Daemon6Free (hTelnet6);
    Daemon6Free (hOob6);
    Daemon6Free (hWeb6);
#endif

#ifdef  TEST_RAW_SEND
    TaskDestroy (hSendRaw);
#endif
#ifdef  TEST_RAW_RECV
    TaskDestroy (hRecvRaw);
#endif

    // Kill any active console
    ConsoleClose();
}


//
// NIMU_testNetworkIpAddr
//
// This function is called whenever an IP address binding is
// added or removed from the system.
//
static void NIMU_testNetworkIpAddr( uint32_t IPAddr, uint32_t IfIdx, uint32_t fAdd )
{
    static uint32_t fAddGroups = 0;
    uint32_t IPTmp;

    if( fAdd )
        NIMU_testLog("Network Added: ");
    else
        NIMU_testLog("Network Removed: ");

    // Print a message
    IPTmp = NDK_ntohl( IPAddr );
    NIMU_testLog("If-%d:%d.%d.%d.%d\n", IfIdx,
            (uint8_t)(IPTmp>>24)&0xFF, (uint8_t)(IPTmp>>16)&0xFF,
            (uint8_t)(IPTmp>>8)&0xFF, (uint8_t)IPTmp&0xFF );

    // This is a good time to join any multicast group we require
    if( fAdd && !fAddGroups )
    {
        fAddGroups = 1;
//              IGMPJoinHostGroup( inet_addr("224.1.2.3"), IfIdx );
    }

    /* Create a Task to send/receive Raw ethernet traffic */
#ifdef  TEST_RAW_SEND
    hSendRaw = TaskCreate( Nimu_testSendRawEth, "TxRawEthTsk", OS_TASKPRINORM, 0x1400, 0, 0, 0 );
#endif
#ifdef  TEST_RAW_RECV
    hRecvRaw = TaskCreate( Nimu_testRecvRawEth, "PerformRawRX", OS_TASKPRIHIGH, 0x1400, 0, 0, 0 );
#endif
}

//
// Nimu_testDHCPReset()
//
// Code to reset DHCP client by removing it from the active config,
// and then reinstalling it.
//
// Called with:
// IfIdx    set to the interface (1-n) that is using DHCP.
// fOwnTask set when called on a new task thread (via TaskCreate()).
//
void Nimu_testDHCPReset( uint32_t IfIdx, uint32_t fOwnTask )
{
    CI_SERVICE_DHCPC dhcpc;
    void * h;
    int    rc,tmp;
    uint32_t   idx;

    // If we were called from a newly created task thread, allow
    // the entity that created us to complete
    if( fOwnTask )
        TaskSleep(500);

    // Find DHCP on the supplied interface
    for(idx=1; ; idx++)
    {
        // Find a DHCP entry
        rc = CfgGetEntry( 0, CFGTAG_SERVICE, CFGITEM_SERVICE_DHCPCLIENT,
                          idx, &h );
        if( rc != 1 )
            goto RESET_EXIT;

        // Get DHCP entry data
        tmp = sizeof(dhcpc);
        rc = CfgEntryGetData( h, &tmp, (uint8_t *)&dhcpc );

        // If not the right entry, continue
        if( (rc<=0) || dhcpc.cisargs.IfIdx != IfIdx )
        {
            CfgEntryDeRef(h);
            h = 0;
            continue;
        }

        // This is the entry we want!

        // Remove the current DHCP service
        CfgRemoveEntry( 0, h );

        // Specify DHCP Service on specified IF
        bzero( &dhcpc, sizeof(dhcpc) );
        dhcpc.cisargs.Mode   = CIS_FLG_IFIDXVALID;
        dhcpc.cisargs.IfIdx  = IfIdx;
        dhcpc.cisargs.pCbSrv = &NIMU_testServiceReport;
        CfgAddEntry( 0, CFGTAG_SERVICE, CFGITEM_SERVICE_DHCPCLIENT, 0,
                     sizeof(dhcpc), (uint8_t *)&dhcpc, 0 );
        break;
    }

RESET_EXIT:
    // If we are a function, return, otherwise, call TaskExit()
    if( fOwnTask )
        TaskExit();
}


void Nimu_testCheckDHCPOptions();

//
// Service Status Reports
//
// Here's a quick example of using service status updates
//
static char *TaskName[]  = { "Telnet","HTTP","NAT","DHCPS","DHCPC","DNS" };
static char *ReportStr[] = { "","Running","Updated","Complete","Fault" };
static char *StatusStr[] = { "Disabled","Waiting","IPTerm","Failed","Enabled" };
static void NIMU_testServiceReport( uint32_t Item, uint32_t Status, uint32_t Report, void * h )
{
    NIMU_testLog( "Service Status: %-9s: %-9s: %-9s: %03d\n",
            TaskName[Item-1], StatusStr[Status],
            ReportStr[Report/256], Report&0xFF );

    //
    // Example of adding to the DHCP configuration space
    //
    // When using the DHCP client, the client has full control over access
    // to the first 256 entries in the CFGTAG_SYSINFO space.
    //
    // Note that the DHCP client will erase all CFGTAG_SYSINFO tags except
    // CFGITEM_DHCP_HOSTNAME. If the application needs to keep manual
    // entries in the DHCP tag range, then the code to maintain them should
    // be placed here.
    //
    // Here, we want to manually add a DNS server to the configuration, but
    // we can only do it once DHCP has finished its programming.
    //
    if( Item == CFGITEM_SERVICE_DHCPCLIENT &&
        Status == CIS_SRV_STATUS_ENABLED &&
        (Report == (NETTOOLS_STAT_RUNNING|DHCPCODE_IPADD) ||
         Report == (NETTOOLS_STAT_RUNNING|DHCPCODE_IPRENEW)) )
    {
        uint32_t IPTmp;

        // Manually add the DNS server when specified
        IPTmp = inet_addr(DNSServer);
        if( IPTmp )
            CfgAddEntry( 0, CFGTAG_SYSINFO, CFGITEM_DHCP_DOMAINNAMESERVER,
                         0, sizeof(IPTmp), (uint8_t *)&IPTmp, 0 );
    }

    // Reset DHCP client service on failure
    if( Item==CFGITEM_SERVICE_DHCPCLIENT && (Report&~0xFF)==NETTOOLS_STAT_FAULT )
    {
        CI_SERVICE_DHCPC dhcpc;
        int tmp;

        // Get DHCP entry data (for index to pass to Nimu_testDHCPReset).
        tmp = sizeof(dhcpc);
        CfgEntryGetData( h, &tmp, (uint8_t *)&dhcpc );

        // Create the task to reset DHCP on its designated IF
        // We must use TaskCreate instead of just calling the function as
        // we are in a callback function.
        TaskCreate( Nimu_testDHCPReset, "DHCPreset", OS_TASKPRINORM, 0x1000,
                    dhcpc.cisargs.IfIdx, 1, 0 );
    }
}

void Nimu_testCheckDHCPOptions()
{
    char IPString[16];
    uint32_t  IPAddr;
    int  i, rc;

    // Now scan for DHCPOPT_SERVER_IDENTIFIER via configuration
    NIMU_testLog("\nDHCP Server ID:\n");
    for(i=1;;i++)
    {
        // Try and get a DNS server
        rc = CfgGetImmediate( 0, CFGTAG_SYSINFO, DHCPOPT_SERVER_IDENTIFIER,
                              i, 4, (uint8_t *)&IPAddr );
        if( rc != 4 )
            break;

        // We got something

        // Convert IP to a string:
        NtIPN2Str( IPAddr, IPString );
        NIMU_testLog("DHCP Server %d = '%s'\n", i, IPString);
    }
    if( i==1 )
        NIMU_testLog("None\n\n");
    else
        NIMU_testLog("\n");

    // Now scan for DHCPOPT_ROUTER via the configuration
    NIMU_testLog("Router Information:\n");
    for(i=1;;i++)
    {
        // Try and get a DNS server
        rc = CfgGetImmediate( 0, CFGTAG_SYSINFO, DHCPOPT_ROUTER,
                              i, 4, (uint8_t *)&IPAddr );
        if( rc != 4 )
            break;

        // We got something

        // Convert IP to a string:
        NtIPN2Str( IPAddr, IPString );
        NIMU_testLog("Router %d = '%s'\n", i, IPString);
    }
    if( i==1 )
        NIMU_testLog("None\n\n");
    else
        NIMU_testLog("\n");
}

#ifdef TEST_RAW_SEND
/* Routine to demonstrate sending raw ethernet packets using
 * send() / sendnc() APIs and AF_RAWETH family socket.
 */
static void Nimu_testSendRawEth()
{
    char*       pBuffer = NULL;
    ETHHDR*     ptr_eth_header;
    uint32_t      rawether_type = 0x300, rawchannel_num = 0;
    uint8_t       src_mac[6], dst_mac[6], bData[20];
    int         i, j, val, bytes, retVal;
    SOCKET      sraw = INVALID_SOCKET;
#ifdef TEST_RAW_NC
    PBM_Handle  hPkt = NULL;
#endif

    /* Allocate the file environment for this task */
    fdOpenSession( TaskSelf() );

    /* wait for the ethernet link to come up. */
    TaskSleep(20000);

    NIMU_testLog("Raw Eth Task Started ... \n");

    /* Demonstrating use of SO_PRIORITY to configure
     * custom properties for all packets travelling
     * using this socket.
     *
     * Here, in this example we will use it for
     * configuring a distinct EMAC channel number for each
     * of the raw ethernet sockets.
     *
     * For example, Channel Assignment:
     *      Chan 0 - IP
     *      Chan 3 - Raw
     */
    rawchannel_num = 3;

    /* Create the raw ethernet socket */
    sraw = socket(AF_RAWETH, SOCK_RAWETH, rawether_type);
    if( sraw == INVALID_SOCKET )
    {
        NIMU_testLog("Fail socket, %d\n", fdError());
        fdCloseSession (TaskSelf());
        return;
    }

    /* Configure the transmit device */
    val = 1;
    retVal = setsockopt(sraw, SOL_SOCKET, SO_IFDEVICE, &val, sizeof(val));
    if(retVal)
        NIMU_testLog("error in setsockopt \n");

    /* Configure the EMAC channel number */
    val = rawchannel_num;
    retVal = setsockopt(sraw, SOL_SOCKET, SO_PRIORITY, &val, sizeof(val));
    if(retVal)
        NIMU_testLog("error in setsockopt \n");

    /* Send the RAW eth packets out */
    for(j = 0; j < PACKET_COUNT; j++)
    {
#ifndef  TEST_RAW_NC
        if ((pBuffer = mmAlloc (sizeof(char) * PACKET_SIZE)) == NULL)
        {
            NIMU_testLog("OOM ?? \n");
            TaskExit();
        }
#else
        if(getsendncbuff(sraw, PACKET_SIZE, (void **) &pBuffer, &hPkt))
        {
            NIMU_testLog("Error: Raw Eth getsendncbuff failed Error:%d\n", fdError());
            fdCloseSession( TaskSelf() );
            fdClose(sraw);
            TaskExit();
        }
#endif

        /* Configure the Source MAC, Destination MAC, Protocol and Payload */
        for (i = 0; i < 6; i++)
        {
            src_mac[i] = 0x10 + i;
        }

        for (i = 0; i < 6; i++)
            dst_mac[i] = 0x20 + i + 2;

        for (i = 0; i < 20; i++)
            bData[i] = 0x60 + i;

        ptr_eth_header = (ETHHDR*)pBuffer;

        /* Copy the source MAC address as is. */
        mmCopy (ptr_eth_header->SrcMac, src_mac, 6);

        /* Copy the destination MAC address as is. */
        mmCopy (ptr_eth_header->DstMac, dst_mac, 6);

        /* Configure the type in network order. */
        ptr_eth_header->Type = HNC16(rawether_type);

        /* Copy over the payload to the buffer */
        mmCopy(pBuffer + ETHHDR_SIZE, bData, 20);


#ifndef TEST_RAW_NC
        /* Send the packet using the copy version of send() API. */
        bytes = send(sraw, (char *)pBuffer, PACKET_SIZE, 0);
#else
        /* Use the no-copy version of send, sendnc() to send out the data */
        bytes = sendnc(sraw, (char *)pBuffer, PACKET_SIZE, hPkt, 0);
#endif

#ifndef TEST_RAW_NC
        /* If we allocated the buffer, free it up. If we used up the sendnc()
         * API, the buffer will be freed up by the stack.
         */
        mmFree(pBuffer);
#endif

        if( bytes < 0 )
        {
            NIMU_testLog("Error: Raw Eth Send failed Error:%d\n", fdError());

#ifdef TEST_RAW_NC
            sendncfree(hPkt);
#endif

            fdCloseSession( TaskSelf() );
            fdClose(sraw);
            TaskExit();
        }
    }

    NIMU_testLog("Raw Eth Task Ended ... \n");

    fdClose(sraw);

    /* Close the session & kill the task */
    fdCloseSession( TaskSelf() );
    TaskExit();
}
#endif

#ifdef TEST_RAW_RECV

/* Routine to demonstrate packet receive using recvnc() API
 * and AF_RAWETH family sockets.
 */
static void Nimu_testRecvRawEth()
{
    SOCKET      sraw;
    INT32       val,retVal, count = 0, bytes;
    char*        pBuf;
    void *       hBuffer;
    uint32_t      rawchannel_num;
    ETHHDR*     ptr_eth_header;

    NIMU_testLog ("Raw Eth Rx Task has been started\n");

    /* Allocate the file environment for this task */
    fdOpenSession( TaskSelf() );

    /* Demonstrating use of SO_PRIORITY to configure
     * custom properties for all packets travelling
     * using this socket.
     *
     * Here, in this example we will use it for
     * configuring a distinct EMAC channel number for each
     * of the raw ethernet sockets.
     *
     * For example, Channel Assignment:
     *      Chan 0 - IP
     *      Chan 3 - Raw
     */
    rawchannel_num = 3;

    /* Create the main UDP listen socket */
    sraw = socket(AF_RAWETH, SOCK_RAWETH, 0x300);
    if( sraw == INVALID_SOCKET )
        return;

    /* Configure the transmit device */
    val = 1;
    retVal = setsockopt(sraw, SOL_SOCKET, SO_IFDEVICE, &val, sizeof(val));
    if(retVal)
        NIMU_testLog("error in setsockopt \n");

    /* Configure the EMAC channel number as the priority tag for packets */
    val = rawchannel_num;
    retVal = setsockopt(sraw, SOL_SOCKET, SO_PRIORITY, &val, sizeof(val));
    if(retVal)
        NIMU_testLog("error in setsockopt \n");

    /* Configure the Receive buffer size */
    val = 1000;
    retVal = setsockopt(sraw, SOL_SOCKET, SO_RCVBUF, &val, sizeof(val));
    if(retVal)
        NIMU_testLog("error in setsockopt \n");


    while (count < PACKET_COUNT)
    {
        bytes = (int)recvnc( sraw, (void **)&pBuf, 0, &hBuffer );

        if (bytes < 0)
        {
            /* Receive failed: Close the session & kill the task */
            NIMU_testLog("Receive failed after packets Error:%d\n",fdError());
            fdCloseSession( TaskSelf() );
            TaskExit();
        }
        else
        {
            ptr_eth_header = (ETHHDR*)pBuf;

            NIMU_testLog("Received RAW ETH packet, len: %d \n", PBM_getValidLen((PBM_Handle)hBuffer));
            NIMU_testLog("Dst MAC Address = %02x-%02x-%02x-%02x-%02x-%02x Src MAC Address = %02x-%02x-%02x-%02x-%02x-%02x Eth Type = %d Data = %s \n",
                       ptr_eth_header->DstMac[0],ptr_eth_header->DstMac[1],ptr_eth_header->DstMac[2],
                       ptr_eth_header->DstMac[3],ptr_eth_header->DstMac[4],ptr_eth_header->DstMac[5],
                       ptr_eth_header->SrcMac[0],ptr_eth_header->SrcMac[1],ptr_eth_header->SrcMac[2],
                       ptr_eth_header->SrcMac[3],ptr_eth_header->SrcMac[4],ptr_eth_header->SrcMac[5],
                       ntohs(ptr_eth_header->Type), (pBuf + ETHHDR_SIZE));
        }


        count++;

        /* Clean out the buffer */
        recvncfree( hBuffer );
    }

    /* Close the session & kill the task */
    fdCloseSession( TaskSelf() );
    TaskExit();

    return;
}

#endif

