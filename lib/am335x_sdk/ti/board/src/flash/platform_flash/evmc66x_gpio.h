/*
 * Copyright (c) 2011-2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

 /**
 *
 * \file	evmc66x_gpio.h
 *
 * \brief	This file is the header	file for GPIO module
 *
 ******************************************************************************/

#ifndef	_EVMC66X_GPIO_H_
#define	_EVMC66X_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************
 * Defines and Macros
 ************************/

/** GPIO port 0 */
#define GPIO_PORT_0				   (CSL_GPIO_0)
/** GPIO port 1 */
#define GPIO_PORT_1			       (CSL_GPIO_1)

/** GPIO pin number 0 */
#define GPIO_PIN_0    (0)
/** GPIO pin number 1 */
#define GPIO_PIN_1    (1)
/** GPIO pin number 2 */
#define GPIO_PIN_2    (2)
/** GPIO pin number 3 */
#define GPIO_PIN_3    (3)
/** GPIO pin number 4 */
#define GPIO_PIN_4    (4)
/** GPIO pin number 5 */
#define GPIO_PIN_5    (5)
/** GPIO pin number 6 */
#define GPIO_PIN_6    (6)
/** GPIO pin number 7 */
#define GPIO_PIN_7    (7)
/** GPIO pin number 8 */
#define GPIO_PIN_8    (8)
/** GPIO pin number 9 */
#define GPIO_PIN_9    (9)
/** GPIO pin number 10 */
#define GPIO_PIN_10    (10)
/** GPIO pin number 11 */
#define GPIO_PIN_11    (11)
/** GPIO pin number 12 */
#define GPIO_PIN_12    (12)
/** GPIO pin number 13 */
#define GPIO_PIN_13    (13)
/** GPIO pin number 14 */
#define GPIO_PIN_14    (14)
/** GPIO pin number 15 */
#define GPIO_PIN_15    (15)
/** GPIO pin number 16 */
#define GPIO_PIN_16    (16)
/** GPIO pin number 17 */
#define GPIO_PIN_17    (17)
/** GPIO pin number 18 */
#define GPIO_PIN_18    (18)
/** GPIO pin number 19 */
#define GPIO_PIN_19    (19)
/** GPIO pin number 20 */
#define GPIO_PIN_20    (20)
/** GPIO pin number 21 */
#define GPIO_PIN_21    (21)
/** GPIO pin number 22 */
#define GPIO_PIN_22    (22)
/** GPIO pin number 23 */
#define GPIO_PIN_23    (23)
/** GPIO pin number 24 */
#define GPIO_PIN_24    (24)
/** GPIO pin number 25 */
#define GPIO_PIN_25    (25)
/** GPIO pin number 26 */
#define GPIO_PIN_26    (26)
/** GPIO pin number 27 */
#define GPIO_PIN_27    (27)
/** GPIO pin number 28 */
#define GPIO_PIN_28    (28)
/** GPIO pin number 29 */
#define GPIO_PIN_29    (29)
/** GPIO pin number 30 */
#define GPIO_PIN_30    (30)
/** GPIO pin number 31 */
#define GPIO_PIN_31    (31)
/** GPIO pin number 32 */
#define GPIO_PIN_32    (32)
/** GPIO pin number 33 */
#define GPIO_PIN_33    (33)
/** GPIO pin number 34 */
#define GPIO_PIN_34    (34)
/** GPIO pin number 35 */
#define GPIO_PIN_35    (35)
/** GPIO pin number 36 */
#define GPIO_PIN_36    (36)
/** GPIO pin number 37 */
#define GPIO_PIN_37    (37)
/** GPIO pin number 38 */
#define GPIO_PIN_38    (38)
/** GPIO pin number 39 */
#define GPIO_PIN_39    (39)
/** GPIO pin number 40 */
#define GPIO_PIN_40    (40)
/** GPIO pin number 41 */
#define GPIO_PIN_41    (41)
/** GPIO pin number 42 */
#define GPIO_PIN_42    (42)
/** GPIO pin number 43 */
#define GPIO_PIN_43    (43)
/** GPIO pin number 44 */
#define GPIO_PIN_44    (44)
/** GPIO pin number 45 */
#define GPIO_PIN_45    (45)
/** GPIO pin number 46 */
#define GPIO_PIN_46    (46)
/** GPIO pin number 47 */
#define GPIO_PIN_47    (47)
/** GPIO pin number 48 */
#define GPIO_PIN_48    (48)
/** GPIO pin number 49 */
#define GPIO_PIN_49    (49)
/** GPIO pin number 50 */
#define GPIO_PIN_50    (50)
/** GPIO pin number 51 */
#define GPIO_PIN_51    (51)
/** GPIO pin number 52 */
#define GPIO_PIN_52    (52)
/** GPIO pin number 53 */
#define GPIO_PIN_53    (53)
/** GPIO pin number 54 */
#define GPIO_PIN_54    (54)
/** GPIO pin number 55 */
#define GPIO_PIN_55    (55)
/** GPIO pin number 56 */
#define GPIO_PIN_56    (56)
/** GPIO pin number 57 */
#define GPIO_PIN_57    (57)
/** GPIO pin number 58 */
#define GPIO_PIN_58    (58)
/** GPIO pin number 59 */
#define GPIO_PIN_59    (59)
/** GPIO pin number 60 */
#define GPIO_PIN_60    (60)
/** GPIO pin number 61 */
#define GPIO_PIN_61    (61)
/** GPIO pin number 62 */
#define GPIO_PIN_62    (62)
/** GPIO pin number 63 */
#define GPIO_PIN_63    (63)
/** GPIO pin number 64 */
#define GPIO_PIN_64    (64)
/** GPIO pin number 65 */
#define GPIO_PIN_65    (65)
/** GPIO pin number 66 */
#define GPIO_PIN_66    (66)
/** GPIO pin number 67 */
#define GPIO_PIN_67    (67)
/** GPIO pin number 68 */
#define GPIO_PIN_68    (68)
/** GPIO pin number 69 */
#define GPIO_PIN_69    (69)
/** GPIO pin number 70 */
#define GPIO_PIN_70    (70)
/** GPIO pin number 71 */
#define GPIO_PIN_71    (71)
/** GPIO pin number 72 */
#define GPIO_PIN_72    (72)
/** GPIO pin number 73 */
#define GPIO_PIN_73    (73)
/** GPIO pin number 74 */
#define GPIO_PIN_74    (74)
/** GPIO pin number 75 */
#define GPIO_PIN_75    (75)
/** GPIO pin number 76 */
#define GPIO_PIN_76    (76)
/** GPIO pin number 77 */
#define GPIO_PIN_77    (77)
/** GPIO pin number 78 */
#define GPIO_PIN_78    (78)
/** GPIO pin number 79 */
#define GPIO_PIN_79    (79)
/** GPIO pin number 80 */
#define GPIO_PIN_80    (80)
/** GPIO pin number 81 */
#define GPIO_PIN_81    (81)
/** GPIO pin number 82 */
#define GPIO_PIN_82    (82)
/** GPIO pin number 83 */
#define GPIO_PIN_83    (83)
/** GPIO pin number 84 */
#define GPIO_PIN_84    (84)
/** GPIO pin number 85 */
#define GPIO_PIN_85    (85)
/** GPIO pin number 86 */
#define GPIO_PIN_86    (86)
/** GPIO pin number 87 */
#define GPIO_PIN_87    (87)
/** GPIO pin number 88 */
#define GPIO_PIN_88    (88)
/** GPIO pin number 89 */
#define GPIO_PIN_89    (89)
/** GPIO pin number 90 */
#define GPIO_PIN_90    (90)
/** GPIO pin number 91 */
#define GPIO_PIN_91    (91)
/** GPIO pin number 92 */
#define GPIO_PIN_92    (92)
/** GPIO pin number 93 */
#define GPIO_PIN_93    (93)
/** GPIO pin number 94 */
#define GPIO_PIN_94    (94)
/** GPIO pin number 95 */
#define GPIO_PIN_95    (95)
/** GPIO pin number 96 */
#define GPIO_PIN_96    (96)
/** GPIO pin number 97 */
#define GPIO_PIN_97    (97)
/** GPIO pin number 98 */
#define GPIO_PIN_98    (98)
/** GPIO pin number 99 */
#define GPIO_PIN_99    (99)
/** GPIO pin number 100 */
#define GPIO_PIN_100    (100)
/** GPIO pin number 101 */
#define GPIO_PIN_101    (101)
/** GPIO pin number 102 */
#define GPIO_PIN_102    (102)
/** GPIO pin number 103 */
#define GPIO_PIN_103    (103)
/** GPIO pin number 104 */
#define GPIO_PIN_104    (104)
/** GPIO pin number 105 */
#define GPIO_PIN_105    (105)
/** GPIO pin number 106 */
#define GPIO_PIN_106    (106)
/** GPIO pin number 107 */
#define GPIO_PIN_107    (107)
/** GPIO pin number 108 */
#define GPIO_PIN_108    (108)
/** GPIO pin number 109 */
#define GPIO_PIN_109    (109)
/** GPIO pin number 110 */
#define GPIO_PIN_110    (110)
/** GPIO pin number 111 */
#define GPIO_PIN_111    (111)
/** GPIO pin number 112 */
#define GPIO_PIN_112    (112)
/** GPIO pin number 113 */
#define GPIO_PIN_113    (113)
/** GPIO pin number 114 */
#define GPIO_PIN_114    (114)
/** GPIO pin number 115 */
#define GPIO_PIN_115    (115)
/** GPIO pin number 116 */
#define GPIO_PIN_116    (116)
/** GPIO pin number 117 */
#define GPIO_PIN_117    (117)
/** GPIO pin number 118 */
#define GPIO_PIN_118    (118)
/** GPIO pin number 119 */
#define GPIO_PIN_119    (119)
/** GPIO pin number 120 */
#define GPIO_PIN_120    (120)
/** GPIO pin number 121 */
#define GPIO_PIN_121    (121)
/** GPIO pin number 122 */
#define GPIO_PIN_122    (122)
/** GPIO pin number 123 */
#define GPIO_PIN_123    (123)
/** GPIO pin number 124 */
#define GPIO_PIN_124    (124)
/** GPIO pin number 125 */
#define GPIO_PIN_125    (125)
/** GPIO pin number 126 */
#define GPIO_PIN_126    (126)
/** GPIO pin number 127 */
#define GPIO_PIN_127    (127)
/** GPIO pin number 128 */
#define GPIO_PIN_128    (128)
/** GPIO pin number 129 */
#define GPIO_PIN_129    (129)
/** GPIO pin number 130 */
#define GPIO_PIN_130    (130)
/** GPIO pin number 131 */
#define GPIO_PIN_131    (131)
/** GPIO pin number 132 */
#define GPIO_PIN_132    (132)
/** GPIO pin number 133 */
#define GPIO_PIN_133    (133)
/** GPIO pin number 134 */
#define GPIO_PIN_134    (134)
/** GPIO pin number 135 */
#define GPIO_PIN_135    (135)
/** GPIO pin number 136 */
#define GPIO_PIN_136    (136)
/** GPIO pin number 137 */
#define GPIO_PIN_137    (137)
/** GPIO pin number 138 */
#define GPIO_PIN_138    (138)
/** GPIO pin number 139 */
#define GPIO_PIN_139    (139)
/** GPIO pin number 140 */
#define GPIO_PIN_140    (140)
/** GPIO pin number 141 */
#define GPIO_PIN_141    (141)
/** GPIO pin number 142 */
#define GPIO_PIN_142    (142)
/** GPIO pin number 143 */
#define GPIO_PIN_143    (143)

/** Number of GPIO pins per bank */
#define GPIO_PINS_PER_BANK         (32)
/** Maximum number of GPIO banks */
#define GPIO_MAX_BANKS             (5)

/** Maximum number of GPIO pins supported per instance */
#define GPIO_MAX_NUMBER            ((GPIO_MAX_BANKS) * (GPIO_PINS_PER_BANK))

/*
 * \brief GPIO function returned result
 */
/** GPIO pin value is low */
#define GPIO_LOW                   (0)
/** GPIO pin value is high */
#define GPIO_HIGH                  (1)
/** Requested operation is successful */
#define GPIO_RET_OK                (0)
/** Requested operation is failed */
#define GPIO_RET_FAIL              (1)
/** Invalid GPIO pin/bank number error */
#define INVALID_GPIO_NUMBER        (2)
/** Invalid GPIO direction error */
#define INVALID_GPIO_DIRECTION     (3)
/** Invalid GPIO state error */
#define	INVALID_GPIO_STATE         (4)
/** Invalid GPIO port number error */
#define	INVALID_GPIO_PORT          (5)

/** Command to set GPIO pin direction */
#define GPIO_CTRL_SET_DIR          (0)
/** Command to set GPIO pin output */
#define GPIO_CTRL_SET_OUTPUT       (1)
/** Command to clear GPIO pin output */
#define GPIO_CTRL_CLEAR_OUTPUT     (2)
/** Command to read GPIO pin input */
#define GPIO_CTRL_READ_INPUT       (3)
/** Command to set rising edge interrupt */
#define GPIO_CTRL_SET_RE_INTR      (4)
/** Command to clear rising edge interrupt */
#define GPIO_CTRL_CLEAR_RE_INTR    (5)
/** Command to set falling edge interrupt */
#define GPIO_CTRL_SET_FE_INTR      (6)
/** Command to clear falling edge interrupt */
#define GPIO_CTRL_CLEAR_FE_INTR    (7)

/** GPIO function return type */
typedef uint16_t GPIO_RET;

/**
 * \brief Options to configure GPIO pin direction
 */
typedef enum _GpioDirection
{
    GPIO_OUT = 0,  /**< Configures GPIO pin as output */
    GPIO_IN        /**< Configures GPIO pin as input */
} GpioDirection;

/************************
 * Function declarations
 ************************/
/**
 * \brief  Returns base address of given GPIO port number.
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 *
 * \return CSL_GpioHandle\n
 *
 */
CSL_GpioHandle gpioGetRegBaseAddr(uint8_t gpioPortNumber);

/**
 * \brief  Initializes the GPIO peripheral
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 *
 */
GPIO_RET gpioInit(uint8_t gpioPortNumber);

/**
 * \brief  This function configures the specified GPIO's direction
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 * \param   direction      [IN]    GPIO pin direction
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 *
 */
GPIO_RET gpioSetDirection(uint8_t gpioPortNumber, uint8_t pinNum,
                          GpioDirection direction);

/**
 * \brief  This function sets the specified GPIO's pin state to 1
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 *
 */
GPIO_RET gpioSetOutput(uint8_t gpioPortNumber, uint8_t pinNum);

/**
 * \brief  This function Clears the specified GPIO's pin state to 0
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 *
 */
GPIO_RET gpioClearOutput(uint8_t gpioPortNumber, uint8_t pinNum);

/**
 * \brief  This function gets the specified GPIO's pin state
 *
 * The specified GPIO should be configured as input
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      uint32_t - Input state of GPIO if success
 * \n				- else GPIO status
 */
uint32_t gpioReadInput(uint8_t gpioPortNumber, uint8_t pinNum);

/**
 * \brief  This function Enables GPIO interrupts to CPU
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   bankNum        [IN]    GPIO bank number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO bank number
 */
GPIO_RET gpioEnableGlobalInterrupt(uint8_t gpioPortNumber, uint8_t bankNum);

/**
 * \brief  This function Disables GPIO interrupts to CPU
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   bankNum        [IN]    GPIO bank number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO bank number
 */
GPIO_RET gpioDisableGlobalInterrupt(uint8_t gpioPortNumber, uint8_t bankNum);

/**
 * \brief  This function sets specified GPIO's rising edge interrupt
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 */
GPIO_RET gpioSetRisingEdgeInterrupt(uint8_t gpioPortNumber, uint8_t pinNum);

/**
 * \brief  This function clears specified GPIO's rising edge interrupt
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 */
GPIO_RET gpioClearRisingEdgeInterrupt(uint8_t gpioPortNumber, uint8_t pinNum);

/**
 * \brief  This function sets specified GPIO's falling edge interrupt
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 */
GPIO_RET gpioSetFallingEdgeInterrupt(uint8_t gpioPortNumber, uint8_t pinNum);

/**
 * \brief  This function clears specified GPIO's falling edge interrupt
 *
 * \param   gpioPortNumber [IN]    GPIO port number
 * \param   pinNum         [IN]    GPIO pin number
 *
 * \return
 * \n      GPIO_RET_OK          - Requested operation is successful
 * \n      INVALID_GPIO_PORT    - Invalid GPIO port number
 * \n      INVALID_GPIO_NUMBER  - Invalid GPIO pin number
 */
GPIO_RET gpioClearFallingEdgeInterrupt(uint8_t gpioPortNumber, uint8_t pinNum);

#ifdef __cplusplus
}
#endif

#endif /* _EVMC66X_GPIO_H_ */

/* Nothing past this point */
