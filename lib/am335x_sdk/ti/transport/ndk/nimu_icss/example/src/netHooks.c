/*
 *  ======== netHooks.c ========
 *  This file contains hook functions to start the send and recv threads
 */
 
#include <xdc/std.h>
#include <ti/ndk/inc/netmain.h>
#include <ti/ndk/inc/tools/servers.h>
#include <ti/transport/ndk/nimu_icss/example/src/osdrv_ndkdeviceconfig.h>
static HANDLE hEcho = 0;
static HANDLE hEchoUdp = 0;
static HANDLE hData = 0;
static HANDLE hNull = 0;
static HANDLE hOob = 0;

void netOpenHook()
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
}

void netCloseHook()
{
    DaemonFree(hOob);
    DaemonFree(hNull);
    DaemonFree(hData);
    DaemonFree(hEchoUdp);
    DaemonFree(hEcho);
}
