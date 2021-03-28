@******************************************************************************
@
@ am43xx_pm_Slp_Wkup.S - This file contains sub-routines to save the processor
@ context before a deep sleep mode is invoked and also to restore the context
@ after waking up.
@
@
@******************************************************************************
@ Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
@
@
@  Redistribution and use in source and binary forms, with or without
@  modification, are permitted provided that the following conditions
@  are met:
@
@    Redistributions of source code must retain the above copyright
@    notice, this list of conditions and the following disclaimer.
@
@    Redistributions in binary form must reproduce the above copyright
@    notice, this list of conditions and the following disclaimer in the
@    documentation and/or other materials provided with the
@    distribution.
@
@    Neither the name of Texas Instruments Incorporated nor the names of
@    its contributors may be used to endorse or promote products derived
@    from this software without specific prior written permission.
@
@  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
@  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
@  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
@  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
@  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
@  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
@  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
@  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
@  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
@  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
@  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
@
@******************************************************************************
@ Share header file with assembly source code
@

#define AM43XX_EMIF_PHY_CTRL_REG_COUNT                   0x120
#define EMIF_SDRAM_CONFIG                                0x0008
#define EMIF_SDRAM_REFRESH_CONTROL                       0x0010
#define EMIF_SDRAM_REFRESH_CTRL_SHDW                     0x0014
#define EMIF_SDRAM_TIMING_1                              0x0018
#define EMIF_SDRAM_TIMING_1_SHDW                         0x001c
#define EMIF_SDRAM_TIMING_2                              0x0020
#define EMIF_SDRAM_TIMING_2_SHDW                         0x0024
#define EMIF_SDRAM_TIMING_3                              0x0028
#define EMIF_SDRAM_TIMING_3_SHDW                         0x002c
#define EMIF_POWER_MANAGEMENT_CONTROL                    0x0038
#define EMIF_POWER_MANAGEMENT_CTRL_SHDW                  0x003c
#define EMIF_SDRAM_OUTPUT_IMPEDANCE_CALIBRATION_CONFIG   0x00c8
#define EMIF_DDR_PHY_CTRL_1                              0x00e4
#define EMIF_DDR_PHY_CTRL_1_SHDW                         0x00e8
#define EMIF_DDR_PHY_CTRL_2                              0x00ec
#define EMIF_READ_WRITE_LEVELING_RAMP_CONTROL            0x00d8
#define EMIF_READ_WRITE_EXECUTION_THRESHOLD              0x0120
#define EMIF_COS_CONFIG                                  0x0124
#define EMIF_PRIORITY_TO_CLASS_OF_SERVICE_MAPPING        0x0100
#define EMIF_CONNECTION_ID_TO_CLASS_OF_SERVICE_1_MAPPING 0x0104
#define EMIF_CONNECTION_ID_TO_CLASS_OF_SERVICE_2_MAPPING 0x0108
#define EMIF_LPDDR2_NVM_TIMING                           0x0030
#define EMIF_LPDDR2_NVM_TIMING_SHDW                      0x0034
#define EMIF_OCP_CONFIG                                  0x0054
#define EMIF_DLL_CALIB_CTRL                              0x0098
#define EMIF_DLL_CALIB_CTRL_SHDW                         0x009c

#define EMIF_POWER_MGMT_SELF_REFRESH_MODE                0x0200
#define EMIF_POWER_MGMT_SELF_REFRESH_MODE_MASK           0x0700
#define EMIF_POWER_MGMT_DELAY_PERIOD                     0x1000

#define AM33XX_CM_CLKCTRL_MODULEMODE_DISABLE             0x0003
#define AM33XX_CM_CLKCTRL_MODULEMODE_ENABLE              0x0002

#define AM43XX_EMIF_POWEROFF_ENABLE                      0x1
#define AM43XX_EMIF_POWEROFF_DISABLE                     0x0


/** SMC ID to configure CP15 axillary control register */
#define SMC_ID_CP15_ACTLR_REG                            0x118

        .global romRestoreLocation
        .global saveRestoreContext

        .set  MODE_SYS, 0x1F
        .set  MODE_FIQ, 0x11
        .set  MODE_IRQ, 0x12
        .set  MODE_SVC, 0x13
        .set  MODE_ABT, 0x17
        .set  MODE_UND, 0x1B
        .set  MODE_SEC, 0x16
        .equ  I_F_BIT, 0xC0
        .equ  NUM_ARM_MODES, 7
        .equ  CACHE_DCACHE, 2
        .equ  CACHE_ALL, 3

        .section IRAM_CODE, "ax"      @ a - Allocatable, x - Executable
@**************************** Code section ************************************
        @ This code is assembled for ARM instructions
        .code 32

@ This function saves/restores the context
saveRestoreContext:
        LDR     r12, _slpmode_                     @ Save the sleep Mode
        STR     r0, [r12, #0]
        LDR     r12, _memtype_                     @ Save the Memory Type
        STR     r1, [r12, #0]
        LDR     r12, _socver_                      @ Save the SoC Version
        STR     r2, [r12, #0]

        MRS     r3, cpsr
        VMRS    r2, FPSCR                          @ Copy fpscr
        STMFD   sp!, {r2 - r12, lr}                @ Save the Registers
        @ VFP arch revision based register configuration is not implemented
        @ Current implementation is based on VFPv3 arch
        VSTMDB  r13!, {d0-d15}                     @ Save D0-D15 NEON/VFP registers
        VSTMDB  r13!, {d16-d31}                    @ Save D16-D31 NEON/VFP registers

        @ Save required CP15 registers. If more are used, can be saved here
        MRC     p15, #0, r0, c12, c0, #0           @ Vector base register
        MRC     p15, #0, r1, c1, c0, #0            @ Control register
        MRC     p15, #0, r2, c1, c0, #1            @ Aux control register
        MRC     p15, #0, r3, c2, c0, #0            @ TTB0 register
        MRC     p15, #0, r4, c3, c0, #0            @ Domain Access Control
        STMFD   sp!, {r0 - r4}

        LDR     r0, _cnxtstack_                    @ Save the stack pointer
        STR     sp, [r0], #4                       @ for the current mode

        MSR     cpsr_c, #MODE_FIQ|I_F_BIT
        STR     sp, [r0], #4

        MSR     cpsr_c, #MODE_SVC|I_F_BIT
        STR     sp, [r0], #4

        MSR     cpsr_c, #MODE_ABT|I_F_BIT
        STR     sp, [r0], #4

        MSR     cpsr_c, #MODE_IRQ|I_F_BIT
        STR     sp, [r0], #4

        MSR     cpsr_c, #MODE_UND|I_F_BIT
        STR     sp, [r0], #4

        MSR     cpsr_c, #MODE_SYS|I_F_BIT
        STR     sp, [r0], #4

@
@ EMIF Context Save
@
        LDR     r0, _emifcontext_
        LDR     r1, emif_base
        MOV     r3, #0

        LDR     r2, [r1, #EMIF_SDRAM_CONFIG]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_SDRAM_REFRESH_CONTROL]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_SDRAM_REFRESH_CTRL_SHDW]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_SDRAM_TIMING_1]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_SDRAM_TIMING_1_SHDW]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_SDRAM_TIMING_2]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_SDRAM_TIMING_2_SHDW]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_SDRAM_TIMING_3]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_SDRAM_TIMING_3_SHDW]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_POWER_MANAGEMENT_CONTROL]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_SDRAM_OUTPUT_IMPEDANCE_CALIBRATION_CONFIG]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_DDR_PHY_CTRL_1]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_READ_WRITE_LEVELING_RAMP_CONTROL]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_COS_CONFIG]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_PRIORITY_TO_CLASS_OF_SERVICE_MAPPING]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_CONNECTION_ID_TO_CLASS_OF_SERVICE_1_MAPPING]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_CONNECTION_ID_TO_CLASS_OF_SERVICE_2_MAPPING]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_LPDDR2_NVM_TIMING]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_LPDDR2_NVM_TIMING_SHDW]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_OCP_CONFIG]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_DLL_CALIB_CTRL]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4
        LDR     r2, [r1, #EMIF_DLL_CALIB_CTRL_SHDW]
        STR     r2, [r0, r3]
        ADDS    r3, r3, #4

        /* Loop and Save entire block of emif phy regs. */
        ADD r1, r1, #0x200
        ADD r0, r0, r3
        MOV r3, #0

emif_cont_save:
        LDR     r2, [r1, r3]
        STR     r2, [r0, r3]
        ADDS    r3, r3 ,#4

        CMP     r3, #AM43XX_EMIF_PHY_CTRL_REG_COUNT
        BNE     emif_cont_save
        @ EMIF Context Save End

        @ Make sure that the Cache is Cleaned before putting DDR
        @ to self-refresh.
        MOV     r0, #CACHE_DCACHE
        MOV     r1, #0x03
        BL      CACHEDisable

        @ Putting DDR into self refresh mode
        LDR   r1, emif_pmctl
        LDR   r2, [r1]
        BIC   r2, r2, #EMIF_POWER_MGMT_SELF_REFRESH_MODE_MASK
        ORR   r2, r2, #EMIF_POWER_MGMT_SELF_REFRESH_MODE
        STR   r2, [r1]
        @ORR   r2, r2, #0xA0        @after 32 clks of idle, go to SR
        @STR   r2, [r1, #0]         @Write value to PWR_MGMT_CTRL_REG
        @STR   r2, [r1, #4]         @Write value to PWR_MGMT_CTRL_SHDW_REG

        LDR   r2, ddr_start
        LDR   r3, [r2, #0]            @read from DDR to make PMCTL write take affect
        STR   r3, [r2, #0]
        ISB
        @LDR   r3, [r1, #0]            @put pm_ctrl reg in r3
        @ORR   r3,r3,#0x200            @set pm_ctrl to self refresh
        @STR   r3, [r1, #0]
        @STR   r3, [r1, #4]            @shdw register

        MOV     r0, #0x1000
wait_enable_sr_:                            @wait for SR to complete
        SUBS    r0, r0 ,#1
        BNE     wait_enable_sr_

        /* Disable EMIF */
        LDR r1, emif_clkctl
        LDR r2, [r1]
        BIC r2, r2, #AM33XX_CM_CLKCTRL_MODULEMODE_DISABLE
        STR r2, [r1]

wait_emif_disable:
        LDR r2, [r1]
        LDR r3, module_disabled_val
        CMP r2, r3
        BNE wait_emif_disable

WaitForInterrupt:

        /*
         * Put IO in isolation
         */
        @ldr     r1, pm_io_ctrl
        @ldr     r2, [r1]
        @orr     r2, r2, #0x01000000
        @str     r2, [r1]

       /*
         * Put SCU to SW_SLEEP
         */
        ldr     r1, mpu_scu
        ldr     r2, [r1]
        orr     r2, r2, #0x3
        str     r2, [r1]

        /*
         * For the MPU WFI to be registered as an interrupt
         * to WKUP_M3, MPU_CLKCTRL.MODULEMODE needs to be set
         * to DISABLED
         */
        ldr     r1, mpu_clkctl
        ldr     r2, [r1]
        bic     r2, r2, #3
        str     r2, [r1]

        /*
         * Put MPU CLKDM to SW_SLEEP
         */
        ldr     r1, mpu_clkstctl
        mov     r2, #1
        str     r2, [r1]

        dsb
        dmb
        isb
        WFI                                        @ Wait for interrupt

        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop

romRestoreLocation:
        nop
        nop
        nop
        nop

        /* We come here in case of an abort due to a late interrupt */
        ldr     r1, mpu_clkstctl
        mov     r2, #2
        str     r2, [r1]

        /* Set MPU_CLKCTRL.MODULEMODE back to ENABLE */
        ldr     r1, mpu_clkctl
        mov     r2, #2
        str     r2, [r1]

        /*
         * Put SCU to SW_SLEEP
         */
        ldr     r1, mpu_scu
        ldr     r2, [r1]
        bic     r2, r2, #0x3
        str     r2, [r1]

        @ldr     r1, pm_io_ctrl
        @ldr     r2, [r1]
        @bic     r2, r2, #0x01000000
        @str     r2, [r1]

        /* For AM43xx, use EMIF power down until context is restored */
        LDR r2, emif_pwr_ctrl                     @ 0x44DF4030 am43xx_phys_emif_poweroff
        MOV r1, #AM43XX_EMIF_POWEROFF_ENABLE
        STR r1, [r2, #0x0]

skip_emif_pwrdn_config:
        /* Re-enable EMIF */
        LDR r1, emif_clkctl
        MOV r2, #AM33XX_CM_CLKCTRL_MODULEMODE_ENABLE
        STR r2, [r1]
wait_emif_enable1:
        LDR r3, [r1]
        CMP r2, r3
        BNE wait_emif_enable1

        LDR    r0, _emifcontext_
        LDR    r1, emif_base
        MOV    r2, #0

        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_SDRAM_CONFIG]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_SDRAM_REFRESH_CONTROL]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_SDRAM_REFRESH_CTRL_SHDW]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_SDRAM_TIMING_1]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_SDRAM_TIMING_1_SHDW]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_SDRAM_TIMING_2]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_SDRAM_TIMING_2_SHDW]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_SDRAM_TIMING_3]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_SDRAM_TIMING_3_SHDW]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_POWER_MANAGEMENT_CONTROL]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_SDRAM_OUTPUT_IMPEDANCE_CALIBRATION_CONFIG]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_DDR_PHY_CTRL_1]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_READ_WRITE_LEVELING_RAMP_CONTROL]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_COS_CONFIG]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_PRIORITY_TO_CLASS_OF_SERVICE_MAPPING]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_CONNECTION_ID_TO_CLASS_OF_SERVICE_1_MAPPING]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_CONNECTION_ID_TO_CLASS_OF_SERVICE_2_MAPPING]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_LPDDR2_NVM_TIMING]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_LPDDR2_NVM_TIMING_SHDW]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_OCP_CONFIG]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_DLL_CALIB_CTRL]
        ADDS   r2, r2, #4
        LDR    r3, [r0, r2]
        STR    r3, [r1, #EMIF_DLL_CALIB_CTRL_SHDW]
        ADDS   r2, r2, #4

        /* Loop and Restore entire block of emif phy regs. */
        ADD    r1, r1, #0x200
        ADD    r0, r0, r2
        MOV    r2, #0

emif_cont_restore:
        LDR    r3, [r0, r2]
        STR    r3, [r1, r2]
        ADD    r2, r2, #4

        CMP    r2, #AM43XX_EMIF_PHY_CTRL_REG_COUNT
        BNE    emif_cont_restore

        @disable_self_refresh    DDR3
        @Disable EMIF self-refresh
        /*
        * Toggle EMIF to exit refresh mode:
        * if EMIF lost context, PWR_MGT_CTRL is currently 0, writing disable
        *   (0x0), wont do diddly squat! so do a toggle from SR(0x2) to disable
        *   (0x0) here.
        * *If* EMIF did not loose context, nothing broken as we write the same
        *   value(0x2) to reg before we write a disable (0x0).
        */
        LDR     r0, emif_pmctl
        LDR     r1, [r0]
        BIC     r1, r1, #EMIF_POWER_MGMT_SELF_REFRESH_MODE_MASK
        ORR     r1, r1, #EMIF_POWER_MGMT_SELF_REFRESH_MODE
        STR     r1, [r0, #0x0]

        @BIC     r1, r1, #(0x7 << 7)
        @STR     r1, [r0]

        ldr r2, emif_pwr_ctrl                     @ 0x44DF4030 am43xx_phys_emif_poweroff
        mov r1, #AM43XX_EMIF_POWEROFF_DISABLE
        str r1, [r2, #0x0]

        LDR     r0, emif_pmctl
        LDR     r1, [r0]
        BIC     r1, r1, #EMIF_POWER_MGMT_SELF_REFRESH_MODE_MASK
        STR     r1, [r0, #0x0]

        MOV     r0, #0x2000
wait_disable_sr_:                                         @wait for SR to complete
        SUBS    r0, r0 ,#1
        BNE     wait_disable_sr_

        @B       CoreContextRestore

CoreContextRestore:

        LDR     r4, _cnxtstack_
        MSR     cpsr_c, #MODE_FIQ|I_F_BIT
        LDR     sp, [r4, #4]

        MSR     cpsr_c, #MODE_SVC|I_F_BIT
        LDR     sp, [r4, #8]

        MSR     cpsr_c, #MODE_ABT|I_F_BIT
        LDR     sp, [r4, #12]

        MSR     cpsr_c, #MODE_IRQ|I_F_BIT
        LDR     sp, [r4, #16]

        MSR     cpsr_c, #MODE_UND|I_F_BIT
        LDR     sp, [r4, #20]

        MSR     cpsr_c, #MODE_SYS|I_F_BIT
        LDR     sp, [r4, #24]

        LDR     sp, [r4, #0]                      @ Load the stack pointer
                                                  @ for the mode before sleep

        @ Restore all the saved CPSR registers
        LDMFD    sp!, {r3-r7}

        MCR     p15, #0, r3, c12, c0, #0          @ Vector base register
        @swicth to secure to restore the Auxillary control register
        MOV     r0, #SMC_ID_CP15_ACTLR_REG
        MOV     r1, r5
        BL      Pub2MonDispatch
        MCR     p15, #0, r6, c2, c0, #0           @ TTB0 register
        MCR     p15, #0, r7, c3, c0, #0           @ Domain Access Control
        MCR     p15, #0, r4, c1, c0, #0           @ Control register

        @ Enable Neon/VFP Co-Processor
        MRC     p15, #0, r8, c1, c0, #2           @ r1 = Access Control Register
        ORR     r8, r8, #(0xf << 20)              @ enable full access for p10,11
        MCR     p15, #0, r8, c1, c0, #2           @ Access Control Register = r1
        MOV     r8, #0
        MCR     p15, #0, r8, c7, c5, #4           @flush prefetch buffer
        MOV     r8,#0x40000000
        FMXR    FPEXC, r8                         @ Set Neon/VFP Enable bit

        @ VFP arch revision based register configuration is not implemented
        @ Current implementation is based on VFPv3 arch
        VLDMIA  r13!, {d16-d31}                   @ Restore D16-D31 Neon/VFP registers
        VLDMIA  r13!, {d0-d15}                    @ Restore D0-D15 Neon/VFP registers
        LDMFD   sp!, {r2 - r12, lr}
        MSR     cpsr_cf, r3                       @ Update CPSR
        VMSR    fpscr, r2                         @ Restore fpscr

Exit:
        DSB
        BX    lr


_slpmode_:
    .word _slpmode
_memtype_:
    .word _memtype
_socver_:
    .word _socver
_cnxtstack_:
    .word _cnxtstack
_emifcontext_:
    .word _emifcontext
emif_pmctl:
    .word 0x4C000038
emif_pwr_ctrl:
    .word 0x44DF4030
ddr_start:
    .word 0x80000000
emif_clkctl:
    .word 0x44DF8F20
emif_base:
    .word 0x4C000000
dpll_extdev_clock_mode:
    .word 0x44DF2E60
pm_io_ctrl:
    .word 0x44DF4024
mpu_clkctl:
    .word 0x44DF8320
mpu_clkstctl:
    .word 0x44DF8300
mpu_scu:
    .word 0x48240008
module_disabled_val:
	.word 0x30000
module_enabled_val:
    .word 0x0002
l2_base_virt:
    .word 0xDEADBEEF
l2_aux_ctrl_val:
    .word 0xDEADBEEF
l2_prefetch_ctrl_val:
    .word 0xDEADBEEF
l2_cache_base:
    .word 0x48242000
l2_val:
    .word 0xffff
l2_smc1:
    .word 0x113
l2_smc2:
    .word 0x109
l2_smc3:
    .word 0x102


@
@ This code is assembled for ARM instructions
@
        .section IRAM_DATA
        .align

_slpmode:
        .space (4)
_memtype:
        .space (4)
_socver:
        .space (4)
_cnxtstack:
        .space (NUM_ARM_MODES * 4)
_emifcontext:
        .space (1168)	@238
@
@ End of the file
@
    .end
