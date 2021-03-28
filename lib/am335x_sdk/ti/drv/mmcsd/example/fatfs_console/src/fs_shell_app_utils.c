/**
 *  \file  fs_shell_app_utils.c
 *
 *  \brief This file implements file system shell interface.
 *
 *  \copyright Copyright (C) 2013 - 2018 Texas Instruments Incorporated -
 *             http://www.ti.com/
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/csl/tistdtypes.h>
#include "string.h"
#include "stdio.h"
#include <ti/csl/csl_error.h>
#include <ti/fs/fatfs/ff.h>
#include "MMCSD_log.h"
#include "fs_shell_app_utils.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/*****************************************************************************
Defines the size of the buffers that hold the path, or temporary data from
the memory card.  There are two buffers allocated of this size.  The buffer
size must be large enough to hold the longest expected full path name,
including the file name, and a trailing null character.
******************************************************************************/
#define FS_SHELL_APP_UTILS_PATH_BUF_SIZE   512

/* Defines size of the buffers that hold temporary data. */
#define FS_SHELL_APP_UTILS_DATA_BUF_SIZE   512
/*****************************************************************************
Defines the size of the buffer that holds the command line.
******************************************************************************/
#define FS_SHELL_APP_UTILS_CMD_CMD_BUF_SIZE    512

/*****************************************************************************
Defines the help message for cat.
******************************************************************************/
#define FS_SHELL_APP_UTILS_CMD_INFO_CAT                                            \
        "  : Show contents of a text file : cat <FILENAME> \n"                 \
                  "       Write to a file : cat <INPUTFILE> > <OUTPUTFILE> \n" \
                   "       Read from UART : cat dev.UART \n"                   \
                  "       Write from UART : cat dev.UART > <OUTPUTFILE>"
#define FS_SHELL_APP_UTILS_CMD_INFO_HELP  " : Display list of commands"
#define FS_SHELL_APP_UTILS_CMD_INFO_LS  "   : Display list of files"
#define FS_SHELL_APP_UTILS_CMD_INFO_CD     ": Change directory"
#define FS_SHELL_APP_UTILS_CMD_INFO_MKDIR  ": Create directory"
#define FS_SHELL_APP_UTILS_CMD_INFO_PWD  "  : Show current working directory"
#define FS_SHELL_APP_UTILS_CMD_INFO_RM  "   : Delete a file or an empty directory"

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief  Process a command line string into arguments and execute the command.
 *          This function will take the supplied command line string and break it
 *          up into individual arguments.  The first argument is treated as a
 *          command and is searched for in the command table. If the command is
 *          found, then the command function is called and all of the command line
 *          arguments are passed in the normal argc, argv form.
 *
 *  \param  pCmdLine points to a string that contains a command line that was
 *                  obtained by an application by some means.
 *
 *  \param  pCmdList points to a list of command entries used to process command
 *                  line that was obtained by an application by some means.
 *
 *  \return Returns the status of execution of command line.
 *          Following are possible values.
 *          - CMDLINE_BAD_CMD if the command is not found,
 *          - CMDLINE_TOO_MANY_ARGS if there are more arguments than can be parsed.
 *          Otherwise it returns the code that was returned by the command function.
 *
 */
int32_t FSShellAppUtilsCmdExecute(uint8_t *pCmdLine,
                                         fsShellAppUtilsCmdEntry_t *pCmdList);

/**
 *  \brief   This function implements the "ls" command.
 *
 *  \param   argc   Number of arguments.
 *  \param   argv   Arguments required to execute "ls" command.
 *                  - First argument shall be "ls".
 *                  - Ignore other arguments.
 *
 *  \return  CSL_SOK on success else error code.
 *
 **/
int32_t FSShellAppUtilsCmdLs(int32_t argc, char *argv[]);

/**
 *  \brief   This function implements the "cd"/"chdir" command.
 *
 *  \param   argc   Number of arguments.
 *  \param   argv   Arguments required to execute "cd"/"chdir" command.
 *                  - First argument shall be "cd"/"chdir".
 *                  - Second argument specifies the directory to be changed as
 *                    current working directory.
 *                    It shall be in one of the following format
 *                      - file or directory name that is in current directory
 *                        ("mydir").
 *                      - file or directory name that is in current drive
 *                        ("/my/path/to/my-dir").
 *                      - fully specified path of file or directory with drive
 *                        number/name ("drive:/my/path/to/my-dir").
 *                  - Ignore other arguments.
 *
 *  \return  CSL_SOK on success else error code.
 *
 **/
int32_t FSShellAppUtilsCmdCd(int32_t argc, char *argv[]);

/**
 *  \brief   This function implements the "pwd" command. It prints the current
 *           working directory.
 *
 *  \param   argc   Number of arguments.
 *  \param   argv   Arguments required to execute "pwd" command.
 *                  - First argument shall be "pwd".
 *                  - Ignore other arguments.
 *
 *  \return  CSL_SOK on success else error code.
 *
 **/
int32_t FSShellAppUtilsCmdPwd(int32_t argc, char *argv[]);

/**
 *  \brief   This function implements the "mkdir" command.
 *
 *  \param   argc   Number of arguments.
 *  \param   argv   Arguments required to execute "mkdir" command.
 *                  - First argument shall be "mkdir".
 *                  - Second argument specifies the new directory to be created.
 *                    It shall be in one of the following format
 *                      - file or directory name that is in current directory
 *                        ("mydir").
 *                      - file or directory name that is in current drive
 *                        ("/my/path/to/my-dir").
 *                      - fully specified path of file or directory with drive
 *                        number/name ("drive:/my/path/to/my-dir").
 *                  - Ignore other arguments.
 *
 *  \return  CSL_SOK on success else error code.
 *
 **/
int32_t FSShellAppUtilsCmdMkDir(int32_t argc, char *argv[]);

/**
 *  \brief   This function implements the "rm" command.
 *
 *  \param   argc   Number of arguments.
 *  \param   argv   Arguments required to execute "rm" command.
 *                  - First argument shall be "rm".
 *                  - Second argument specifies the file or working directory to
 *                    be deleted. It shall be in one of the following format
 *                      - file or directory name that is in current directory
 *                        ("my-dir-file").
 *                      - file or directory name that is in current drive
 *                        ("/my/path/to/my-dir-file").
 *                      - fully specified path of file or directory with drive
 *                        number/name ("drive:/my/path/to/my-dir-file").
 *                  - Ignore other arguments.
 *
 *  \return  CSL_SOK on success else error code.
 *
 **/
int32_t FSShellAppUtilsCmdRm(int32_t argc, char *argv[]);

/**
 *  \brief   This function implements the "cat" command.
 *
 *  \param   argc   Number of arguments.
 *  \param   argv   Arguments required to execute "cat" command.
 *                  - First argument shall be "cat".
 *                  - Second argument specifies the source of data or file to be
 *                    read from.
 *                    It shall be in one of the following format
 *                      - file name that is in current directory ("myfile").
 *                      - file that is in current drive ("/my/path/to/my-file").
 *                      - fully specified path of file with drive number/name
 *                        ("drive:/my/path/to/my-file").
 *                      - "dev.UART" to read input from UART through xmodem
 *                        protocol.
 *                  - Third argument shall be ">" to perform write operation else
 *                    read operation is performed.
 *                  - Fouth argument specifies the file to which the data read
 *                    shall be written.
 *                    It shall be in one of the following format
 *                      - file name that is in current directory ("myfile").
 *                      - file that is in current drive ("/my/path/to/my-file").
 *                      - fully specified path of file with drive number/name
 *                        ("drive:/my/path/to/my-file").
 *                  - Ignore other arguments.
 *
 *  \return  CSL_SOK on success else error code.
 *
 **/
int32_t FSShellAppUtilsCmdCat(int32_t argc, char *argv[]);

/**
 *  \brief   This function provides help information on supported commands.
 *
 *  \param   argc   Number of arguments.
 *  \param   argv   Arguments required provide help info on supported commands.
 *                  - First argument shall be "help"/"h"/"?".
 *                  - Ignore other arguments.
 *
 *  \return  CSL_SOK on success else error code.
 *
 **/
int32_t FSShellAppUtilsCmdHelp(int32_t argc, char *argv[]);

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

static DIR gFsShellAppUtilsDirObj;

static FILINFO gFsShellAppUtilsFileInfo;

volatile uint32_t gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_MAX;

/*****************************************************************************
A temporary data buffer used when manipulating file paths, or reading data
from the memory card.
******************************************************************************/
static FIL gFsShellAppUtilsReadFileObj  __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

/*****************************************************************************
A temporary data buffer used when manipulating file paths, or reading data
from the memory card.
******************************************************************************/
static FIL gFsShellAppUtilsWriteFileObj  __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

/*****************************************************************************
A temporary data buffer used when manipulating file paths, or reading data
from the memory card.
******************************************************************************/
static char gFsShellAppUtilsTempPath[FS_SHELL_APP_UTILS_PATH_BUF_SIZE]
                      __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

/*****************************************************************************
A temporary data buffer used for reading data from or writing data
to the memory card.
******************************************************************************/
static char gFsShellAppUtilsCwd[FS_SHELL_APP_UTILS_DATA_BUF_SIZE]
                             __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

/*****************************************************************************
A temporary data buffer used for reading data from or writing data
to the memory card.
******************************************************************************/
static char gFsShellAppUtilsDataBuf[FS_SHELL_APP_UTILS_DATA_BUF_SIZE]
                             __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

/*******************************************************************************
**
** This is the table that holds the command names, implementing functions, and
** brief description.
**
*******************************************************************************/
fsShellAppUtilsCmdEntry_t gFsShellAppUtilsCmdTable[] =
{
    { "help",     &FSShellAppUtilsCmdHelp,  FS_SHELL_APP_UTILS_CMD_INFO_HELP},
    { "ls",       &FSShellAppUtilsCmdLs,    FS_SHELL_APP_UTILS_CMD_INFO_LS},
    { "cd",       &FSShellAppUtilsCmdCd,    FS_SHELL_APP_UTILS_CMD_INFO_CD},
    { "mkdir",    &FSShellAppUtilsCmdMkDir, FS_SHELL_APP_UTILS_CMD_INFO_MKDIR},
    { "rm",       &FSShellAppUtilsCmdRm,    FS_SHELL_APP_UTILS_CMD_INFO_RM},
    { "pwd",      &FSShellAppUtilsCmdPwd,   FS_SHELL_APP_UTILS_CMD_INFO_PWD},
    { "cat",      &FSShellAppUtilsCmdCat,   FS_SHELL_APP_UTILS_CMD_INFO_CAT},
    { 0, 0, 0 }
};

uint8_t gFsShellAppUtilsRxBuf[80U];
extern Uint32 fatfsShellProcessFlag;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

int32_t FSShellAppUtilsInit(void)
{

    return(FS_SHELL_APP_UTILS_CMD_STATUS_INVALID);
}

int32_t FSShellAppUtilsProcess(void)
{
    uint32_t spinProcess = TRUE;
    int32_t retStat = CSL_ESYS_FAIL;
    uint8_t inputChar = 0U;
    uint8_t inputCharIdx = 0U;

    do
    {
        switch(gFsShellAppUtilsCurState)
        {
            case FS_SHELL_APP_UTILS_STATE_HELP:
            {
                /* On completion jump to next state. */
                if(FR_OK == f_opendir(&gFsShellAppUtilsDirObj, gFsShellAppUtilsCwd))
                {
                    UART_printStatus("All tests have PASSED\n");
                    MMCSD_log("%s>", gFsShellAppUtilsCwd);
                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_READ_COMMAND;
                    spinProcess = TRUE;
                    retStat = CSL_SOK;
                }
                /* Exit on error. */
                else
                {
                    MMCSD_log("%s>", "UNKNOWN");
                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_MAX;
                    spinProcess = TRUE;
                    retStat = CSL_ESYS_FAIL;
                }
                break;
            }

            case FS_SHELL_APP_UTILS_STATE_READ_COMMAND:
            {
                if(FR_OK == f_opendir(&gFsShellAppUtilsDirObj, gFsShellAppUtilsCwd))
                {
                    //scanf("%s", gFsShellAppUtilsRxBuf);
                    //UART_gets(gFsShellAppUtilsRxBuf, 80U);
                    //gets(gFsShellAppUtilsRxBuf);
                    //fflush(stdin);
                    inputCharIdx = 0;

                    do
                    {
                        /*
                        ** Read the next character from the UART.
                        */
                        inputChar = UART_getc();

                        /*
                        ** See if this character is a backspace and there is at least one
                        ** character in the input line.
                        */
                        if((inputChar == '\b') && (inputCharIdx != 0))
                        {
                            /*
                            ** Erase the last character from the input line.
                            */
                            UART_printf("\b \b");
                            inputCharIdx--;
                            gFsShellAppUtilsRxBuf[inputCharIdx] = '\0';
                        }

                        /*
                        ** See if this character is a newline.
                        */
                        else if((inputChar == '\r') || (inputChar == '\n'))
                        {
                            /*
                            ** Return to the caller.
                            */
                            UART_printf("\n");
                            break;
                        }

                        /*
                        ** See if this is a printable ASCII character.
                        */
                        else if((inputChar >= ' ') && (inputChar <= '~') &&
                                (inputCharIdx < (sizeof(gFsShellAppUtilsRxBuf) - 1)))
                        {
                            /*
                            ** Add this character to the input buffer.
                            */
                            gFsShellAppUtilsRxBuf[inputCharIdx++] = inputChar;
                            gFsShellAppUtilsRxBuf[inputCharIdx] = '\0';
                            UART_printf("%c", inputChar);
                        }
                    } while (1);

                    if(fatfsShellProcessFlag != 0)
                    {
                        gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_EXECUTE_COMMAND;
                        spinProcess = TRUE;
                        retStat = CSL_SOK;
                    }
                    else
                    {
                        gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_MAX;
                        spinProcess = TRUE;
                        break;
                    }
                }
                /* Exit on error. */
                else
                {
                    MMCSD_log("%s>", "UNKNOWN");
                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_MAX;
                    spinProcess = TRUE;
                    retStat = CSL_ESYS_FAIL;
                }
                break;
            }

            case FS_SHELL_APP_UTILS_STATE_EXECUTE_COMMAND:
            {
                /* On completion jump to next state. */
                if(FR_OK == f_opendir(&gFsShellAppUtilsDirObj, gFsShellAppUtilsCwd))
                {
                    FSShellAppUtilsCmdExecute(gFsShellAppUtilsRxBuf, gFsShellAppUtilsCmdTable);
                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_HELP;
                    spinProcess = TRUE;
                    retStat = CSL_SOK;
                }
                /* Exit on error. */
                else
                {
                    MMCSD_log("%s>", "UNKNOWN");
                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_MAX;
                    spinProcess = TRUE;
                    retStat = CSL_ESYS_FAIL;
                }
                break;
            }

            case FS_SHELL_APP_UTILS_STATE_MAX:
            default:
            {
                if(fatfsShellProcessFlag != 0)
                {
                    strcpy(gFsShellAppUtilsCwd, "0:");

                    if(FR_OK == f_opendir(&gFsShellAppUtilsDirObj, gFsShellAppUtilsCwd))
                    {
                        gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_HELP;
                        spinProcess = TRUE;
                        retStat = CSL_SOK;
                    }
                    else
                    {
                        spinProcess = TRUE;
                        gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_MAX;
                        retStat = CSL_ESYS_FAIL;
                        break;
                    }
                }
            }
        }

    } while(TRUE == spinProcess);

    return retStat;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

int32_t FSShellAppUtilsCmdExecute(uint8_t *pCmdLine,
                                         fsShellAppUtilsCmdEntry_t *pCmdList)
{
    int32_t retStatus = CSL_ESYS_FAIL;
    static uint8_t *argv[FSSHELLAPPUTILS_CMDLINE_MAX_ARGS + 1U];
    uint8_t *pChar;
    int32_t argc;
    uint32_t findArg = TRUE;

    /*
	 * Initialize the argument counter, and point to the beginning of the
     * command line string.
	 */
    argc = 0U;
    pChar = pCmdLine;

    /* Advance through the command line until a zero character is found. */
    while(*pChar)
    {
        /*
		 * If there is a space, then replace it with a zero, and set the flag
         * to search for the next argument.
		 */
        if(*pChar == ' ')
        {
            *pChar = 0;
            findArg = TRUE;
        }

        /*
         * Otherwise it is not a space, so it must be a character that is part
         * of an argument.
		 */
        else
        {
            /*
			 * If findArg is set, then that means we are looking for the start
             * of the next argument.
			 */
            if(TRUE == findArg)
            {
                /*
				 * As long as the maximum number of arguments has not been
                 * reached, then save the pointer to the start of this new arg
                 * in the argv array, and increment the count of args, argc.
				 */
                if(argc < FSSHELLAPPUTILS_CMDLINE_MAX_ARGS)
                {
                    argv[argc] = pChar;
                    argc++;
                    findArg = FALSE;
                    retStatus = CSL_SOK;
                }

                /*
				 * The maximum number of arguments has been reached so return
                 * the error.
				 */
                else
                {
                    MMCSD_log("Too many arguments for command processor!\n");
                    retStatus = CSL_ESYS_FAIL;
                    break;
                }
            }
        }

        /* Advance to the next character in the command line. */
        pChar++;
    }

    /* If one or more arguments was found, then process the command. */
    if((CSL_SOK == retStatus) && (0U != argc))
    {
        /*
		 * Search through the command table until a null command string is
         * found, which marks the end of the table.
		 */
        while(pCmdList->pCmd)
        {
            /*
			 * If this command entry command string matches argv[0], then call
             * the function for this command, passing the command line
             * arguments.
			 */
            if(!strcmp((const char *)argv[0], (const char *)pCmdList->pCmd))
            {
                retStatus = pCmdList->pfnCmd(argc, (char **)argv);
            }

            /* Not found, so advance to the next entry. */
            pCmdList++;
        }
    }

    /*
	 * Fall through to here means that no matching command was found, so return
     * an error.
	 */
    return retStatus;
}

static int32_t FSShellAppUtilsFrmtPath(char* inputPath, char* outputPath)
{
    int32_t retStat = CSL_ESYS_FAIL;
    uint32_t drvLen = 0U; /* relative path */

    /* Append the input path. */
    strcpy(outputPath, "");

    /* Look for drive separator. */
    drvLen = strcspn(inputPath, ":");

    /*
     * If path contains driver name.
     */
    if (drvLen < strlen(inputPath))
    {
        /* Append the input path. */
        strcpy(outputPath, inputPath);

        retStat = CSL_SOK;
    }
    /*
     * If the first character is /, then this is a fully specified path, and it
     * should just be used as-is.
     */
    else
    {
        /* Look for drive separator. */
        drvLen = strcspn(gFsShellAppUtilsCwd, ":");

        /*
         * If path contains driver name.
         */
        if (drvLen < strlen(gFsShellAppUtilsCwd))
        {
            if('/' == *inputPath)
            {
                /*
                 * Make sure the new path with drive number [X:] is not bigger than the
                 * cwd buffer. It need to include a drive number, separator and a
                 * trailing null character.
                 */
                if((strlen(inputPath) + drvLen + 1U + 1U) <= sizeof(gFsShellAppUtilsCwd))
                {
                    if(0U != strlen(gFsShellAppUtilsCwd))
                    {
                        /* Copy the current drive into the output buffer. */
                        strncpy(outputPath, gFsShellAppUtilsCwd, drvLen + 1U);

                        outputPath[drvLen + 1U] = '\0';

                        if(strlen(inputPath) > 1U)
                        {
                            /* Append the input path. */
                            strcat(outputPath, inputPath);
                        }

                        retStat = CSL_SOK;
                    }
                }
                else
                {
                    retStat = CSL_ESYS_FAIL;
                }
            }
            else
            {
                /*
                 * Test to make sure that when the new additional path is added on to
                 * the current path, there is room in the buffer for the full new path.
                 * It needs to include a new separator, and a trailing null character.
                 */
                if((strlen(gFsShellAppUtilsCwd) + strlen(inputPath) + 1U + 1U) <= sizeof(gFsShellAppUtilsCwd))
                {
                    /*
                     * Append the current working directory to relative path.
                     */
                    strcat(outputPath, gFsShellAppUtilsCwd);
                    strcat(outputPath, "/");
                    strcat(outputPath, inputPath);

                    retStat = CSL_SOK;
                }
                else
                {
                    retStat = CSL_ESYS_FAIL;
                }
            }
        }
        else
        {
            retStat = FALSE;
        }
    }

    return retStat;
}

int32_t FSShellAppUtilsCmdLs(int32_t argc, char *argv[])
{
    uint32_t totalSize = 0U;
    uint32_t fileCount = 0U;
    uint32_t dirCount = 0U;
    FRESULT fresult;
    FATFS *pFatFs;

    /* Open the current directory for access. */
    fresult = f_opendir(&gFsShellAppUtilsDirObj, gFsShellAppUtilsCwd);

    /* Enter loop to enumerate through all directory entries. */
    while(FR_OK == fresult)
    {
        /* Read an entry from the directory. */
        fresult = f_readdir(&gFsShellAppUtilsDirObj, &gFsShellAppUtilsFileInfo);

        /* Check for error and return if there is a problem. */
        if(FR_OK == fresult)
        {
            /* If the file name is blank, then this is the end of the listing. */
            if('\0' == gFsShellAppUtilsFileInfo.fname[0])
            {
                break;
            }

            /* If the attribute is directory, then increment the directory count. */
            if(AM_DIR == (gFsShellAppUtilsFileInfo.fattrib & AM_DIR))
            {
                dirCount++;
            }

            /*
             * Otherwise, it is a file.  Increment the file count, and add in the
             * file size to the total.
             */
            else
            {
                fileCount++;
                totalSize += gFsShellAppUtilsFileInfo.fsize;
            }

            /*
             * Print the entry information on a single line with formatting to show
             * the attributes, date, time, size, and name.
             */
            MMCSD_log("%c%c%c%c%c %u/%02u/%02u %02u:%02u %9u  %s\n",
                               (gFsShellAppUtilsFileInfo.fattrib & AM_DIR) ? 'D' : '-',
                               (gFsShellAppUtilsFileInfo.fattrib & AM_RDO) ? 'R' : '-',
                               (gFsShellAppUtilsFileInfo.fattrib & AM_HID) ? 'H' : '-',
                               (gFsShellAppUtilsFileInfo.fattrib & AM_SYS) ? 'S' : '-',
                               (gFsShellAppUtilsFileInfo.fattrib & AM_ARC) ? 'A' : '-',
                               (gFsShellAppUtilsFileInfo.fdate >> 9) + 1980,
                               (gFsShellAppUtilsFileInfo.fdate >> 5) & 15,
                                gFsShellAppUtilsFileInfo.fdate & 31,
                               (gFsShellAppUtilsFileInfo.ftime >> 11),
                               (gFsShellAppUtilsFileInfo.ftime >> 5) & 63,
                                gFsShellAppUtilsFileInfo.fsize,
                                gFsShellAppUtilsFileInfo.fname);
        }
    }

    /* Check for error and return if there is a problem. */
    if(FR_OK == fresult)
    {
        /* Print summary lines showing the file, dir, and size totals. */
        MMCSD_log("\n%4u File(s),%10u bytes total\n%4u Dir(s)",
                           fileCount, totalSize, dirCount);

        /* Get the free space. */
        fresult = f_getfree("/", (DWORD *)&totalSize, &pFatFs);

        /* Check for error and return if there is a problem. */
        if(FR_OK == fresult)
        {
            /* Display the amount of free space that was calculated. */
            MMCSD_log(", %10uK bytes free\n", totalSize * pFatFs->csize / 2);
        }
    }

    /* Return status. */
    return fresult;
}

int32_t FSShellAppUtilsCmdRm(int32_t argc, char *argv[])
{
    int32_t retStat = CSL_ESYS_FAIL;
    FRESULT fresult;

    /*
     * Format the path of file/folder to be removed with drive and absolute path.
     */
    retStat = FSShellAppUtilsFrmtPath(argv[1U], gFsShellAppUtilsTempPath);

    if (CSL_SOK == retStat)
    {
        /* Remove file or directory path is in gFsShellAppUtilsTempPath. */
        fresult = f_unlink(gFsShellAppUtilsTempPath);

        /* Check status. Inform user and return. */
        if(fresult != FR_OK)
        {
            retStat = CSL_ESYS_FAIL;
        }
    }

    /* Return status. */
    return retStat;
}

int32_t FSShellAppUtilsCmdMkDir(int32_t argc, char *argv[])
{
    int32_t retStat = CSL_ESYS_FAIL;
    FRESULT fresult;

    /*
     * Format the path of folder to be created with drive and absolute path.
     */
    retStat = FSShellAppUtilsFrmtPath(argv[1U], gFsShellAppUtilsTempPath);

    if (CSL_SOK == retStat)
    {
        /* Create new directory at the path in chTmpBuf. */
        fresult = f_mkdir(gFsShellAppUtilsTempPath);

        /* Check for the status of create directory.  Inform user and return. */
        if(FR_OK != fresult)
        {
            MMCSD_log("mkdir: %s\n", gFsShellAppUtilsTempPath);
            retStat = CSL_ESYS_FAIL;
        }
    }

    /* Return status. */
    return retStat;
}

int32_t FSShellAppUtilsCmdCd(int32_t argc, char *argv[])
{
    int32_t retStat = CSL_ESYS_FAIL;
    FRESULT fresult;

    /*
     * Format the path of folder to be created with drive and absolute path.
     */
    retStat = FSShellAppUtilsFrmtPath(argv[1U], gFsShellAppUtilsTempPath);

    if (CSL_SOK == retStat)
    {
        /*
         * At this point, a candidate new directory path is in chTmpBuf.  Try to
         * open it to make sure it is valid.
         */
        fresult = f_opendir(&gFsShellAppUtilsDirObj, gFsShellAppUtilsTempPath);

        /* If it can't be opened, then it is a bad path.  Inform user and return. */
        if(FR_OK != fresult)
        {
            MMCSD_log("cd: %s\n", gFsShellAppUtilsTempPath);
            retStat = CSL_ESYS_FAIL;
        }

        /* Otherwise, it is a valid new path, so copy it into the CWD. */
        else
        {
            strncpy(gFsShellAppUtilsCwd, gFsShellAppUtilsTempPath, sizeof(gFsShellAppUtilsCwd));
        }
    }

    /* Return status. */
    return retStat;
}

int32_t FSShellAppUtilsCmdPwd(int32_t argc, char *argv[])
{
    /* Print the CWD to the console. */
    MMCSD_log("%s\n", gFsShellAppUtilsCwd);

    return CSL_SOK;
}

int32_t FSShellAppUtilsCmdCat(int32_t argc, char *argv[])
{
    FRESULT fresultRead = FR_NOT_READY;
    FRESULT fresultWrite = FR_NOT_READY;
    uint32_t bytesWrite = 0;
    uint32_t flagWrite = FALSE;
    uint32_t usBytesRead = 0;
    uint32_t flagRead = FALSE;
    int32_t retStat = CSL_ESYS_FAIL;

    strcpy(gFsShellAppUtilsTempPath, "");

    /*
     * Format the path of folder to be created with drive and absolute path.
     */
    retStat = FSShellAppUtilsFrmtPath(argv[1U], gFsShellAppUtilsTempPath);

    if (CSL_SOK == retStat)
    {
        /* Open the file for reading. */
        fresultRead = f_open(&gFsShellAppUtilsReadFileObj, gFsShellAppUtilsTempPath, FA_READ);

        /* If there was some problem opening the file, then return an error. */
        if(fresultRead != FR_OK)
        {
            MMCSD_log("Fail to open file for read !!!!\n");
            retStat = CSL_ESYS_FAIL;
        }
        else
        {
            flagRead = TRUE;
        }
    }

    if (CSL_SOK == retStat)
    {
        /*
         * Check for arguments if requested for copy to another file.
         * Copy the current path to the temporary buffer for new file creation.
         */
        if(argc >= 4)
        {
            if(0U == strcmp(argv[2], ">"))
            {
                strcpy(gFsShellAppUtilsTempPath, "");

                /*
                 * Format the path of folder to be created with drive and absolute path.
                 */
                retStat = FSShellAppUtilsFrmtPath(argv[3U], gFsShellAppUtilsTempPath);

                if (CSL_SOK == retStat)
                {
                    fresultWrite = f_open(&gFsShellAppUtilsWriteFileObj, gFsShellAppUtilsTempPath,
                                                               FA_WRITE|FA_OPEN_ALWAYS);

                    if(fresultWrite != FR_OK)
                    {
                        MMCSD_log("Fail to open file for write !!!!\n");
                        retStat = CSL_ESYS_FAIL;
                    }
                    else
                    {
                        flagWrite = TRUE;
                    }
                }
            }
        }
    }

    if (CSL_SOK == retStat)
    {
        /*
         * Enter a loop to repeatedly read data from the file and display it,
         * until the end of the file is reached.
         */
        do
        {
            /*
             * Read a block of data from the file.  Read as much as can fit in
             * temporary buffer, including a space for the trailing null.
             */
            fresultRead = f_read(&gFsShellAppUtilsReadFileObj, gFsShellAppUtilsDataBuf,
                                 sizeof(gFsShellAppUtilsDataBuf) - 1, &usBytesRead);

            /*
             * If there was an error reading, then print a newline and return
             * error to the user.
             */
            if(fresultRead != FR_OK)
            {
                MMCSD_log("Fail to read from file !!!!\n");
                retStat = CSL_ESYS_FAIL;
            }

            /*
             * Write the data to the destination file user has selected.
             * If there was an error writing, then print a newline and return
             * error to the user.
             */
            if(TRUE == flagWrite)
            {
                fresultWrite = f_write(&gFsShellAppUtilsWriteFileObj, gFsShellAppUtilsDataBuf,
                                       usBytesRead, &bytesWrite);

                if(fresultWrite != FR_OK)
                {
                    MMCSD_log("Fail to write into file !!!!\n");
                    retStat = CSL_ESYS_FAIL;
                }
            }
            else

            {
                /*
                 * Null terminate the last block that was read to make it a null
                 * terminated string that can be used with printf.
                 */
                gFsShellAppUtilsDataBuf[usBytesRead] = 0;

                /* Print the last chunk of the file that was received. */
                MMCSD_log("%s",gFsShellAppUtilsDataBuf);
            }

            /*
             * Continue reading until less than the full number of bytes are
             * read. That means the end of the buffer was reached.
             */
        }
        while(usBytesRead == (sizeof(gFsShellAppUtilsDataBuf) - 1));
    }

	/*
	 * Close the Read file.
	 * If there was an error writing, then print a newline and return the
	 * error to the user.
	 */
	if(TRUE == flagRead)
	{
		fresultRead = f_close(&gFsShellAppUtilsReadFileObj);

		if(fresultRead != FR_OK)
		{
            MMCSD_log("Fail to close read file !!!!\n");
            retStat = CSL_ESYS_FAIL;
		}
	}

	/*
	 * Close the Write file.
	 * If there was an error writing, then print a newline and return the
	 * error to the user.
	 */
	if(TRUE == flagWrite)
	{
		fresultWrite = f_close(&gFsShellAppUtilsWriteFileObj);

		if(fresultWrite != FR_OK)
		{
            MMCSD_log("Fail to close write file !!!!\n");
            retStat = CSL_ESYS_FAIL;
		}
	}

    /* Return success. */
    return retStat;
}

int32_t FSShellAppUtilsCmdHelp(int32_t argc, char *argv[])
{
    fsShellAppUtilsCmdEntry_t *pEntry;

    /*
    ** Print some header text.
    */
    MMCSD_log("\nAvailable commands\n");
    MMCSD_log("------------------\n");

    /*
    ** Point at the beginning of the command table.
    */
    pEntry = &gFsShellAppUtilsCmdTable[0];

    /*
    ** Enter a loop to read each entry from the command table.  The end of the
    ** table has been reached when the command name is NULL.
    */
    while(pEntry->pCmd)
    {
        /*
        ** Print the command name and the brief description.
        */
        MMCSD_log("%s%s\n", pEntry->pCmd, pEntry->pHelp);

        /*
        ** Advance to the next entry in the table.
        */
        pEntry++;
    }

    /* Return success. */
    return(0);
}
