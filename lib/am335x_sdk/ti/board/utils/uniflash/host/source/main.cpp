/**
 * \file  main.cpp
 *
 * \brief Main Function
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

/**
 * Display Help
 *
 * \param None
 *
 * This function displays help menu and exits the program.
 *
 * \return None
 *
 */

void displayHelp( void )
{
#ifdef WINDOWS
	cout << "\nUsage:" << endl << "dslite.bat --mode processors -c <COM_Port> -f <Path_to_the_file_to_be_transfered> -d <Device_Type> -i <Image_Type> -e <erase_length -o <Offset>\
                                                                        \nDevice_Type:\n0 - NAND\n1 - SPI\n2 - QSPI\n3 - OSPI\n4 - eMMC\n5 - HyperFlash\n6 - UFS\
                                                                        \nImage_Type:\n0 - Flash\n1 - MLO\n2 - Uboot\n3 - UImage\n4 - Firmware\n5 - Custom Image\
																		\nerase_length:Length in Bytes\
																		\nNote: File Path should not be specified in case of Flash Erase"<< endl;
#else
	cout << "\nUsage:" << endl << "sudo dslite.sh --mode processors -c <COM_Port> -f <Path_to_the_file_to_be_transfered> -d <Device_Type> -i <Image_Type> -e <erase_length -o <Offset>\
                                                                        \nDevice_Type:\n0 - NAND\n1 - SPI\n2 - QSPI\n3 - OSPI\n4 - eMMC\n5 - HyperFlash\n6 - UFS\
                                                                        \nImage_Type:\n0 - Flash\n1 - MLO\n2 - Uboot\n3 - UImage\n4 - Firmware\n5 - Custom Image\
																		\nerase_length:Length in Bytes\
																		\nNote: File Path should not be specified in case of Flash Erase"<< endl;
#endif
	exit(1);
}

/**
 * Display Version
 *
 * \param None
 *
 * This function displays the version number of the Uniflash Tool.
 *
 * \return None
 *
 */
void displayVersion( void )
{
	cout <<"\n----------------------------------------------------------------------------";
	cout <<"\nProcessorSDKSerialFlash CLI Tool";
	cout <<"\nCopyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/";
	cout <<"\nVersion " <<VERSION;
	cout <<"\n----------------------------------------------------------------------------";
}

/**
 * MAIN
 *
 * \param argc points the number of command line arguments
 * \param argv points to the command line arguments
 *
 * This is the main function
 *
 * \return Returns 0 on success and error value on failure.
 *
 */

int main(int argc,const char *argv[])
{
	int argmin = 5, argmax = 11, i = 0, e_argmin = 7, e_argmax = 9, retVal = 0;
    const char *eraseCommand = "FlashErase";

	if((argc == 1) || !(strcmp(argv[1],"-h")))
	{
		displayVersion();
		cout<<"\nDisplaying Help..\n";
		displayHelp();
	}

	for( i = 1; i < argc; i++ )
	{
		if( !(strcmp(argv[i],"-e")) )/* Check if erase option is selected */
		{
			if(i == (argc - 1))
			{
				displayVersion();
				cout <<"\nSpecify Erase Length!!";
				displayHelp();
			}
			if( (!(argc % 2)) | (argc > e_argmax) )
			{
				displayVersion();
				cout <<"\nErase:Invalid Input Paramaters!!";
				displayHelp();
			}
			/* Check for Image Type argument in case of Flash Erase */
			for( i = 2; i < argc; i++ ) 
			{
				if( (!strcmp(argv[i],"-i")) || (!strcmp(argv[i],"-f")))
				{
					displayVersion();
					cout <<"\nImage Type/File Name not required for Flash Erase!!";
					displayHelp();
				}
			}
            retVal = ExecCommand( eraseCommand, &argv[1], &argv[2], argc );
			return(retVal);
		}
	}
	if( (argc < argmin) || (argc > argmax) || !(argc % 2) )
	{
		displayVersion();
		cout <<"\nParameter Missing! Invalid Input Paramaters!!";
		displayHelp();
	}
	/* Parsing Command Line Arguments to get the File Path */
	for( i = 1; i < argc; i++ ) 
	{
		if(!(strcmp(argv[i],"-f")))
		{
			break;
		}
	}
	LoadImage( argv[i+1], &argv[1], &argv[2], argc );

	return(1);
}