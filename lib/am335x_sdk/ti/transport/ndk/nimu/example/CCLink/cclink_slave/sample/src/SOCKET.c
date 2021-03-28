/*
 * Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
 * Copyright (C) 2016 CC-Link Partner Association -http://am.cc-link.org/
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

#include "SOCKET.h"

#include <stdio.h>
#ifdef _WIN32
#include <stdint.h>
#include <winsock2.h>
#elif __linux__
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <errno.h>

#define SOCKET_ERROR	-1
#define SOCKET_NOT_OPEN	0
#define TRUE			1
#elif __TIRTOS__
#include <ti/ndk/inc/stkmain.h>
#include <ti/ndk/inc/netmain.h>
#include <ti/ndk/inc/socket.h>
#endif

/************************************************************************************/
/* This is an user defined function for initialization of the socket.		    */
/* The following is one of a sample in the TI RTOS. Please rewrite if necessary.    */
/************************************************************************************/
#ifdef __TIRTOS__
int socket_initialize( SOCKET *sock, uint32_t ulIpAddress, uint16_t usPortNumber)
{
	SOCKET		        sock_tmp;
	struct sockaddr_in	addr;
    int			addr_len = 0;
	int			opt_val = 0;
	int			opt_len = sizeof( int );
	int			iResult;
        int                     tmp;

	/* Create a socket */
	sock_tmp = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if ( sock_tmp == INVALID_SOCKET )
	{
        UART_printf("TEST FAILED: Socket create failed with error (%d)\n",fdError());
	    return SOCKET_ERR_SOCKET;
	}

	/* Setup the UDP socket */
	bzero( &addr, sizeof(struct sockaddr_in) );
        addr.sin_family = AF_INET;
	addr.sin_port	= NDK_htons(usPortNumber);		/* Port number */
	addr.sin_addr.s_addr = INADDR_ANY;  /* IP address */
	//addr.sin_addr.s_addr = NDK_htonl(ulIpAddress);	/* IP address */
	addr_len = sizeof( addr );

	iResult = bind( sock_tmp, (struct sockaddr *)&addr, (int)addr_len );
	if ( iResult   )
	{
        UART_printf("bind failed with error: %d\n",fdError());
	    return SOCKET_ERR_SOCKET;
	}

	/* Sets the socket option for broadcast packet. */
	opt_val = TRUE;

	iResult = setsockopt( sock_tmp, SOL_SOCKET, SO_BROADCAST, (void *) &opt_val, opt_len );
	if (iResult == SOCKET_ERROR)
	{
		UART_printf("ERR : setsockopt : SO_BROADCASTError: %d\n", fdError());
		return SOCKET_ERR_SOCKET;
	}

	/* Sets the socket option for broadcast packet. */
    opt_val = FALSE;

	/* for Non-blocking operation */
    iResult = setsockopt( sock_tmp, SOL_SOCKET, SO_BLOCKING, (void *) &opt_val, opt_len );
	if (iResult == SOCKET_ERROR)
	{
		UART_printf("ERR : setsockopt : SO_NONBLOCKINGError: %d\n", fdError());
		return SOCKET_ERR_SOCKET;
	}

    tmp = 65500;
    /* for Non-blocking operation */
    iResult = setsockopt( sock_tmp, SOL_SOCKET, SO_SNDBUF, &tmp, sizeof(int) );
	if (iResult == SOCKET_ERROR)
	{
		UART_printf("ERR : setsockopt : SO_SNDBUFError: %d\n", fdError());
		return SOCKET_ERR_SOCKET;
	}

    /* for Non-blocking operation */
    iResult = setsockopt( sock_tmp, SOL_SOCKET, SO_RCVBUF, &tmp, sizeof(int) );
	if (iResult == SOCKET_ERROR)
	{
		UART_printf("ERR : setsockopt : SO_RCVBUFError: %d\n", fdError());
		return SOCKET_ERR_SOCKET;
	}

	*sock = sock_tmp;

	return SOCKET_ERR_OK;
}
#else
#ifdef _WIN32 
int socket_initialize( SOCKET *sock, uint32_t ulIpAddress, uint16_t usPortNumber )
#elif __linux__
int socket_initialize( int *sock, uint32_t ulIpAddress, uint16_t usPortNumber )
#endif
{
#ifdef _WIN32
	SOCKET		sock_tmp;
	SOCKADDR_IN	addr;
	int			addr_len = 0;
	BOOL		opt_val = FALSE;
	int			opt_len = sizeof( BOOL );
#elif __linux__
	struct sockaddr_in	addr;
	int					sock_tmp;
	int					addr_len = 0;
	int					opt_val = 0;
	int					opt_len = sizeof( int );
#endif
	u_long		val = 0;
	int			iResult;

	/* Create a socket */
	sock_tmp = socket( AF_INET, SOCK_DGRAM, 0 );
#ifdef _WIN32
	if ( sock_tmp == INVALID_SOCKET )
#elif __linux__
	if ( sock_tmp < SOCKET_NOT_OPEN )
#endif
	{
#ifdef _WIN32
		printf( "socket failed with error: %ld\n", WSAGetLastError() );
#elif __linux__
		perror( "socket failed with error" );
#endif
		return SOCKET_ERR_SOCKET;
	}

	/* Setup the UDP socket */
	addr.sin_family = AF_INET;					/* Address Famiry : Internet */
	addr.sin_port	= NDK_htons(usPortNumber);		/* Port number */
#ifdef _WIN32 
	addr.sin_addr.s_addr = NDK_htonl(ulIpAddress);	/* IP address */
#elif __linux__
	addr.sin_addr.s_addr = INADDR_ANY;			/* It can be bound to all of the local interface */
#endif
	addr_len = sizeof( addr );

#ifdef _WIN32
	iResult = bind( sock_tmp, (SOCKADDR *)&addr, (int)addr_len );
#elif __linux__
	iResult = bind( sock_tmp, (struct sockaddr *)&addr, (unsigned int )addr_len );
#endif
	if ( iResult == SOCKET_ERROR )
	{
#ifdef _WIN32
		printf( "bind failed with error: %d\n", WSAGetLastError() );
		closesocket( sock_tmp );
#elif __linux__
		perror( "bind failed with error" );
		close( sock_tmp );
#endif
		return SOCKET_ERR_SOCKET;
	}

	/* Sets the socket option for broadcast packet. */
	opt_val = TRUE;

#ifdef _WIN32
	iResult = setsockopt( sock_tmp, SOL_SOCKET, SO_BROADCAST, (char *) &opt_val, opt_len );
#elif __linux__
	iResult = setsockopt( sock_tmp, SOL_SOCKET, SO_BROADCAST, (char *) &opt_val, (unsigned int )opt_len );
#endif
	if (iResult == SOCKET_ERROR)
	{
#ifdef _WIN32
		printf("ERR : setsockopt : SO_BROADCAST\n");
		closesocket( sock_tmp );
#elif __linux__
		perror( "ERR : setsockopt : SO_BROADCAST" );
		close( sock_tmp );
#endif
		return SOCKET_ERR_SOCKET;
	}

	/* for Non-blocking operation */
	val = 1;
#ifdef _WIN32
	ioctlsocket( sock_tmp, FIONBIO, &val );
#elif __linux__
	ioctl( sock_tmp, FIONBIO, &val );
#endif

	*sock = sock_tmp;

	return SOCKET_ERR_OK;
}
#endif
/************************************************************************************/
/* This is an user defined function for termination of the socket.					*/
/* The following is one of a sample in the Windows OS. Please rewrite if necessary.	*/
/* The following is one of a sample in the Linux. Please rewrite if necessary.		*/
/************************************************************************************/
#ifdef __TIRTOS__
void socket_terminate( SOCKET sock )
{
    /* Close a socket */
    return;
}
#else
#ifdef _WIN32
void socket_terminate( SOCKET sock )
#elif __linux__
void socket_terminate( int sock )
#endif
{
	/* Close a socket */
#ifdef _WIN32
	closesocket( sock );
#elif __linux__
	close( sock );
#endif

	return;
}
#endif

/************************************************************************************/
/* This is an user defined function for receiving packet. The following is one of a	*/
/* sample in the Windows OS. Please rewrite if necessary.							*/
/*The following is one of a	sample in the Linux. Please rewrite if necessary.		*/
/************************************************************************************/
#ifdef __TIRTOS__
int socket_recv( SOCKET sock, uint8_t *pucStream, int iLength, uint32_t *pulRecvAddr, uint16_t *pusRecvPortNumber )
{
    int             iErrCode = 0;
    int             iAddrSize = 0;
    int             i2ErrCode = 0;
    struct sockaddr_in      addrSender;
    int     ret_val = SOCKET_ERR_OK;

    iAddrSize = sizeof( addrSender );
    /* Packet receiving */
    iErrCode = recvfrom( sock, (void *)pucStream, iLength, 0, (struct sockaddr *)&addrSender, &iAddrSize);

    if( iErrCode == SOCKET_ERROR )
    {

        i2ErrCode = fdError();
        if ( i2ErrCode == NDK_EWOULDBLOCK )
        {
            ret_val = SOCKET_ERR_NO_RECEIVABLE;
        }
        else
        {
            UART_printf( "ERR : recvfrom failed with negative error: %ld\n", i2ErrCode );
            ret_val = SOCKET_ERR_RECV;
        }/* No received data */
    }
    else if ( iErrCode == 0 )
    {
        UART_printf( "ERR : recvfrom failed with error: disconnected: %d\n", fdError());
        ret_val = SOCKET_ERR_RECV;
    }

    (*pulRecvAddr) = NDK_ntohl(addrSender.sin_addr.s_addr);
    (*pusRecvPortNumber) = NDK_ntohs(addrSender.sin_port);

    if (ret_val == SOCKET_ERR_NO_RECEIVABLE)
        return SOCKET_ERR_NO_RECEIVABLE;
    else
        return ret_val;
}
#else
#ifdef _WIN32
int socket_recv( SOCKET sock, uint8_t *pucStream, int iLength, uint32_t *pulRecvAddr, uint16_t *pusRecvPortNumber )
#elif __linux__
int socket_recv( int sock, uint8_t *pucStream, int iLength, uint32_t *pulRecvAddr, uint16_t *pusRecvPortNumber )
#endif
{
	int				iErrCode = 0;
	int				iAddrSize = 0;
#ifdef _WIN32
	SOCKADDR_IN		addrSender;

	iAddrSize = sizeof( SOCKADDR_IN );
#elif __linux__
	struct sockaddr_in		addrSender;
	iAddrSize = sizeof( addrSender );
#endif

	/* Packet receiving */
#ifdef _WIN32
	iErrCode = recvfrom( sock, (char *)pucStream, iLength, 0, (SOCKADDR *)&addrSender, &iAddrSize );
#elif __linux__
	iErrCode = recvfrom( sock, (char *)pucStream, iLength, 0, (struct sockaddr *)&addrSender, &iAddrSize );
#endif

	if( iErrCode == SOCKET_ERROR )
	{
		/*No received data*/
#ifdef _WIN32
		errno = WSAGetLastError();
		if ( errno == WSAEWOULDBLOCK )
#elif __linux__
		if( errno == EAGAIN )
#endif
		{
			return SOCKET_ERR_NO_RECEIVABLE;
		}
		else
		{
#ifdef _WIN32
			printf( "ERR : recvfrom failed with error: %ld\n", errno );
#elif __linux__
			perror("recvfrom failed with error");
#endif
			return SOCKET_ERR_RECV;
		}
	}
	else if ( iErrCode == 0 )
	{
		printf( "ERR : recvfrom failed with error: disconnected\n" );
		return SOCKET_ERR_RECV;
	}

	(*pulRecvAddr) = ntohl(addrSender.sin_addr.s_addr);
	(*pusRecvPortNumber) = NDK_ntohs(addrSender.sin_port);

	return SOCKET_ERR_OK;
}
#endif
/************************************************************************************/
/* This is an user defined function for sending packet. The following is one of a	*/
/* sample in the Windows OS. Please rewrite if necessary.							*/
/* The following is one of a sample in the Linux. Please rewrite if necessary.		*/
/************************************************************************************/
#ifdef __TIRTOS__
int socket_send( SOCKET sock, uint8_t *pucStream, int iLength, uint32_t ulSendAddr, uint16_t usSendPortNumber )
{
	int				iErrCode = 0;
	int				iAddrSize = 0;
	struct sockaddr_in	        addrServer;

	addrServer.sin_family = AF_INET;				/* Address Famiry	: Internet */
	addrServer.sin_port	= NDK_htons(usSendPortNumber);	/* Port Number */
	addrServer.sin_addr.s_addr = NDK_htonl(ulSendAddr);
	iAddrSize = sizeof( addrServer );

	/* Packet Sending */
	iErrCode = sendto( sock, (void*)pucStream, iLength, 0, (struct sockaddr *)&addrServer, iAddrSize );

        if( iErrCode == SOCKET_ERROR )
	{
        UART_printf( "ERR : sendto failed with error: %d\n", fdError());
	    return SOCKET_ERR_SEND;
	}

	return SOCKET_ERR_OK;
}
#else
#ifdef _WIN32
int socket_send( SOCKET sock, uint8_t *pucStream, int iLength, uint32_t ulSendAddr, uint16_t usSendPortNumber )
#elif __linux__
int socket_send( int sock, uint8_t *pucStream, int iLength, uint32_t ulSendAddr, uint16_t usSendPortNumber )
#endif
{
	int				iErrCode = 0;
	int				iAddrSize = 0;
#ifdef _WIN32
	SOCKADDR_IN		addrServer;
#elif __linux__
	struct sockaddr_in	addrServer;
#endif

	addrServer.sin_family = AF_INET;				/* Address Famiry	: Internet */
	addrServer.sin_port	= NDK_htons(usSendPortNumber);	/* Port Number */
	addrServer.sin_addr.s_addr = NDK_htonl(ulSendAddr);
	iAddrSize = sizeof( addrServer );

	/* Packet Sending */
#ifdef _WIN32
	iErrCode = sendto( sock, (char *)pucStream, iLength, 0, (LPSOCKADDR)&addrServer, iAddrSize );
#elif __linux__
	iErrCode = sendto( sock, (char *)pucStream, iLength, 0, (struct sockaddr *)&addrServer, iAddrSize );
#endif
	if( iErrCode == SOCKET_ERROR )
	{
#ifdef _WIN32
		printf( "sendto failed with error: %ld\n", WSAGetLastError() );
#elif __linux__
		perror("send to failed with error");
#endif
		return SOCKET_ERR_SEND;
	}

	return SOCKET_ERR_OK;
}
#endif
