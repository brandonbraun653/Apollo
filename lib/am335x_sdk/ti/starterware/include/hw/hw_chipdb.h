/**
 *
 * \file   hw_chipdb.h
 *
 * \brief  This file contains the Chip Database APIs. This API functions are
 *         used to get the device definition information.
 *
 *   Chip DB enables the SW to scale across similar devices. The SW can query
 *   various aspects of the device using the Chip DB API and can make
 *   runtime decision. Examples of the device attributes that can be queried:
 *
 *   - Is the given resource present?
 *   - How many instances of the given module (IP) is in the device
 *   - Maximum frequency of the processing units in the device
 *   - Minimum and Maximum junction temperature of the device
 *   - Packaging type
 *   - Device revision
 *   - Security Level
 *   - and others
 *
 *   A resource in the SOC is uniquely identified using the pair
 *   (moduleID, instance).
 *   The module ID is unique for a given IP. If the same IP is present
 *   in different SoCs, they will have the same module ID. That is, module
 *   list is a global list with unique ID assigned to the list elements.
 *
 *   An SoC is defined by a list of Modules and number of instance of each
 *   module (IP). If an IP is not present in the SoC, the number of
 *   instance is zero.
 *
 *   To reiterate, the pair (moduleID, instance) uniquely identifies a
 *   SOC resource.
 *
 *
 * \version 0.0 (Aug 2013) : [AE] First version
 *
 */

/*
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef HW_CHIPDB_H_
#define HW_CHIPDB_H_


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <chipdb.h>


#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *
 * \brief Total number of devices supported by Chip DB
 *
 */
#define CHIPDB_DEVICE_COUNT               (64U)

/**
 *
 * \brief Maximum number of resources in this class of device. The actual
 *        device may have less resources than this number.
 *
 */
#define CHIPDB_RESOURCE_COUNT            (128)

/**
 *
 * \brief The size of a record (in bits) in the resource table. This
 *        is the upper limit of the number of resources supported by
 *        the Chip DB
 *
 */
#define CHIPDB_RESOURCE_RECORD_SIZE      ((CHIPDB_RESOURCE_COUNT + (32-1)) / 32)


/**
 *
 * \brief Macro to map the (moduleID, instance) pair to Resource ID.
 *
 */
#define CHIPDB_GET_RESOURCEID(moduleID, instance)   \
                                   (gChipDBResourceIDMap[moduleID] + instance)

/**
 *
 * \brief Maximum number of speed grades supported.
 *
 */
#define CHIPDB_SG_COUNT                  (26U)


/**
 *
 * \brief The number of modules in the SOC that are characterized using
 *        different speed grades.
 *
 */
#define CHIPDB_SG_MODULE_COUNT           (7U)


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/**
 *
 * \brief Chip DB Base Address table.
 *
 */
extern const uint32_t gChipDBBaseAddrTable[CHIPDB_RESOURCE_COUNT];

/**
 *
 * \brief Resource ID Map
 *
 *        The ResourceIDMap is used to map the pair (moduleID, instance) to
 *        unique resource ID. For this mapping, the number of instances of
 *        each module (IP) in a given SOC is needed. This array is defined
 *        as below:
 *
 *        gChipDBResourceIDMap[i] = 0                            when i == 0
 *                                  (gChipDBResourceIDMap[i-1] +
 *                                     num_instance_of_module(i-1))  when i > 0
 *
 *        So, this array has the resource ID of the first instance of the
 *        module. For example, say modules 0 and 1 have 3 and 2 instances
 *        respectively then the array has the following values:
 *            gChipDBResourceIDMap[0] = 0;
 *            gChipDBResourceIDMap[1] = 3;
 *            gChipDBResourceIDMap[2] = 5;
 *
 *        The mapping of the pair (moduleID, instance) to the unique resource
 *        ID is done as follows:
 *            Resource ID = gChipDBResourceIDMap[moduleID] + instance;
 *
 *        This table can also be used to get the number of instances of a
 *        module in the SOC:
 *            Number of instance = gChipDBResourceIDMap[moduleID + 1] -
 *                                   gChipDBResourceIDMap[moduleID]
 *
 *        To make the above calculation seamless for all values of moduleID,
 *        this array has the last entry as below:
 *           gChipDBResourceIDMap[CHIPDB_MOD_ID_COUNT] = CHIPDB_RESOURCE_COUNT;
 *
 *        Note that if a module is not in an SOC the instance is zero. Also,
 *        the Module ID may not be contiguous as there could be holes for
 *        IPs not relevant for a SOC. Yet these holes are represented in this
 *        table with instance = 0.
 *
 *        This Table is auto-generated.
 *
 */

extern const uint32_t gChipDBResourceIDMap[CHIPDB_MOD_ID_COUNT+1];


/**
 *
 * \brief Resource Table
 *
 *        The ResourceTable encodes the device definition. It is a bitmap that
 *        encodes if a resource is present or not. The bitmap is indexed using
 *        the SOC specific unique resource id.
 *
 *        The Table is auto-generated. The sample below assumes 4-bytes which
 *        can encode a maximum of 128 resources.
 *
 *        This Table is auto-generated.
 *
 */
extern const uint32_t
gChipDBResourceTable[CHIPDB_DEVICE_COUNT][CHIPDB_RESOURCE_RECORD_SIZE];


/**
 * \brief Speed Grade Table
 *
 *        The SpeedGrade encodes the maximum frequency allowed for a processing
 *        unit.
 *
 *        This Table is auto-generated.
 *
 */
extern const uint32_t gChipDBSpeedGrade[CHIPDB_SG_COUNT][CHIPDB_SG_MODULE_COUNT];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *
 * \brief   Map the moduleID to the processor ID used to lookup speed grade.
 *
 *          This function is auto-generated
 *
 * \param   moduleID    Unique ID that identifies a Module (IP)
 *
 * \return  The processor ID
 *
 */
uint32_t CHIPDBSpeedGradeProcID(const chipdbModuleID_t moduleID);

/**
 *
 * \brief   Is the given ModuleID is a secure IP
 *
 *          This function is auto-generated
 *
 * \param   moduleID    Unique ID that identifies a Module (IP)
 *
 * \return  Return TRUE if the given moduleID is a secure IP; FALSE
 *          otherwise.
 *
 */
uint32_t CHIPDBIsSecureModule(const chipdbModuleID_t moduleID);

#ifdef  __cplusplus
}
#endif

#endif

