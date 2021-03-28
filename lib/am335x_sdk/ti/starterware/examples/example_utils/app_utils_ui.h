/**
 *  \file  app_utils_ui.h
 *
 *  \brief This file provides structure, api, variable and macro required to
 *         use user interface example utils.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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

#ifndef UIAPPUTILS_H_
#define UIAPPUTILS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "console_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Maximum number of characters user can input. */
#define UI_APP_UTILS_MAX_INPUT_SIZE                      (80U)

/** \brief Mask bits for type of page item. */
#define UI_APP_UTILS_PAGEITEMCONFIG_TYPE_MASK            (0xF0000000U)

/** \brief Bits shift for type of page item. */
#define UI_APP_UTILS_PAGEITEMCONFIG_TYPE_SHIFT           (28U)

/** \brief Mask bits for application use cases configuration. */
#define UI_APP_UTILS_PAGEITEMCONFIG_VIEW_MASK            (0x0000000FU)

/** \brief Bits shift for application use cases configuration. */
#define UI_APP_UTILS_PAGEITEMCONFIG_VIEW_SHIFT           (0U)

/**
 *  \brief Formulate application configuration of page item with type and use case.
 *
 *  \param type       Page item type configuration.
 *  \param appUseCase Application use cases configuration for page item.
 */
#define UI_APP_UTILS_PAGEITEMCONFIG(type, view) \
    (((type << UI_APP_UTILS_PAGEITEMCONFIG_TYPE_SHIFT) & \
    UI_APP_UTILS_PAGEITEMCONFIG_TYPE_MASK)\
    | ((view << UI_APP_UTILS_PAGEITEMCONFIG_VIEW_SHIFT) & \
    UI_APP_UTILS_PAGEITEMCONFIG_VIEW_MASK))

/**
 *  \brief Formulate application configuration of page item for execute type.
 *
 *  \param appUseCase Application use cases configuration for page item.
 */
#define UI_APP_UTILS_PAGEITEMCONFIG_EXECUTE_TYPE(view) \
    UI_APP_UTILS_PAGEITEMCONFIG(UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_EXECUTE, view)

/**
 *  \brief Formulate application configuration of page item for navigation type.
 *
 *  \param appUseCase Application use cases configuration for page item.
 */
#define UI_APP_UTILS_PAGEITEMCONFIG_NAVG_TYPE(view) \
    UI_APP_UTILS_PAGEITEMCONFIG(UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_NAVG, view)

/**
 *  \brief Formulate application configuration of page item for configuration
 *         type.
 *
 *  \param appUseCase Application use cases configuration for page item.
 */
#define UI_APP_UTILS_PAGEITEMCONFIG_CONFIG_TYPE(view) \
    UI_APP_UTILS_PAGEITEMCONFIG(UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_CONFIG, view)

/** \brief Compute page item id from page index and page item index. */
#define UI_APP_UTILS_PAGEITEM_ID(pageIdx, pageItemIdx) ((pageIdx << 16U) | \
                                                                (pageItemIdx))

/** \brief Help message to navigate to parent page or home page. */
#define UI_APP_UTILS_PAGE_HELP       (" 0 - Home; (carriage return) - Back")

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Enumerates types of user interfaces.
 */
typedef enum uiAppUtilsInterfaceType
{
    UI_APP_UTILS_INTERFACE_TYPE_MIN = 0U,
    /**< Maximum configurations for user interface. */
    UI_APP_UTILS_INTERFACE_TYPE_CONSOLE = UI_APP_UTILS_INTERFACE_TYPE_MIN,
    /**< Console interface. */
    UI_APP_UTILS_INTERFACE_TYPE_MAX = UI_APP_UTILS_INTERFACE_TYPE_CONSOLE
    /**< Maximum configurations for user interface. */
} uuiAppUtilsInterfaceType_t;

/**
 *  \brief Enumerates user interface mode of operation.
 */
typedef enum uiAppUtilsConsoleMode
{
    UI_APP_UTILS_CONSOLE_MODE_MIN = 0U,
    /**< Minimum configuration for user interface. */
    UI_APP_UTILS_CONSOLE_MODE_BLOCKING = UI_APP_UTILS_CONSOLE_MODE_MIN,
    /**< Blocking user interface. */
    UI_APP_UTILS_CONSOLE_MODE_NON_BLOCKING = 1U,
    /**< Non-Blocking user interface. */
    UI_APP_UTILS_CONSOLE_MODE_MAX = UI_APP_UTILS_CONSOLE_MODE_NON_BLOCKING
    /**< Maximum configurations for user interface. */
} uiAppUtilsConsoleMode_t;

/**
 *  \brief Enumerates page item's display configurations.
 */
typedef enum uiAppUtilsPageItemViewConfig
{
    UI_APP_UTILS_PAGE_ITEM_VIEW_CONFIG_MIN = 0U,
    /**< Maximum configurations to display page item. */
    UI_APP_UTILS_PAGE_ITEM_VIEW_CONFIG_HIDE =
        UI_APP_UTILS_PAGE_ITEM_VIEW_CONFIG_MIN,
    /**< Hide page item. */
    UI_APP_UTILS_PAGE_ITEM_VIEW_CONFIG_SHOW_ALL = 1U,
    /**< Display page item with option for selection. */
    UI_APP_UTILS_PAGE_ITEM_VIEW_CONFIG_SHOW_WITHOUT_OPTION = 2U,
    /**< Display page item without option for selection. */
    UI_APP_UTILS_PAGE_ITEM_VIEW_CONFIG_MAX
    /**< Maximum configurations to display page item. */
} uiAppUtilsPageItemViewConfig_t;

/**
 *  \brief Enumerates type of page item.
 */
typedef enum uiAppUtilsPageItemTypeConfig
{
    UI_APP_UTILS_PAGE_ITEM_TYPE_CONFIG_MIN = 0U,
    /**< Maximum configurations for type of page item. */
    UI_APP_UTILS_PAGE_ITEM_TYPE_CONFIG_EXECUTE =
        UI_APP_UTILS_PAGE_ITEM_TYPE_CONFIG_MIN,
    /**< Page entry is execute type. */
    UI_APP_UTILS_PAGE_ITEM_TYPE_CONFIG_NAVG = 1U,
    /**< Page entry is of navigation type. */
    UI_APP_UTILS_PAGE_ITEM_TYPE_CONFIG_CONFIG = 2U,
    /**< Page entry is of configuration type. */
    UI_APP_UTILS_PAGE_ITEM_TYPE_CONFIG_MAX
    /**< Maximum configurations for type of page item. */
} uiAppUtilsPageItemTypeConfig_t;

/**
 *  \brief Enumerates states of user interface.
 */
typedef enum uiAppUtilsState
{
    UI_APP_UTILS_STATE_MIN = 0U,
    /**< Maximum configurations for type of page item. */
    UI_APP_UTILS_STATE_ENTRY = UI_APP_UTILS_STATE_MIN,
    /**< Page entry is execute type. */
    UI_APP_UTILS_STATE_HELP = 1U,
    /**< Page entry is of navigation type. */
    UI_APP_UTILS_STATE_READ_INPUT = 2U,
    /**< Page entry is of configuration type. */
    UI_APP_UTILS_STATE_VALIDATE_INPUT = 3U,
    /**< Page entry is of configuration type. */
    UI_APP_UTILS_STATE_EXIT = 4U,
    /**< Page entry is of configuration type. */
    UI_APP_UTILS_STATE_MAX
    /**< Maximum configurations for type of page item. */
} uiAppUtilsState_t;

/**
 *  \brief Enumerates execution status user interface.
 */
typedef enum uiAppUtilsStatus
{
    UI_APP_UTILS_STATUS_MIN = 0U,
    /**< Maximum configurations for type of page item. */
    UI_APP_UTILS_STATUS_COMPLETE = UI_APP_UTILS_STATUS_MIN,
    /**< Page entry is execute type. */
    UI_APP_UTILS_STATUS_INPROGRESS = 1U,
    /**< Page entry is of navigation type. */
    UI_APP_UTILS_STATUS_ERROR = 2U,
    /**< Page entry is of navigation type. */
    UI_APP_UTILS_STATUS_MAX = UI_APP_UTILS_STATUS_ERROR
    /**< Maximum configurations for type of page item. */
} uiAppUtilsStatus_t;

/**
 *  \brief Structure defining configuration parameters for page item.
 *
 *  \details These configurations are used to determine the type of page item
 *           and validate page item for application use cases.
 */
typedef struct uiAppUtilsPageItemConfigParams
{
    uint32_t type : 4;
    /**< Page item type. */
    uint32_t reserved : 24;
    /**< reserved bits. */
    uint32_t view : 4;
    /**< Configuration to display page item. */
} uiAppUtilsPageItemConfigParams_t;

/**
 *  \brief Structure defining configuration for page item.
 *
 *  \details These parameters are used to configure and navigate page item.
 */
typedef struct uiAppUtilsPageItemConfig
{
    uiAppUtilsPageItemConfigParams_t params;
    /**< Application configuration for page item with parameters. */
    uint32_t itemIdx;
    /**< Page or Configuration to navigate on selecting this page item. */
} uiAppUtilsPageItemConfig_t;

/**
 *  \brief Structure defining the page item list.
 *
 *  \details These parameters are used to display, configure and navigate
 *           page item.
 */
typedef struct uiAppUtilsPageItemList
{
    uiAppUtilsPageItemConfig_t *pConfig;
    /**< Configuration of page item. */
    uint8_t *pHeading;
    /**< Page item heading. */
} uiAppUtilsPageItemList_t;

/**
 *  \brief Structure defining the page entry.
 *
 *  \details These parameters are used to display and navigate page.
 */
typedef struct uiAppUtilsPageEntry
{
    uint8_t* pInfo;
    /**< Information about the page other than heading. */
    uint32_t noOfPageItems;
    /**< Number of page items in the page. */
    uiAppUtilsPageItemList_t* pPageItemsList;
    /**< List of page items in the page. */
    uint32_t backPageIdx;
    /**< Page to navigate on selecting back. */
} uiAppUtilsPageEntry_t;

/**
 *  \brief Structure defining the configuration parameters entry.
 *
 *  \details These entries are used to read the configuration parameter.
 */
typedef struct uiAppUtilsConfigParamEntry
{
    uint32_t dataType;
    /**< Data type of parameter. */
    void* variable;
    /**< Variable of the parameter. */
} uiAppUtilsConfigParamEntry_t;

/** \brief Structure defining index of page and page item. */
typedef struct uiAppUtilsIdx
{
    uint32_t page;
    /**< Index of current page. */
    uint32_t pageItem;
    /**< Index of current page item. */
} uiAppUtilsIdx_t;

/**
 *  \brief Structure defining application console interface.
 *
 *  \details These parameters are used to navigate, configure and execute the
 *           application on console interface.
 */
typedef struct uiAppUtilsConsoleInterface
{
    uint32_t opMode;
    /**< User interface operating mode. #uiAppUtilsConsoleMode_t. */
    consoleUtilsBuf_t* pRxConsoleBuf;
    /**< Buffer to store the user input. */
    uint32_t readStatus;
    /**< Status of the read. */
    uint32_t selPageItem;
    /**< Page item selected. */
    uint32_t (*pCurrentConfigDisplay) (uiAppUtilsIdx_t idx);
    /**< Display current configuration of page item. */
    uint32_t (*pConfigHelpDisplay) (uiAppUtilsIdx_t idx);
    /**< Display help information for page item configuration. */
} uiAppUtilsConsoleInterface_t;

/**
 *  \brief Structure defining application user interface.
 *
 *  \details These parameters are used to navigate, configure and execute
 *           the application.
 */
typedef struct uiAppUtilsInterface
{
    uint32_t curState;
    /**< Current state of operation. #uiAppUtilsState_t. */
    uiAppUtilsIdx_t curIdx;
    /**< Index of current item. */
    uiAppUtilsIdx_t nextIdx;
    /**< Index of next item selected. */
    uint32_t noOfPages;
    /**< Number of pages. */
    uiAppUtilsPageEntry_t *pPagesList;
    /**< List of pages. */
    uint32_t noOfConfigParams;
    /**< Number of configuration parameters. */
    uiAppUtilsConfigParamEntry_t *pConfigParamsList;
    /**< List of configuration parameters. */
    uiAppUtilsConsoleInterface_t *pConsole;
    /**< Console interface configuration. */
    uint32_t (*pUserInputValidateSet) (uiAppUtilsIdx_t idx);
    /**< Validates the user input to configure page item. */
    uint32_t (*pEntryAction) (uiAppUtilsIdx_t idx);
    /**< Action taken when enter a page or page item. */
    uint32_t (*pExitAction) (uiAppUtilsIdx_t idx);
    /**< Action taken on exit from a page or page item. */
} uiAppUtilsInterface_t;

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief   This API initializes the application user interface.
 *
 *  \param   pAppInterface Pointer to application interface structure object.
 *
 *  \retval  S_PASS Executed without an error.
 *  \retval  E_FAIL Error occurred.
 */
int32_t UIAppUtilsInit(uiAppUtilsInterface_t *pAppInterface);

/**
 *  \brief   Interface API for application user interface.
 *
 *  \details User interface performs the following.
 *           -# Help interface to select an action for execution.
 *           -# Input interface that facilitates user to select an action.
 *           -# Execute the action requested by the user.
 *
 *           Following depicts the state machine to process the user interface.
 *           -# Entry action: Perform entry action corresponding to current user
 *                            input. The action is in progress till completed.
 *           -# Update console: Update interface to facilitate next user input.
 *           -# New user input: Take new input from user and validate it. If the
 *                              new user input is not valid go-to update console
 *           -# Exit action: Perform exit action corresponding to previous user
 *                           input. The exit action sets up the context for new
 *                           new user input.
 *                    - - - - - - - - - - - - - -
 *                   |       Entry action        |
 *                    - - - - - - - - - - - - - -
 *                                |
 *                    - - - - - - - - - - - - - -
 *                   |       Update console      |<- - - -
 *                    - - - - - - - - - - - - - -         |
 *                                |                       |
 *                    - - - - - - - - - - - - - -         |
 *                   |       New user input      |        |
 *                    - - - - - - - - - - - - - -         |
 *                                |       FAIL            |
 *                                |- - - - - - - - - - - -
 *                           PASS |
 *                    - - - - - - - - - - - - - -
 *                   |       Exit action         |
 *                    - - - - - - - - - - - - - -
 *
 *  \param   pAppInterface Pointer to application interface structure object.
 *
 *  \retval  S_PASS Executed without an error.
 *  \retval  E_FAIL Error occurred.
 */
int32_t UIAppUtilsProcess(uiAppUtilsInterface_t *pAppInterface);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef UIAPPUTILS_H_ */
