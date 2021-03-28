/*
 *
 * Copyright (C) 2010-2013 Texas Instruments Incorporated - http://www.ti.com/ 
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



/* setuprm.c
 */

#include "cpsw_singlecore.h"
#include <ti/drv/rm/rm.h>
#include <ti/drv/rm/rm_services.h>
#ifdef __LINUX_USER_SPACE
#include <ti/drv/rm/rm_transport.h>
#endif
#include <string.h>

#if RM
Rm_Handle          rmHandle = NULL;
Rm_ServiceHandle  *rmServiceHandle = NULL; 

/* RM test Global Resource List (GRL) */
extern const char rmGlobalResourceList[];
/* RM test Global Policy provided to RM Server */
extern const char rmDspOnlyPolicy[];
/* RM test Global Policy provided to RM Server */
extern const char rmDspPlusArmPolicy[];

#ifndef __LINUX_USER_SPACE
Int setupRm (void)
{
  Rm_InitCfg rmInitCfg;
  char       rmServerName[RM_NAME_MAX_CHARS] = "RM_Server"; 
  int32_t    rmResult;

  /* Create the Server instance */
  memset((void *)&rmInitCfg, 0, sizeof(Rm_InitCfg));
  rmInitCfg.instName = rmServerName;
  rmInitCfg.instType = Rm_instType_SERVER;
  if (no_bootMode == TRUE) {
    rmInitCfg.instCfg.serverCfg.globalResourceList = (void *)rmGlobalResourceList;
  	rmInitCfg.instCfg.serverCfg.globalPolicy = (void *)rmDspOnlyPolicy;
  }
  else {
    rmInitCfg.instCfg.serverCfg.globalResourceList = (void *)rmGlobalResourceList;
  	rmInitCfg.instCfg.serverCfg.globalPolicy = (void *)rmDspPlusArmPolicy;
  }
  rmHandle = Rm_init(&rmInitCfg, &rmResult);
  if (rmResult != RM_OK) {
    return (-1);
  }
  
  rmServiceHandle = Rm_serviceOpenHandle(rmHandle, &rmResult);
  if (rmResult != RM_OK) {
    return (-1);
  } 
  return (0);
}
#else
/* Client socket name */
#define MAX_CLIENT_SOCK_NAME 32

/* Application's registered RM transport indices */
#define SERVER_TO_CLIENT_MAP_ENTRY   0
/* Maximum number of registered RM transports */
#define MAX_MAPPING_ENTRIES          1

/* Error checking macro */
#define RM_ERROR_CHECK(checkVal, resultVal, rmInstName, printMsg)                 \
    if (resultVal != checkVal) {                                                  \
        char errorMsgToPrint[] = printMsg;                                        \
        printf("RM Inst : %s : ", rmInstName);                                    \
        printf("%s with error code : %d, exiting\n", errorMsgToPrint, resultVal); \
        return(-1);                                                               \
    }

/* Socket timeout */
#define CLIENT_SOCK_TIMEOUT_USEC     (500)	

/* RM registered transport mapping structure */
typedef struct trans_map_entry_s {
    /* Registered RM transport handle */
    Rm_TransportHandle        transportHandle;
    /* Remote socket tied to the transport handle */
    sock_name_t              *remote_sock;
} Transport_MapEntry;

char                rmClientSockName[MAX_CLIENT_SOCK_NAME];

/* Client instance name (must match with RM Global Resource List (GRL) and policies */
char                rmClientName[RM_NAME_MAX_CHARS] = "RM_Client0";

/* Client socket name */
char                rmClientSockName[] = "/tmp/var/run/rm/rm_client";

/* Transport map stores the RM transport handle to IPC MessageQ queue mapping */
Transport_MapEntry  rmTransportMap[MAX_MAPPING_ENTRIES];

/* RM Client Vars */
Rm_Handle           rmClientHandle = NULL;
Rm_ServiceHandle   *rmClientServiceHandle = NULL;


Rm_Packet *transportAlloc(Rm_AppTransportHandle appTransport, uint32_t pktSize, Rm_PacketHandle *pktHandle)
{
    Rm_Packet *rm_pkt = NULL;

    rm_pkt = (Rm_Packet *) calloc(1, sizeof(*rm_pkt));
    if (!rm_pkt) {
        System_printf("can't malloc for RM send message (err: %s)\n", strerror(errno));
        return (NULL);
    }
    rm_pkt->pktLenBytes = pktSize;
    *pktHandle = rm_pkt;

    return(rm_pkt);
}

void transportFree (Rm_Packet *rm_pkt)
{
    if (rm_pkt) {
        free (rm_pkt);
    }         
}

void transportReceive (void)
{
    int32_t             rm_result;
    int                 retval;
    int                 length = 0;
    sock_name_t         server_sock_addr;
    Rm_Packet          *rm_pkt = NULL;
    struct sockaddr_un  server_addr;    
	int                 coreNum = 0; /* single process, so hard code it */
    
    retval = sock_wait(rmClientSocket, &length, NULL, -1);
    if (retval == -2) {
        /* Timeout */
        printf("core %d: Error socket timeout\n", coreNum);
        return;
    }
    else if (retval < 0) {
        printf("core %d: Error in reading from socket, error %d\n", coreNum, retval);
        return;
    }
    
    if (length < sizeof(*rm_pkt)) {
        printf("core %d: invalid RM message length %d\n", coreNum, length);
        return;
    }
    rm_pkt = calloc(1, length);
    if (!rm_pkt) {
        printf("core %d: can't malloc for recv'd RM message (err: %s)\n",
               coreNum, strerror(errno));
        return;
    }
    
    server_sock_addr.type = sock_addr_e;
    server_sock_addr.s.addr = &server_addr;
    retval = sock_recv(rmClientSocket, (char *)rm_pkt, length, &server_sock_addr);
    if (retval != length) {
        printf("core %d: recv RM pkt failed from socket, received = %d, expected = %d\n",
               coreNum, retval, length);
        return;
    }
    
    //printf("core %d: received RM pkt of size %d bytes from %s\n", coreNum, length, server_sock_addr.s.addr->sun_path);

    /* Provide packet to RM Client for processing */       
    if ((rm_result = Rm_receivePacket(rmTransportMap[SERVER_TO_CLIENT_MAP_ENTRY].transportHandle, rm_pkt))) {
        printf("core %d: RM failed to process received packet: %d\n", coreNum, rm_result);
    }

    transportFree(rm_pkt);
}

int32_t transportSendRcv (Rm_AppTransportHandle appTransport, Rm_PacketHandle pktHandle)
{
    sock_name_t *server_sock_name = (sock_name_t *)appTransport;
    Rm_Packet   *rm_pkt = (Rm_Packet *)pktHandle;
	int          coreNum = 0;
    
    if (sock_send(rmClientSocket, (char *)rm_pkt, (int) rm_pkt->pktLenBytes, server_sock_name)) {
        printf("core %d: send data failed\n", coreNum);
    }

    /* Wait for response from Server */
    transportReceive();
 
    return (0);
}

int connection_setup(void)
{
    Rm_TransportCfg rmTransCfg;
    int32_t         rm_result;
    int             i;
    sock_name_t     sock_name;
    char            server_sock_name[] = RM_SERVER_SOCKET_NAME;
	int             coreNum = 0;
    
    /* Initialize the transport map */
    for (i = 0; i < MAX_MAPPING_ENTRIES; i++) {
        rmTransportMap[i].transportHandle = NULL;
    }

    if (snprintf (rmClientSockName, MAX_CLIENT_SOCK_NAME, "/tmp/var/run/rm/rm_client%d", coreNum) >= MAX_CLIENT_SOCK_NAME)
    {
        printf("error: client socket name truncated\n");
        return -1;
    }
    sock_name.type = sock_name_e;
    sock_name.s.name = rmClientSockName;

    rmClientSocket = sock_open(&sock_name);
    if (!rmClientSocket) {
        printf("connection_setup: Client socket open failed\n");
        return (-1);
    }

    rmTransportMap[SERVER_TO_CLIENT_MAP_ENTRY].remote_sock = calloc(1, sizeof(sock_name_t));
    rmTransportMap[SERVER_TO_CLIENT_MAP_ENTRY].remote_sock->type = sock_name_e;    
    rmTransportMap[SERVER_TO_CLIENT_MAP_ENTRY].remote_sock->s.name = calloc(1, strlen(server_sock_name)+1);
    strncpy(rmTransportMap[SERVER_TO_CLIENT_MAP_ENTRY].remote_sock->s.name, server_sock_name, strlen(server_sock_name)+1);

    /* Register the Server with the Client instance */
    rmTransCfg.rmHandle = rmClientHandle;
    rmTransCfg.appTransportHandle = (Rm_AppTransportHandle) rmTransportMap[SERVER_TO_CLIENT_MAP_ENTRY].remote_sock;
    rmTransCfg.remoteInstType = Rm_instType_SERVER;
    rmTransCfg.transportCallouts.rmAllocPkt = transportAlloc;
    rmTransCfg.transportCallouts.rmSendPkt = transportSendRcv;
    rmTransportMap[SERVER_TO_CLIENT_MAP_ENTRY].transportHandle = Rm_transportRegister(&rmTransCfg, &rm_result);  

    return(0);
}

int setupRm (void)
{
    Rm_InitCfg         rmInitCfg;
    int32_t            result;
	int                coreNum = 0;
    
    /* Initialize the RM Client - RM must be initialized before anything else in the system */
    memset(&rmInitCfg, 0, sizeof(rmInitCfg));
    if (snprintf (rmClientName, RM_NAME_MAX_CHARS, "RM_Client%d", coreNum) >= RM_NAME_MAX_CHARS)
    {
        printf("client name truncated\n");
        return -1;
    }
    rmInitCfg.instName = rmClientName;
    rmInitCfg.instType = Rm_instType_CLIENT;
    rmClientHandle = Rm_init(&rmInitCfg, &result);
    RM_ERROR_CHECK(RM_OK, result, rmClientName, "Initialization failed");

    printf("\n\nInitialized %s\n\n", rmClientName);

    /* Open Client service handle */
    rmClientServiceHandle = Rm_serviceOpenHandle(rmClientHandle, &result);
    RM_ERROR_CHECK(RM_OK, result, rmClientName, "Service handle open failed");

    return(connection_setup());

}
#endif
#endif /* RM */

