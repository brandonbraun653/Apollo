/**
 *  \file  app_utils_fs_shell.h
 *
 *  \brief This file provides structure, api, variable and macro required to
 *         use user interface example utils.
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

#ifndef APP_UTILS_FS_SHELL_H_
#define APP_UTILS_FS_SHELL_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define SOC_CACHELINE_SIZE                             (64U)

/** \brief Maximum number of characters user can input. */
#define UI_APP_UTILS_MAX_INPUT_SIZE                      (80U)

/** \brief Help message to navigate to parent page or home page. */
#define UI_APP_UTILS_PAGE_HELP       (" 0 - Home; (carriage return) - Back")

/** \brief Defines maximum number of arguments that can be parsed in command line. */
#define FSSHELLAPPUTILS_CMDLINE_MAX_ARGS               (8U)

/** \brief Defines the value that is returned if the command is not found. */
#define FSSHELLAPPUTILS_CMDLINE_BAD_CMD                (-1)

/** \brief Defines the value that is returned if there are too many arguments. */
#define FSSHELLAPPUTILS_CMDLINE_TOO_MANY_ARGS          (-2)

#define FS_SHELL_APP_UTILS_CACHELINE_SIZE 32

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Enumerates execution status user interface.
 */
typedef enum fsShellAppUtilsStatus
{
    FS_SHELL_APP_UTILS_STATUS_MIN,
    /**< Maximum configurations for type of page item. */
    FS_SHELL_APP_UTILS_STATUS_COMPLETE = FS_SHELL_APP_UTILS_STATUS_MIN,
    /**< Page entry is execute type. */
    FS_SHELL_APP_UTILS_STATUS_INPROGRESS,
    /**< Page entry is of navigation type. */
    FS_SHELL_APP_UTILS_STATUS_ERROR,
    /**< Page entry is of navigation type. */
    FS_SHELL_APP_UTILS_STATUS_MAX = FS_SHELL_APP_UTILS_STATUS_ERROR
    /**< Maximum configurations for type of page item. */
} fsShellAppUtilsStatus_t;

/**
 *  \brief Structure defining application console interface.
 *
 *  These parameters are used to navigate, configure and execute the application
 *  on console interface.
 */
typedef struct fsShellAppUtilsConsoleInterface
{
    uint32_t opMode;
    /**< User interface operating mode. #fsShellAppUtilsConsoleMode_t. */
    uint8_t* pRxConsoleBuf;
    /**< Buffer to store the user input. */
    uint32_t readStatus;
    /**< Buffer to store the user input. */
} fsShellAppUtilsConsoleInterface_t;

/**
 *  \brief Enumerates configurations for type of page item.
 */
typedef enum fsShellAppUtilsState
{
    FS_SHELL_APP_UTILS_STATE_HELP,
    /**< Page entry is execute type. */
    FS_SHELL_APP_UTILS_STATE_READ_COMMAND,
    /**< Page entry is of configuration type. */
    FS_SHELL_APP_UTILS_STATE_EXECUTE_COMMAND,
    /**< Page entry is of configuration type. */
    FS_SHELL_APP_UTILS_STATE_MAX
    /**< Maximum configurations for type of page item. */
} fsShellAppUtilsState_t;

/**
 *  \brief Enumerates configurations for type of page item.
 */
typedef enum fsShellAppUtilsCmdStatus
{
    FS_SHELL_APP_UTILS_CMD_STATUS_PASS,
    /**< Page entry is execute type. */
    FS_SHELL_APP_UTILS_CMD_STATUS_TOO_MANY_ARG,
    /**< Page entry is of configuration type. */
    FS_SHELL_APP_UTILS_CMD_STATUS_FAIL,
    /**< Page entry is of configuration type. */
    FS_SHELL_APP_UTILS_CMD_STATUS_INVALID
    /**< Maximum configurations for type of page item. */
} fsShellAppUtilsCmdStatus_t;

/**
 *  \brief Structure defining the commands supported for command line operation.
 *
 *  These parameters are used to decode and execute command line entry.
 */
typedef struct fsShellAppUtilsCmdEntry
{
    const char *pCmd;
    /**< A pointer to a string containing the name of the command. */
    int32_t (*pfnCmd) (int32_t argc, char *argv[]);
    /**< A function pointer to the implementation of the command. */
    const char *pHelp;
    /**< A pointer to a string of brief help text for the command. */
} fsShellAppUtilsCmdEntry_t;

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */
extern volatile uint8_t fs_is_media_inserted;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief   This API configures mode of operation for user interface application utils.
 *
 *  \param   configType Index for Page to be displayed.
 *           Following are possible values.
 *           - FSSHELLAPPUTILSCONFIGTYPE_BLOCKING - Blocking type
 *           - FSSHELLAPPUTILSCONFIGTYPE_NON_BLOCKING - Non blocking type
 *
 *  \return  S_PASS on success else error code.
 *
 **/
int32_t FSShellAppUtilsInit(void);

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
 *          - FSSHELLAPPUTILS_CMDLINE_BAD_CMD if the command is not found,
 *          - FSSHELLAPPUTILS_CMDLINE_TOO_MANY_ARGS if there are more arguments than can be parsed.
 *          Otherwise it returns the code that was returned by the command function.
 *
 */
#ifdef MULTI_PARTITION
int32_t FSShellAppUtilsProcess(char *path);
#else
int32_t FSShellAppUtilsProcess(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* #ifndef APP_UTILS_FS_SHELL_H_ */
