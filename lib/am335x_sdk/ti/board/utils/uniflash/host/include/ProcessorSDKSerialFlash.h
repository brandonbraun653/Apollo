#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <iostream>
#include <stdio.h>
#include <string.h>

#ifdef WINDOWS

#include <fstream>
#include <time.h>
#include <windows.h>
#include <tchar.h>
#include <string>


class SerialPort {
private:
HANDLE serialPortHandle;
 
public:
SerialPort();
~SerialPort();
 
int connect (wchar_t *device, unsigned int baudrate);
void disconnect(void);
 
int sendArray(unsigned char *buffer, int len);
int getArray (unsigned char *buffer, int len);
 
void clear();
};

int xmodemHTransfer( wchar_t *destname, unsigned char *src);
int xmodemFTransfer( wchar_t *destname, char *sname);

#else

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int set_interface_attribs ( int, int, int );
int openport ( char* );
int readport ( char*, int );
int xmodemFTransfer ( char*, int );
int xmodemHTransfer ( unsigned char*, int );

#endif	

using namespace std;

#define VERSION "1.2.0.0"

#define	SUCCESS                  0
#define ERR_RCAN                -1
#define ERR_NOSYNC              -2
#define ERR_XMIT                -4
#define ERR_NOACK               -5
#define ERR_INVALID             -6
#define ERR_COMSTAT             -7

#define PROGRAM_CMD             0x50U
#define ERASE_CMD               0x45U
#define GET_MAX_BAUDRATE_CMD    0x47U
#define SET_BAUDRATE_CMD        0x53U

#define SOH                     0x01
#define STX                     0x02
#define EOT                     0x04
#define ACK                     0x06
#define NAK                     0x15
#define CAN                     0x18
#define CTRLZ                   0x1A
#define NOT_SUPPORTED_BAUDRATE  0x29
#define FLASH_SUCCESS           0x2A
#define FLASH_FAILURE           0x2B

#define FIRMWARE_DEVTYPE        '4'

#define BAUDRATE_115200         0x0U
#define BAUDRATE_230400         0x1U
#define BAUDRATE_460800         0x2U
#define BAUDRATE_500000         0x3U
#define BAUDRATE_576000         0x4U
#define BAUDRATE_921600         0x5U
#define BAUDRATE_1000000        0x6U
#define BAUDRATE_1152000        0x7U
#define BAUDRATE_1500000        0x8U
#define BAUDRATE_2000000        0x9U
#define BAUDRATE_2500000        0xAU
#define BAUDRATE_3000000        0xBU
#define BAUDRATE_3500000        0xCU
#define BAUDRATE_4000000        0xDU
#define BAUDRATE_6000000        0xEU

#ifdef WINDOWS
#define NUM_OF_SUP_BAUDRATE     15
#define BAUDRATE_0              115200U
#define BAUDRATE_1              230400U
#define BAUDRATE_2              460800U
#define BAUDRATE_3              500000U
#define BAUDRATE_4              576000U
#define BAUDRATE_5              921600U
#define BAUDRATE_6              1000000U
#define BAUDRATE_7              1152000U
#define BAUDRATE_8              1500000U
#define BAUDRATE_9              2000000U
#define BAUDRATE_10             2500000U
#define BAUDRATE_11             3000000U
#define BAUDRATE_12             3500000U
#define BAUDRATE_13             4000000U
#define BAUDRATE_14             6000000U
#else
#define NUM_OF_SUP_BAUDRATE     14
#define BAUDRATE_0              B115200
#define BAUDRATE_1              B230400
#define BAUDRATE_2              B460800
#define BAUDRATE_3              B500000
#define BAUDRATE_4              B576000
#define BAUDRATE_5              B921600
#define BAUDRATE_6              B1000000
#define BAUDRATE_7              B1152000
#define BAUDRATE_8              B1500000
#define BAUDRATE_9              B2000000
#define BAUDRATE_10             B2500000
#define BAUDRATE_11             B3000000
#define BAUDRATE_12             B3500000
#define BAUDRATE_13             B4000000
#endif


#ifdef WINDOWS
#define MAX_SUPPORTED_BAUDRATE  BAUDRATE_6000000
#else
#define MAX_SUPPORTED_BAUDRATE  BAUDRATE_4000000
#endif



unsigned short crc16_ccitt ( unsigned char *, int );
void displayHelp( void );
void displayVersion(void);

int Init();
int LoadImage( const char * imagePath, const char** optionNames, const char** optionValues, const int optionLen );
int ExecCommand( const char * commandName, const char** optionNames, const char** optionValues, const int optionLen );
int FlashErase( const char** optionNames, const char** optionValues, const int optionLen );
int Shutdown();

typedef void (*ProgressInfoCallBackFunc)( int percentage , const char *subtask_name ); 
int SetProgressInfoCallBack ( ProgressInfoCallBackFunc pFunc );

typedef void (*ErrorMsgCallBackFunc)( int type, const char *msg, bool flag ); 
int SetErrorMsgCallBack ( ErrorMsgCallBackFunc pFunc );

typedef bool (*IsCancelledCallBackFunc)(); 
int SetIsCancelledCallBack ( IsCancelledCallBackFunc pFunc );

#endif
