/**
 *  \file  fs_shell_app_utils.c
 *
 *  \brief This file implements file system shell interface.
 *
 *  \copyright Copyright (C) 2013-2018 Texas Instruments Incorporated -
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
#include "error.h"
#include "ascii_utils.h"
#include <ti/fs/fatfs/ff.h>
#include "fs_shell_app_utils.h"
#include "usb_osal.h"


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
#define FS_SHELL_APP_UTILS_DATA_BUF_SIZE   64 * (2 * 512)
/*****************************************************************************
Defines the size of the buffer that holds the command line.
******************************************************************************/
#define FS_SHELL_APP_UTILS_CMD_CMD_BUF_SIZE    512

/*****************************************************************************
Defines the size of the buffer that holds the command line.
******************************************************************************/
#define BM_LOG_BUF_SIZE (1600)

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
#define FS_SHELL_APP_UTILS_CMD_INFO_CD  "   : Change directory"
#define FS_SHELL_APP_UTILS_CMD_INFO_MKDIR  ": Create directory"
#define FS_SHELL_APP_UTILS_CMD_INFO_PWD  "  : Show current working directory"
#define FS_SHELL_APP_UTILS_CMD_INFO_RM  "   : Delete a file or an empty directory"
#define FS_SHELL_APP_UTILS_CMD_INFO_BM  "   : Benchmark USB host throughput\n"\
                                        "       bm <TestFile>\n"\
                                        "       Need at least 100MB free on your USB drive\n"

#define FS_SHELL_TERM_KEY   27U /* ESC key is used to terminate user input */
#define MAX_UINT64_VAL      (0xFFFFFFFFFFFFFFFF)
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
 *  \return  S_PASS on success else error code.
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
 *  \return  S_PASS on success else error code.
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
 *  \return  S_PASS on success else error code.
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
 *  \return  S_PASS on success else error code.
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
 *  \return  S_PASS on success else error code.
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
 *  \return  S_PASS on success else error code.
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
 *  \return  S_PASS on success else error code.
 *
 **/
int32_t FSShellAppUtilsCmdHelp(int32_t argc, char *argv[]);

/**
 *  \brief   This function implements the "BM" command.
 *
 *  \param   argc   Number of arguments.
 *  \param   argv   Arguments required to execute "bm" command.
 *                  - First argument shall be "bm".
 *                  - Second argument specifies the file 
 *                  - Ignore other arguments.
 *
 *  \return  S_PASS on success else error code.
 *
 **/
int32_t FSShellAppUtilsCmdBm(int32_t argc, char *argv[]);

/**
 *  \brief   This function corrects the entered command based on user input.
 *
 *  \param   commandBuffer  the buffer storing user entered command.
 *
 *  \return  None
 *
 **/
static void processInputCommand(uint8_t* commandBuffer);

/* extern functions */
extern void consolePrintf(const char *pcString, ...);
extern void consoleGets(uint8_t* buffer, int32_t size);
extern void consolePuts(const char *pString, int32_t size);
extern uint8_t consoleGetc(void);
extern void consolePutc(uint8_t ch);

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
#ifdef __IAR_SYSTEMS_ICC__
#pragma data_alignment=SOC_CACHELINE_SIZE
static FIL gFsShellAppUtilsReadFileObj;

#elif defined(__TMS470__)
#pragma DATA_ALIGN(gFsShellAppUtilsReadFileObj, SOC_CACHELINE_SIZE);
static FIL gFsShellAppUtilsReadFileObj;

#elif defined(gcc) || defined(_TMS320C6X) || defined(__aarch64__)
static FIL gFsShellAppUtilsReadFileObj  __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

#else
#error "Unsupported Compiler. \r\n"

#endif

/*****************************************************************************
A temporary data buffer used when manipulating file paths, or reading data
from the memory card.
******************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
#pragma data_alignment=SOC_CACHELINE_SIZE
static FIL gFsShellAppUtilsWriteFileObj;

#elif defined(__TMS470__)
#pragma DATA_ALIGN(gFsShellAppUtilsWriteFileObj, SOC_CACHELINE_SIZE);
static FIL gFsShellAppUtilsWriteFileObj;

#elif defined(gcc) || defined(_TMS320C6X) || defined(__aarch64__)
static FIL gFsShellAppUtilsWriteFileObj  __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

#else
#error "Unsupported Compiler. \r\n"

#endif

/*****************************************************************************
A temporary data buffer used when manipulating file paths, or reading data
from the memory card.
******************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
#pragma data_alignment=SOC_CACHELINE_SIZE
static char gFsShellAppUtilsTempPath[FS_SHELL_APP_UTILS_PATH_BUF_SIZE];

#elif defined(__TMS470__)
#pragma DATA_ALIGN(gFsShellAppUtilsTempPath, SOC_CACHELINE_SIZE);
static char gFsShellAppUtilsTempPath[FS_SHELL_APP_UTILS_PATH_BUF_SIZE];

#elif defined(gcc) || defined(_TMS320C6X) || defined(__aarch64__)
static char gFsShellAppUtilsTempPath[FS_SHELL_APP_UTILS_PATH_BUF_SIZE]
                      __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

#else
#error "Unsupported Compiler. \r\n"

#endif

/*****************************************************************************
A temporary data buffer used for reading data from or writing data
to the memory card.
******************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
#pragma data_alignment=SOC_CACHELINE_SIZE
static char gFsShellAppUtilsCwd[FS_SHELL_APP_UTILS_PATH_BUF_SIZE];

#elif defined(__TMS470__)
#pragma DATA_ALIGN(gFsShellAppUtilsCwd, SOC_CACHELINE_SIZE);
static char gFsShellAppUtilsCwd[FS_SHELL_APP_UTILS_PATH_BUF_SIZE];

#elif defined(gcc) || defined(_TMS320C6X) || defined(__aarch64__)
static char gFsShellAppUtilsCwd[FS_SHELL_APP_UTILS_PATH_BUF_SIZE]
                             __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

#else
#error "Unsupported Compiler. \r\n"

#endif

/*****************************************************************************
A temporary data buffer used for reading data from or writing data
to the memory card.
******************************************************************************/
#ifdef __IAR_SYSTEMS_ICC__
#pragma data_alignment=SOC_CACHELINE_SIZE
static char gFsShellAppUtilsDataBuf[FS_SHELL_APP_UTILS_DATA_BUF_SIZE];

#elif defined(__TMS470__)
#pragma DATA_ALIGN(gFsShellAppUtilsDataBuf, SOC_CACHELINE_SIZE);
static char gFsShellAppUtilsDataBuf[FS_SHELL_APP_UTILS_DATA_BUF_SIZE];

#elif defined(gcc) || defined(_TMS320C6X) || defined(__aarch64__)
static char gFsShellAppUtilsDataBuf[FS_SHELL_APP_UTILS_DATA_BUF_SIZE]
                             __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

#else
#error "Unsupported Compiler. \r\n"

#endif

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
    { "bm",       &FSShellAppUtilsCmdBm,    FS_SHELL_APP_UTILS_CMD_INFO_BM},
    { 0, 0, 0 }
};

uint8_t gFsShellAppUtilsRxBuf[UI_APP_UTILS_MAX_INPUT_SIZE];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

int32_t FSShellAppUtilsInit(void)
{

    return(FS_SHELL_APP_UTILS_CMD_STATUS_INVALID);
}

int32_t FSShellAppUtilsProcess(void)
{
    int32_t retStat = E_FAIL;
    int32_t len = 0;

    do
    {
        switch(gFsShellAppUtilsCurState)
        {
            case FS_SHELL_APP_UTILS_STATE_HELP:
            {
                /* On completion jump to next state. */
                if(FR_OK == f_opendir(&gFsShellAppUtilsDirObj, gFsShellAppUtilsCwd))
                {
                    consolePrintf("%s>", gFsShellAppUtilsCwd);
                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_READ_COMMAND;
                    retStat = S_PASS;
                }
                /* Exit on error. */
                else
                {
                    consolePrintf("%s>", "UNKNOWN");
                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_MAX;
                    retStat = E_FAIL;
                }
                break;
            }

            case FS_SHELL_APP_UTILS_STATE_READ_COMMAND:
            {
                if(FR_OK == f_opendir(&gFsShellAppUtilsDirObj, gFsShellAppUtilsCwd))
                {
                    consoleGets(gFsShellAppUtilsRxBuf, UI_APP_UTILS_MAX_INPUT_SIZE - 1U);

                    /* apply any user correction into the command */
                    processInputCommand(gFsShellAppUtilsRxBuf);

                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_EXECUTE_COMMAND;

                    retStat = S_PASS;
                }
                /* Exit on error. */
                else
                {
                    consolePrintf("%s>", "UNKNOWN");
                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_MAX;
                    retStat = E_FAIL;
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
                    retStat = S_PASS;
                }
                /* Exit on error. */
                else
                {
                    consolePrintf("%s>", "UNKNOWN");
                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_MAX;
                    retStat = E_FAIL;
                }
                break;
            }

            case FS_SHELL_APP_UTILS_STATE_MAX:
            default:
            {
                len = strlen(gFsShellAppUtilsCwd);
                if (len == 0)
                {
                    strcat(gFsShellAppUtilsCwd, "0:");
                }

                if(FR_OK == f_opendir(&gFsShellAppUtilsDirObj, gFsShellAppUtilsCwd))
                {
                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_HELP;
                    retStat = S_PASS;
                }
                else
                {
                    gFsShellAppUtilsCurState = FS_SHELL_APP_UTILS_STATE_MAX;
                    retStat = E_FAIL;
                    break;
                }
            }
        }
	} while(0);

    return retStat;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

int32_t FSShellAppUtilsCmdExecute(uint8_t *pCmdLine,
                                         fsShellAppUtilsCmdEntry_t *pCmdList)
{
    int32_t retStatus = E_FAIL;
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
                    retStatus = S_PASS;
                }

                /*
				 * The maximum number of arguments has been reached so return
                 * the error.
				 */
                else
                {
                    consolePrintf("Too many arguments for command processor!\n");
                    retStatus = E_FAIL;
                    break;
                }
            }
        }

        /* Advance to the next character in the command line. */
        pChar++;
    }

    /* If one or more arguments was found, then process the command. */
    if((S_PASS == retStatus) && (0U != argc))
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
    int32_t retStat = E_FAIL;
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

        retStat = S_PASS;
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

                        retStat = S_PASS;
                    }
                }
                else
                {
                    retStat = E_FAIL;
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
                    if (strlen(outputPath) + strlen(gFsShellAppUtilsCwd) < FS_SHELL_APP_UTILS_PATH_BUF_SIZE)
                    {
                        strcat(outputPath, gFsShellAppUtilsCwd);
                    }

                    if (strlen(outputPath)  < FS_SHELL_APP_UTILS_PATH_BUF_SIZE-1)
                    {
                        strcat(outputPath, "/");
                    }

                    if (strlen(outputPath) + strlen(inputPath) < FS_SHELL_APP_UTILS_PATH_BUF_SIZE)
                    {
                        strcat(outputPath, inputPath);
                    }

                    retStat = S_PASS;
                }
                else
                {
                    retStat = E_FAIL;
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
            consolePrintf("%c%c%c%c%c %u/%02u/%02u %02u:%02u %9uB  %s\n",
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
        consolePrintf("\n%4u File(s),%10u bytes total\n%4u Dir(s)",
                           fileCount, totalSize, dirCount);

        /* Get the free space. */
        fresult = f_getfree("/", (DWORD *)&totalSize, &pFatFs);

        /* Check for error and return if there is a problem. */
        if(FR_OK == fresult)
        {
            /* Display the amount of free space that was calculated. */
            consolePrintf(", %10uK bytes free\n", totalSize * pFatFs->csize / 2);
        }
    }

    /* Return status. */
    return fresult;
}

int32_t FSShellAppUtilsCmdRm(int32_t argc, char *argv[])
{
    int32_t retStat = E_FAIL;
    FRESULT fresult;

    if (argc <= 1)
    {
    	return S_PASS;
    }

    /*
     * Format the path of file/folder to be removed with drive and absolute path.
     */
    retStat = FSShellAppUtilsFrmtPath(argv[1U], gFsShellAppUtilsTempPath);

    if (S_PASS == retStat)
    {
        /* Remove file or directory path is in gFsShellAppUtilsTempPath. */
        fresult = f_unlink(gFsShellAppUtilsTempPath);

        /* Check status. Inform user and return. */
        if(fresult != FR_OK)
        {
            retStat = E_FAIL;
        }
    }

    /* Return status. */
    return retStat;
}

int32_t FSShellAppUtilsCmdMkDir(int32_t argc, char *argv[])
{
    int32_t retStat = E_FAIL;
    FRESULT fresult;

    if (argc <= 1)
    {
    	return S_PASS;
    }

    /*
     * Format the path of folder to be created with drive and absolute path.
     */
    retStat = FSShellAppUtilsFrmtPath(argv[1U], gFsShellAppUtilsTempPath);

    if (S_PASS == retStat)
    {
        /* Create new directory at the path in chTmpBuf. */
        fresult = f_mkdir(gFsShellAppUtilsTempPath);

        /* Check for the status of create directory.  Inform user and return. */
        if(FR_OK != fresult)
        {
            consolePrintf("mkdir: %s\n", gFsShellAppUtilsTempPath);
            retStat = E_FAIL;
        }
    }

    /* Return status. */
    return retStat;
}

int32_t FSShellAppUtilsCmdCd(int32_t argc, char *argv[])
{
    int32_t retStat = E_FAIL;
    FRESULT fresult;

    if (argc <= 1)
    {
    	return S_PASS;
    }

    /*
     * Format the path of folder to be created with drive and absolute path.
     */
    retStat = FSShellAppUtilsFrmtPath(argv[1U], gFsShellAppUtilsTempPath);

    if (S_PASS == retStat)
    {
        /*
         * At this point, a candidate new directory path is in chTmpBuf.  Try to
         * open it to make sure it is valid.
         */
        fresult = f_opendir(&gFsShellAppUtilsDirObj, gFsShellAppUtilsTempPath);

        /* If it can't be opened, then it is a bad path.  Inform user and return. */
        if(FR_OK != fresult)
        {
            consolePrintf("cd: %s\n", gFsShellAppUtilsTempPath);
            retStat = E_FAIL;
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
    consolePrintf("%s\n", gFsShellAppUtilsCwd);

    return S_PASS;
}

int32_t FSShellAppUtilsCmdCat(int32_t argc, char *argv[])
{
    FRESULT fresultRead = FR_NOT_READY;
    FRESULT fresultWrite = FR_NOT_READY;
    uint32_t bytesWrite = 0;
    uint32_t flagWrite = FALSE;
    uint32_t flagUartDirect = FALSE;
    uint32_t usBytesRead = 0;
    uint32_t flagRead = FALSE;
    int32_t retStat   = E_FAIL;
    uint32_t idx = 0;
    uint8_t  ch = 0;

    strcpy(gFsShellAppUtilsTempPath, "");

    if (argc <= 1U)
    {
    	return S_PASS;
    }

    /* check if user wants to do UART redirection:
     * cat dev.UART > <OUTPUTFILE> 
     */
    if (argc >= 2U) 
    {
        if (strcmp(argv[1U], "dev.UART") == 0)
        {
            flagUartDirect = TRUE;
        }        
    }

    /*
     * Format the path of folder to be created with drive and absolute path.
     */
    if (flagUartDirect == FALSE)
    {
        retStat = FSShellAppUtilsFrmtPath(argv[1U], gFsShellAppUtilsTempPath);

        if (S_PASS == retStat)
        {
            /* Open the file for reading. */
            fresultRead = f_open(&gFsShellAppUtilsReadFileObj, 
                                 gFsShellAppUtilsTempPath, FA_READ);

            /* If there was some problem opening the file, then return an error. */
            if(fresultRead != FR_OK)
            {
                consolePrintf("Fail to open file for read !!!!\n");
                retStat = E_FAIL;
            }
            else
            {
                flagRead = TRUE;
            }
        }
    }

    if ((S_PASS == retStat) || (flagUartDirect == TRUE))
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

                if (S_PASS == retStat)
                {
                    fresultWrite = f_open(&gFsShellAppUtilsWriteFileObj, 
                                          gFsShellAppUtilsTempPath,
                                          FA_WRITE|FA_OPEN_ALWAYS);

                    if(fresultWrite != FR_OK)
                    {
                        consolePrintf("Fail to open file for write !!!!\n");
                        retStat = E_FAIL;
                    }
                    else
                    {
                        flagWrite = TRUE;
                    }
                }
            }
        }
    }

    if ((S_PASS == retStat) && (flagUartDirect == FALSE))
    {
        /*
         * read from file and not a UART redirection
         *
         * Enter a loop to repeatedly read data from the file and display it,
         * until the end of the file is reached.
         */
        do
        {
            /*
             * Read a block of data from the file.  Read as much as can fit in
             * temporary buffer, including a space for the trailing null.
             */
            fresultRead = f_read(&gFsShellAppUtilsReadFileObj, 
                                 gFsShellAppUtilsDataBuf,
                                 sizeof(gFsShellAppUtilsDataBuf) - 1, 
                                 &usBytesRead);

            /*
             * If there was an error reading, then print a newline and return
             * error to the user.
             */
            if(fresultRead != FR_OK)
            {
                consolePrintf("Fail to read from file !!!!\n");
                retStat = E_FAIL;
            }

            /*
             * Write the data to the destination file user has selected.
             * If there was an error writing, then print a newline and return
             * error to the user.
             */
            if(TRUE == flagWrite)
            {
                fresultWrite = f_write(&gFsShellAppUtilsWriteFileObj, 
                                       gFsShellAppUtilsDataBuf,
                                       usBytesRead, &bytesWrite);

                if(fresultWrite != FR_OK)
                {
                    consolePrintf("Fail to write into file !!!!\n");
                    retStat = E_FAIL;
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
                consolePuts(gFsShellAppUtilsDataBuf, usBytesRead);
            }

            /*
             * Continue reading until less than the full number of bytes are
             * read. That means the end of the buffer was reached.
             */
        }
        while(usBytesRead == (sizeof(gFsShellAppUtilsDataBuf) - 1));
    }
    else if (flagUartDirect == TRUE)
    {
        /* handling UART redirection 
         *
         * keep reading UART until we see an ESC key
         *
         */
        consolePrintf("Type your content below. Hit ESC to finish!\n");

        idx = 0;
        do
        {   
            ch = consoleGetc();

            if (ch != FS_SHELL_TERM_KEY) /* ESC key */
            {
                /* echo the character back if it's not the ESC key */
                consolePutc(ch);

                gFsShellAppUtilsDataBuf[idx] = ch;

                idx++;

                if (idx >= FS_SHELL_APP_UTILS_DATA_BUF_SIZE)
                {
                    if(TRUE == flagWrite)
                    {
                        fresultWrite = f_write(&gFsShellAppUtilsWriteFileObj, 
                                               gFsShellAppUtilsDataBuf,
                                               idx, &bytesWrite);

                        if(fresultWrite != FR_OK)
                        {
                            consolePrintf("Fail to write into file !!!!\n");
                            retStat = E_FAIL;
                        }
                    }
                    idx = 0;
                }
            }
            else
            {
                /* we get the termination key while the buffer is not full.
                   Flush the remaining buffer out now */
                if(TRUE == flagWrite)
                {
                    fresultWrite = f_write(&gFsShellAppUtilsWriteFileObj, 
                                           gFsShellAppUtilsDataBuf,
                                           idx, &bytesWrite);

                    if(fresultWrite != FR_OK)
                    {
                        consolePrintf("Fail to write into file !!!!\n");
                        retStat = E_FAIL;
                    }
                }
                idx = 0;
            }
        }
        while(ch!= FS_SHELL_TERM_KEY);
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
            consolePrintf("Fail to close read file !!!!\n");
            retStat = E_FAIL;
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
            consolePrintf("Fail to close write file !!!!\n");
            retStat = E_FAIL;
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
    consolePrintf("\nAvailable commands\n");
    consolePrintf("------------------\n");

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
        consolePrintf("%s%s\n", pEntry->pCmd, pEntry->pHelp);

        /*
        ** Advance to the next entry in the table.
        */
        pEntry++;
    }

    /* Return success. */
    return(0);
}

#if (defined(SOC_AM65XX) || defined (SOC_J721E))
/* function to benchmark the write throughput */
static int32_t writing_bm_file(uint32_t ticksPerSec, uint32_t fileSize, uint32_t blockSize, void* memBuffer)
{
    FRESULT fresultWrite = FR_NOT_READY;

    uint32_t loopCount    = 0;
    uint32_t remainder    = 0;
    uint32_t i = 0;

    uint32_t bytesWrite = 0;
    int32_t  retStat = S_PASS;

    uint64_t cycleCnt = 0;
    float    data_rate = 0.0;

    uint64_t startTime = 0;
    uint64_t endTime = 0;
    float    timeSpent;

    loopCount = fileSize / blockSize;
    remainder = fileSize % blockSize;

    cycleCnt = 0;

    /* Open the file for writing. */
    fresultWrite = f_open(&gFsShellAppUtilsWriteFileObj, gFsShellAppUtilsTempPath,
                                                           FA_WRITE|FA_OPEN_ALWAYS);
    /* If there was some problem opening the file, then return an error. */
    if(fresultWrite != FR_OK)
    {
        consolePrintf("Fail to open file for BM write !!!!\n");
        retStat = E_FAIL;
    }

    if (S_PASS == retStat)
    {
        /*
         * enter the loop to write a 100MB file to the USB drive in chunnk of blockSize
         */

        for (i=0; i<loopCount; i++)
        {
            usb_osalStartPerfCounter();

            startTime = usb_osalGetPerfCounter();

            fresultWrite = f_write(&gFsShellAppUtilsWriteFileObj, memBuffer,
                                    blockSize, &bytesWrite);

            endTime = usb_osalGetPerfCounter();

            usb_osalStopPerfCounter();
            usb_osalClearPerfCounter();

            if(fresultWrite != FR_OK)
            {
                consolePrintf("Fail to write into BM file !!!!\n");
                retStat = E_FAIL;
            }

            if(bytesWrite != blockSize)
            {
                consolePrintf("Fail to write full block to BM file !!!!\n");
                retStat = E_FAIL;
            }
            if(endTime > startTime)
            {
                cycleCnt = cycleCnt + endTime - startTime;
            }
            else
            {
                cycleCnt = cycleCnt + endTime + (MAX_UINT64_VAL - startTime);
            }
        }

        if ((retStat == S_PASS) & (remainder > 0))
        {
            usb_osalStartPerfCounter();

            startTime = usb_osalGetPerfCounter();

            fresultWrite = f_write(&gFsShellAppUtilsWriteFileObj, memBuffer,
                                    remainder, &bytesWrite);

            endTime = usb_osalGetPerfCounter();

            usb_osalStopPerfCounter();
            usb_osalClearPerfCounter();

            if(fresultWrite != FR_OK)
            {
                consolePrintf("Fail to write into BM file !!!!\n");
                retStat = E_FAIL;
            }

            if(bytesWrite != remainder)
            {
                consolePrintf("Fail to write part of BM file !!!!\n");
                retStat = E_FAIL;
            }
            if(endTime > startTime)
            {
                cycleCnt = cycleCnt + endTime - startTime;
            }
            else
            {
                cycleCnt = cycleCnt + endTime + (MAX_UINT64_VAL - startTime);
            }
        }

        fresultWrite = f_close(&gFsShellAppUtilsWriteFileObj);

        if(fresultWrite != FR_OK)
        {
            consolePrintf("Fail to close BM write file !!!!\n");
            retStat = E_FAIL;
        }


        consolePrintf("\n\n---------------------------------------------------------------\n");

        timeSpent = (float)cycleCnt/(float)ticksPerSec;
        data_rate = fileSize/timeSpent/1024/1024;

        consolePrintf("Total Data written : %10u MB\n", fileSize/1024/1024);
        consolePrintf("BlockSize          : %10u KB\n", blockSize/1024);
        consolePrintf("Total cycles       : %10u\n", cycleCnt);
        consolePrintf("Total time         : %10.2f s\n",  timeSpent);
        consolePrintf("Writing rate       : %10.2f MB/s\n", data_rate);
    }

    return retStat;
}

/* function to benchmark the read throughput */
static int32_t reading_bm_file(uint32_t ticksPerSec, uint32_t fileSize, uint32_t blockSize, void* memBuffer)
{
    FRESULT fresultRead = FR_NOT_READY;

    uint32_t usBytesRead = 0;
    int32_t  retStat = S_PASS;
    uint32_t i = 0;

    uint64_t cycleCnt = 0;
    float    data_rate = 0.0;

    uint64_t startTime = 0;
    uint64_t endTime = 0;
    float    timeSpent;

    uint32_t loopCount    = 0;
    uint32_t remainder    = 0;

    loopCount = fileSize / blockSize;
    remainder = fileSize % blockSize;

    /* Open the file for reading. */
    fresultRead = f_open(&gFsShellAppUtilsReadFileObj, 
                            gFsShellAppUtilsTempPath, FA_READ);

    /* If there was some problem opening the file, then return an error. */
    if(fresultRead != FR_OK)
    {
        consolePrintf("Fail to open file for BM read !!!!\n");
        retStat = E_FAIL;
    }

    cycleCnt = 0;

    if (S_PASS == retStat)
    {
        /*
         * enter the loop to read a particular testFile 
         */

        for(i=0;i<loopCount;i++)
        {
            usb_osalStartPerfCounter();

            startTime = usb_osalGetPerfCounter();
            fresultRead = f_read(&gFsShellAppUtilsReadFileObj, memBuffer,
                                blockSize, &usBytesRead);

            endTime = usb_osalGetPerfCounter();

            usb_osalStopPerfCounter();
            usb_osalClearPerfCounter();

            if(fresultRead != FR_OK)
            {
                consolePrintf("Fail to read into BM file !!!!\n");
                retStat = E_FAIL;
            }

            if(usBytesRead != blockSize)
            {
                consolePrintf("Fail to read full block to BM file !!!!\n");
                retStat = E_FAIL;
            }
            if(endTime > startTime)
            {
                cycleCnt = cycleCnt + endTime - startTime;
            }
            else
            {
                cycleCnt = cycleCnt + endTime + (MAX_UINT64_VAL - startTime);
            }
        }
        if ((retStat == S_PASS) & (remainder>0))
        {
            usb_osalStartPerfCounter();

            startTime = usb_osalGetPerfCounter();

            fresultRead = f_read(&gFsShellAppUtilsReadFileObj, memBuffer,
                                remainder, &usBytesRead);


            endTime = usb_osalGetPerfCounter();

            usb_osalStopPerfCounter();
            usb_osalClearPerfCounter();

            if(fresultRead != FR_OK)
            {
                consolePrintf("Fail to read BM file !!!!\n");
                retStat = E_FAIL;
            }

            if(usBytesRead != remainder)
            {
                consolePrintf("Fail to read part of BM file !!!!\n");
                retStat = E_FAIL;
            }
            if(endTime > startTime)
            {
                cycleCnt = cycleCnt + endTime - startTime;
            }
            else
            {
                cycleCnt = cycleCnt + endTime + (MAX_UINT64_VAL - startTime);
            }
        }

        consolePrintf("---------------------------------------------------------------\n");

        timeSpent = (float)cycleCnt/(float)ticksPerSec;
        data_rate = fileSize/timeSpent/1024/1024;

        consolePrintf("Total Data Read    : %10u MB\n", fileSize/1024/1024);
        consolePrintf("BlockSize          : %10u KB\n", blockSize/1024);
        consolePrintf("Total cycles       : %10u\n", cycleCnt); 
        consolePrintf("Total time         : %10.2f s\n", timeSpent);
        consolePrintf("Reading rate       : %10.2f MB/s\n", data_rate);
    }

    fresultRead = f_close(&gFsShellAppUtilsReadFileObj);

    if(fresultRead != FR_OK)
    {
        consolePrintf("Fail to close BM read file !!!!\n");
        retStat = E_FAIL;
    }

    return retStat;
}

/* limit the benchmark tool for AM65xx for now since 
   the hardware tick counters in usb_osal only work with AM65x for now*/
#define NUM_BLOCK_SIZES 4
uint8_t bmBuffer[5*1024*1024] __attribute__ ((section (".benchmark_buffer")));
#endif


int32_t FSShellAppUtilsCmdBm(int32_t argc, char *argv[])
{
    int32_t  retStat = E_FAIL;

/* support only AM65xx for now since getting perf counter for 
   other SOCs is not yet done */
#if (defined(SOC_AM65XX) || defined (SOC_J721E))
    uint32_t ticksPerSec = 0;

    uint64_t startTime = 0;
    uint64_t endTime = 0;
    uint64_t timeDiff;

    uint32_t blockSize[NUM_BLOCK_SIZES] = {100*1024, 256*1024, 1024*1024, 5*1024*1024};
                                        /* 100K, 256K, 1MB, 5MB */

    uint32_t fileSize = 100*1024*1024; /* 100MB file used for test */
    uint32_t blkSize; 

    strcpy(gFsShellAppUtilsTempPath, "");

    if (argc <= 1)
    {
        return S_PASS;
    }


    /*
     * Format the path of folder to be created with drive and absolute path.
     */
    retStat = FSShellAppUtilsFrmtPath(argv[1U], gFsShellAppUtilsTempPath);

    consolePrintf("\nStarting throughput test\n");
 
    usb_osalInitPerfUnit();

    /* find number of ticks per second */
    consolePrintf("Calibration Start\n");

    /* 
     * delay 1 sec to find number of ticks per second
     */
    usb_osalStartPerfCounter();

    startTime = usb_osalGetPerfCounter();
    usb_osalDelayMs(1000);
    endTime = usb_osalGetPerfCounter();

    if(endTime > startTime) {
       timeDiff=endTime-startTime;
    } else {
        timeDiff = (0xFFFFFFFF - startTime) + endTime;
    }

    ticksPerSec = timeDiff;
 
    consolePrintf("Ticks per seconds = %u\n\n", ticksPerSec);
    consolePrintf("Starting measurement....\n");

    /* for each of the defined block sizes */
    for(blkSize=0;blkSize<NUM_BLOCK_SIZES;blkSize++)
    {
        if (S_PASS == retStat)
        {
            retStat = writing_bm_file(ticksPerSec, fileSize, blockSize[blkSize], bmBuffer);
        }

        if (S_PASS == retStat)
        {
            retStat = reading_bm_file(ticksPerSec, fileSize, blockSize[blkSize], bmBuffer);
        }
    }

    if (S_PASS == retStat)
    {
        consolePrintf("---------------------------------------------------------------\n");
        consolePrintf("All tests passed\n");
    }

#endif

    /* Return success. */
    return retStat;
}

/*-----------------------------------------------------------
 * applying user correction during command input
 * For example if user enters ll then backspace then s, then the function would replace l with s
 */
static void processInputCommand(uint8_t* commandBuffer)
{
    uint8_t i = 0, j=0;
    uint8_t len = strlen((char*)commandBuffer);
    uint8_t tmpBuffer[UI_APP_UTILS_MAX_INPUT_SIZE];

    while(i<len)
    {        
        if ((commandBuffer[i] != 8) && 
            (commandBuffer[i] != 0x7f)) /* not backspace or DEL key */
        {
            tmpBuffer[j] = commandBuffer[i];
            j++;
        }
        else
        {
            /* see the backspace key */
            j--;
        }
        i++;
    }
    tmpBuffer[j] = 0;
    strcpy((char*)commandBuffer, (char*)tmpBuffer);
}



