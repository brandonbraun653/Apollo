/**
 * @file   client_am572x.c
 *
 * @brief  TCP/IP Stack 'Client!' Example application
 * 
 */
/*
 * Copyright (c) 2017, Texas Instruments Incorporated
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
 */


/*
 * This is a skeleton application, intended to provide application
 * programmers with a basic Stack setup, to which they can start
 * adding their code.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>


#include <ti/csl/soc.h>
#include <ti/csl/cslr_device.h>

#include <ti/ndk/inc/stkmain.h>
#include <ti/ndk/inc/netmain.h>
#include <ti/ndk/inc/_stack.h>
#include <ti/ndk/inc/tools/console.h>
#include <ti/ndk/inc/tools/servers.h>
#include "ti/transport/ndk/nimu/example/client/src/client.h"
#include <ti/board/board.h>

#include <ti/drv/emac/emac_drv.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>


/* Enable the below macro to have prints on the CIO Console */
//#define IO_CONSOLE
#ifndef IO_CONSOLE
#define NIMU_log                UART_printf
#else
#define NIMU_log                printf
#endif

/* ========================================================================== */
/*                             Macros                                  */
/* ========================================================================== */
#define MAX_TABLE_ENTRIES   3U

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static int nimu_device_index = 0U;

NIMU_DEVICE_TABLE_ENTRY NIMUDeviceTable[MAX_TABLE_ENTRIES];

extern int CpswEmacInit (STKEVENT_Handle hEvent);

/* Title String */
char *VerStr = "\nTCP/IP Stack 'Hello World!' Application\n\n";

/* Our NETCTRL callback functions */
static void   NetworkOpen();
static void   NetworkClose();
static void   NetworkIPAddr( uint32_t IPAddr, uint32_t IfIdx, uint32_t fAdd );


/*  Reporting function */
static void   NIMU_testServiceReport( uint32_t Item, uint32_t Status, uint32_t Report, void* hCfgEntry );

/* Configuration */
char *HostName    = "tiNet";
char *LocalIPAddr = "192.168.1.4";
char *LocalIPMask = "255.255.255.0";    // Not used when using DHCP
char *GatewayIP   = "192.168.1.1";    // Not used when using DHCP
char *DomainName  = "demo.net";         // Not used when using DHCP
char *DNSServer   = "0.0.0.0";          // Used when set to anything but zero


/* main entry point */
int main()
{
    /* Start the BIOS 6 Scheduler */
    BIOS_start ();
    return 0;
}

/* Main Thread */
int StackTest()
{
    int             rc;
    void*          hCfg;
    CI_SERVICE_TELNET telnet;
    CI_SERVICE_HTTP   http;

    /* by default, use DHCP */
    bool useStaticIp = false;
    /* Call board init functions */
    Board_initCfg boardCfg;


    boardCfg =  BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

#ifdef _TMS320C6X
    CSL_xbarDspIrqConfigure(1,CSL_XBAR_INST_DSP1_IRQ_75, CSL_XBAR_GMAC_SW_IRQ_RX_PULSE);
    CSL_xbarDspIrqConfigure(1,CSL_XBAR_INST_DSP1_IRQ_76, CSL_XBAR_GMAC_SW_IRQ_TX_PULSE);
#elif defined (__TI_ARM_V7M4__)
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU1_IRQ_60, CSL_XBAR_GMAC_SW_IRQ_RX_PULSE);
    CSL_xbarIpuIrqConfigure(1, CSL_XBAR_INST_IPU1_IRQ_61, CSL_XBAR_GMAC_SW_IRQ_TX_PULSE);
#elif defined(__ARM_ARCH_7A__)
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_92, CSL_XBAR_GMAC_SW_IRQ_RX_PULSE);
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_93, CSL_XBAR_GMAC_SW_IRQ_TX_PULSE);
#endif

    /* Select RGMII 2 ports GMIIx_SEL = 2 for RGMII*/
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_1,
          CONTROL_CORE_CONTROL_IO_1_GMII1_SEL, 2U);
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_1,
          CONTROL_CORE_CONTROL_IO_1_GMII2_SEL, 2U);

    /*GMAC RESET ISOLATION Enable*/
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_2,
          CONTROL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE, 0U);
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_2,
          CONTROL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE, 1U);

    /* Update device table with NIMU init function */
    NIMUDeviceTable[nimu_device_index++].init =  &CpswEmacInit ;
    NIMUDeviceTable[nimu_device_index].init =  NULL ;

    /* THIS MUST BE THE ABSOLUTE FIRST THING DONE IN AN APPLICATION before
        using the stack*/
    rc = NC_SystemOpen( NC_PRIORITY_LOW, NC_OPMODE_INTERRUPT );
    if( rc )
    {
        UART_printf("NC_SystemOpen Failed (%d)\n",rc);
        for(;;);
    }

    /*Create and build the system configuration from scratch. */
    /* Create a new configuration */
    hCfg = CfgNew();
    if( !hCfg )
    {
        UART_printf("Unable to create configuration\n");
        goto main_exit;
    }
    /* Print out our banner */
    UART_printf(VerStr);


    /* We better validate the length of the supplied names */
    if( strlen( DomainName ) >= CFG_DOMAIN_MAX ||
        strlen( HostName ) >= CFG_HOSTNAME_MAX )
    {
        UART_printf("Names too long\n");
        goto main_exit;
    }

    /*Add our global hostname to hCfg (to be claimed in all connected domains) */
    CfgAddEntry( hCfg, CFGTAG_SYSINFO, CFGITEM_DHCP_HOSTNAME, 0,
                 strlen(HostName), (uint8_t *)HostName, 0 );

    /* By default will use DHCP, set this flag to true  above to verify staticIP use case*/
    if (useStaticIp == true)
    {
        CI_IPNET NA;
        CI_ROUTE RT;
        uint32_t      IPTmp;

        UART_printf("StackTest: using localIp\n");
        /* Setup manual IP address */
        bzero( &NA, sizeof(NA) );
        NA.IPAddr  = inet_addr(LocalIPAddr);
        NA.IPMask  = inet_addr(LocalIPMask);
        strcpy( NA.Domain, DomainName );
        NA.NetType = 0;

        /*Add the address to interface 1 */
        CfgAddEntry( hCfg, CFGTAG_IPNET, 1, 0,
                           sizeof(CI_IPNET), (uint8_t *)&NA, 0 );

        /* Add the default gateway. Since it is the default, the
            destination address and mask are both zero (we go ahead
            and show the assignment for clarity) */
        bzero( &RT, sizeof(RT) );
        RT.IPDestAddr = 0;
        RT.IPDestMask = 0;
        RT.IPGateAddr = inet_addr(GatewayIP);

        /* Add the route */
        CfgAddEntry( hCfg, CFGTAG_ROUTE, 0, 0,
                           sizeof(CI_ROUTE), (uint8_t *)&RT, 0 );

        /* Manually add the DNS server when specified */
        IPTmp = inet_addr(DNSServer);
        if( IPTmp )
            CfgAddEntry( hCfg, CFGTAG_SYSINFO, CFGITEM_DHCP_DOMAINNAMESERVER,
                         0, sizeof(IPTmp), (uint8_t *)&IPTmp, 0 );
    }
    /* Else we specify DHCP */
    else
    {
        UART_printf("StackTest: using dhcp\n");
        CI_SERVICE_DHCPC dhcpc;

        /* Specify DHCP Service on IF-1 */
        bzero( &dhcpc, sizeof(dhcpc) );
        dhcpc.cisargs.Mode   = CIS_FLG_IFIDXVALID;
        dhcpc.cisargs.IfIdx  = 1;
        dhcpc.cisargs.pCbSrv = &NIMU_testServiceReport;
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

        /* Create a sample user account who is a member of realm 1.
         * The username and password are just "username" and "password"
         */
        strcpy( CA.Username, "username" );
        strcpy( CA.Password, "password" );
        CA.Flags = CFG_ACCTFLG_CH1;  // Make a member of realm 1
        rc = CfgAddEntry( hCfg, CFGTAG_ACCT, CFGITEM_ACCT_REALM,
                          0, sizeof(CI_ACCT), (uint8_t *)&CA, 0 );
    }

    /* Specify HTTP service */
    bzero( &http, sizeof(http) );
    http.cisargs.IPAddr = INADDR_ANY;
    http.cisargs.pCbSrv = &NIMU_testServiceReport;
    CfgAddEntry( hCfg, CFGTAG_SERVICE, CFGITEM_SERVICE_HTTP, 0,
                 sizeof(http), (uint8_t *)&http, 0 );



    /* Configure IPStack/OS Options */

    /* We don't want to see debug messages less than WARNINGS */
    rc = DBG_WARN;
    CfgAddEntry( hCfg, CFGTAG_OS, CFGITEM_OS_DBGPRINTLEVEL,
                 CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );

    /* This code sets up the TCP and UDP buffer sizes
     (Note 8192 is actually the default. This code is here to
     illustrate how the buffer and limit sizes are configured.) 
    */

    /* TCP Transmit buffer size */
    rc = 8192;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPTXBUF,
                 CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );

    /*TCP Receive buffer size */
    rc = 8192;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPRXBUF,
                 CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );

    /* TCP Receive limit (non-copy mode) */
    rc = 8192;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPRXLIMIT,
                 CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );

    /* UDP Receive limit */
    rc = 8192;
    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKUDPRXLIMIT,
                 CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );

    /* increase stack size */
    rc = 8192;
    CfgAddEntry(hCfg, CFGTAG_OS, CFGITEM_OS_TASKSTKBOOT, CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );

    /* Boot the system using this configuration
        We keep booting until the function returns 0. This allows
        us to have a "reboot" command. 
    */
   
    do
    {
        rc = NC_NetStart( hCfg, NetworkOpen, NetworkClose, NetworkIPAddr );
    } while( rc > 0 );

    /* Free the WEB files */
    RemoveWebFiles();
    /* Delete Configuration */
    CfgFree( hCfg );

    /*Close the OS */
main_exit:
    UART_printf("StackTest: exiting\n");
    NC_SystemClose();
    return(0);
}


/* System Task Code [ Server Daemon Servers ] */
static HANDLE hEcho=0,hEchoUdp=0,hData=0,hNull=0,hOob=0;

#ifdef _INCLUDE_IPv6_CODE
static HANDLE hEcho6=0, hEchoUdp6=0, hTelnet6=0, hOob6=0, hWeb6=0;
#endif


/* NetworkOpen
 *This function is called after the configuration has booted
 */
static void NetworkOpen()
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


/* NetworkClose
 *This function is called when the network is shutting down,
 * or when it no longer has any IP addresses assigned to it.
 */
static void NetworkClose()
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

/* NetworkIPAddr
 *This function is called whenever an IP address binding is
 * added or removed from the system.
 */
static void NetworkIPAddr( uint32_t IPAddr, uint32_t IfIdx, uint32_t fAdd )
{
    uint32_t IPTmp;

    if( fAdd )
        UART_printf("Network Added: ");
    else
        UART_printf("Network Removed: ");

    // Print a message
    IPTmp = NDK_ntohl( IPAddr );
    UART_printf("If-%d:%d.%d.%d.%d\n", IfIdx,
            (uint8_t)(IPTmp>>24)&0xFF, (uint8_t)(IPTmp>>16)&0xFF,
            (uint8_t)(IPTmp>>8)&0xFF, (uint8_t)IPTmp&0xFF );
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
    void* h;
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

/* Service Status Reports
 * Here's a quick example of using service status updates
 */
static char *TaskName[]  = { "Telnet","HTTP","NAT","DHCPS","DHCPC","DNS" };
static char *StatusStr[] = { "Disabled","Waiting","IPTerm","Failed","Enabled" };
static void NIMU_testServiceReport( uint32_t Item, uint32_t Status, uint32_t Report, void* h )
{

    UART_printf( "Service Status: %s: %s\n", TaskName[Item-1], StatusStr[Status]);

    /* Example of adding to the DHCP configuration space
     *
     * When using the DHCP client, the client has full control over access
     * to the first 256 entries in the CFGTAG_SYSINFO space.
     *
     * Note that the DHCP client will erase all CFGTAG_SYSINFO tags except
     * CFGITEM_DHCP_HOSTNAME. If the application needs to keep manual
     * entries in the DHCP tag range, then the code to maintain them should
     * be placed here.
     *
     * Here, we want to manually add a DNS server to the configuration, but
     * we can only do it once DHCP has finished its programming.
     */
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




