/*
 * helloWorld_bios6.c
 *
 * TCP/IP Stack 'Hello World!' Example ported to use BIOS6 OS.
 *
 * Copyright (C) 2007, 2011 Texas Instruments Incorporated - http://www.ti.com/
 * 
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

//--------------------------------------------------------------------------
// IP Stack 'Hello World!' Example
//
// This is a skeleton application, intended to provide application  
// programmers with a basic Stack setup, to which they can start 
// adding their code.
//
// To test it as is, use with helloWorld.exe from \winapps directory
//

#include <stdio.h>
#include <ti/ndk/inc/netmain.h>

/* BIOS6 include */
#include <ti/sysbios/BIOS.h>

/* Platform utilities include */
//#include "ti/platform/platform.h"
//#include "ti/platform/resource_mgr.h"

/* Platform Information - we will read it form the Platform Library */
//platform_info  gPlatformInfo;


#define platform_write printf


//---------------------------------------------------------------------------
// Title String
//
char *VerStr = "\nTCP/IP Stack 'Hello World!' Application\n\n";

// Our NETCTRL callback functions
static void   NetworkOpen();
static void   NetworkClose();
static void   NetworkIPAddr( uint32_t IPAddr, uint32_t IfIdx, uint32_t fAdd );

// Fun reporting function
static void   ServiceReport( uint32_t Item, uint32_t Status, uint32_t Report, void* hCfgEntry );

// External references
extern int dtask_udp_hello();


//---------------------------------------------------------------------------
// Configuration
//
char *HostName    = "tidsp";
char *LocalIPAddr = "192.168.1.4";
char *LocalIPMask = "255.255.255.0";    // Not used when using DHCP
char *GatewayIP   = "192.168.1.1";    // Not used when using DHCP
char *DomainName  = "demo.net";         // Not used when using DHCP
char *DNSServer   = "0.0.0.0";          // Used when set to anything but zero


#if 0
/*************************************************************************
 *  @b EVM_init()
 * 
 *  @n
 *
 *  Initializes the platform hardware. This routine is configured to start in 
 *   the evm.cfg configuration file. It is the first routine that BIOS
 *   calls and is executed before Main is called. If you are debugging within
 *  CCS the default option in your target configuration file may be to execute 
 *  all code up until Main as the image loads. To debug this you should disable
 *  that option. 
 *
 *  @param[in]  None
 * 
 *  @retval
 *      None
 ************************************************************************/
void EVM_init()
{
        int i;
        platform_init_flags  sFlags;
        platform_init_config sConfig;
    /* Status of the call to initialize the platform */
    Int32 pform_status;
    /* Platform Information - we will read it form the Platform Library */
    platform_info       sPlatformInfo;

        /*
         * You can choose what to initialize on the platform by setting the following
         * flags. We will initialize everything.
        */
        memset( (void *) &sFlags,  0, sizeof(platform_init_flags));
        memset( (void *) &sConfig, 0, sizeof(platform_init_config));

        sFlags.pll = 0;
        sFlags.ddr = 0;
    sFlags.tcsl = 0;    /* Time stamp counter   */
    sFlags.phy  = 1;    /* Ethernet                     */
    sFlags.ecc = 0;

    sConfig.pllm = 0;

        pform_status = platform_init(&sFlags, &sConfig);

        /* If we initialized the platform okay */
        if (pform_status == Platform_EOK) {
                /* Get information about the platform so we can use it in various places */
                memset( (void *) &sPlatformInfo, 0, sizeof(platform_info));
                (void) platform_get_info(&sPlatformInfo);
        }
        else {
                /* Intiialization of the platform failed... die */
                printf("Platform failed to initialize. Error code %d \n", pform_status);
                printf("We will die in an infinite loop... \n");
                while (1) {
                        (void) platform_led(1, PLATFORM_LED_ON, (LED_CLASS_E) PLATFORM_USER_LED_CLASS);
                        (void) platform_delay(50000);
                        (void) platform_led(1, PLATFORM_LED_OFF, (LED_CLASS_E) PLATFORM_USER_LED_CLASS);
                        (void) platform_delay(50000);
                };
        }

        platform_write_configure(PLATFORM_WRITE_PRINTF);
        platform_uart_init();
        platform_uart_set_baudrate(19200);





        /* Check to see that we are running on the Master Core */
        if (CSL_chipReadDNUM() != 0) {
                /* We are not on the Master Core... die */
                printf("You must run this application on Core 0. \n");
                printf("We will die in an infinite loop... \n");
                while (1) {
//                        (void) platform_led(1, PLATFORM_LED_ON, (LED_CLASS_E) PLATFORM_USER_LED_CLASS);
//                        (void) platform_delay(50000);
//                        (void) platform_led(1, PLATFORM_LED_OFF, (LED_CLASS_E) PLATFORM_USER_LED_CLASS);
//                        (void) platform_delay(50000);
                };
        }

#if 0
        /* Clear the state of the LEDs to OFF */
        for (i=0; i < sPlatformInfo.led[1].count; i++) {
                platform_led(i, PLATFORM_LED_OFF, (LED_CLASS_E) PLATFORM_USER_LED_CLASS);
        }
#endif
        return;
}

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
int StackTest()
{
    int             rc;
    int        i;
    void*          hCfg;

     //
    // THIS MUST BE THE ABSOLUTE FIRST THING DONE IN AN APPLICATION before
    //  using the stack!!
    //
    rc = NC_SystemOpen( NC_PRIORITY_LOW, NC_OPMODE_INTERRUPT );
    if( rc )
    {
        platform_write("NC_SystemOpen Failed (%d)\n",rc);
        for(;;);
    }

    // Print out our banner
    platform_write(VerStr);

    //
    // Create and build the system configuration from scratch.
    //

    // Create a new configuration
    hCfg = CfgNew();
    if( !hCfg )
    {
        platform_write("Unable to create configuration\n");
        goto main_exit;
    }

    // We better validate the length of the supplied names
    if( strlen( DomainName ) >= CFG_DOMAIN_MAX ||
        strlen( HostName ) >= CFG_HOSTNAME_MAX )
    {
        printf("Names too long\n");
        goto main_exit;
    }

    // Add our global hostname to hCfg (to be claimed in all connected domains)
    CfgAddEntry( hCfg, CFGTAG_SYSINFO, CFGITEM_DHCP_HOSTNAME, 0,
                 strlen(HostName), (uint8_t *)HostName, 0 );

    // If the IP address is specified, manually configure IP and Gateway
    //if (!platform_get_switch_state(1))
    if (1)
    {
        CI_IPNET NA;
        CI_ROUTE RT;
        uint32_t      IPTmp;

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
        CI_SERVICE_DHCPC dhcpc;

        // Specify DHCP Service on IF-1
        bzero( &dhcpc, sizeof(dhcpc) );
        dhcpc.cisargs.Mode   = CIS_FLG_IFIDXVALID;
        dhcpc.cisargs.IfIdx  = 1;
        dhcpc.cisargs.pCbSrv = &ServiceReport;
        CfgAddEntry( hCfg, CFGTAG_SERVICE, CFGITEM_SERVICE_DHCPCLIENT, 0,
                     sizeof(dhcpc), (uint8_t *)&dhcpc, 0 );
    }

    //
    // Configure IPStack/OS Options
    //

    // We don't want to see debug messages less than WARNINGS
    rc = DBG_WARN;
    CfgAddEntry( hCfg, CFGTAG_OS, CFGITEM_OS_DBGPRINTLEVEL,
                 CFG_ADDMODE_UNIQUE, sizeof(uint32_t), (uint8_t *)&rc, 0 );

    //
    // This code sets up the TCP and UDP buffer sizes
    // (Note 8192 is actually the default. This code is here to
    // illustrate how the buffer and limit sizes are configured.)
    //

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
        rc = NC_NetStart( hCfg, NetworkOpen, NetworkClose, NetworkIPAddr );
    } while( rc > 0 );

    // Delete Configuration
    CfgFree( hCfg );

    // Close the OS
main_exit:
    NC_SystemClose();
    return(0);
}


//
// System Task Code [ Server Daemon Servers ]
//
static void* hHello=0;

//
// NetworkOpen
//
// This function is called after the configuration has booted
//
static void NetworkOpen()
{
    // Create our local server
    hHello = DaemonNew( SOCK_DGRAM, 0, 7, dtask_udp_hello,
                       OS_TASKPRINORM, OS_TASKSTKNORM, 0, 1 );
}

//
// NetworkClose
//
// This function is called when the network is shutting down,
// or when it no longer has any IP addresses assigned to it.
//
static void NetworkClose()
{
    DaemonFree( hHello );
}


//
// NetworkIPAddr
//
// This function is called whenever an IP address binding is
// added or removed from the system.
//
static void NetworkIPAddr( uint32_t IPAddr, uint32_t IfIdx, uint32_t fAdd )
{
    uint32_t IPTmp;

    if( fAdd )
        printf("Network Added: ");
    else
        printf("Network Removed: ");

    // Print a message
    IPTmp = NDK_ntohl( IPAddr );
    printf("If-%d:%d.%d.%d.%d\n", IfIdx,
            (uint8_t)(IPTmp>>24)&0xFF, (uint8_t)(IPTmp>>16)&0xFF,
            (uint8_t)(IPTmp>>8)&0xFF, (uint8_t)IPTmp&0xFF );
}

//
// Service Status Reports
//
// Here's a quick example of using service status updates
//
static char *TaskName[]  = { "Telnet","HTTP","NAT","DHCPS","DHCPC","DNS" };
static char *ReportStr[] = { "","Running","Updated","Complete","Fault" };
static char *StatusStr[] = { "Disabled","Waiting","IPTerm","Failed","Enabled" };
static void ServiceReport( uint32_t Item, uint32_t Status, uint32_t Report, void* h )
{
    printf( "Service Status: %-9s: %-9s: %-9s: %03d\n",
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
}


