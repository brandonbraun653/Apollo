/**
 *  \file  app_utils_ui.c
 *
 *  \brief This file implements user interface example utils.
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "error.h"
#include "types.h"
#include "app_utils_ui.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Help message to navigate to parent page or home page. */
#define UI_APP_UTILS_PAGE_HELP       (" 0 - Home; (carriage return) - Back")

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief   This function displays help of page or page item.
 *
 *  \param   pAppInterface Pointer to application interface structure object.
 *
 *  \retval  S_PASS Executed without an error.
 *  \retval  E_FAIL Error occurred.
 */
static uint32_t UiAppUtilsHelpDisplay(uiAppUtilsInterface_t *pAppInterface);

/**
 *  \brief   Action to be performed on selection of page or page item.
 *
 *  \param   pAppInterface Pointer to application interface structure object.
 *
 *  \retval  status        Current status of given user interface takes values
 *                         #uiAppUtilsStatus_t.
 */
static int32_t UiAppUtilsEntryAction(uiAppUtilsInterface_t *pAppInterface);

/**
 *  \brief   Action to be performed on exit of page or page item.
 *
 *  \param   pAppInterface Pointer to application interface structure object.
 *
 *  \retval  S_PASS Executed without an error.
 *  \retval  E_FAIL Error occurred.
 */
static int32_t UiAppUtilsExitAction(uiAppUtilsInterface_t *pAppInterface);

/**
 *  \brief   Read input from console to navigate or configure a page item.
 *
 *  \param   pAppInterface Pointer to application interface structure object.
 *
 *  \retval  S_PASS Executed without an error.
 *  \retval  E_FAIL Error occurred.
 */
static int32_t UiAppUtilsReadInput(uiAppUtilsInterface_t *pAppInterface);

/**
 *  \brief   Validates configuration of page item provided by user.
 *
 *  \param   pAppInterface Pointer to application interface structure object.
 *
 *  \retval  S_PASS Executed without an error.
 *  \retval  E_FAIL Error occurred.
 */
static
    int32_t UiAppUtilsUserInputValidate(uiAppUtilsInterface_t *pAppInterface);

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

int32_t UIAppUtilsInit(uiAppUtilsInterface_t *pAppInterface)
{
    int32_t retStat = E_FAIL;
    uiAppUtilsIdx_t curIdx = {0U, 0U};
    uiAppUtilsPageEntry_t *pCurPage = NULL;

    /* Validate input parameters */
    if(NULL != pAppInterface)
    {
        if(0U != pAppInterface->noOfPages)
        {
            curIdx.page = pAppInterface->curIdx.page;

            if(curIdx.page < pAppInterface->noOfPages)
            {
                *pCurPage = pAppInterface->pPagesList[curIdx.page];

                if(NULL != pCurPage)
                {
                    if(0U != pCurPage->noOfPageItems)
                    {
                        retStat = S_PASS;
                    }
                }
            }
        }
    }

    /* Initialize user interface utils */
    if(S_PASS == retStat)
    {
        pAppInterface->curIdx.page = curIdx.page;
        pAppInterface->curIdx.pageItem = pCurPage->noOfPageItems;
        pAppInterface->nextIdx.page = curIdx.page;
        pAppInterface->nextIdx.pageItem = pCurPage->noOfPageItems;
        pAppInterface->pConsole->selPageItem = pCurPage->noOfPageItems;
        pAppInterface->curState = UI_APP_UTILS_STATE_ENTRY;
    }

    return retStat;
}

int32_t UIAppUtilsProcess(uiAppUtilsInterface_t *pAppInterface)
{
    int32_t retStat = E_FAIL;
    uiAppUtilsIdx_t curIdx = {0U, 0U};
    uiAppUtilsPageEntry_t *pCurPage = NULL;

    if(NULL != pAppInterface)
    {
        retStat = S_PASS;
        uint32_t spinProcess = TRUE;
        int32_t status = pAppInterface->curState;

        while(TRUE == spinProcess)
        {
            /* Validate input parameters */
            if(0U != pAppInterface->noOfPages)
            {
                curIdx.page = pAppInterface->curIdx.page;

                if(curIdx.page < pAppInterface->noOfPages)
                {
                    *pCurPage = pAppInterface->pPagesList[curIdx.page];

                    if(NULL != pCurPage)
                    {
                        if(0U != pCurPage->noOfPageItems)
                        {
                            retStat= S_PASS;
                        }
                    }
                }
            }

            if(S_PASS == retStat)
            {
                switch(pAppInterface->curState)
                {
                    /*
                     * Performs the entry action. Entry action is non-blocking
                     * process checked every time on the process
                     *
                     */
                    case UI_APP_UTILS_STATE_ENTRY:
                    {
                        status = UiAppUtilsEntryAction(pAppInterface);

                        /* On completion jump to next state. */
                        if(UI_APP_UTILS_STATUS_COMPLETE == status)
                        {
                            pAppInterface->curState = UI_APP_UTILS_STATE_HELP;
                            spinProcess = FALSE;
                        }
                        /* Loop till entry action is complete. */
                        else if(UI_APP_UTILS_STATUS_INPROGRESS == status)
                        {
                            spinProcess = TRUE;
                        }
                        /* Exit on error. */
                        else
                        {
                            pAppInterface->curState = UI_APP_UTILS_STATE_MAX;
                            spinProcess = FALSE;
                            retStat = E_FAIL;
                        }
                        break;
                    }

                    case UI_APP_UTILS_STATE_HELP:
                    {
                        retStat = UiAppUtilsHelpDisplay(pAppInterface);

                        /* On completion jump to next state. */
                        if(S_PASS == retStat)
                        {
                            pAppInterface->curState =
                                UI_APP_UTILS_STATE_READ_INPUT;
                            spinProcess = FALSE;
                        }
                        /* Exit on error. */
                        else
                        {
                            pAppInterface->curState = UI_APP_UTILS_STATE_MAX;
                            spinProcess = FALSE;
                            retStat = E_FAIL;
                        }
                        break;
                    }

                    case UI_APP_UTILS_STATE_READ_INPUT:
                    {
                        retStat = UiAppUtilsReadInput(pAppInterface);

                        if(S_PASS == retStat)
                        {
                            /* On completion jump to next state. */
                            if(CONSOLE_UTILS_READ_STATUS_TERMINATE == status)
                            {
                                pAppInterface->curState =
                                    UI_APP_UTILS_STATE_EXIT;
                                spinProcess = FALSE;
                            }
                            /* Loop till read input action is complete. */
                            else if
                                (CONSOLE_UTILS_READ_STATUS_CONTINUE == status)
                            {
                                spinProcess = TRUE;
                            }
                            else
                            {
                                pAppInterface->curState =
                                    UI_APP_UTILS_STATE_HELP;
                                spinProcess = FALSE;
                            }
                        }
                        /* Exit on error. */
                        else
                        {
                            pAppInterface->curState = UI_APP_UTILS_STATE_MAX;
                            spinProcess = FALSE;
                            retStat = E_FAIL;
                        }
                        break;
                    }

                    case UI_APP_UTILS_STATE_VALIDATE_INPUT:
                    {
                        retStat = UiAppUtilsUserInputValidate(pAppInterface);

                        /* On completion jump to next state. */
                        if(S_PASS == retStat)
                        {
                            pAppInterface->curState = UI_APP_UTILS_STATE_EXIT;
                            spinProcess = FALSE;
                        }
                        /* Exit on error. */
                        else
                        {
                            pAppInterface->curState = UI_APP_UTILS_STATE_HELP;
                            spinProcess = FALSE;
                            retStat = E_FAIL;
                        }
                        break;
                    }

                    case UI_APP_UTILS_STATE_EXIT:
                    {
                        retStat = UiAppUtilsExitAction(pAppInterface);

                        /* On completion jump to next state. */
                        if(S_PASS == retStat)
                        {
                            pAppInterface->curState = UI_APP_UTILS_STATE_ENTRY;
                            spinProcess = TRUE;
                        }
                        /* Exit on error. */
                        else
                        {
                            pAppInterface->curState = UI_APP_UTILS_STATE_MAX;
                            spinProcess = FALSE;
                            retStat = E_FAIL;
                        }
                        break;
                    }

                    case UI_APP_UTILS_STATE_MAX:
                    default:
                    {
                        spinProcess = FALSE;
                        pAppInterface->curState = UI_APP_UTILS_STATE_MAX;
                        retStat = E_FAIL;
                        break;
                    }
                }
            }
        }
    }
    return retStat;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static uint32_t UiAppUtilsHelpDisplay(uiAppUtilsInterface_t *pAppInterface)
{
    int32_t retStat= E_FAIL;
    uint32_t idx = 0U;
    uint32_t virtIdx = 0U;
    uint32_t viewConfig = UI_APP_UTILS_PAGEITEM_VIEW_CONFIG_MAX;
    uint32_t typeConfig = UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_MAX;
    uiAppUtilsPageEntry_t *pCurPage = NULL;
    uiAppUtilsPageItemList_t *pCurPageItemList = NULL;
    uiAppUtilsPageItemConfig_t curPageItemConfig;
    uiAppUtilsIdx_t curIdx = {0U, 0U};

    curIdx.page = pAppInterface->curIdx.page;
    *pCurPage = pAppInterface->pPagesList[curIdx.page];
    curIdx.pageItem = pAppInterface->curIdx.pageItem;

    if(curIdx.pageItem == pCurPage->noOfPageItems)
    {
        /* Display current page information. */
        CONSOLEUtilsPrintf("%s\n", pCurPage->pInfo);

        /* Display the entries of page. */
        for(idx = 0U;
            ((S_PASS == retStat) && (idx < pCurPage->noOfPageItems));
            idx++)
        {
            curIdx.pageItem = idx;
            pCurPageItemList = pCurPage->pPageItemsList;

            /* Check for valid page item. */
            if(NULL != pCurPageItemList)
            {
                curPageItemConfig = pCurPageItemList->pConfig[idx];
                retStat= S_PASS;
            }

            /* Validate the page item configuration. */
            if(S_PASS == retStat)
            {
                viewConfig = curPageItemConfig.params.view;
                typeConfig = curPageItemConfig.params.type;

                if((UI_APP_UTILS_PAGEITEM_VIEW_CONFIG_MAX == viewConfig) ||
                    (UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_MAX == typeConfig))
                {
                    retStat= E_FAIL;
                }
            }

            if(S_PASS == retStat)
            {
                /* Display page item if not configured ad hidden. */
                if(UI_APP_UTILS_PAGEITEM_VIEW_CONFIG_HIDE != viewConfig)
                {
                    /* Provide index to select page item. */
                    if(UI_APP_UTILS_PAGEITEM_VIEW_CONFIG_SHOW_WITHOUT_OPTION
                        != viewConfig)
                    {
                        virtIdx++;
                        CONSOLEUtilsPrintf("%2d. ", &virtIdx);
                    }
                    /* Index is not provided to page item. */
                    else
                    {
                        CONSOLEUtilsPrintf("    ");
                    }

                    CONSOLEUtilsPrintf("%s", pCurPageItemList->pHeading[idx]);

                    /* Display the current configuration of page item. */
                    if(UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_CONFIG != typeConfig)
                    {
                        CONSOLEUtilsPrintf(" :- ");
                        pAppInterface->pConsole->pCurrentConfigDisplay(curIdx);
                    }

                    CONSOLEUtilsPrintf("\n");
                }
            }
        }
    }
    else if(curIdx.pageItem < pCurPage->noOfPageItems)
    {
        /* Display the help to configure page item. */
        retStat= pAppInterface->pConsole->pConfigHelpDisplay(curIdx);
    }
    else
    {
        /* Invalid page item. */
        retStat= E_FAIL;
    }

    return retStat;
}

static int32_t UiAppUtilsEntryAction(uiAppUtilsInterface_t *pAppInterface)
{
    int32_t retStat= UI_APP_UTILS_STATUS_ERROR;
    uiAppUtilsIdx_t curIdx = {0U, 0U};
    uiAppUtilsPageEntry_t *pCurPage = NULL;

    curIdx.page = pAppInterface->curIdx.page;
    *pCurPage = pAppInterface->pPagesList[curIdx.page];
    curIdx.pageItem = pAppInterface->curIdx.pageItem;
    retStat= pAppInterface->pEntryAction(curIdx);

    return retStat;
}

static int32_t UiAppUtilsExitAction(uiAppUtilsInterface_t *pAppInterface)
{
    int32_t retStat= E_FAIL;
    uint32_t typeConfig = UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_MAX;
    uiAppUtilsIdx_t curIdx = {0U, 0U};
    uiAppUtilsPageEntry_t *pCurPage = NULL;
    uiAppUtilsPageItemList_t *pCurPageItemList = NULL;
    uiAppUtilsPageItemConfig_t curPageItemConfig;

    curIdx.page = pAppInterface->curIdx.page;
    *pCurPage = pAppInterface->pPagesList[curIdx.page];
    curIdx.pageItem = pAppInterface->curIdx.pageItem;
    retStat= pAppInterface->pExitAction(curIdx);

    /* Update page and page item. */
    if(S_PASS == retStat)
    {
        /* For configuration and execute type page item. */
        if((UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_CONFIG == typeConfig) ||
            (UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_EXECUTE == typeConfig))
        {
            pAppInterface->curIdx.pageItem = pCurPage->noOfPageItems;
            pAppInterface->pConsole->selPageItem = pCurPage->noOfPageItems;
        }
        /* For navigation type page item. */
        else if(UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_NAVG == typeConfig)
        {
            /* On selecting Home. */
            if(pAppInterface->pConsole->selPageItem == pCurPage->noOfPageItems)
            {
                curIdx.page = 0U;
                *pCurPage = pAppInterface->pPagesList[curIdx.page];
            }
            /* On selecting page item. */
            else if
                (pAppInterface->pConsole->selPageItem < pCurPage->noOfPageItems)
            {
                *pCurPageItemList = pCurPage->pPageItemsList[curIdx.pageItem];
                curIdx.page = curPageItemConfig.itemIdx;
                curIdx.pageItem = pCurPage->noOfPageItems;
                *pCurPage = pAppInterface->pPagesList[curIdx.page];
            }
            /* Go back. */
            else
            {
                curIdx.page = pCurPage->backPageIdx;
                *pCurPageItemList = pCurPage->pPageItemsList[curIdx.pageItem];
                curIdx.pageItem = curPageItemConfig.itemIdx;
                *pCurPage = pAppInterface->pPagesList[curIdx.page];
            }

            /* Update page and page item index. */
            if(S_PASS == retStat)
            {
                pAppInterface->curIdx.page = curIdx.page;
                pAppInterface->curIdx.pageItem = pCurPage->noOfPageItems;
                pAppInterface->nextIdx.page = curIdx.page;
                pAppInterface->nextIdx.pageItem = pCurPage->noOfPageItems;
                pAppInterface->pConsole->selPageItem = pCurPage->noOfPageItems;
            }
        }
        /* Invalid page item type. */
        else
        {
            retStat= E_FAIL;
        }
    }

    return retStat;
}

static int32_t UiAppUtilsReadInput(uiAppUtilsInterface_t *pAppInterface)
{
    int32_t retStat= E_FAIL;
    uint32_t configParamIdx = 0U;
    uint32_t idx = 0U;
    uint32_t typeConfig = UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_MAX;
    uint32_t dataType = CONSOLE_UTILS_DATA_TYPE_MAX;
    uiAppUtilsPageEntry_t *pCurPage = NULL;
    uiAppUtilsPageItemList_t *pCurPageItemList = NULL;
    uiAppUtilsConfigParamEntry_t *pConfigParam = NULL;
    uiAppUtilsPageItemConfig_t curPageItemConfig;
    uiAppUtilsIdx_t curIdx = {0U, 0U};
    void *pVar = NULL;

    curIdx.page = pAppInterface->curIdx.page;
    *pCurPage = pAppInterface->pPagesList[curIdx.page];
    curIdx.pageItem = pAppInterface->curIdx.pageItem;

    /* Read the selection of page item on navigation page. */
    if(curIdx.pageItem == pCurPage->noOfPageItems)
    {
        retStat= CONSOLEUtilsGetNonBlockingInput(
            pAppInterface->pConsole->pRxConsoleBuf,
            &pAppInterface->pConsole->selPageItem,
            CONSOLE_UTILS_DATA_TYPE_UNSIGN_DECIMAL,
            &pAppInterface->pConsole->readStatus);
    }
    /* Read the configuration of page item. */
    else if(curIdx.pageItem < pCurPage->noOfPageItems)
    {
        pCurPageItemList = pCurPage->pPageItemsList;

        /* Check for valid page item. */
        if(NULL != pCurPageItemList)
        {
            curPageItemConfig = pCurPageItemList->pConfig[idx];
            retStat = S_PASS;
        }

        /* Validate the configuration of page item. */
        if(S_PASS == retStat)
        {
            typeConfig = curPageItemConfig.params.type;

            if(UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_CONFIG == typeConfig)
            {
                if(curPageItemConfig.itemIdx < pAppInterface->noOfConfigParams)
                {
                    configParamIdx = curPageItemConfig.itemIdx;

                    if(NULL != pAppInterface->pConfigParamsList)
                    {
                        *pConfigParam = pAppInterface->pConfigParamsList[configParamIdx];

                        if(NULL != pConfigParam->variable)
                        {
                            pVar = pConfigParam->variable;

                            if(0U == pConfigParam->dataType)
                            {
                                dataType = pConfigParam->dataType;
                                retStat= S_PASS;
                            }
                        }
                    }
                }
            }
        }

        /* Read user input. */
        if(S_PASS == retStat)
        {
            retStat= CONSOLEUtilsGetNonBlockingInput(
                pAppInterface->pConsole->pRxConsoleBuf, pVar, dataType,
                &pAppInterface->pConsole->readStatus);

        }
    }
    else
    {
        retStat= E_FAIL;
    }

    return retStat;
}

static int32_t UiAppUtilsUserInputValidate(uiAppUtilsInterface_t *pAppInterface)
{
    int32_t retStat= E_FAIL;
    uint32_t idx = 0U;
    uint32_t virtIdx = 0U;
    uint32_t viewConfig = UI_APP_UTILS_PAGEITEM_VIEW_CONFIG_MAX;
    uint32_t typeConfig = UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_MAX;
    uiAppUtilsIdx_t curIdx = {0U, 0U};
    uiAppUtilsPageEntry_t *pCurPage = NULL;
    uiAppUtilsPageItemList_t *pCurPageItemList = NULL;
    uiAppUtilsPageItemConfig_t curPageItemConfig;

    curIdx.page = pAppInterface->curIdx.page;
    *pCurPage = pAppInterface->pPagesList[curIdx.page];
    curIdx.pageItem = pAppInterface->curIdx.pageItem;

    if(curIdx.pageItem == pCurPage->noOfPageItems)
    {
        if(pAppInterface->pConsole->selPageItem >= pCurPage->noOfPageItems)
        {
            retStat= E_FAIL;
        }

        for(idx = 0U;
            ((S_PASS == retStat) && (idx < pCurPage->noOfPageItems));
            idx++)
        {
            pCurPageItemList = pCurPage->pPageItemsList;

            /* Check for valid page item. */
            if(NULL != pCurPageItemList)
            {
                curPageItemConfig = pCurPageItemList->pConfig[idx];
                retStat = S_PASS;
            }

            if(S_PASS == retStat)
            {
                viewConfig = curPageItemConfig.params.view;
                typeConfig = curPageItemConfig.params.type;

                if((UI_APP_UTILS_PAGEITEM_VIEW_CONFIG_MAX == viewConfig) ||
                    (UI_APP_UTILS_PAGEITEM_TYPE_CONFIG_MAX == typeConfig))
                {
                    retStat= E_FAIL;
                }
            }

            if(S_PASS == retStat)
            {
                if(UI_APP_UTILS_PAGEITEM_VIEW_CONFIG_HIDE != viewConfig)
                {
                    if(UI_APP_UTILS_PAGEITEM_VIEW_CONFIG_SHOW_WITHOUT_OPTION
                        != viewConfig)
                    {
                        virtIdx++;
                    }
                }
            }
        }

        if(S_PASS == retStat)
        {
            if(pAppInterface->pConsole->selPageItem > virtIdx)
            {
                retStat= E_FAIL;
            }
        }

        if(E_FAIL == retStat)
        {
            pAppInterface->pConsole->selPageItem = pCurPage->noOfPageItems;
        }
    }
    else if(curIdx.pageItem < pCurPage->noOfPageItems)
    {
        retStat= pAppInterface->pUserInputValidateSet(curIdx);
    }
    else
    {
        retStat= E_FAIL;
    }

    return retStat;
}
