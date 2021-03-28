/**
 * \file  ProcessorSDKSerialFlash.cpp
 *
 * \brief Command Line Application for File Transfer over UART
 */
/*
* Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
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
#include "../include/ProcessorSDKSerialFlash.h"

#define DEVICE_SUPPORTED 7
#define IMAGETYPE_SUPPORTED 5
#define BUFF_SIZE 20
#define FIND_STRING 2

unsigned int baudRate = BAUDRATE_0;

int devtype = 0, imgtype = 0, addroff = 0, elen = 0, RBL = 0, FW = 1, fdesc = 0, flashErase = 0;
unsigned int offset = 0, def_elen = 0;
char def_itype = '5', def_dtype = '1', def_off = '0';
char device_list[DEVICE_SUPPORTED][BUFF_SIZE]={"NAND", "SPI", "QSPI", "OSPI", "eMMC", "HyperFlash", "UFS"};

unsigned int standardBaudRate[NUM_OF_SUP_BAUDRATE] = { BAUDRATE_0,
                                                       BAUDRATE_1,
                                                       BAUDRATE_2,
                                                       BAUDRATE_3,
                                                       BAUDRATE_4,
                                                       BAUDRATE_5,
                                                       BAUDRATE_6,
                                                       BAUDRATE_7,
                                                       BAUDRATE_8,
                                                       BAUDRATE_9,
                                                       BAUDRATE_10,
                                                       BAUDRATE_11,
                                                       BAUDRATE_12,
                                                       BAUDRATE_13
#ifdef WINDOWS
                                                       ,BAUDRATE_14
#endif                                                       
};

#ifdef WINDOWS	/* Windows APIs */

/**
 * Prints COM port Configuration Parameters.
 *
 * \param dcb specifies the control setting for a serial communications device.
 *
 * This function prints the COM port parameters like BaudRate, ByteSize, Parity
 * and StopBits
 *
 * \return None.
 */

void PrintCommState(DCB dcb)
{
    /*  Print some of the DCB structure values */
    printf("\nBaudRate = %d, ByteSize = %d, Parity = %d, StopBits = %d\n\n", dcb.BaudRate,
              dcb.ByteSize, 
              dcb.Parity,
              dcb.StopBits);
}

SerialPort::SerialPort() {
	serialPortHandle = INVALID_HANDLE_VALUE;
}
 
SerialPort::~SerialPort() {
	if (serialPortHandle!=INVALID_HANDLE_VALUE)
	CloseHandle(serialPortHandle);
	serialPortHandle = INVALID_HANDLE_VALUE;
}

/**
 * Establishes Serial connection with the COM Port
 *
 * \param device specifies the COM Port to be connected.
 *
 * This function establishes serial connection with the COM Port with the defined 
 * dcb parameters.
 *
 * \return Returns 0 on success.
 */

int SerialPort::connect( wchar_t* device, unsigned int baudrate ) {
	int error=0, buf_siz = 1024;
	wchar_t append_str[20] = L"\\\\.\\";
	wchar_t* port_name;
	DCB dcb = {0};
	COMMTIMEOUTS timeouts = {0};
    port_name = wcscat(append_str, device);

	if(*device == NULL)
	{
		cout << "Invalid Device!" << endl;
		return ERR_INVALID;
	}
	serialPortHandle = CreateFileW(port_name, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (serialPortHandle == INVALID_HANDLE_VALUE)
	{
		cout << "Couldn't Open Serial Port!\n";
		return ERR_INVALID;
	}
	dcb.DCBlength = sizeof(DCB);

	if(!(GetCommState(serialPortHandle, &dcb)))
	{
		cout << "GetComm Failed!" << endl;
		return ERR_COMSTAT;
	}

	dcb.BaudRate = baudrate;
	dcb.Parity = NOPARITY;
	dcb.StopBits = ONESTOPBIT;
	dcb.ByteSize = 8;
	dcb.fParity = 0;
	dcb.XoffChar = 19;
	dcb.XonChar = 17;
	dcb.fOutxCtsFlow = 0;
	dcb.fOutxDsrFlow = 0;
	dcb.fDtrControl = 0;
	dcb.fDsrSensitivity = 0;
	dcb.fTXContinueOnXoff = 0;
	dcb.fRtsControl = 0;
	dcb.XonLim = 0;
	dcb.XoffLim = 0;

	#ifdef DEBUG
	cout << endl << "Configuring COM Port!" << endl;
	#endif
	if(!SetCommState(serialPortHandle,&dcb))
	{
		error=ERR_COMSTAT;
		cout << endl << "Configuration Failed!" << endl;
	}

	GetCommState(serialPortHandle, &dcb);
	#ifdef DEBUG
		PrintCommState(dcb);
	#endif
	if(SetupComm(serialPortHandle, buf_siz, buf_siz))
	{
		#ifdef DEBUG
		cout << "Configuring COM Port success!" << endl;
		#endif
	}
	else
	{
		cout << "Configuring COM Port failed!"  << endl;
	}
	#ifdef DEBUG
		PrintCommState(dcb);
	#endif
	if (error!=0) {
	disconnect();

	}
	else {
		clear();
	}
	return error;
}

/**
 * Closes the established connection with the COM Port
 *
 * \param None
 *
 * This function Closes the established connection with the COM Port
 *
 * \return None
 */

void SerialPort::disconnect(void) {
	CloseHandle(serialPortHandle);
	serialPortHandle = INVALID_HANDLE_VALUE;
}

int SerialPort::sendArray(unsigned char *buffer, int len) {
	unsigned long result =0U;
	if(len <= 0)
	{
		cout << "Read Length cannot be 0!" << endl;
		return ERR_INVALID;
	}

	if (serialPortHandle!=INVALID_HANDLE_VALUE)
		WriteFile(serialPortHandle, buffer, len, (LPDWORD)&result, NULL);
	else
		cout << "Invalid Handle!!" << endl;
	return result;
}

/**
 * Reads the COM port
 *
 * \param buffer points to the buffer to store the input data
 * \param len specifies the length of the input data
 *
 * This function receives input over the COM port.
 *
 * \return Returns the length of the data received.
 */

int SerialPort::getArray (unsigned char *buffer, int len) {
	unsigned long read_nbr;
	DWORD dwRead;
	OVERLAPPED osReader = {0};
	BOOL fWaitingOnRead = FALSE; 
	read_nbr = 0;

	if( len <= 0 )
	{
		cout << "SerialPortGet: Invalid input parameters!" << len << endl;
		return ERR_INVALID;
	}

	if (!fWaitingOnRead) {
	   /* Issue read operation */
	   if (!ReadFile(serialPortHandle, buffer, len, &dwRead, &osReader)) {
		  if (GetLastError() != ERROR_IO_PENDING)
			 /* Error in communications */
			 cout <<"Error in reading!!" << endl;
		  else
			 fWaitingOnRead = TRUE;
	   }
	}
	return((int) dwRead);
}

/**
 * Terminates pending read or write operations
 *
 * \param None
 *
 * This function Discards all characters from the output or input 
 * buffer on the Serial Port
 *
 * \return None.
 */

void SerialPort::clear() {
	PurgeComm (serialPortHandle, PURGE_RXCLEAR | PURGE_TXCLEAR);
}

/**
 * Opens the source file
 *
 * \param fname points to the absolute path to the file
 * \param fsize points to the size of the file
 *
 * This function opens the source file to be transferred over 
 * COM Port
 *
 * \return Returns the handle to the file.
 */

ifstream file_open( char *fname, int *fsize)
{
	ifstream ifile;

#ifdef DEBUG
	cout << endl << "Opening file " << fname << endl;
#endif
	ifile.open(fname, ios::binary);	/* Open the file to be transfered */
	if(!ifile)
	{
		cout<<"Error in opening file..!!";
		exit(0);
	}

	ifile.seekg (0, ifile.end);
    *fsize = ifile.tellg();
    ifile.seekg (0, ifile.beg);
	return ifile;
}

#else	/* Linux APIs */

FILE *file;

/**
 * Serial Port Setup
 *
 * \param fd points to the file descriptor of the Serial Port
 * \param speed specifies the Bps of the Serial Port
 * \param parity specifies the Parity of the Serial Port
 *
 * This function configures the Serial Port with given Parameters
 *
 * \return Returns 0 on success and error value on failure.
 */

int set_interface_attribs (int fd, int speed, int parity)
{
		int error = 0;
        struct termios tty;
        memset (&tty, 0, sizeof(tty));
        if (tcgetattr (fd, &tty) != 0)
        {
                cout << "Error " << strerror(errno) << "from tcgetattr\n";
		error = errno;
                return error;
        }

        cfsetospeed (&tty, speed);
        cfsetispeed (&tty, speed);

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     /* 8-bit chars */
        tty.c_iflag &= ~(IXON | IXOFF | IXANY); /* shut off xon/xoff ctrl */
		tty.c_cflag &= ~(PARENB | PARODD);      /* shut off parity */
        tty.c_cflag |= parity;
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CRTSCTS;
		tty.c_oflag = 0;
		tty.c_lflag = 0;

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
        {
                cout << "error " << errno << "from tcsetattr";
		error = errno;
                return error;
        }
        return error;
}

/**
 * Serial Port Read 
 *
 * \param buff points to the buffer to get the input byte
 *
 * This function reads a byte from Serial port
 *
 * \return Returns the number of bytes read.
 *
 */

int readport(char *buff, int fd)
{
	int n;
	while (1) { 
	n = read(fd, buff, 1);
	if (n == -1) 
		switch(errno) {
	        	case EAGAIN: /* sleep() */ 
        		continue;
		default: break;
	}
	if (n ==0) break;
	return n;
	}
}

#endif
 
/**
 * CRC calculation
 *
 * \param buf points to the buffer that contains the data
 * \param len specifies the length of the data
 *
 * This function calculates CRC for each and every packet to 
 * be transmitted over the Serial interface.
 *
 * \return Returns the calculated CRC value.
 */

unsigned short crc16_ccitt(unsigned char *buf, int len)
{
	int crc;
	char i;
	crc = 0;

	if(len <= 0) 
	{
		cout <<"Invalid input parameters!\nCRC Calculation Fails!\n";
		return ERR_INVALID;
	}
	while (--len >= 0)
	{
        	crc = crc ^ (int) *buf++ << 8;
        	i = 8;
        	do
	        {
        	    if (crc & 0x8000)
                	crc = crc << 1 ^ 0x1021;
	            else
        	        crc = crc << 1;
	        } while(--i);
    	}
	return (crc);
}

#ifdef WINDOWS
/**
 * Xmodem File Transmit
 *
 * \param destname points to the COM Port to be connected
 * \param sname points to the file to be transferred over the COM port
 *
 * This function Transfers the file over UART using XMODEM protocol
 *
 * \return Returns 0 on success and error value on failure.
 *
 */

int xmodemFTransfer( wchar_t *destname, char *sname)
{
	SerialPort serialPort;
	ifstream ifile;
	unsigned char rxBuff[1];
#else
/**
 * Xmodem Transmit
 *
 * \param destname points to the COM Port to be connected
 * \param sname points to the file to be transferred over the COM port
 *
 * This function Transfers the file over UART using XMODEM protocol
 *
 * \return Returns 0 on success and error value on failure.
 *
 */

int xmodemFTransfer( char *sname, int fd )
{
	char rxBuff[1];
#endif	
	unsigned char txBuff[1030], src[1030], packetno = 1, ack = ACK, EoT = EOT;
	int i = 0, c =0, ret = 0, len = 0, retry = 0, bufsz = 1, crc = -1, error = 0, ktbytes = 1024, tbytes = 128;
	int srcsz = 0, maxretry = 25, inbyte = 1, txretry =16, eotretry = 20;
#ifdef WINDOWS
	if((*destname || *sname ) == NULL)
	{
		cout << "xmodemFTransfer: Invalid input parameters!" << endl;
		serialPort.clear();
		serialPort.disconnect();
		return ERR_INVALID;
	}

	ifile = file_open( sname, &srcsz); /* Opening Binary file to be copied */
	error = serialPort.connect(destname, baudRate);
	if(error < 0)
		return error;
#else

	/* Opening Binary file to be copied */
	file = fopen(sname, "rb");
	fseek(file, 0, SEEK_END);
	srcsz = ftell(file);
	fseek(file, 0, SEEK_SET);
#endif
	#ifdef DEBUG
	cout << "\nFile size " << srcsz << "bytes\n";
	#endif

	for(;;) {
		for( retry = 0; retry < txretry; ++retry) {
		#ifdef WINDOWS
			if ((serialPort.getArray(rxBuff, inbyte)) == inbyte) {
		#else
			if ( readport(&rxBuff[0], fd) == inbyte ) {
		#endif
				switch (rxBuff[0]) {
				case 'C':
                    if( FW == 1 )
                        cout << "\nFlashing Image of size " << srcsz << " bytes\n";
                    else
                        cout << "\nTransferring File of size " << srcsz << " bytes\n";
					crc = 1;
					goto start_trans;
				case NAK:
					#ifdef DEBUG
						cout << "In case NAK\n";
					#endif
					crc = 0;
					goto start_trans;
				case CAN:
					#ifdef DEBUG
						cout << "In case CAN\n";
					#endif
					#ifdef WINDOWS
					if( serialPort.getArray(rxBuff, inbyte) == inbyte)
					#else
					if( (readport(rxBuff, fd)) == inbyte)
					#endif
					{
						if (rxBuff[0] == CAN) {
							#ifdef WINDOWS
							if( (serialPort.sendArray(&ack, inbyte)) && (serialPort.sendArray(&ack, inbyte)) == inbyte )
							#else
							if( ((write(fd, &ack, inbyte)) && (write(fd, &ack, inbyte))) == inbyte )
							#endif
								cout << "Failure: Canceled by remote !!\n";
							else
								cout << " Sending ACK Failed!!\n";
							#ifdef WINDOWS
							ifile.close();
							serialPort.clear();
							serialPort.disconnect();
							#endif
							error = ERR_RCAN; /* canceled by remote */
							return error;
						}
					}
					break;
				default:
					#ifdef DEBUG
						cout << "In Default" << rxBuff[0] << endl;
					#endif
					break;
				}
			}
		}
		cout << "\nFailure:Unknown response from target! ";
		#ifdef WINDOWS
		if( ((serialPort.sendArray(&ack, inbyte)) && (serialPort.sendArray(&ack, inbyte)) && (serialPort.sendArray(&ack, inbyte))) == inbyte )
		#else
		if( ((write(fd, &ack, inbyte)) && (write(fd, &ack, inbyte)) && (write(fd, &ack, inbyte))) == inbyte )
		#endif
			cout << "Please check the connection!\n";
		else
			cout << "Sending ACK Failed!!\n";
		error = ERR_NOSYNC; /* no sync */
		#ifdef WINDOWS
		ifile.close();
		serialPort.clear();
		serialPort.disconnect();
		#else
		fclose(file);
		#endif
		return error;

		for(;;) {
			start_trans:
			txBuff[0] = STX; bufsz = ktbytes;
			txBuff[1] = packetno;
			txBuff[2] = ~packetno;
			c = srcsz - len;
			if (c > bufsz) c = bufsz;
			#ifdef WINDOWS
				ifile.read((char*)src,c);
			#else
				fread(src, inbyte, c, file);
			#endif
			if (c >= 0) {
				memset (&txBuff[3], 0, bufsz);
				if (c == 0) {
					txBuff[3] = CTRLZ;
				}
				else {
					cout <<((len*100)/srcsz) <<"% complete\r";
					#ifndef windows
					fflush(stdout);
					#endif
					memcpy (&txBuff[3], &src[0], c);
					if (c < bufsz) txBuff[3+c] = 26;
				}
				if (crc) {
					unsigned short ccrc = crc16_ccitt(&txBuff[3], bufsz);
					if( crc < 0 )
					{
						#ifdef WINDOWS
						ifile.close();
						serialPort.clear();
						serialPort.disconnect();
						#else
						fclose(file);
						#endif
						return crc;
					}
					txBuff[bufsz+3] = (ccrc>>8) & 0xFF;
					txBuff[bufsz+4] = ccrc & 0xFF;
				}
				else {
					unsigned char ccks = 0;
					for (i = 3; i < bufsz+3; ++i) {
						ccks += txBuff[i];
					}
					txBuff[bufsz+3] = ccks;
				}
				for (retry = 0; retry < maxretry; ++retry) {
						#ifdef WINDOWS
						if(serialPort.sendArray(&txBuff[i], bufsz+4+(crc?1:0)) != bufsz+4+(crc?1:0)) //Check this
						#else
						if(write(fd, &txBuff[i], bufsz+4+(crc?1:0)) != bufsz+4+(crc?1:0))
						#endif
						{
							cout <<endl << "Transmit Failed at " << len+i << " byte" <<endl;
							#ifdef WINDOWS
							ifile.close();
							serialPort.clear();
							serialPort.disconnect();
							#else
							fclose(file);
							#endif
							error = ERR_XMIT;
							return error;
						}
					#ifdef WINDOWS
					if ((serialPort.getArray(rxBuff, inbyte)) == inbyte ) {
					#else
					if ( (readport(rxBuff, fd)) == inbyte ) {
					#endif
						#ifdef DEBUG
						 cout <<endl << "Received from Rx !!" << rxBuff[0] << "Retry" << retry << endl;
						 #endif
						 switch (rxBuff[0]) {
						 case ACK:
							++packetno;
							len += bufsz;
							goto start_trans;
						 case CAN:
							#ifdef WINDOWS
							if( (serialPort.getArray(rxBuff, inbyte)) == inbyte )
							#else
							if( (readport(rxBuff, fd) ) == inbyte )
							#endif
							 {
								if (rxBuff[0] == CAN) {
									#ifdef WINDOWS
									if (serialPort.sendArray(&ack, inbyte) != inbyte)
									#else
									if (write(fd, &ack, inbyte) != inbyte)
									#endif
										cout << "Sending ACK Failed!!\n";
									cout << "\nFailure: Canceled by remote!!\n";
									#ifdef WINDOWS
									ifile.close();
									serialPort.clear();
									serialPort.disconnect();
									#else
									fclose(file);
									#endif
									error = ERR_RCAN; 
									return error; /* canceled by remote */
								}
							}
							break;
                        case FLASH_FAILURE:
                            cout << "\nFlash Programming Failed!!\n";
                            #ifdef WINDOWS
                            if (serialPort.sendArray(&ack, inbyte) != inbyte)
                            #else
                            if (write(fd, &ack, inbyte) != inbyte)
                            #endif
                                cout << "\nSending ACK Failed!!\n";
                            goto conn_close;
                            break;
						case NAK:
						default:
							break;
						 }
					 }
				}
				#ifdef WINDOWS
				if( ((serialPort.sendArray(&ack, inbyte)) && (serialPort.sendArray(&ack, inbyte)) && (serialPort.sendArray(&ack, inbyte))) == inbyte )
				#else
				if( ((write(fd, &ack, inbyte)) && (write(fd, &ack, inbyte)) && (write(fd, &ack, inbyte))) == inbyte )
				#endif
					cout << "Failure: Transmit Error!!\n";
				else
					cout << "Sending ACK Failed!!\n";
				#ifdef WINDOWS
				ifile.close();
				serialPort.clear();
				serialPort.disconnect();
				#else
				fclose(file);
				#endif
				error = ERR_XMIT; 
				return error; /* xmit error */
			}
			else {
				error = 0;
				for (retry = 0; retry < eotretry; ++retry) {
					#ifdef DEBUG
						cout << "Sending EOT\n";
					#endif
					#ifdef WINDOWS
					if (serialPort.sendArray(&EoT, inbyte) != inbyte)
					#else
					if (write(fd, &EoT, inbyte) != inbyte)
					#endif
						cout << "Sending EOT Failed!!\n";
					#ifdef WINDOWS
					if (serialPort.getArray(rxBuff, inbyte) != inbyte)
					#else
					if ( (readport(rxBuff, fd)) != inbyte)
					#endif
						cout << "ACK not received for EOT!!\n";
					if ( rxBuff[0] == ack)
					{
						#ifdef DEBUG
							{cout << "Rcvd ACK for EOT\n"; }
						#endif
                        if( FW == 0 )
                            cout <<"File Transfer complete!\n";
					}
					break;
				}
				if( FW == 1 )
				{
				for(;;)
				{
					#ifdef WINDOWS
					if (serialPort.getArray(rxBuff, inbyte) != inbyte)
					#else
					if ( (readport(rxBuff, fd)) != inbyte)
					#endif
					{
						cout << "Read Failure!!\n";
					}
					if ( rxBuff[0] == FLASH_SUCCESS)
					{
						cout << "\rFlash Programming Success!";
						cout << "\n";
						rxBuff[0] = ack;
						#ifdef WINDOWS
						if (serialPort.sendArray(&ack, inbyte) != inbyte)
						#else
						if (write(fd, &ack, inbyte) != inbyte)
						#endif
							cout << "\nSending SPI ACK Failed!!\n";
						goto conn_close;
					}
					else if ( rxBuff[0] == FLASH_FAILURE)
					{
						cout << "\nFlash Programming Failed!!\n";
						#ifdef WINDOWS
						if (serialPort.sendArray(&ack, inbyte) != inbyte)
						#else
						if (write(fd, &ack, inbyte) != inbyte)
						#endif
							cout << "\nSending ACK Failed!!\n";
						goto conn_close;
					}
				}
				}
				goto conn_close;
conn_close:
				#ifdef WINDOWS
				ifile.close();
				serialPort.clear();
				serialPort.disconnect();
				#else
	                	fclose(file);
				#endif
				error = (rxBuff[0] == ack)?0:ERR_NOACK;
				break;
			}
		}
		break;
	}
	return error;
}

#ifdef WINDOWS
/**
 * Xmodem Baudrate change
 *
 * \param destname points to the COM Port to be connected
 *
 * This function request a baudrate change over UART using XMODEM protocol.
 *
 * \return Returns 0 on success and error value on failure.
 *
 */
int getMaxBaudRate( wchar_t *destname, unsigned char *maxBaudrate )
{
	SerialPort serialPort;
    unsigned char rxBuff[1];
#else
/**
 * Xmodem Header Transmit
 *
 * This function request a baudrate change over UART using XMODEM protocol.
 *
 * \return Returns 0 on success and error value on failure.
 *
 */
int getMaxBaudRate( int fd, unsigned char *maxBaudrate )
{
    char rxBuff[1];
#endif
    unsigned char ack = ACK, EoT = EOT, nSupported = NOT_SUPPORTED_BAUDRATE;
	int error = 0, inbyte = 1, crc = 0, hsize = 12;
	unsigned short ccrc;
    unsigned char command[14];
	const char start = 'S', getCmd = GET_MAX_BAUDRATE_CMD;
    unsigned short i;

#ifdef WINDOWS
	if((*destname) == NULL)
	{
		cout << "xmodemHTransfer: Invalid input parameters!" << endl;
		return ERR_INVALID;
	}
	error = serialPort.connect(destname, BAUDRATE_0);
	if(error < 0)
		return error;
#endif

    memset (command, 0, sizeof(command));
    memcpy (command, &start, 1);
    memcpy (&command[1], &getCmd, 1);

    for (;;){
        #ifdef WINDOWS
        if ((serialPort.getArray(rxBuff, inbyte)) == inbyte)
        #else
        if ((readport(rxBuff, fd)) == inbyte)
        #endif
        {
            if (rxBuff[0] == 'C') {
                crc = 1;
                ccrc = crc16_ccitt(command, hsize);
                #ifdef DEBUG
                cout <<"crc: " <<ccrc <<endl;
                #endif
                command[hsize] = (ccrc>>8) & 0xFF;
                command[hsize+1] = ccrc & 0xFF;

                #ifdef DEBUG
                cout <<"hsize: " <<hsize <<endl;
                #endif
                #ifdef WINDOWS
                if(serialPort.sendArray(command, (hsize+2)) != (hsize+2))
                #else
                if(write(fd, command, (hsize+2)) != (hsize+2))
                #endif
                {
                    cout << "Transmit of header Failed!\n";
                    error = ERR_XMIT;
                    #ifdef WINDOWS
                        serialPort.clear();
                        serialPort.disconnect();
                    #endif
                    return error;
                }
                else
                {
                    #ifdef WINDOWS
                    if ((serialPort.getArray(rxBuff, inbyte)) != inbyte )
                    #else
                    if ( (readport(rxBuff, fd)) != inbyte )
                    #endif
                    {
                        #ifdef DEBUG
                            cout << "Received from Rx !!" << rxBuff[0] << "Retry" << retry << endl;
                        #endif
                    }
                    else {
                        if (rxBuff[0] == ACK)
                        {
                            for (i=0; i<2; i++) { //Maximum supported baudrate can be get maximum of 2 times
                                #ifdef WINDOWS
                                if ((serialPort.getArray(rxBuff, inbyte)) != inbyte)
                                #else
                                if ((readport(rxBuff, fd)) != inbyte)
                                #endif
                                {
                                    error = ERR_XMIT;
                                    #ifdef WINDOWS
                                        serialPort.clear();
                                        serialPort.disconnect();
                                    #endif
                                    return error;
                                }
                                else
                                {
                                    /* Currently, BAUDRATE_6000000 is the maximum supported baudrate supported */
                                    if (rxBuff[0] <= BAUDRATE_6000000)
                                    {
                                        if (rxBuff[0] <= MAX_SUPPORTED_BAUDRATE)
                                            break;
                                        else
                                        {
                                            #ifdef WINDOWS
                                            if (serialPort.sendArray(&nSupported, inbyte) != inbyte)
                                            #else
                                            if ( write(fd, &nSupported, inbyte)!= inbyte )
                                            #endif
                                            {
                                                cout << "Failure in transmission" << endl;
                                                #ifdef WINDOWS
                                                    serialPort.clear();
                                                    serialPort.disconnect();
                                                #endif
                                                error = ERR_XMIT;
                                                return error;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        #ifdef WINDOWS
                                        if( (serialPort.getArray(rxBuff, inbyte)) == inbyte )
                                        #else
                                        if( readport(rxBuff, fd) == inbyte )
                                        #endif
                                        {
                                            if (rxBuff[0] == CAN) {
                                                #ifdef WINDOWS
                                                if (serialPort.sendArray(&ack, inbyte) != inbyte)
                                                #else
                                                if ( write(fd, &ack, inbyte)!= inbyte )
                                                #endif
                                                    cout <<"Sending ACK Failed!!\n";
                                                cout <<"\nFailure: Canceled by remote!!\n";
                                                error = ERR_RCAN;
                                            #ifdef WINDOWS
                                                serialPort.clear();
                                                serialPort.disconnect();
                                            #endif
                                                return error; /* canceled by remote */
                                            }
                                        }
                                    }
                                }
                            }

                            if (i < 2) { //checks whether a valid baudrate received within 2times
                                *maxBaudrate = rxBuff[0];
                                #ifdef WINDOWS
                                if (serialPort.sendArray(&ack, inbyte) != inbyte)
                                #else
                                if ( write(fd, &ack, inbyte) != inbyte )
                                #endif
                                    cout << "Sending ACK Failed!!\n";
                                #ifdef WINDOWS
                                if (serialPort.sendArray(&EoT, inbyte) != inbyte)
                                #else
                                if ( write(fd, &EoT, inbyte) != inbyte )
                                #endif
                                    cout <<"Sending EOT Failed!!\n";
                                #ifdef WINDOWS
                                if (serialPort.getArray(rxBuff, inbyte) != inbyte)
                                #else
                                if (readport(rxBuff, fd) != inbyte)
                                #endif
                                {
                                    cout << "ACK not received for EOT!!\n";
                                    error = ERR_XMIT;
                                    #ifdef WINDOWS
                                        serialPort.clear();
                                        serialPort.disconnect();
                                    #endif
                                    return error;
                                }
                                else if (rxBuff[0] != ack)
                                {
                                    error = ERR_RCAN;
                                    #ifdef WINDOWS
                                        serialPort.clear();
                                        serialPort.disconnect();
                                    #endif
                                    return error; /* canceled by remote */
                                }
                                else
                                {
                                    return error;
                                }
                            }
                            else //else if CAN
                            {
                                #ifdef WINDOWS
                                if( (serialPort.getArray(rxBuff, inbyte)) == inbyte )
                                #else
                                if( readport(rxBuff, fd) == inbyte )
                                #endif
                                {
                                    if (rxBuff[0] == CAN) {
                                    #ifdef WINDOWS
                                        if (serialPort.sendArray(&ack, inbyte) != inbyte)
                                    #else
                                        if ( write(fd, &ack, inbyte)!= inbyte )
                                    #endif
                                            cout <<"Sending ACK Failed!!\n";
                                        cout <<"\nFailure: Canceled by remote!!\n";
                                        error = ERR_RCAN;
                                    #ifdef WINDOWS
                                        serialPort.clear();
                                        serialPort.disconnect();
                                    #endif
                                        return error; /* canceled by remote */
                                    }
                                }
                            }
                        }
                        else{
                            #ifdef WINDOWS
                            if( (serialPort.getArray(rxBuff, inbyte)) == inbyte )
                            #else
                            if( readport(rxBuff, fd) == inbyte )
                            #endif
                            {
                                if (rxBuff[0] == CAN) {
                                #ifdef WINDOWS
                                    if (serialPort.sendArray(&ack, inbyte) != inbyte)
                                #else
                                    if ( write(fd, &ack, inbyte)!= inbyte )
                                #endif
                                        cout <<"Sending ACK Failed!!\n";
                                    cout <<"\nFailure: Canceled by remote!!\n";
                                    error = ERR_RCAN;
                                #ifdef WINDOWS
                                    serialPort.clear();
                                    serialPort.disconnect();
                                #endif
                                    return error; /* canceled by remote */
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            #ifdef DEBUG
            cout << "Failure in sending Command packet" << endl;
            #endif
                
        }
    }

#ifdef WINDOWS
	serialPort.clear();
	serialPort.disconnect();
#endif
	return error;
}

#ifdef WINDOWS

/**
 * Xmodem Header Transmit
 *
 * \param destname points to the COM Port to be connected
 * \param sname points to the Header packet to be transferred over the COM port
 *
 * This function Transfers the Header over UART using XMODEM protocol.
 * The Header contains information about the file to be tranfered to the Flash Writer 
 * program
 *
 * \return Returns 0 on success and error value on failure.
 *
 */

int xmodemHTransfer( wchar_t *destname, unsigned char *src)
{
	SerialPort serialPort;
	unsigned char rxBuff[1], ack = ACK, EoT = EOT;

#else
/**
 * Xmodem Header Transmit
 *
 * \param src points to the Header packet to be transferred over the COM port
 *
 * This function Transfers the Header over UART using XMODEM protocol.
 * The Header contains information about the file to be tranfered to the Flash Writer 
 * program
 *
 * \return Returns 0 on success and error value on failure.
 *
 */
int xmodemHTransfer( unsigned char *src, int fd )
{
	char rxBuff[1], ack = ACK, EoT = EOT;
#endif
	int error = 0, retry = 0, txretry = 16, inbyte = 1, srcsz = 0, crc = 0, hsize = 12;
	unsigned short ccrc;
#ifdef WINDOWS
	if((*destname || *src ) == NULL)
	{
		cout << "xmodemHTransfer: Invalid input parameters!" << endl;
		return ERR_INVALID;
	}
	error = serialPort.connect(destname, BAUDRATE_0);
	if(error < 0)
		return error;
#else
	if(!(*src) )
	{
		cout << "xmodemHTransfer: Invalid input parameters!" << endl;
		return ERR_INVALID;
	}
#endif

	for(;;) {
	#ifdef WINDOWS
		if ((serialPort.getArray(rxBuff, inbyte)) == inbyte) {
	#else
		if ( (readport(rxBuff, fd)) == inbyte ) {
	#endif
			switch (rxBuff[0]) {
			case 'C':
				crc = 1;
				ccrc = crc16_ccitt(src, hsize);
#ifdef DEBUG
				cout <<"crc: " <<ccrc <<endl;
#endif
				src[hsize] = (ccrc>>8) & 0xFF;
				src[hsize+1] = ccrc & 0xFF;
				
#ifdef DEBUG
				cout <<"hsize: " <<hsize <<endl;
#endif
			#ifdef WINDOWS
				if(serialPort.sendArray(src, (hsize+2)) != (hsize+2))
			#else
				if(write(fd, src, (hsize+2)) != (hsize+2))
			#endif
				{
					cout << "Transmit of header Failed!\n";
					error = ERR_XMIT;
				#ifdef WINDOWS
					serialPort.clear();
					serialPort.disconnect();
				#endif
					return error;
				}
				else
				{
				#ifdef WINDOWS
					if ((serialPort.getArray(rxBuff, inbyte)) == inbyte ) {
				#else
					if ( (readport(rxBuff, fd)) == inbyte ) {
				#endif
						#ifdef DEBUG
							cout << "Received from Rx !!" << rxBuff[0] << "Retry" << retry << endl;
						#endif
						switch (rxBuff[0]) {
						case ACK:
							for (retry = 0; retry < txretry; ++retry) {
							#ifdef DEBUG
							cout << "Sending EOT\n";
							#endif
							#ifdef WINDOWS
							if (serialPort.sendArray(&EoT, inbyte) != inbyte)
							#else
							if ( write(fd, &EoT, inbyte) != inbyte )
							#endif
								cout <<"Sending EOT Failed!!\n";
							#ifdef WINDOWS
							if (serialPort.getArray(rxBuff, inbyte) != inbyte)
							#else
							if (readport(rxBuff, fd) != inbyte)
							#endif
								cout << "ACK not received for EOT!!\n";
							if ( rxBuff[0] == ack)
							#ifdef DEBUG
							cout << "Rcvd ACK for EOT\n";
							#endif
							break;
							}
                            break;
						case CAN:
							#ifdef WINDOWS
							if( (serialPort.getArray(rxBuff, inbyte)) == inbyte )
							#else
							if( readport(rxBuff, fd) == inbyte )
							#endif
							{
								if (rxBuff[0] == CAN) {
								#ifdef WINDOWS
									if (serialPort.sendArray(&ack, inbyte) != inbyte)
								#else
									if ( write(fd, &ack, inbyte)!= inbyte )
								#endif
										cout <<"Sending ACK Failed!!\n";
									cout <<"\nFailure: Canceled by remote!!\n";
									error = ERR_RCAN;
								#ifdef WINDOWS
									serialPort.clear();
									serialPort.disconnect();
								#endif
									return error; /* canceled by remote */
								}
							}
							break;
						case NAK:
						default:
							cout <<"NAK: Transmit of header Failed\n";
							error = ERR_XMIT;
							break;
						}
					}
				}
				break;
			default:
			#ifdef DEBUG
				cout << "In Default" << rxBuff[0] << endl;
			#endif
				continue;
			}
			break;
		}
	}
	if(flashErase && (!error))
	{
		cout << "Header Transfer Complete!!\n";
		for(;;) /* Wait for Flash Erase to complete */
		{
#ifdef WINDOWS
			if (serialPort.getArray(rxBuff, inbyte) != inbyte)
#else
			if ( (readport(rxBuff, fd)) != inbyte)
#endif
			{
				cout << "Read Failure!!\n";
			}
			if ( rxBuff[0] == FLASH_SUCCESS)
			{
				cout << "Flash Erase Success!\n";
#ifdef WINDOWS
				if (serialPort.sendArray(&ack, inbyte) != inbyte)
#else
				if (write(fd, &ack, inbyte) != inbyte)
#endif
					cout << "Sending ACK Failed!!\n";
			}
			else if ( rxBuff[0] == FLASH_FAILURE)
			{
				cout << "Flash Erase Failed!!\n";
#ifdef WINDOWS
				if (serialPort.sendArray(&ack, inbyte) != inbyte)
#else
				if (write(fd, &ack, inbyte) != inbyte)
#endif
					cout << "Sending ACK Failed!!\n";
			}
			break;
		}
	}
#ifdef WINDOWS
	serialPort.clear();
	serialPort.disconnect();
#endif
	return error;
}

/**
 * Input Validation
 *
 * \param argval contains the input argument to be validated
 *
 * This function checks for the valid Command Line Arguments
 *
 * \return Returns 0 on success and error value on failure.
 *
 */

int validate( const char *argval )
{
	int error = 0, dtype = 0, itype = 0, erLen = 0;
	/* Validate the Command Line Arguments recived */
	if( devtype == 1 )
	{
		dtype = atoi( argval );
		if( (dtype<0) || (dtype>=DEVICE_SUPPORTED) || !isdigit((int) (*argval)) )
		{
			displayVersion();
			cout << "Invalid Device Type!!\n";
			devtype++;
			displayHelp();
		}
		devtype++;
		memcpy(&def_dtype, argval, 1);
	}
	if( imgtype == 1 )
	{
		itype = atoi( argval );
		if( (itype<0) || (itype>IMAGETYPE_SUPPORTED) || !isdigit((int) (*argval)) )
		{
			displayVersion();
			cout << "Invalid Image Type!!\n";
			imgtype++;
			displayHelp();
		}
		imgtype++;
		if( itype == 0 )
			RBL = 1;
		memcpy(&def_itype, argval, 1);
	}
	if( addroff == 1 )
	{
		offset = strtol( argval, NULL, 16 );
		if( !isxdigit((int)*argval) )
		{
			displayVersion();
			cout << "Invalid Offset Value!!\n";
			addroff++;
			displayHelp();
		}
		addroff++;
	}
	if( elen == 1 )
	{
		def_elen = strtol( argval, NULL, 16 );
		if(!isxdigit((int) (*argval)) )
		{
			displayVersion();
			cout << "Invalid Erase Length!!\n";
			elen++;
			displayHelp();
		}
		elen++;
	}
	return error;
}

/**
 * Input Parser
 *
 * \param cliarg contains the parser command
 * \param cliargval contains the input argument to be validated
 *
 * This function parses the Command Line Argument and validates it
 *
 * \return Returns 0 on success and error value on failure.
 *
 */

int chparam( const char *cliarg, const char *cliargval)
{
	int err = 0;
#ifdef DEBUG
	cout<<"cliarg: " <<cliarg <<endl <<"cliargval :" <<cliargval <<endl;
#endif
	if( !(strcmp(cliarg,"-d")) )
	{
		if( devtype > 0 )
		{
			displayVersion();
			cout <<"\nDuplication of Device Type Detected!!";
			err = -1;
			return err;
		}
		else
			devtype++;
		validate(cliargval);
	}
	else if( !(strcmp(cliarg,"-i")) )
	{
		if( imgtype > 0 )
		{
			displayVersion();
			cout <<"\nDuplication of Image Type Detected!!";
			err = -1;
			return err;
		}
		else
			imgtype++;
		validate(cliargval);
	}
	else if( !(strcmp(cliarg,"-o")) )
	{
		if( addroff > 0 )
		{
			displayVersion();
			cout <<"\nDuplication of Offset Detected!!";
			err = -1;
			return err;
		}
		else
			addroff++;
		validate(cliargval);
	}
	else if( !(strcmp(cliarg,"-e")) )
	{
		if( elen > 0 )
		{
			displayVersion();
			cout <<"\nDuplication of Erase Length Detected!!";
			err = -1;
			return err;
		}
		else
			elen++;
		validate(cliargval);
	}
	else if( !(strcmp(cliarg,"-f")) )
		err = 0;
	else
		err = -1;

	return err;
}

/**
 * Serial Port Open 
 *
 * \param comm_port points to the Serial port to be opened
 *
 * This function opens the Serial port in the given configuration
 *
 * \return Returns 0 on success and error value on failure.
 *
 */

#ifndef WINDOWS
int  openport(char *comm_port, unsigned int baudrate)
{
        int error = 0;

        fdesc = open(comm_port, O_RDWR | O_NOCTTY |O_NDELAY );
        if (fdesc <0)
        {
                cout << "Error opening " << comm_port << ": "  << strerror(errno);
                error = errno;
                return error;

        }

        error = set_interface_attribs(fdesc, baudrate, 0);
        return error;
}
#endif

/**
 * FlashErase
 *
 * \param optionNames points to the options available
 * \param optionValues points to the values of the options
 * \param optionLen points to the number of the options 
 *
 * This function erases the flash memory starting from the 
 * offset value till the erase length
 *
 * \return Returns 0 on success and error value on failure.
 *
 */

int FlashErase( const char** optionNames, const char** optionValues, const int optionLen )
{
	const char **commPort, **optInName, **optInVal;
	size_t cSize;
	wchar_t* wc;
	int err = 0, i = 0;
	unsigned char header[16];
	const char start = 'S', erase = ERASE_CMD;

	flashErase++;

	for( i = 0; i < (optionLen-2) ; i+=2 ) 
	{
		optInName = (&(*optionNames))+i;
		optInVal = (&(*optionValues))+i;
		if(!(strcmp( *optInName,"-c" )))
		{
			commPort = optInVal;
		}
		else
		{
			if( chparam(*optInName, *optInVal) != 0)
				displayHelp();
		}
	}
#ifdef WINDOWS
	cSize = strlen(*commPort)+1;
	wc = new wchar_t[cSize];
	mbstowcs (wc, *commPort, cSize);
#else
	err = openport( (char *)*commPort, baudRate );
        if(err == 0)
                cout <<"Opening Port Successful!\n";
        else
        {
                cout <<"Opening Port Failed!\n";
                return err;
        }
#endif
		/* Create Header Packet */
		memset (header, 0, sizeof(header));
		memcpy(header, &start, 1);
		memcpy(&header[1], &erase, 1);
		memcpy(&header[2], &def_dtype, 1);
		memcpy(&header[3], &def_itype, 1);
		memcpy(&header[4], &offset, 4);
		memcpy(&header[8], &def_elen, 4);
		displayVersion();
		cout <<"\nErasing Flash....\n";

		#ifdef DEBUG
			cout <<"Header - " << header << endl;
		#endif

        cout << "\nTransferring Header information..\n";
#ifdef WINDOWS
		err =xmodemHTransfer( wc, header );
#else
		err = xmodemHTransfer( header, fdesc );
#endif
		if(!err)
		{
			if(!flashErase)
				cout << "Header Transfer Complete!\n";
		}
		else
#ifndef WINDOWS
		close(fdesc);
		if(!err)
		{
			if(!flashErase)
				cout << "Header Transfer Complete!\n";
		}
		else
			cout << "Header Transfer Failed!\n";
#endif
		return err;
}

/**
 * LoadImage
 *
 * \param imagePath points the path to the image file to be opened
 * \param optionNames points to the options available
 * \param optionValues points to the values of the options
 * \param optionLen points to the number of the options 
 *
 * This function loads the image from the imagePath to the flash device
 *
 * \return Returns 0 on success and error value on failure.
 *
 */

int LoadImage( const char * imagePath, const char** optionNames, const char** optionValues, const int optionLen )
{
	const char **commPort, **optInName, **optInVal;
	size_t cSize;
	wchar_t* wc;
	int err = 0, i = 0, pathLen = 0;
	unsigned char header[16];
    unsigned char supBaudRate = 0;
	const char start = 'S', program = PROGRAM_CMD, setBaudrate = SET_BAUDRATE_CMD;
    std::string sysfw_path;
    char findStr[FIND_STRING][BUFF_SIZE]={"am65xx", "j721e"};
    char *tokenStr, *tempStr;
    char *found = NULL;
    std::string fullpath = imagePath;
    int beginIdx = fullpath.find_last_of("/\\");
    std::string filename = fullpath.substr(beginIdx + 1);

#ifdef DEBUG
    if( optionValues == NULL )
        cout <<"No option values!\n";
#endif
	for( i = 0; i < (optionLen-2) ; i+=2 )
	{
		optInName = (&(*optionNames))+(i);
		optInVal = (&(*optionValues))+(i);
		if(!(strcmp( *optInName,"-c" )))
		{
			commPort = optInVal;
		}
		else
		{
#ifdef DEBUG
			cout <<"optInName: " <<*optInName <<endl <<"optInVal: " <<*optInVal <<endl;
#endif
			if( chparam(*optInName, *optInVal) != 0)
				displayHelp();
		}
	}
	if((RBL == 1) | (optionLen < 6))
	{
		displayVersion();
		cout <<"\nDownloading Flash Programmer..\n";
		RBL = 1;
		FW = 0;
	}
	else
	{
		displayVersion();
		FW = 1;
		cout <<"\nTransferring the Image to Flash Programmer..\n";
		if( addroff == 0 )
			offset = strtol( &def_off, NULL, 16 );
	}
    if (def_itype == '0')
    {
        for(i=0; i<FIND_STRING; i++)
        {
            found = strstr((char *)filename.c_str(), findStr[i]);
            if(found)
            {
                break;
            }
        }
        if(found)
        {
#ifdef DEBUG
            cout <<"\nFinding string: " <<findStr;
            cout <<endl <<"Filename=" <<filename <<endl;
#endif
            cout <<endl <<"Enabling SysFw transfer!!!\n";
        }
    }
#ifdef DEBUG
	cout <<"Device Type-" << def_dtype << endl <<"ImageType-" << def_itype << endl << "Offset-" << offset << endl;
#endif

#ifdef WINDOWS
	cSize = strlen(*commPort)+1;
	wc = new wchar_t[cSize];
	mbstowcs (wc, *commPort, cSize);
#else
	err = openport( (char *)*commPort, baudRate );
    if(err == 0)
        cout <<"Opening Port Successful!\n";
    else
    {
        cout <<"Opening Port Failed!\n";
        return err;
    }
#endif

	if( RBL )	/* Transfer Flash Writer to RBL */
	{
		FileTx:
#ifdef WINDOWS
		err =xmodemFTransfer( wc, (char *)imagePath);
#else
		err =xmodemFTransfer( (char *)imagePath, fdesc );
	if(!found)
	{
        close(fdesc);
	}
#endif
        /* System Firmware Transfer */
        if (found)
        {
            tokenStr = strtok((char *)imagePath, "/\\");
            tempStr = tokenStr;
            while (tokenStr != NULL)
            {
                tokenStr = strtok(NULL, "/\\");
                if(tokenStr !=  NULL)
                {
#ifndef WINDOWS
                    sysfw_path.append("/");
#endif
                    sysfw_path.append(tempStr);
                    sysfw_path.append("/");
                }
                else
                {
                    sysfw_path.append("sysfw.bin");
                }
                tempStr = tokenStr;
            }
#ifdef DEBUG
            cout <<endl <<"\nSysfw Filename=" <<sysfw_path <<endl;
#endif
            pathLen = sysfw_path.length();
            char sysfwPath[pathLen+1];
            strcpy(sysfwPath, sysfw_path.c_str());

            /* Create Header Packet */
            def_itype = FIRMWARE_DEVTYPE; /* Image Type is Firmware */
            memset (header, 0, sizeof(header));
            memcpy(header, &start, 1);
            memcpy(&header[1], &program, 1);
            memcpy(&header[3], &def_itype, 1);
#ifdef DEBUG
            cout <<"\nSystem Firmware Header - " << header << endl;
#endif

#ifdef WINDOWS
            err =xmodemHTransfer( wc, header );
#else
            err = xmodemHTransfer( header, fdesc );
#endif
            if(!err)
            {
                cout << "Header Transfer complete\n";
                cout << "Transferring System Firmware..";
#ifdef WINDOWS
                err =xmodemFTransfer( wc, sysfwPath);
#else
                err =xmodemFTransfer( sysfwPath, fdesc );
                close(fdesc);
#endif
            }
        }
        return err;
	}
	else	/* Transfer Files to Flash Writer */
	{
#ifdef WINDOWS
		err = getMaxBaudRate( wc, &supBaudRate );
#else
		err = getMaxBaudRate( fdesc, &supBaudRate );
#endif
        if(err)
        {
#ifndef WINDOWS
            close(fdesc);
#endif
            cout << "File Transfer Failed!\n";
            return err;
        }

        /* Create Header Packet */
		memset (header, 0, sizeof(header));
		memcpy(header, &start, 1);
		memcpy(&header[1], &setBaudrate, 1);
        memcpy(&header[2], &supBaudRate, 1);
#ifdef WINDOWS
		err = xmodemHTransfer( wc, header );
#else
		err = xmodemHTransfer( header, fdesc );
#endif

#ifdef DEBUG
        cout <<"Set BaudRate command packet - " << header << endl;
#endif
        if(err)
        {
#ifndef WINDOWS
            close(fdesc);
#endif
            cout << "File Transfer Failed!\n";
            return err;
        }

        /* Create Header Packet */
		memset (header, 0, sizeof(header));
		memcpy(header, &start, 1);
		memcpy(&header[1], &program, 1);
		memcpy(&header[2], &def_dtype, 1);
		memcpy(&header[3], &def_itype, 1);
		memcpy(&header[4], &offset, 4);

        cout << "\nTransferring Header Information..\n";
#ifdef DEBUG
        cout <<"Header - " << header << endl;
#endif

#ifdef WINDOWS
		err = xmodemHTransfer( wc, header );
#else
		err = xmodemHTransfer( header, fdesc );
#endif
        if(!err)
        {
            cout << "Header Transfer Complete!\n";
            baudRate = standardBaudRate[supBaudRate];
#ifdef DEBUG
            cout <<"BaudRate need to change - " << baudRate << endl;
#endif
#ifndef WINDOWS
            close(fdesc);
            err = openport( (char *)*commPort, baudRate );
            if(err == 0)
                    cout <<"Opening Port Successful!\n";
            else
            {
                    cout <<"Opening Port Failed!\n";
                    return err;
            }
#endif
            goto FileTx;
        }
        else
#ifndef WINDOWS
			close(fdesc);

        if(!err)
            cout << "File Transfer Complete!\n";
        else
            cout << "File Transfer Failed!\n";
#endif
		return err;
	}
}

int Init()
{
	return 0;
}

int ExecCommand( const char * commandName, const char** optionNames, const char** optionValues, const int optionLen )
{
    int retVal = 0;
    if(!strcmp(commandName,"FlashErase"))
        retVal = FlashErase( optionNames, optionValues, optionLen );
    else
        cout << "Command not supported!\n";
	return retVal;
}

int Shutdown()
{
	return 0;
}

