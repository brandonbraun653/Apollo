/*
 * Copyright (C) 2017 - 2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include "SLMP.h"
#include "CCIEF_BASIC_MASTER.h"
#include "USER_SAMPLE.h"
#include "TIMER.h"

#include <stdio.h>
#ifdef __TIRTOS__
#include <ti/ndk/inc/stkmain.h>
#include <ti/ndk/inc/netmain.h>
#include <ti/ndk/inc/socket.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/drv/uart/soc/UART_soc.h>
#include <ti/drv/uart/src/UART_utils_defs.h>
#include <ti/drv/uart/test/src/UART_board.h>
#include <ti/drv/emac/emac_drv.h>

/*[ Definition for sample program ]*/
#define	MAX_INTERFACE						20
#define	MAX_PATH							260
#define	SOCKET_NOT_OPEN						0

#elif _WIN32
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <iphlpapi.h>
#include <conio.h>
#elif __linux__
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/route.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

/*[ Definition for sample program ]*/
#define	MAX_INTERFACE						20
#define	MAX_PATH							260
#define	SOCKET_NOT_OPEN						0
#define	DIR_PROC_ROUTE						"/proc/net/route"

/*[ Structure of sample program ]*/
typedef struct
{
	char				IPAddr[INET_ADDRSTRLEN];
	char				IPMask[INET_ADDRSTRLEN];
	char				MACAddr[18];
	char				Defo[1028];
	struct ifreq		USER_ifreq;
} USER_NETWORK_INFO;

typedef struct 
{
	char 				cIface[IF_NAMESIZE];
	struct in_addr		cDst;
	struct in_addr		cGateway;
	unsigned short int	iFlag;
	int					iRecCnt;
	int					iUse;
	short int			iMetric;
	struct in_addr		cMask;
	unsigned long int	iMTU;
	unsigned long int	iWindow;
	unsigned short int	iIRTT;
} t_RouteInfo;
#endif

typedef struct 
{
	uint8_t		aucMacAddress[6];			/* MAC Address */
	uint32_t	ulIpAddress;				/* IP Address */
	uint32_t	ulSubnetMask;				/* Subnet Mask */
	uint32_t	ulDefaultGatewayIPAddress;	/* Default Gateway IP Address */
} USER_ADAPTER_INFO;

/* Definition of external variable of sample program */
static CCIEF_BASIC_MASTER_PARAMETER	UserMasterParameter;
static USER_ADAPTER_INFO			AdapterInfo;
static char							acMasterParameterFile[MAX_PATH] = "";

/* Definition of function of sample program */
static void user_callback_cyclic_link_scan_end( uint8_t ucGroupNumber );
static int user_parameter_file_read( char *file_path, CCIEF_BASIC_MASTER_PARAMETER *pParameter );
#ifndef __TIRTOS__
static void user_get_input_line( char *pcLine, int iLineLength );
#endif
static void user_show_menu_top( void );
static int user_input_check( void );
static void user_start_application( void );
static void user_stop_application( void );
static void user_start_cyclic( void );
static void user_stop_cyclic( void );
static void user_show_slave_info( void );
static void user_show_master_info( void );
static void user_show_parameter( void );
static int user_get_adapter_info( USER_ADAPTER_INFO *pGetAdapterInfo );

#ifdef __TIRTOS__
extern char *LocalIPAddr;
extern char *LocalIPMask;
extern char *GatewayIP;
extern char *DomainName;
char *SlaveIPAddr1 = "192.168.3.4";
char *SlaveIPAddr2 = "192.168.3.20";
char *SlaveIPAddr3 = "192.168.3.30";
extern uint8_t lclMac[6];
char userInputChar;
uint32_t display_slave_connection_status;

/************************************************************************************/
/************************************************************************************/
/* This is an user defined function for converting a string to IPV4 network address */
/************************************************************************************/
int inet_pton(int af, const char *src, void *dst)
{
    inet_aton(src, dst);
    return 1;
}

/************************************************************************************/
/************************************************************************************/
/* This is an user defined function for converting IPV4 address to a string         */
/************************************************************************************/
const char *inet_ntop(int af, const void *src, char *dst, int cnt)
{
    NtIPN2Str(*((uint32_t *)src), dst);
    return (dst);
}
#endif

/************************************************************************************/
/* This is an user defined function for main function.								*/
/* The following is one of a sample in the Windows OS. Please rewrite if necessary.	*/
/* The following is one of a sample in the Linux. Please rewrite if necessary.		*/
/************************************************************************************/
#ifdef __TIRTOS__
void cclink_thread (UArg a0, UArg a1)
#else
void main( int argc, char *argv[] )
#endif
{
	int iErrCode = 0;
#ifdef __TIRTOS__
	// Allocate the file environment for this task
	fdOpenSession( TaskSelf() );
        UART_Params      uartParams;
        UART_HwAttrs     uart_cfg;

        UART_stdioDeInit();
        /* Get the default UART init configurations */
        UART_socGetInitCfg(UART_INSTANCE, &uart_cfg);

        uart_cfg.edmaHandle = NULL;
        uart_cfg.dmaMode    = FALSE;
        uart_cfg.loopback   = FALSE;

        /* Set the DMA enabled UART init configurations */
        UART_socSetInitCfg(UART_INSTANCE, &uart_cfg);

        /* Initialize the default configuration params. */
        UART_Params_init(&uartParams);

        /* timeout is 0 for both read and write */
        uartParams.readTimeout  = UART_NO_WAIT;

        UART_stdioInit2(UART_INSTANCE, &uartParams);
#elif _WIN32
	WSADATA wsaData;
#elif __linux__
#endif

#ifdef _WIN32
	int iResult;

	/* Initialize Winsock */
	iResult = WSAStartup( MAKEWORD(2,2), &wsaData );
	if ( iResult != 0 )
	{
		#ifdef __TIRTOS__
                UART_printf( "WSAStartup failed with error: %d\n", iResult );
                #else
                printf( "WSAStartup failed with error: %d\n", iResult );
                #endif
		goto end;
	}
#elif __linux__
#endif

	/* Get the Network adapter information */
	iErrCode = user_get_adapter_info( &AdapterInfo );
	if ( iErrCode != USER_ERR_OK )
	{
		goto end;
	}

#ifdef __TIRTOS__
#else
	/* Get command line argument */
	if ( 1 < argc )
	{
#ifdef _WIN32
		strncpy_s( acMasterParameterFile, sizeof(acMasterParameterFile), argv[1], sizeof( acMasterParameterFile ) );
#elif __linux__
		strncpy( acMasterParameterFile, argv[1], sizeof( acMasterParameterFile ) );
#endif
	}
	else
	{
		#ifdef __TIRTOS__
                UART_printf( "Please input the master parameter file:\n> " );
                #else
                printf( "Please input the master parameter file:\n> " );
                #endif
		user_get_input_line( acMasterParameterFile, sizeof( acMasterParameterFile ) );
	}
#endif
	/* Read the parameter file */
	iErrCode = user_parameter_file_read( acMasterParameterFile, &UserMasterParameter );
	if ( iErrCode != USER_ERR_OK )
	{
		goto end;
	}
#ifdef __TIRTOS__
	Task_sleep(10000);
        /*emac_poll(0, &link_info);
        while (link_info.link_status == EMAC_LINKSTATUS_NOLINK)
        {
            Task_sleep(1000);
            emac_poll(0, &link_info);
        }*/
#endif
	/* Show parameter of the CCIEF-BASIC Master */
	#ifdef __TIRTOS__
	UART_printf( "\nStart CC-Link IE Field Basic Master Station!\n" );
	#else
	printf( "\nStart CC-Link IE Field Basic Master Station!\n" );
	#endif
	user_show_parameter();

	/****************************************************************************/
	/* Initialization of the Timer.												*/
	/****************************************************************************/
	/* Initialization the timer environment */
	timer_initialize();

	/****************************************************************************/
	/* Initialization of the CCIEF-BASIC Master.								*/
	/****************************************************************************/
	/* Initialization of the CCIEF-BASIC Master */
	iErrCode = ccief_basic_master_initialize( AdapterInfo.ulIpAddress, AdapterInfo.ulSubnetMask, &UserMasterParameter,
											user_callback_cyclic_link_scan_end );
	if ( iErrCode != CCIEF_BASIC_MASTER_ERR_OK )
	{
		#ifdef __TIRTOS__
		UART_printf( "\nCCIEF-BASIC Master Station initialization error!\n" );
		#else
		printf( "\nCCIEF-BASIC Master Station initialization error!\n" );
		#endif
		goto end;
	}

	/* Start cyclic operation */
	user_start_cyclic();

	/* Start application */
	user_start_application();

	/* Showing the menu */
	user_show_menu_top();

	/****************************************************************************/
	/* Main loop of sample code.												*/
	/****************************************************************************/
	while (1)
	{
		/* CCIEF-BASIC Master */
		iErrCode = ccief_basic_master_main();
		if ( iErrCode == CCIEF_BASIC_MASTER_ERR_MASTER_DUPLICATION )
		{
			#ifdef __TIRTOS__
                        UART_printf( "\nMaster duplication! Please check the parameter.\n" );
                        UART_printf( "\r\n Some tests have failed. \r\n" );
                        #else
                        printf( "\nMaster duplication! Please check the parameter.\n" );
                        printf( "\r\n Some tests have failed. \r\n" );
                        #endif
                        break;
		}
		if ( iErrCode == CCIEF_BASIC_MASTER_ERR_SLAVE_DUPLICATION )
		{
			#ifdef __TIRTOS__
                        UART_printf( "\nSlave duplication! Please check the slave parameter.\n" );
                        UART_printf( "\r\n Some tests have failed. \r\n" );
                        #else
                        printf( "\nSlave duplication! Please check the slave parameter.\n" );
                        printf( "\r\n Some tests have failed. \r\n" );
                        #endif
			break;
		}

		/* Timer */
		timer_main();

		/* Check key input */
		iErrCode = user_input_check();
		if ( iErrCode == USER_EXIT )
		{
			#ifdef __TIRTOS__
			UART_printf( "\r\n All tests have passed. \r\n" );
			#else
			printf( "\r\n All tests have passed. \r\n" );
			#endif
                        break;
		}
	}

	/* Termination of CCIEF-BASIC Master */
	ccief_basic_master_terminate();

	/* Termination of the timer environment */
	timer_terminate();

	/* Exit the application */
end:
#ifdef __TIRTOS__ 
#elif _WIN32
	/* WinSock clean up */
	WSACleanup();
#elif __linux__
#endif

#ifdef __TIRTOS__ 
	/* Close the session & kill the task */
	fdCloseSession( TaskSelf() );
	TaskExit();
#elif _WIN32
        printf( "\nApplication has exited.(please any press)\n" );
        _getch();
#elif __linux__
	printf( "\nApplication has exited.(please any press)\n" );
        getchar();
#endif
	return;
}

/************************************************************************************/
/* This is an user defined function for callback function for cyclic link scan end. */
/************************************************************************************/
static uint16_t ausSendData[CCIEF_BASIC_MAX_SLAVE_NUMBER] = { 0 };
void user_callback_cyclic_link_scan_end( uint8_t ucGroupNumber )
{
	CCIEF_BASIC_GROUP_INFO MasterInfo;
	uint16_t *pusRWw, *pusRY,usSendData_RY,usSendData_RWw;
	int	i, j, iOccupiedStationNumberTotal;

	/* Please write here the operating of cyclic link scan end. */

	/* Getting the master group information */
	ccief_basic_master_get_group_info( ucGroupNumber, &MasterInfo );

	/*[ Example: Sending the increment data to the slaves. ]*/
	/*----<Sendig data details>-----------------*/
	/* | 0b to  3b| Increment from 0x0 to 0xF   */
	/* | 4b to  7b| RY(0x5) or RWw(0xA)         */
	/* | 8b to 11b| Slave No.                   */
	/* |12b to 15b| Group No.                   */
	/*------------------------------------------*/
	iOccupiedStationNumberTotal = 0;
	for ( i = 0; i < UserMasterParameter.iTotalSlaveNumber; i ++ )
	{
		/* Check the group number */
		if ( UserMasterParameter.Slave[i].ucGroupNumber == ucGroupNumber )
		{
			usSendData_RY = 0;
			usSendData_RWw = 0;
			/* Check the unit information */
			if (( MasterInfo.usUnitInfo & CCIEF_BASIC_UNIT_INFO_APPLICATION_RUNNING ) == CCIEF_BASIC_UNIT_INFO_APPLICATION_RUNNING )
			{
				/* Starting the application */
				/* Increase the sending data */
				if ( ausSendData[i] >= 0x000F )
				{
					ausSendData[i] = 0;
				}
				else
				{
					ausSendData[i] ++;
				}
				usSendData_RY = ausSendData[i];
				usSendData_RWw = ausSendData[i];
				usSendData_RY |= ((uint16_t)ucGroupNumber << 12) | 0x0050 | ((uint16_t)(i+1) << 8);
				usSendData_RWw |= ((uint16_t)ucGroupNumber << 12) | 0x00A0 | ((uint16_t)(i+1) << 8);
			}
			else
			{
				/* Stopping the application */
				/* Clear the sending data */
				ausSendData[i] = 0;
			}

			/* Getting the start pointer of RY */
			pusRY = ccief_basic_master_get_pointer( CCIEF_BASIC_DEVICE_TYPE_RY )
				  + ( iOccupiedStationNumberTotal * ( CCIEF_BASIC_RX_RY_SIZE / sizeof( uint16_t )));
			/* Getting the start pointer of RWw */
			pusRWw = ccief_basic_master_get_pointer( CCIEF_BASIC_DEVICE_TYPE_RWW )
				   + ( iOccupiedStationNumberTotal * ( CCIEF_BASIC_RWW_RWR_SIZE / sizeof( uint16_t )));

			/* Setting the sending RY data */
			for ( j = 0; j < (int)( UserMasterParameter.Slave[i].usOccupiedStationNumber * ( CCIEF_BASIC_RX_RY_SIZE / sizeof( uint16_t ))); j ++ )
			{
				*pusRY = usSendData_RY;
				pusRY ++;
			}
			/* Setting the sending RWw data */
			for ( j = 0; j < (int)( UserMasterParameter.Slave[i].usOccupiedStationNumber * ( CCIEF_BASIC_RWW_RWR_SIZE / sizeof( uint16_t ))); j ++ )
			{
				*pusRWw = usSendData_RWw;
				pusRWw ++;
			}
		}
		iOccupiedStationNumberTotal += UserMasterParameter.Slave[i].usOccupiedStationNumber;
	}
	
	return;
}

/************************************************************************************/
/* This is an user defined function for parse of the parameter. (csv format)		*/
/************************************************************************************/
int user_parameter_file_read( char *file_path, CCIEF_BASIC_MASTER_PARAMETER *pParameter )
{
#ifdef __TIRTOS__
        struct in_addr      addr;        
        int                 iIndex, iResult;
        memset( pParameter, 0, sizeof( CCIEF_BASIC_MASTER_PARAMETER ) );
       	
        iIndex = 0;
        pParameter->iTotalGroupNumber = 1;
	pParameter->Group[iIndex / 4].ucGroupNumber = (uint8_t)1;
        pParameter->Group[iIndex / 4].usCyclicTransmissionTimeout = (uint16_t)500;
	pParameter->Group[iIndex / 4].usCyclicTransmissionTimeoutCount = (uint16_t)3;
	pParameter->Group[iIndex / 4].usConstantLinkScanTime = (uint16_t)0;

#ifdef CONFORMANCE_TEST
        pParameter->iTotalSlaveNumber = 3;
        iResult = inet_aton(SlaveIPAddr1, &addr);
        if ( iResult == 1)
        {
                pParameter->Slave[iIndex / 3].ulIpAddress = NDK_htonl(addr.s_addr);
        }
        else
        {
                #ifdef __TIRTOS__
                UART_printf("IP address error.\n");
                #else
                printf("IP address error.\n");
                #endif
                return USER_ERR_NG;
        }
	pParameter->Slave[iIndex / 3].usOccupiedStationNumber = (uint16_t)1;
	pParameter->Slave[iIndex / 3].ucGroupNumber = (uint8_t)1;

        iIndex = iIndex + 3;
        iResult = inet_aton(SlaveIPAddr2, &addr);
        if ( iResult == 1)
        {
                pParameter->Slave[iIndex / 3].ulIpAddress = NDK_htonl(addr.s_addr);
        }
        else
        {
                #ifdef __TIRTOS__
                UART_printf("IP address error.\n");
                #else
                printf("IP address error.\n");
                #endif
                return USER_ERR_NG;
        }
	pParameter->Slave[iIndex / 3].usOccupiedStationNumber = (uint16_t)1;
	pParameter->Slave[iIndex / 3].ucGroupNumber = (uint8_t)1;

        iIndex = iIndex + 3;
        iResult = inet_aton(SlaveIPAddr3, &addr);
        if ( iResult == 1)
        {
                pParameter->Slave[iIndex / 3].ulIpAddress = NDK_htonl(addr.s_addr);
        }
        else
        {
                #ifdef __TIRTOS__
                UART_printf("IP address error.\n");
                #else
                printf("IP address error.\n");
                #endif
                return USER_ERR_NG;
        }
	pParameter->Slave[iIndex / 3].usOccupiedStationNumber = (uint16_t)4;
	pParameter->Slave[iIndex / 3].ucGroupNumber = (uint8_t)1;
#else
        pParameter->iTotalSlaveNumber = 1;
        iResult = inet_aton(SlaveIPAddr1, &addr);
        if ( iResult == 1)
        {
                pParameter->Slave[iIndex / 3].ulIpAddress = NDK_htonl(addr.s_addr);
        }
        else
        {
                #ifdef __TIRTOS__
                UART_printf("IP address error.\n");
                #else
                printf("IP address error.\n");
                #endif
                return USER_ERR_NG;
        }
	pParameter->Slave[iIndex / 3].usOccupiedStationNumber = (uint16_t)1;
	pParameter->Slave[iIndex / 3].ucGroupNumber = (uint8_t)1;
#endif

#else
	FILE *fp;
#ifdef _WIN32
	errno_t error;
#elif __linux__
#endif
	static char aucLine[32];
	static char aucId[32];
	static char aucData[32];
	uint32_t ulIpaddr;
	int iId, iIndex, iResult;

#ifdef _WIN32
	error = fopen_s(&fp, file_path, "r" );
	if ( error != 0 )
#elif __linux__
	fp = fopen( file_path, "r" );
	if ( fp == NULL )
#endif
	{
		#ifdef __TIRTOS__
                UART_printf( "Could not open file \"%s\"\n", file_path );
                #else
                printf( "Could not open file \"%s\"\n", file_path );
                #endif
                                return USER_ERR_NG;
	}

	memset( pParameter, 0, sizeof( CCIEF_BASIC_MASTER_PARAMETER ) );

	/* Start analyze the parameter file */
	while ( fgets( aucLine, sizeof(aucLine), fp ) != NULL )
	{
#ifdef _WIN32
		sscanf_s( aucLine, "%[^,],%[^,]", aucId, sizeof(aucId), aucData, sizeof(aucData) );
#elif __linux__
		sscanf( aucLine, "%[^,],%[^,]", aucId, aucData );
#endif
		if ( memcmp( aucId, "Group", 5 ) == 0 )
		{
			break;
		}
	}

	/* Getting the parameter of "Group"  */
	while ( fgets( aucLine, sizeof( aucLine ), fp ) != NULL )
	{
		memset( aucId, 0, sizeof( aucId ) );
		memset( aucData, 0, sizeof( aucData ) );
#ifdef _WIN32
		sscanf_s( aucLine, "%[^,],%[^,]", aucId, sizeof(aucId), aucData, sizeof(aucData) );
#elif __linux__
		sscanf( aucLine, "%[^,],%[^,]", aucId, aucData );
#endif
		if ( memcmp( aucId, "Slave", 5 ) == 0 )
		{
			break;
		}
		iId = strtol( aucId, NULL, 0 );
		switch ( iId )
		{
			case USER_PARAMETER_GROUP_ID_TOTAL_NUMBER:
				pParameter->iTotalGroupNumber = strtoul( aucData, NULL, 0 );

			/* Please write user parameters here. */

			default:
				iIndex = iId - USER_PARAMETER_GROUP_ID_GROUP_NUMBER;
				if (( 0 <= iIndex ) && ( iIndex < CCIEF_BASIC_MAX_GROUP_NUMBER * 4 ) )
				{
					if (( iIndex % 4 ) == 0)
					{
						pParameter->Group[iIndex / 4].ucGroupNumber = (uint8_t)strtoul( aucData, NULL, 0 );
					}
					else if (( iIndex % 4 ) == 1)
					{
						pParameter->Group[iIndex / 4].usCyclicTransmissionTimeout = (uint16_t)strtoul( aucData, NULL, 0 );
					}
					else if (( iIndex % 4 ) == 2)
					{
						pParameter->Group[iIndex / 4].usCyclicTransmissionTimeoutCount = (uint16_t)strtoul( aucData, NULL, 0 );
					}
					else if (( iIndex % 4 ) == 3)
					{
						pParameter->Group[iIndex / 4].usConstantLinkScanTime = (uint16_t)strtoul( aucData, NULL, 0 );
					}
				}
				break;
		}
	}

	/* Getting the parameter of "Slave" */
	while ( fgets( aucLine, sizeof( aucLine ), fp ) != NULL )
	{
		memset( aucId, 0, sizeof( aucId ) );
		memset( aucData, 0, sizeof( aucData ) );
#ifdef _WIN32
		sscanf_s( aucLine, "%[^,],%[^,]", aucId, sizeof(aucId), aucData, sizeof(aucData) );
#elif __linux__
		sscanf( aucLine, "%[^,],%[^,]", aucId, aucData );
#endif
		iId = strtol( aucId, NULL, 0 );
		switch ( iId )
		{
			case USER_PARAMETER_SLAVE_ID_TOTAL_NUMBER:
				pParameter->iTotalSlaveNumber = strtoul( aucData, NULL, 0 );
				break;

			/* Please write user parameters here. */

			default:
				iIndex = iId - USER_PARAMETER_SLAVE_ID_IP_ADDRESS;
				if (( 0 <= iIndex ) && ( iIndex < CCIEF_BASIC_MAX_SLAVE_NUMBER * 3 ) )
				{
					if (( iIndex % 3 ) == 0)
					{
						iResult=inet_pton( AF_INET, aucData, &ulIpaddr );
						if ( iResult == 1)
						{
							pParameter->Slave[iIndex / 3].ulIpAddress = htonl(ulIpaddr);
						}
						else
						{
							#ifdef __TIRTOS__
							UART_printf("IP address error.\n");
							#else
							printf("IP address error.\n");
							#endif
							return USER_ERR_NG;
						}
					}
					else if (( iIndex % 3 ) == 1)
					{
						pParameter->Slave[iIndex / 3].usOccupiedStationNumber = (uint16_t)strtoul( aucData, NULL, 0 );
					}
					else if (( iIndex % 3 ) == 2)
					{
						pParameter->Slave[iIndex / 3].ucGroupNumber = (uint8_t)strtoul( aucData, NULL, 0 );
					}
				}
				break;
		}
	}

	fclose( fp );
#endif
	return USER_ERR_OK;
}

/************************************************************************************/
/* This is an user defined function for getting input line while 'ENTER' key.		*/
/************************************************************************************/
#ifndef __TIRTOS__
void user_get_input_line( char *pcLine, int iLineLength )
{
#ifdef __TIRTOS__
	char input_line[256];

	UART_gets(input_line,sizeof(input_line));
	input_line[strlen(input_line)-1]='\0';
	strcpy(pcLine,input_line);
#elif _WIN32
	int	iKey;
	int	iIndex = 0;

	/* Set 'NULL' */
	memset( pcLine, 0, iLineLength );

	while ( iIndex <= iLineLength )
	{
		iKey = _getch();
		if ( iKey == 0x08 )
		{	/* 'BackSpace' */
			if ( 0 < iIndex )
			{
				_putch( iKey );
				*( pcLine + iIndex ) = 0x00;
				iIndex --;
				if ( iIndex < 0 )
				{
					iIndex = 0;
				}
			}
		}
		else if ( iKey == 0x0d )
		{	/* 'Enter' */
			printf( "\n" );
			break;
		}
		else
		{
			_putch( iKey );
			*( pcLine + iIndex ) = (char)iKey;
			iIndex ++;
		}
	}
#elif __linux__
	char input_line[256];

	fgets(input_line,sizeof(input_line),stdin);
	input_line[strlen(input_line)-1]='\0';
	strcpy(pcLine,input_line);
#endif
	return;
}
#endif

/************************************************************************************/
/* This is an user defined function for show "Top Menu".							*/
/************************************************************************************/
void user_show_menu_top( void )
{
	/* Showing the menu */
	#ifdef __TIRTOS__
        UART_printf( "\nPlease input the following key values if you want any action.\n\n" );
        UART_printf( "    '1'   - Start the cyclic.\n" );
        UART_printf( "    '2'   - Stop the cyclic.\n" );
        UART_printf( "    '3'   - Start the application.\n" );
        UART_printf( "    '4'   - Stop the application.\n" );
        UART_printf( "    '5'   - Show information of the slave.\n" );
        UART_printf( "    '6'   - Show information of the master.\n" );
        UART_printf( "    '7'   - Show the parameter.\n" );
        UART_printf( "    '8'   - Show the disconnected slave status.\n" );
        UART_printf( "    'Esc' - Exit the application.\n" );
        #else
        printf( "\nPlease input the following key values if you want any action.\n\n" );
        printf( "    '1'   - Start the cyclic.\n" );
        printf( "    '2'   - Stop the cyclic.\n" );
        printf( "    '3'   - Start the application.\n" );
        printf( "    '4'   - Stop the application.\n" );
        printf( "    '5'   - Show information of the slave.\n" );
        printf( "    '6'   - Show information of the master.\n" );
        printf( "    '7'   - Show the parameter.\n" );
        printf( "    'Esc' - Exit the application.\n" );
        #endif

	return;
}

/************************************************************************************/
/* This is an user defined function for check key input.							*/
/************************************************************************************/
int user_input_check( void )
{
#ifdef   __TIRTOS__
	static int iExit = USER_ERR_OK;
	{
            if(display_slave_connection_status == 2)
            {
                display_slave_connection_status = 0;
                user_show_menu_top();
            }
#elif _WIN32
	int	iKey;
	static int iExit = USER_ERR_OK;

	/* Chcek key input */
	if ( _kbhit() )
	{
		iKey = _getch();
#elif __linux__
	struct termios		oldt;
	struct termios		newt;
	int					ch;
	int					oldf;
	static int iExit = USER_ERR_OK;

	/* Get the now of setting */
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(unsigned int)(ICANON | ECHO);
	/* Stop of the echo */
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	/* Return to the initial setting */
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF) 
	{
		ungetc(ch, stdin);
#endif
		if ( iExit == USER_ERR_OK )
		{
#ifdef  __TIRTOS__
			switch ( (char)UART_getc() )
#elif _WIN32
			switch ( iKey )
#elif __linux__
			switch ( getchar() )
#endif

#ifdef  __TIRTOS__
			{
				case '1':	/* Start cyclic of the slave */
					user_start_cyclic();
                                        user_show_menu_top();
					break;
				case '2':	/* Stop cyclic of the slave */
					user_stop_cyclic();
                                        user_show_menu_top();
					break;
				case '3':	/* Start the application */
					user_start_application();
                                        user_show_menu_top();
					break;
				case '4':	/* Stop the application */
					user_stop_application();
                                        user_show_menu_top();
					break;
				case '5':	/* Show information of the slave */
					user_show_slave_info();
                                        user_show_menu_top();
					break;
				case '6':	/* Show information of the master */
					user_show_master_info();
                                        user_show_menu_top();
					break;
				case '7':	/* Show the parameter */
					user_show_parameter();
                                        user_show_menu_top();
					break;
                                case '8':	/* Show the parameter */
					UART_printf( "\nDisplaying the status of disconnected slave\n" );
                                        display_slave_connection_status = 1;
					break;
				case 0x1b:	/* 'Esc' */
					UART_printf( "\nExit the application? (if you want exit, please press 'Y')\n" );
					iExit = USER_EXIT;
					return USER_EXIT;
				default:	/* Check selecting */
                                        break;
			}
#else
			{
				case '1':	/* Start cyclic of the slave */
					user_start_cyclic();
					break;
				case '2':	/* Stop cyclic of the slave */
					user_stop_cyclic();
					break;
				case '3':	/* Start the application */
					user_start_application();
					break;
				case '4':	/* Stop the application */
					user_stop_application();
					break;
				case '5':	/* Show information of the slave */
					user_show_slave_info();
					break;
				case '6':	/* Show information of the master */
					user_show_master_info();
					break;
				case '7':	/* Show the parameter */
					user_show_parameter();
					break;
				case 0x1b:	/* 'Esc' */
					printf( "\nExit the application? (if you want exit, please press 'Y')\n" );
					iExit = USER_EXIT;
					return USER_ERR_OK;
				default:	/* Check selecting */
					break;
			}
			user_show_menu_top();
#endif
		}
		else
		{
#ifdef __TIRTOS__
			switch ( (char)UART_getc() )
#elif _WIN32
			switch ( iKey )
#elif __linux__
			switch ( ch )
#endif
			{
				case 'Y':	/* Exit the application */
#ifdef __TIRTOS__
#elif _WIN32
#elif __linux__
					getchar();
#endif
					return USER_EXIT;
				default:			/* Check selecting */
					iExit = USER_ERR_OK;
					user_show_menu_top();
					break;
			}
		}
	}

	return USER_ERR_OK;
}

/************************************************************************************/
/* This is an user defined function for menu of starting the application.			*/
/************************************************************************************/
void user_start_application( void )
{
	#ifdef __TIRTOS__
        UART_printf( "\nStart the application!\n" );
        #else
        printf( "\nStart the application!\n" );
        #endif

	/* Set the unit information */
	ccief_basic_master_set_unit_info( CCIEF_BASIC_UNIT_INFO_APPLICATION_RUNNING );

	return;
}

/************************************************************************************/
/* This is an user defined function for menu of stopping the application.			*/
/************************************************************************************/
void user_stop_application( void )
{
	#ifdef __TIRTOS__
        UART_printf( "\nStop the application!\n" );
        #else
        printf( "\nStop the application!\n" );
        #endif

	/* Set the unit information */
	ccief_basic_master_set_unit_info( CCIEF_BASIC_UNIT_INFO_APPLICATION_STOP );

	return;
}

/************************************************************************************/
/* This is an user defined function for menu of starting the cyclic of the slave.	*/
/************************************************************************************/
void user_start_cyclic( void )
{
	int i;
        #ifdef __TIRTOS__
        UART_printf( "\nStart cyclic of all the slaves!\n" );
        #else
        printf( "\nStart cyclic of all the slaves!\n" );
        #endif
	/* Start cyclic all of the slaves */
	for ( i = 0; i < UserMasterParameter.iTotalSlaveNumber; i ++ )
	{
		(void)ccief_basic_master_start_cyclic( i );
	}

	return;
}

/************************************************************************************/
/* This is an user defined function for stopping the cyclic of the slave.			*/
/************************************************************************************/
void user_stop_cyclic( void )
{
	int i;

	#ifdef __TIRTOS__
        UART_printf( "\nStop cyclic of all the slaves!\n" );
        #else
        printf( "\nStop cyclic of all the slaves!\n" );
        #endif

	/* Stop cyclic all of the slaves */
	for ( i = 0; i < UserMasterParameter.iTotalSlaveNumber; i ++ )
	{
		(void)ccief_basic_master_stop_cyclic( i );
	}

	return;
}

/************************************************************************************/
/* This is an user defined function for showing information of the slave.			*/
/************************************************************************************/
static char aucSlaveStateStr[][12] = { "INITAL", "DISCONNECT", "CONNECTING", "CYCLIC_STOP", "CYCLIC_END", "CYCLIC" };
void user_show_slave_info( void )
{
	CCIEF_BASIC_MASTER_PARAMETER *pParameter;
	CCIEF_BASIC_SLAVE_INFO SlaveInfo;
	uint16_t *pusRX, *pusRY, *pusRWw, *pusRWr;
	uint16_t *pusData;
	uint16_t usOccupiedStationNumber;
	int iDataIndex, iDataSize;
	int i, j, k, iStationNumber;

	pParameter = &UserMasterParameter;
	/* Getting the start pointer of RX */
	pusRX = ccief_basic_master_get_pointer( CCIEF_BASIC_DEVICE_TYPE_RX );
	/* Getting the start pointer of RY */
	pusRY = ccief_basic_master_get_pointer( CCIEF_BASIC_DEVICE_TYPE_RY );
	/* Getting the start pointer of RWw */
	pusRWw = ccief_basic_master_get_pointer( CCIEF_BASIC_DEVICE_TYPE_RWW );
	/* Getting the start pointer of RWr */
	pusRWr = ccief_basic_master_get_pointer( CCIEF_BASIC_DEVICE_TYPE_RWR );

	#ifdef __TIRTOS__
        UART_printf( "\nShow the state of all the slaves!\n" );
        #else
        printf( "\nShow the state of all the slaves!\n" );
        #endif

	/* Showing the cyclic data */
	iStationNumber = 0;
	for ( i = 0; i < pParameter->iTotalSlaveNumber; i ++ )
	{
		/* Getting the slave state */
		ccief_basic_master_get_slave_info( i, &SlaveInfo );
		usOccupiedStationNumber = pParameter->Slave[i].usOccupiedStationNumber;
		#ifdef __TIRTOS__
                UART_printf( "\n    Slave No.%d:\n", i + 1 );
                UART_printf( "      Slave ID:\t\t\t0x%08X\n", SlaveInfo.ulId );
                UART_printf( "      Occupied Station Number:\t%d\n", SlaveInfo.usOccupiedStationNumber );
                #else
                printf( "\n    Slave No.%d:\n", i + 1 );
                printf( "      Slave ID:\t\t\t0x%08lX\n", SlaveInfo.ulId );
                printf( "      Occupied Station Number:\t%d\n", SlaveInfo.usOccupiedStationNumber );
                #endif
		if ( SlaveInfo.ucGroupNumber != 0 )
		{
			#ifdef __TIRTOS__
                        UART_printf( "      Group No.:\t\t%d\n", SlaveInfo.ucGroupNumber );
                        #else
                        printf( "      Group No.:\t\t%d\n", SlaveInfo.ucGroupNumber );
                        #endif
		}
		#ifdef __TIRTOS__
                UART_printf( "      State:\t\t\t%d [%s]\n", SlaveInfo.iState, &aucSlaveStateStr[SlaveInfo.iState] );
		UART_printf( "      Protocol Version:\t\t0x%04X\n", SlaveInfo.usProtocolVersion );
                UART_printf( "      End Code:\t\t\t0x%04X\n", SlaveInfo.usEndCode );
                UART_printf( "      Slave Notify Information:\n" );
                UART_printf( "        Vender Code:\t\t0x%04X\n", SlaveInfo.NotifyInfo.usVenderCode );
                UART_printf( "        Model Code:\t\t0x%08X\n", SlaveInfo.NotifyInfo.ulModelCode );
                UART_printf( "        Machine Version:\t0x%04X\n", SlaveInfo.NotifyInfo.usMachineVersion );
                UART_printf( "        Unit Info:\t\t0x%04X\n", SlaveInfo.NotifyInfo.usUnitInfo );
                UART_printf( "        Error Code:\t\t0x%04X\n", SlaveInfo.NotifyInfo.usErrCode );
                UART_printf( "        Unit Data:\t\t0x%08X\n", SlaveInfo.NotifyInfo.ulUnitData );
                UART_printf( "      Frame sequence number:\t0x%04X\n", SlaveInfo.usFrameSequenceNumber );
                #else
                printf( "      Protocol Version:\t\t0x%04X\n", SlaveInfo.usProtocolVersion );
                printf( "      End Code:\t\t\t0x%04X\n", SlaveInfo.usEndCode );
                printf( "      Slave Notify Information:\n" );
                printf( "        Vender Code:\t\t0x%04X\n", SlaveInfo.NotifyInfo.usVenderCode );
                printf( "        Model Code:\t\t0x%08X\n", SlaveInfo.NotifyInfo.ulModelCode );
                printf( "        Machine Version:\t0x%04X\n", SlaveInfo.NotifyInfo.usMachineVersion );
                printf( "        Unit Info:\t\t0x%04X\n", SlaveInfo.NotifyInfo.usUnitInfo );
                printf( "        Error Code:\t\t0x%04X\n", SlaveInfo.NotifyInfo.usErrCode );
                printf( "        Unit Data:\t\t0x%08X\n", SlaveInfo.NotifyInfo.ulUnitData );
                printf( "      Frame sequence number:\t0x%04X\n", SlaveInfo.usFrameSequenceNumber );
                #endif
		iDataIndex = ( CCIEF_BASIC_RX_RY_SIZE / sizeof( uint16_t ) ) * iStationNumber;
		iDataSize = ( CCIEF_BASIC_RX_RY_SIZE / sizeof( uint16_t ) ) * usOccupiedStationNumber;
		#ifdef __TIRTOS__
		UART_printf( "\n        RX  | F E D C B A 9 8 7 6 5 4 3 2 1 0 |  data\n" );
		UART_printf( "      -------------------------------------------------\n" );
		#else
		printf( "\n        RX  | F E D C B A 9 8 7 6 5 4 3 2 1 0 |  data\n" );
		printf( "      -------------------------------------------------\n" );
		#endif
		for ( j = 0; j < iDataSize; j ++ )
		{
			pusData = pusRX + iDataIndex + j;
			#ifdef __TIRTOS__
                        UART_printf( "       %04X |", ( iDataIndex + j ) * 16 );
			for ( k = 0; k < 16; k ++ )
			{
				UART_printf( " %d", ( *pusData >> ( 16 - ( k + 1 ))) & 0x1 );
			}
			UART_printf( " | 0x%04X \n", *pusData );
                        #else
                        printf( "       %04X |", ( iDataIndex + j ) * 16 );
			for ( k = 0; k < 16; k ++ )
			{
				printf( " %d", ( *pusData >> ( 16 - ( k + 1 ))) & 0x1 );
			}
			printf( " | 0x%04X \n", *pusData );
                        #endif
                        
		}
		#ifdef __TIRTOS__
		UART_printf( "\n        RY  | F E D C B A 9 8 7 6 5 4 3 2 1 0 |  data\n" );
		UART_printf( "      -------------------------------------------------\n" );
		#else
		printf( "\n        RY  | F E D C B A 9 8 7 6 5 4 3 2 1 0 |  data\n" );
		printf( "      -------------------------------------------------\n" );
		#endif
		for ( j = 0; j < iDataSize; j ++ )
		{
			pusData = pusRY + iDataIndex + j;
			#ifdef __TIRTOS__
                        UART_printf( "       %04X |", ( iDataIndex + j ) * 16 );
			for ( k = 0; k < 16; k ++ ) {
				UART_printf( " %d", ( *pusData >> ( 16 - ( k + 1 ))) & 0x1 );
			}
			UART_printf( " | 0x%04X \n", *pusData );
                        #else
                        printf( "       %04X |", ( iDataIndex + j ) * 16 );
			for ( k = 0; k < 16; k ++ ) {
				printf( " %d", ( *pusData >> ( 16 - ( k + 1 ))) & 0x1 );
			}
			printf( " | 0x%04X \n", *pusData );
                        #endif
                        
		}
		iDataIndex = ( CCIEF_BASIC_RWW_RWR_SIZE / sizeof( uint16_t ) ) * iStationNumber;
		iDataSize = ( CCIEF_BASIC_RWW_RWR_SIZE / sizeof( uint16_t ) ) * usOccupiedStationNumber;
		#ifdef __TIRTOS__
		UART_printf( "\n        RWw |   +7     +6     +5     +4     +3     +2     +1     +0  \n" );
		UART_printf( "      ----------------------------------------------------------------\n" );
		#else
		printf( "\n        RWw |   +7     +6     +5     +4     +3     +2     +1     +0  \n" );
		printf( "      ----------------------------------------------------------------\n" );
		#endif
		for ( j = 0; j < ( iDataSize / 8 ); j ++ )
		{
			#ifdef __TIRTOS__
                        UART_printf( "       %04X |", iDataIndex + j * 8 );
                        #else
                        printf( "       %04X |", iDataIndex + j * 8 );
                        #endif
			pusData = pusRWw + iDataIndex + ( j + 1 ) * 8;
			for ( k = 0; k < 8; k ++ ) {
				pusData --;
				#ifdef __TIRTOS__
                                UART_printf( " 0x%04X", *pusData );
                                #else
                                printf( " 0x%04X", *pusData );
                                #endif
			}
			#ifdef __TIRTOS__
                        UART_printf( "\n" );
                        #else
                        printf( "\n" );
                        #endif
		}
		#ifdef __TIRTOS__
                UART_printf( "\n        RWr |   +7     +6     +5     +4     +3     +2     +1     +0  \n" );
		UART_printf( "      ----------------------------------------------------------------\n" );
                #else
                printf( "\n        RWr |   +7     +6     +5     +4     +3     +2     +1     +0  \n" );
		printf( "      ----------------------------------------------------------------\n" );
                #endif
		for ( j = 0; j < ( iDataSize / 8 ); j ++ )
		{
			#ifdef __TIRTOS__
			UART_printf( "       %04X |", iDataIndex + j * 8 );
			#else
			printf( "       %04X |", iDataIndex + j * 8 );
			#endif
			pusData = pusRWr + iDataIndex + ( j + 1 ) * 8;
			for ( k = 0; k < 8; k ++ )
			{
				pusData --;
				#ifdef __TIRTOS__
			        UART_printf( " 0x%04X", *pusData );
			        #else
                    		printf( " 0x%04X", *pusData );
	        		#endif
			}
			#ifdef __TIRTOS__
			UART_printf( "\n" );
			#else
			printf( "\n" );
			#endif
		}
		iStationNumber += usOccupiedStationNumber;
	}

	return;
}

/************************************************************************************/
/* This is an user defined function for showing information of the master.			*/
/************************************************************************************/
char aucMasterStateStr[][14] = { "INITAL", "WAITING", "PERSUASION", "LINK_SCAN", "LINK_SCAN_END" };
void user_show_master_info( void )
{
	CCIEF_BASIC_MASTER_PARAMETER *pParameter;
	static CCIEF_BASIC_GROUP_INFO MasterInfo;
	static CCIEF_BASIC_SLAVE_INFO SlaveInfo;
	TIMER_TIME_DATA TimeData;
	int i, j;

	pParameter = &UserMasterParameter;

	#ifdef __TIRTOS__
        UART_printf( "\nShow the state of master!\n" );
        #else
        printf( "\nShow the state of master!\n" );
        #endif

	/* Showing the state of all the groups */
	for ( i = 0; i < pParameter->iTotalGroupNumber; i ++ )
	{
		/* Getting the master group information */
		ccief_basic_master_get_group_info( i, &MasterInfo );
		if ( i == 0 )
		{
			#ifdef __TIRTOS__
                        UART_printf( "\n    Master:\n" );
                        UART_printf( "      Protocol Version:\t\t\t0x%04X\n", MasterInfo.usProtocolVersion );
                        UART_printf( "      Master ID:\t\t\t0x%08X\n", MasterInfo.ulId );
                        UART_printf( "      Unit Info:\t\t\t0x%04X\n", MasterInfo.usUnitInfo );
                        UART_printf( "      Parameter ID:\t\t\t0x%04X\n", MasterInfo.usParameterId );
                        #else
                        printf( "\n    Master:\n" );
                        printf( "      Protocol Version:\t\t\t0x%04X\n", MasterInfo.usProtocolVersion );
                        printf( "      Master ID:\t\t\t0x%08lX\n", MasterInfo.ulId );
                        printf( "      Unit Info:\t\t\t0x%04X\n", MasterInfo.usUnitInfo );
                        printf( "      Parameter ID:\t\t\t0x%04X\n", MasterInfo.usParameterId );
                        #endif
                }
                #ifdef __TIRTOS__
                UART_printf( "\n    Group No.%d:\n", MasterInfo.ucGroupNumber );
                UART_printf( "      Total Number of Slave:\t\t%d\n", MasterInfo.iTotalSlaveNumber );
                UART_printf( "      Total Number of Occupied Station:\t%d\n", MasterInfo.usTotalOccupiedStationNumber );
                UART_printf( "      State:\t\t\t\t%d [%s]\n", MasterInfo.iState, &aucMasterStateStr[MasterInfo.iState] );
                                timer_analyze_time_data( MasterInfo.llTimeData, &TimeData );
                UART_printf( "      Time Data:\t\t\t%d [%02d-%02d-%02d %02d:%02d:%02d.%03d]\n", MasterInfo.llTimeData,
                                TimeData.usYear, TimeData.usMonth, TimeData.usDay, TimeData.usHour, TimeData.usMinute,
                                TimeData.usSecond, TimeData.usMilliseconds );
                UART_printf( "      Frame sequence number:\t\t0x%04X\n", MasterInfo.usFrameSequenceNumber );
                UART_printf( "      Link scan time(Current):\t\t%01d.%03d[ms]\n", (MasterInfo.llLinkScanTimeCurrent / 1000) ,(MasterInfo.llLinkScanTimeCurrent % 1000));
                UART_printf( "      Link scan time(Minimum):\t\t%01d.%03d[ms]\n", (MasterInfo.llLinkScanTimeMinimum / 1000) ,(MasterInfo.llLinkScanTimeMinimum % 1000));
                UART_printf( "      Link scan time(Maximum):\t\t%01d.%03d[ms]\n", (MasterInfo.llLinkScanTimeMaximum / 1000) ,(MasterInfo.llLinkScanTimeMaximum % 1000));
                UART_printf( "      Group:\n" );
                UART_printf( "          Master(ID:0x%08X)\n", MasterInfo.ulId );
                #else
                printf( "\n    Group No.%d:\n", MasterInfo.ucGroupNumber );
                printf( "      Total Number of Slave:\t\t%d\n", MasterInfo.iTotalSlaveNumber );
                printf( "      Total Number of Occupied Station:\t%d\n", MasterInfo.usTotalOccupiedStationNumber );
                printf( "      State:\t\t\t\t%d [%s]\n", MasterInfo.iState, &aucMasterStateStr[MasterInfo.iState] );
                                timer_analyze_time_data( MasterInfo.llTimeData, &TimeData );
                printf( "      Time Data:\t\t\t%lld [%02d-%02d-%02d %02d:%02d:%02d.%03d]\n", MasterInfo.llTimeData,
                                TimeData.usYear, TimeData.usMonth, TimeData.usDay, TimeData.usHour, TimeData.usMinute,
                                TimeData.usSecond, TimeData.usMilliseconds );
                printf( "      Frame sequence number:\t\t0x%04X\n", MasterInfo.usFrameSequenceNumber );
                printf( "      Link scan time(Current):\t\t%01.3f[ms]\n", ((float)MasterInfo.llLinkScanTimeCurrent / 1000) );
                printf( "      Link scan time(Minimum):\t\t%01.3f[ms]\n", ((float)MasterInfo.llLinkScanTimeMinimum / 1000) );
                printf( "      Link scan time(Maximum):\t\t%01.3f[ms]\n", ((float)MasterInfo.llLinkScanTimeMaximum / 1000) );
                printf( "      Group:\n" );
                printf( "          Master(ID:0x%08lX)\n", MasterInfo.ulId );
                #endif
		for ( j = 0; j < pParameter->iTotalSlaveNumber; j ++ )
		{
			/* Getting the slave state */
			ccief_basic_master_get_slave_info( j, &SlaveInfo );
			/* Check the group number */
			if ( MasterInfo.ucGroupNumber == SlaveInfo.ucGroupNumber )
			{
				/* Check the cyclic state */
				#ifdef __TIRTOS__
                                if ( SlaveInfo.iCyclicState == CCIEF_BASIC_CYCLIC_STATE_ON )
				{
					UART_printf( "              |--- Slave No.%2d (ID:0x%08X CyclicState:ON  State:%d [%s])\n",
							( j + 1 ), SlaveInfo.ulId, SlaveInfo.iState, &aucSlaveStateStr[SlaveInfo.iState] );
				}
				else
				{
					UART_printf( "              |--- Slave No.%2d (ID:0x%08X CyclicState:OFF State:%d [%s])\n",
							( j + 1 ), SlaveInfo.ulId, SlaveInfo.iState, &aucSlaveStateStr[SlaveInfo.iState] );
				}
                                #else
                                if ( SlaveInfo.iCyclicState == CCIEF_BASIC_CYCLIC_STATE_ON )
				{
				        printf( "              |--- Slave No.%-2d (ID:0x%-08lX CyclicState:ON  State:%d [%s])\n",
							( j + 1 ), SlaveInfo.ulId, SlaveInfo.iState, &aucSlaveStateStr[SlaveInfo.iState] );
				}
				else
				{
					printf( "              |--- Slave No.%-2d (ID:0x%-08lX CyclicState:OFF State:%d [%s])\n",
							( j + 1 ), SlaveInfo.ulId, SlaveInfo.iState, &aucSlaveStateStr[SlaveInfo.iState] );
				}
                                #endif
			}
		}
	}

	return;
}

/************************************************************************************/
/* This is an user defined function for show parameter of the Master.				*/
/************************************************************************************/
void user_show_parameter( void )
{
	CCIEF_BASIC_MASTER_PARAMETER *pParameter;
	struct in_addr addr;
	char space[3] = "";
	int	i;
	char Ipaddr[16];

	pParameter = &UserMasterParameter;

	/* Show parameter of the master */
	/* Setting of the master */
	#ifdef __TIRTOS__
        UART_printf( "\nShow master parameter!\n" );
        UART_printf( "\n    Master:\n" );
        #else
        printf( "\nShow master parameter!\n" );
        printf( "\n    Master:\n" );
        #endif
#ifdef __TIRTOS__ 
        addr.s_addr = NDK_htonl(AdapterInfo.ulIpAddress);
#elif _WIN32
	addr.S_un.S_addr = htonl(AdapterInfo.ulIpAddress);
#elif __linux__
	addr.s_addr = htonl(AdapterInfo.ulIpAddress);
#endif
	inet_ntop(AF_INET, &addr, Ipaddr, sizeof(Ipaddr) );
	#ifdef __TIRTOS__
        UART_printf( "      IP Address:\t\t\t%s (Master ID:0x%08x)\n", Ipaddr, AdapterInfo.ulIpAddress );
        #else
        printf( "      IP Address:\t\t\t%s (Master ID:0x%08x)\n", Ipaddr, AdapterInfo.ulIpAddress );
        #endif
#ifdef __TIRTOS__ 
        addr.s_addr = NDK_htonl(AdapterInfo.ulSubnetMask);
#elif _WIN32
	addr.S_un.S_addr = htonl(AdapterInfo.ulSubnetMask);
#elif __linux__
	addr.s_addr = htonl(AdapterInfo.ulSubnetMask);
#endif
	inet_ntop(AF_INET, &addr, Ipaddr, sizeof(Ipaddr) );
	#ifdef __TIRTOS__
        UART_printf( "      Subnet mask:\t\t\t%s\n", Ipaddr );
        #else
        printf( "      Subnet mask:\t\t\t%s\n", Ipaddr );
        #endif
#ifdef __TIRTOS__ 
        addr.s_addr = NDK_htonl(AdapterInfo.ulDefaultGatewayIPAddress);
#elif _WIN32
	addr.S_un.S_addr = htonl(AdapterInfo.ulDefaultGatewayIPAddress);
#elif __linux__
	addr.s_addr = htonl(AdapterInfo.ulDefaultGatewayIPAddress);
#endif
	inet_ntop(AF_INET, &addr, Ipaddr, sizeof(Ipaddr) );
	#ifdef __TIRTOS__
        UART_printf( "      Default GW IP address:\t\t%s\n", Ipaddr );
        #else
        printf( "      Default GW IP address:\t\t%s\n", Ipaddr );
        #endif
	/* Setting of the group */
	if (!(( pParameter->iTotalGroupNumber == 1 ) && ( pParameter->Group[0].ucGroupNumber == 0 )))
	{
		#ifdef __TIRTOS__
                UART_printf( "\n    Total Number of Group:\t\t%d\n", pParameter->iTotalGroupNumber );
                #else
                printf( "\n    Total Number of Group:\t\t%d\n", pParameter->iTotalGroupNumber );
                #endif
	}
	for ( i = 0; i < pParameter->iTotalGroupNumber; i++ )
	{
		if ( pParameter->Group[i].ucGroupNumber != 0 )
		{
			#ifdef __TIRTOS__
			UART_printf( "      Group No.%d:\n", pParameter->Group[i].ucGroupNumber );
			#else
			printf( "      Group No.%d:\n", pParameter->Group[i].ucGroupNumber );
			#endif
#ifdef _WIN32
			sprintf_s( space, sizeof(space), "  " );
#elif __linux__
			sprintf( space, "  " );
#endif
		}
		#ifdef __TIRTOS__
		UART_printf( "%s      Disconnection Time[ms]:\t\t%d (0:500[ms])\n", space, pParameter->Group[i].usCyclicTransmissionTimeout );
		UART_printf( "%s      Disconnection Timeout Count:\t%d (0:3)\n", space, pParameter->Group[i].usCyclicTransmissionTimeoutCount );
		#else
		printf( "%s      Disconnection Time[ms]:\t\t%d (0:500[ms])\n", space, pParameter->Group[i].usCyclicTransmissionTimeout );
		printf( "%s      Disconnection Timeout Count:\t%d (0:3)\n", space, pParameter->Group[i].usCyclicTransmissionTimeoutCount );
		#endif
		if ( pParameter->Group[i].usConstantLinkScanTime == 0 )
		{
			#ifdef __TIRTOS__
			UART_printf( "%s      Constant Link Scan Time[ms]:\tNot use\n", space );
			#else
			printf( "%s      Constant Link Scan Time[ms]:\tNot use\n", space );
			#endif
		}
		else
		{
			#ifdef __TIRTOS__
			UART_printf( "%s      Constant Link Scan Time[ms]:\t%d:\n", space, pParameter->Group[i].usConstantLinkScanTime );
			#else
			printf( "%s      Constant Link Scan Time[ms]:\t%d:\n", space, pParameter->Group[i].usConstantLinkScanTime );
			#endif
		}
	}
	/* Setting of the slave */
	#ifdef __TIRTOS__
        UART_printf( "\n    Total Number of Slave:\t\t%d\n", pParameter->iTotalSlaveNumber );
        #else
        printf( "\n    Total Number of Slave:\t\t%d\n", pParameter->iTotalSlaveNumber );
        #endif
	for ( i = 0; i < pParameter->iTotalSlaveNumber; i++ )
	{
		#ifdef __TIRTOS__
                UART_printf( "      Slave No.%d:\n", i + 1 );
                #else
                printf( "      Slave No.%d:\n", i + 1 );
                #endif
#ifdef __TIRTOS__ 
		addr.s_addr = NDK_htonl(pParameter->Slave[i].ulIpAddress);	
#elif _WIN32
		addr.S_un.S_addr = htonl(pParameter->Slave[i].ulIpAddress);
#elif __linux__
		addr.s_addr = htonl(pParameter->Slave[i].ulIpAddress);	
#endif
		inet_ntop(AF_INET, &addr, Ipaddr, sizeof(Ipaddr) );
		UART_printf( "        IP Address:\t\t\t%s (Slave ID:0x%08x)\n", Ipaddr,
				pParameter->Slave[i].ulIpAddress );
		#ifdef __TIRTOS__
                UART_printf( "        Occupied Station Number:\t%d\n", pParameter->Slave[i].usOccupiedStationNumber );
                #else
                printf( "        Occupied Station Number:\t%d\n", pParameter->Slave[i].usOccupiedStationNumber );
                #endif
		if ( pParameter->Slave[i].ucGroupNumber != 0 )
		{
			#ifdef __TIRTOS__
                        UART_printf( "        Group Number:\t\t\t%d\n", pParameter->Slave[i].ucGroupNumber );
                        #else
                        printf( "        Group Number:\t\t\t%d\n", pParameter->Slave[i].ucGroupNumber );
                        #endif
		}
	}

	return;
}

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/************************************************************************************/
/* This is an user defined function for get the adapter information.				*/
/* The following is one of a sample in the Windows OS. Please rewrite if necessary.	*/
/* The following is one of a sample in the Linux. Please rewrite if necessary.		*/
/************************************************************************************/
int user_get_adapter_info( USER_ADAPTER_INFO *pGetAdapterInfo )
{
#ifdef __TIRTOS__
    struct in_addr              addr;
    int				iResult;

    iResult = inet_aton(LocalIPAddr, &addr);
    if ( iResult == 1)
    {
            pGetAdapterInfo->ulIpAddress = NDK_htonl(addr.s_addr);
    }
    else
    {
            #ifdef __TIRTOS__
            UART_printf("Adapter IP address error.\n");
            #else
            printf("Adapter IP address error.\n");
            #endif
            return USER_ERR_NG;
    }
    iResult = inet_aton(LocalIPMask, &addr);
    if ( iResult == 1)
    {
            pGetAdapterInfo->ulSubnetMask = NDK_htonl(addr.s_addr);
    }
    else
    {
            #ifdef __TIRTOS__
            UART_printf("Adapter sub-net mask error.\n");
            #else
            printf("Adapter sub-net mask error.\n");
            #endif
            return USER_ERR_NG;
    }
    iResult = inet_aton(GatewayIP, &addr);
    if ( iResult == 1)
    {
            pGetAdapterInfo->ulDefaultGatewayIPAddress = NDK_htonl(addr.s_addr);
    }
    else
    {
            #ifdef __TIRTOS__
            UART_printf("Adapter default gateway IP address error.\n");
            #else
            printf("Adapter default gateway IP address error.\n");
            #endif
            return USER_ERR_NG;
    }
    
    
    return USER_ERR_OK;
#elif _WIN32
	ULONG			ulOutBufLen;
	ULONG			ulIpaddr, ulSubNetMask, ulDefGateway;
	DWORD			dwRetVal;
	IP_ADAPTER_INFO *pAdapterInfo;
	IP_ADAPTER_INFO *pAdapter;
	int				iAdapterNum;
	int				iKey;
	int				iInputNumber;
	int				i;
	int				iResult;

	/* GetAdaptersInfo */
	pAdapterInfo = (IP_ADAPTER_INFO *) MALLOC(sizeof( IP_ADAPTER_INFO ));
	if ( pAdapterInfo == NULL )
	{
		printf( "Error allocating memory needed to call GetAdapterInfo\n" );
		return USER_ERR_NG;
	}
	ulOutBufLen = sizeof( IP_ADAPTER_INFO );

	if ( GetAdaptersInfo( pAdapterInfo, &ulOutBufLen ) == ERROR_BUFFER_OVERFLOW )
	{
		FREE( pAdapterInfo );
		pAdapterInfo = (IP_ADAPTER_INFO *) MALLOC( ulOutBufLen );
		if ( pAdapterInfo == NULL )
		{
			printf( "Error allocating memory needed to call GetAdapterInfo\n" );
			return USER_ERR_NG;
		}
	}

	if (( dwRetVal = GetAdaptersInfo( pAdapterInfo, &ulOutBufLen )) != NO_ERROR )
	{
		printf( "GetAdaptersInfo failed with error %d\n", dwRetVal );
		if ( pAdapterInfo )
		{
			FREE( pAdapterInfo );
		}
		return USER_ERR_NG;
	}

	pAdapter = pAdapterInfo;
	iAdapterNum = 0;

	/* Check the Multiple Adapter */
	if ( pAdapter->Next != NULL )
	{
		printf( "Found the multiple Network adapter!\n\n");
		while ( pAdapter )
		{
			printf( "%2d: \tAdapter desc: \t\t%s\n", iAdapterNum+1, pAdapter->Description );
			printf( "\tMAC address: \t\t%02X:%02X:%02X:%02X:%02X:%02X\n",
					pAdapter->Address[0], pAdapter->Address[1], pAdapter->Address[2],
					pAdapter->Address[3], pAdapter->Address[4], pAdapter->Address[5] );
			printf( "\tIP address: \t\t%s\n",
					pAdapter->IpAddressList.IpAddress.String );
			printf( "\tSubnet mask: \t\t%s\n", pAdapter->IpAddressList.IpMask.String );
			printf( "\tDefault GW IP address: \t%s\n", pAdapter->GatewayList.IpAddress.String );
			printf( "\n");
			iAdapterNum ++;
			pAdapter = pAdapter->Next;
		}
		printf( "Please select the adapter number (Press 'Enter' Key after select) [1-%d]: ", iAdapterNum );

		iInputNumber = 0;

		while ( 1 )
		{
			iKey = _getch();
			if ( iKey != 0x0d )
			{
				if (( 0x30 <= iKey ) && ( iKey <= 0x39 ))
				{
					printf( "%c",iKey);
					iInputNumber = (iInputNumber*10)+(iKey-0x30);
				}
			}
			else
			{
				printf( "\n");
				if (( iInputNumber == 0 ) || ( iAdapterNum < iInputNumber ))
				{
					printf( "Wrong number select!\n");
					iInputNumber = 0;
					printf( "Please select the adapter number (Press 'Enter' Key after select) [1-%d]: ", iAdapterNum );
				}
				else
				{
					break;
				}
			}
		}
		pAdapter = pAdapterInfo;
		for ( i = 1; i < iInputNumber; i++ )
		{
			pAdapter = pAdapter->Next;
		}
	}
	else
	{
		iAdapterNum = 1;
	}
	printf( "\n" );

	memcpy( AdapterInfo.aucMacAddress, pAdapter->Address, sizeof( AdapterInfo.aucMacAddress ) );
	iResult=inet_pton( AF_INET, pAdapter->IpAddressList.IpAddress.String, &ulIpaddr );
	if ( iResult == 1)
	{
		AdapterInfo.ulIpAddress = htonl(ulIpaddr);
	}
	else
	{
		printf("Adapter IP address error.\n");
		return USER_ERR_NG;
	}
	iResult=inet_pton( AF_INET, pAdapter->IpAddressList.IpMask.String, &ulSubNetMask );
	if ( iResult == 1)
	{
		AdapterInfo.ulSubnetMask = htonl(ulSubNetMask);
	}
	else
	{
		printf("Adapter sub-net mask error.\n");
		return USER_ERR_NG;
	}
	iResult=inet_pton( AF_INET, pAdapter->GatewayList.IpAddress.String, &ulDefGateway );
	if ( iResult == 1)
	{
		AdapterInfo.ulDefaultGatewayIPAddress = htonl(ulDefGateway);
	}
	else
	{
		printf("Adapter default gateway IP address error.\n");
		return USER_ERR_NG;
	}

	FREE( pAdapterInfo );

	/* Copy the argument pointer */
	memcpy( pGetAdapterInfo, &AdapterInfo, sizeof( USER_ADAPTER_INFO ) );

	return USER_ERR_OK;

#elif __linux__
	struct ifconf			Ifc_Get;
	struct ifreq			Ifreq_Size[MAX_INTERFACE];
	struct sockaddr_in 		get_addr[MAX_INTERFACE];
	USER_NETWORK_INFO 		User_Adapter[MAX_INTERFACE];
	USER_NETWORK_INFO 		User_Get_Info;
	unsigned char			*pMAC_addr;
	int						sock_network;
	int						i;
	int						ikey;
	int						iNet_Number=0;
	FILE					*pFile;
	t_RouteInfo				RouteInfo_Defo[MAX_INTERFACE];
	char					input_line[128];

	Ifc_Get.ifc_len = sizeof( Ifreq_Size );
	Ifc_Get.ifc_ifcu.ifcu_buf=(void *)Ifreq_Size;

	/* Socket open */
	sock_network = socket( AF_INET, SOCK_DGRAM, 0 );
	if( sock_network < SOCKET_NOT_OPEN )
	{
		perror("Socket not open");
		return USER_ERR_NG;
	}

	/* Network interface list acquisition */
	if( ioctl( sock_network, SIOCGIFCONF, &Ifc_Get ) == -1 )
	{
		perror("Error can not get the interface list");
		close( sock_network );
		return USER_ERR_NG;
	}

	/* Calculate the number that came back from the kernel */
	iNet_Number = Ifc_Get.ifc_len / ( int )sizeof( struct ifreq );
	for(i=0;i<iNet_Number;i++)
	{
		/* Interface designation */
		strncpy( User_Adapter[i].USER_ifreq.ifr_name,Ifreq_Size[i].ifr_name,IFNAMSIZ-1 );

		/* IP address (IPv4) acquisition */
		if ( ioctl( sock_network, SIOCGIFADDR, &User_Adapter[i].USER_ifreq ) == -1 )
		{
			perror("Error can not get the IP address");
			close( sock_network );
			return USER_ERR_NG;
		}
		memcpy( &get_addr[i], &User_Adapter[i].USER_ifreq.ifr_addr, sizeof( struct sockaddr_in ));
		memcpy( &User_Adapter[i].IPAddr, inet_ntoa( get_addr[i].sin_addr ), sizeof( User_Adapter[i].IPAddr ));

		/* Mask address acquisition */
		if ( ioctl( sock_network, SIOCGIFNETMASK, &User_Adapter[i].USER_ifreq ) == -1 )
		{
			perror("Error can not get the Mask address");
			close( sock_network );
			return USER_ERR_NG;
		}
		memcpy( &get_addr[i], &User_Adapter[i].USER_ifreq.ifr_netmask, sizeof( struct sockaddr_in )); 
		memcpy( &User_Adapter[i].IPMask, inet_ntoa( get_addr[i].sin_addr ), sizeof( User_Adapter[i].IPMask ));

		/* Mac address acquisition */
		if ( ioctl( sock_network, SIOCGIFHWADDR, &User_Adapter[i].USER_ifreq ) == -1 )
		{
			perror("Error can not get the Mac address");
			close( sock_network );
			return USER_ERR_NG;
		}
		pMAC_addr=(unsigned char *)&User_Adapter[i].USER_ifreq.ifr_hwaddr.sa_data;
		sprintf( User_Adapter[i].MACAddr, "%02x:%02x:%02x:%02x:%02x:%02x", *pMAC_addr, *(pMAC_addr+1), *(pMAC_addr+2), *(pMAC_addr+3), *(pMAC_addr+4), *(pMAC_addr+5));

		/* Get the default gateway from the system file */
		pFile = fopen( DIR_PROC_ROUTE , "r" );
		if( pFile == NULL )
		{
			printf("Not systemfile read");
			close( sock_network );
			return USER_ERR_NG;
		}

		while(1)
		{
			if ( fgets( User_Adapter[i].Defo, sizeof( User_Adapter[i].Defo ), pFile ) == 0) 
			{
				memset( User_Adapter[i].Defo,0x00,sizeof( User_Adapter[i].Defo ));
				fclose( pFile );
				break;
			}
			//Route information acquisition
			memset( &RouteInfo_Defo[i], 0x00, sizeof( RouteInfo_Defo[i] ));
			if ( sscanf( User_Adapter[i].Defo, "%s%x%x%d%d%d%d%x%d%d%d",
				&RouteInfo_Defo[i].cIface,
				&RouteInfo_Defo[i].cDst,
				&RouteInfo_Defo[i].cGateway,
				&RouteInfo_Defo[i].iFlag,
				&RouteInfo_Defo[i].iRecCnt,
				&RouteInfo_Defo[i].iUse,
				&RouteInfo_Defo[i].iMetric,
				&RouteInfo_Defo[i].cMask,
				&RouteInfo_Defo[i].iMTU,
				&RouteInfo_Defo[i].iWindow,
				&RouteInfo_Defo[i].iIRTT) == 0 )
			{
				printf("Not file read");
				fclose( pFile );
				close( sock_network );
				return USER_ERR_NG;
			}
			/* device name and default GW flag check */
			if (( strstr( RouteInfo_Defo[i].cIface,User_Adapter[i].USER_ifreq.ifr_name ) != NULL ) && ( RouteInfo_Defo[i].iFlag == ( RTF_UP | RTF_GATEWAY )))
			{
				memcpy( &User_Adapter[i].Defo, inet_ntoa( RouteInfo_Defo[i].cGateway ), INET_ADDRSTRLEN );
				fclose( pFile );
				break;
			}
			memset( User_Adapter[i].Defo,0x00,sizeof( User_Adapter[i].Defo ));
		}
	}
	
	
	
	for(i=0;i<iNet_Number;i++)
	{
		printf( "%2d: \tAdapter desc: \t\t%s\n", i+1, User_Adapter[i].USER_ifreq.ifr_name );
		printf( "\tMAC address: \t\t%s\n", User_Adapter[i].MACAddr );
		printf( "\tIP address: \t\t%s\n",User_Adapter[i].IPAddr );
		printf( "\tSubnet mask: \t\t%s\n", User_Adapter[i].IPMask );
		printf( "\tDefault GW IP address: \t%s\n", User_Adapter[i].Defo );
		printf( "\n");
	}
	printf( "Please select the adapter number (Press 'enter' Key after select) [1-%d]: ", iNet_Number );
	while ( 1 )
	{
		fgets( input_line,sizeof( input_line ),stdin );
		sscanf( input_line,"%d",&ikey );
		if (( 1 > ikey ) || ( iNet_Number < ikey ))
		{
			printf( "Wrong number select!\n");
			printf( "Please select the adapter number (Press 'Enter' Key after select) [1-%d]: ", iNet_Number );
		}
		else
		{
			break;
		}
	}

	User_Get_Info = User_Adapter[ikey-1];

	/* Conversion of endian */
	AdapterInfo.aucMacAddress[0] = ( uint8_t ) User_Get_Info.USER_ifreq.ifr_hwaddr.sa_data[5];
	AdapterInfo.aucMacAddress[1] = ( uint8_t ) User_Get_Info.USER_ifreq.ifr_hwaddr.sa_data[4];
	AdapterInfo.aucMacAddress[2] = ( uint8_t ) User_Get_Info.USER_ifreq.ifr_hwaddr.sa_data[3];
	AdapterInfo.aucMacAddress[3] = ( uint8_t ) User_Get_Info.USER_ifreq.ifr_hwaddr.sa_data[2];
	AdapterInfo.aucMacAddress[4] = ( uint8_t ) User_Get_Info.USER_ifreq.ifr_hwaddr.sa_data[1];
	AdapterInfo.aucMacAddress[5] = ( uint8_t ) User_Get_Info.USER_ifreq.ifr_hwaddr.sa_data[0];
	AdapterInfo.ulIpAddress = htonl( inet_addr( User_Get_Info.IPAddr ));
	AdapterInfo.ulSubnetMask = htonl( inet_addr( User_Get_Info.IPMask ));
	AdapterInfo.ulDefaultGatewayIPAddress = htonl(inet_addr( User_Get_Info.Defo ));

	close( sock_network );

	return USER_ERR_OK;
#endif
}

