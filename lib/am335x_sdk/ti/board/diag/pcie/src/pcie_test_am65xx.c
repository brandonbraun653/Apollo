/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
 *
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
 *****************************************************************************/

/**
 * \file   pcie_test_am65xx.c
 *
 * In the PCIe test example two EVMs are used to test the PCIe driver.
 * As described in the following figure, EVM RC is configured as a Root Complex
 * and EVM EP is configured as End Point.
 *
 *         EVM RC                                          EVM EP
 *   ------------------                             -------------------
 *   |                |                             |                 |
 *   |   Root         |          PCIe Link          |  End Point      |
 *   |   Complex      | <-------------------------->|                 |
 *   |                |                             |                 |
 *   ------------------                             -------------------
 *
 * Once the PCIe link is established, the following sequence of actions will
 * happen:
 *  - EVM RC sends data to EVM EP
 *  - EVM EP waits to receive all the data
 *  - EVM EP sends the data back to EVM RC
 *  - EVM RC waits to receive all the data
 *  - EVM RC verifies if the received data matches the sent data and declares
 *    test pass or fail.
 *  - EVM EP sends 10 MSI and 10 INTA's to EVM RC.
 *
 */


#include "pcie_test_am65xx.h"

pcieMode_e PcieModeGbl;

/**
 * \brief Device configure function
 *
 * This function is used to configure the device as a root complex or end point
 *
 * \param   pcie_index  [IN] pcie instance
 *          device_type [IN] value to specify RC or EP
 *
 */
static void BoardDiag_configurePcieDeviceType(uint32_t pcie_index, uint32_t device_type)
{
    uint32_t get_value;
    // configure pcie as a specific device type
    *((uint32_t *) (uintptr_t)(CSL_PSC0_BASE + 0x324)) = 0x00000001;
    *((uint32_t *) (uintptr_t)(CSL_PSC0_BASE + 0xa4c + 0x4 * pcie_index)) = 0x00000101;
    *((uint32_t *) (uintptr_t)(CSL_PSC0_BASE + 0x120)) = 0x00000200;

    get_value = ~0x00000000;
    while (get_value != 0x00000000)
    {
        get_value = *((uint32_t *) (uintptr_t)(CSL_PSC0_BASE + 0x128));
    }

    *((uint32_t *) (uintptr_t)(CSL_CTRL_MMR0_CFG0_BASE + 0x4060 + 0x10 * pcie_index)) = device_type;

    *((uint32_t *) (uintptr_t)(CSL_PSC0_BASE + 0x324)) = 0x00000001;
    *((uint32_t *) (uintptr_t)(CSL_PSC0_BASE + 0xa4c + 0x4 * pcie_index)) = 0x00000103;
    *((uint32_t *) (uintptr_t)(CSL_PSC0_BASE + 0x120)) = 0x00000200;

    get_value = ~0x00000000;
    while (get_value != 0x00000000)
    {
        get_value = *((uint32_t *) (uintptr_t)(CSL_PSC0_BASE + 0x128));
    }
}

/**
 * This function is used to enable Memory bus access
 *
 * \param   base_address [IN] PCIe data base address
 *
 */
static void BoardDiag_enableMemAndBusMaster(uint32_t base_address)
{
    *((uint32_t *) (uintptr_t)(base_address + 0x1004)) = 0x00100006;
}

/**
 * \brief Configure EndPoint function
 *
 * This function is used to enable the BAR configurations,Inbound  and outbound  
 * configurations for Endpoint.
 * The PCIe core is configured to support 16x 64-bit outbound and 16x 64-bit
 * inbound address translation regions with each region being a minimum of 64KB
 * in size. If only 32-bit address translation is used, then a total of 32
 * regions can be supported in each direction
 *
 * \param   base_address [IN] PCIe data base address
 *
 */
static void BoardDiag_ConfigureIatuRc(uint32_t base_address)
{
    unsigned int offset = 0;

    if (base_address == 0x05600000)
    {
        offset = 0x08000000;
    }

    //OUTBOUND 0 ;
    *((uint32_t *) (uintptr_t)(base_address + 0x6000)) = 0x00000004; //TYPE 4 for CFG access
    *((uint32_t *) (uintptr_t)(base_address + 0x6004)) = 0x80000000; //ENABLE OB
    *((uint32_t *) (uintptr_t)(base_address + 0x6008)) = OB_REGION_0 + offset;
    *((uint32_t *) (uintptr_t)(base_address + 0x600c)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6010)) = OB_REGION_0 + offset + OB_CFG_SIZE - 1;
    *((uint32_t *) (uintptr_t)(base_address + 0x6014)) = 0x00000000; //
    *((uint32_t *) (uintptr_t)(base_address + 0x6018)) = 0x00000000;

    //OUTBOUND 1
    *((uint32_t *) (uintptr_t)(base_address + 0x6200)) = 0x00000000; //TYPE 0 for MEM access
    *((uint32_t *) (uintptr_t)(base_address + 0x6204)) = 0x80000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6208)) = OB_REGION_1 + offset;
    *((uint32_t *) (uintptr_t)(base_address + 0x620c)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6210)) = OB_REGION_1 + offset + OB_MEM_SIZE - 1; //64KB
    *((uint32_t *) (uintptr_t)(base_address + 0x6214)) = RC_OB_ADDRESS; //
    *((uint32_t *) (uintptr_t)(base_address + 0x6218)) = 0x00000000;

    //INBOUND 1
    *((uint32_t *) (uintptr_t)(base_address + 0x6304)) = 0x80000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6308)) = EP_OB_ADDRESS;
    *((uint32_t *) (uintptr_t)(base_address + 0x630c)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6310)) = EP_OB_ADDRESS + OB_MEM_SIZE - 1;
    *((uint32_t *) (uintptr_t)(base_address + 0x6314)) = BUFFER_ADDR;
    *((uint32_t *) (uintptr_t)(base_address + 0x6318)) = 0x00000000;
}

/**
 * \brief Configure EndPoint function
 *
 * This function is used to enable the BAR configurations,Inbound  and outbound  
 * configurations for Endpoint.
 *
 * \param   base_address [IN] PCIe data base address
 *
 */
static void BoardDiag_ConfigureIatuEp(uint32_t base_address)
{
    uint32_t offset = 0;

    if (base_address == 0x05600000)
    {
        offset = 0x08000000;
    }

    // BAR config
    *((uint32_t *) (uintptr_t)(base_address + 0x0004)) = 0x00000021; //Enable DB1_CS2
    *((uint32_t *) (uintptr_t)(base_address + 0x1010)) = 0x7FFFFFFF; //BAR0
    *((uint32_t *) (uintptr_t)(base_address + 0x1014)) = 0x7FFFFFFF; //SHOULD BE BAR1 MASK 128MB
    *((uint32_t *) (uintptr_t)(base_address + 0x1018)) = 0x7FFFFFFF;
    *((uint32_t *) (uintptr_t)(base_address + 0x101c)) = 0x7FFFFFFF;
    *((uint32_t *) (uintptr_t)(base_address + 0x1020)) = 0x7FFFFFFF;
    *((uint32_t *) (uintptr_t)(base_address + 0x1024)) = 0x7FFFFFFF;
    BOARD_delay(100);
    *((uint32_t *) (uintptr_t)(base_address + 0x0004)) = 0x00000001; //DISABLE DB1_CS2

    *((uint32_t *) (uintptr_t)(base_address + 0x18bc)) = 0x00000001; //ENABLE DBI_RO_WR_EN
    *((uint32_t *) (uintptr_t)(base_address + 0x1010)) = 0x05500000; //SHOULD BE BAR 0-5
    *((uint32_t *) (uintptr_t)(base_address + 0x1014)) = RC_OB_ADDRESS;
    *((uint32_t *) (uintptr_t)(base_address + 0x1018)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x101c)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x1020)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x1024)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x18bc)) = 0x00000000; //DISABLE DBI_RO_WR_EN

    //OUTBOUND 1
    *((uint32_t *) (uintptr_t)(base_address + 0x6200)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6204)) = 0x80000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6208)) = OB_REGION_1 + offset;
    *((uint32_t *) (uintptr_t)(base_address + 0x620c)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6210)) = OB_REGION_1 + offset + OB_MEM_SIZE - 1;
    *((uint32_t *) (uintptr_t)(base_address + 0x6214)) = EP_OB_ADDRESS; //
    *((uint32_t *) (uintptr_t)(base_address + 0x6218)) = 0x00000000;

    //INBOUND 1
    *((uint32_t *) (uintptr_t)(base_address + 0x6304)) = 0x80000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6308)) = RC_OB_ADDRESS;
    *((uint32_t *) (uintptr_t)(base_address + 0x630c)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6310)) = RC_OB_ADDRESS + OB_MEM_SIZE - 1;
    *((uint32_t *) (uintptr_t)(base_address + 0x6314)) = BUFFER_ADDR;
    *((uint32_t *) (uintptr_t)(base_address + 0x6318)) = 0x0000000;
}

#if defined(AARCH_64)
static void BoardDiag_ConfigureIatuRc64bit(uint32_t base_address)
{
    unsigned int offset = 0;

    if (base_address == 0x05600000)
    {
        offset = 0x1;
    }

    //OUTBOUND 0 ;
    *((uint32_t *) (uintptr_t)(base_address + 0x6000)) = 0x00000004; //TYPE 4 for CFG access
    *((uint32_t *) (uintptr_t)(base_address + 0x6004)) = 0x80000000; //ENABLE OB
    *((uint32_t *) (uintptr_t)(base_address + 0x6008)) = OB_REGION_0;
    *((uint32_t *) (uintptr_t)(base_address + 0x600c)) = 0x00000040 + offset;
    *((uint32_t *) (uintptr_t)(base_address + 0x6010)) = OB_REGION_0 + OB_CFG_SIZE - 1;
    *((uint32_t *) (uintptr_t)(base_address + 0x6014)) = 0x00000000; //
    *((uint32_t *) (uintptr_t)(base_address + 0x6018)) = 0x00000000;

    //OUTBOUND 1
    *((uint32_t *) (uintptr_t)(base_address + 0x6200)) = 0x00000000; //TYPE 0 for MEM access
    *((uint32_t *) (uintptr_t)(base_address + 0x6204)) = 0x80000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6208)) = 0;
    *((uint32_t *) (uintptr_t)(base_address + 0x620c)) = 0x00000040 + offset;
    *((uint32_t *) (uintptr_t)(base_address + 0x6210)) = 0x0000ffff; //64KB
    *((uint32_t *) (uintptr_t)(base_address + 0x6214)) = 0x70000000; //
    *((uint32_t *) (uintptr_t)(base_address + 0x6218)) = 0x00000000;

    //INBOUND 1
    *((uint32_t *) (uintptr_t)(base_address + 0x6304)) = 0x80000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6308)) = EP_OB_ADDRESS;
    *((uint32_t *) (uintptr_t)(base_address + 0x630c)) = 0x00000040;
    *((uint32_t *) (uintptr_t)(base_address + 0x6310)) = EP_OB_ADDRESS + OB_MEM_SIZE - 1;
    *((uint32_t *) (uintptr_t)(base_address + 0x6314)) = BUFFER_ADDR;
    *((uint32_t *) (uintptr_t)(base_address + 0x6318)) = 0x00000000;

}


static void BoardDiag_ConfigureIatuEp64bit(uint32_t base_address)
{

    uint32_t offset = 0;

    if (base_address == 0x05600000)
    {
        offset = 0x1;
    }

    // BAR config
    *((uint32_t *) (uintptr_t)(base_address + 0x0004)) = 0x00000021; //Enable DB1_CS2
    *((uint32_t *) (uintptr_t)(base_address + 0x1010)) = 0x7FFFFFFF; //BAR0
    *((uint32_t *) (uintptr_t)(base_address + 0x1014)) = 0x7FFFFFFF;
    *((uint32_t *) (uintptr_t)(base_address + 0x1018)) = 0x7FFFFFFF;
    *((uint32_t *) (uintptr_t)(base_address + 0x101c)) = 0x7FFFFFFF;
    *((uint32_t *) (uintptr_t)(base_address + 0x1020)) = 0x7FFFFFFF;
    *((uint32_t *) (uintptr_t)(base_address + 0x1024)) = 0x7FFFFFFF;
    BOARD_delay(100);
    *((uint32_t *) (uintptr_t)(base_address + 0x0004)) = 0x00000001; //DISABLE DB1_CS2

    *((uint32_t *) (uintptr_t)(base_address + 0x18bc)) = 0x00000001; //ENABLE DBI_RO_WR_EN
    *((uint32_t *) (uintptr_t)(base_address + 0x1010)) = 0x00000000; //SHOULD BE BAR 0-5
    *((uint32_t *) (uintptr_t)(base_address + 0x1014)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x1018)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x101c)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x1020)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x1024)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x18bc)) = 0x00000000; //DISABLE DBI_RO_WR_EN

    //OUTBOUND 1
    *((uint32_t *) (uintptr_t)(base_address + 0x6200)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6204)) = 0x80000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6208)) = OB_REGION_1;
    *((uint32_t *) (uintptr_t)(base_address + 0x620c)) = 0x00000040 + offset;
    *((uint32_t *) (uintptr_t)(base_address + 0x6210)) = OB_REGION_1 + OB_MEM_SIZE - 1;
    *((uint32_t *) (uintptr_t)(base_address + 0x6214)) = EP_OB_ADDRESS; //
    *((uint32_t *) (uintptr_t)(base_address + 0x6218)) = 0x00000000;

    //INBOUND 1
    *((uint32_t *) (uintptr_t)(base_address + 0x6304)) = 0x80000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6308)) = 0x70000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x630c)) = 0x00000000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6310)) = 0x7000ffff;
    *((uint32_t *) (uintptr_t)(base_address + 0x6314)) = 0x41c00000;
    *((uint32_t *) (uintptr_t)(base_address + 0x6318)) = 0x00000000;

}
#endif

/**
 * \brief Outbound write function
 *
 * This function is used to write some data to the Outbound Address
 * Translation
 *
 * \param   instance  [IN]  pcie instance
 *
 */ 
static void BoardDiag_testObWrite(uint32_t instance)
{
    uint32_t i, offset = 0;

    if (instance == 1)
    {
        offset = 0x08000000;
    }

    /* Write to remote side */
    for (i = 0; i < BUFFER_SIZE; i++) {
        *((uint32_t *) (uintptr_t)(OB_REGION_1 + offset + 4*i)) = i;
    }
}


/**
 * \brief  BoardDiag_pcieTest function
 *
 * This function is used to test the pcie loopback mode
 * In this data sent to EP, RC waits for the loopback to be completed and
 * receive data back from EP
 *
 * \return  int8_t
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
int8_t BoardDiag_pcieTest(void)
{
    uint32_t i;
    SERDES_DIAG_PCIE_TYPE pcie_gen_type = PCIE_PCIE_GEN_TYPE;
    uint32_t csl_pcie_dat_base;
    CSL_pcie_rc_coreRegs *pcie_core_regs;
    uint32_t pcieInstance;
    uint32_t link_up_done = 0x0;
    uint32_t link_state = 0x0;
	uint32_t data_arrived = 0;
    uint8_t pcieModeResponse;
    uint32_t linkSpeed;

    UART_printf ("**********************************************\n");
    UART_printf ("*                PCIe Test                   *\n");
    UART_printf ("**********************************************\n");
#if !defined(DIAG_COMPLIANCE_TEST)
	UART_printf ("Enter: E for Endpoint or R for Root Complex   \n");
    UART_scanFmt  ("%c", &pcieModeResponse);
#else
	pcieModeResponse = 'E';
#if defined(DIAG_PCIE_MODE_RC)
	pcieModeResponse = 'R';
#endif
#endif
    if ((pcieModeResponse == 'E') || (pcieModeResponse == 'e'))
    {
        PcieModeGbl = pcie_EP_MODE;
        UART_printf ("* EP mode *\n");
    }
    else if ((pcieModeResponse == 'R') || (pcieModeResponse == 'r'))
    {
        PcieModeGbl = pcie_RC_MODE;
        UART_printf ("* RC mode *\n");
    }
    else
    {
        UART_printf ("Wrong Mode Enter. Please enter E or R \n");
        return -1;
    }

    for (i = 0; i < BUFFER_SIZE; i++) {
		*((uint32_t *) (uintptr_t)(BUFFER_ADDR + 4*i)) = 0xBABEFACE;
	}
#if (PCIE_BASE_ADDR == CSL_SERDES0_BASE)
    pcieInstance = 0;
    csl_pcie_dat_base = CSL_PCIE0_DAT_BASE;
    pcie_core_regs = (CSL_pcie_rc_coreRegs *) (CSL_PCIE0_DAT_BASE);
#endif
#if (PCIE_BASE_ADDR == CSL_SERDES1_BASE)
    pcieInstance = 1;
    csl_pcie_dat_base = CSL_PCIE1_DAT_BASE;
    pcie_core_regs = (CSL_pcie_rc_coreRegs *) (CSL_PCIE1_DAT_BASE);
#endif

    if (PcieModeGbl == pcie_RC_MODE)
    {
        BoardDiag_configurePcieDeviceType(pcieInstance, 0x2);
        UART_printf("This is PCIE RC\n");
    }

    if (PcieModeGbl == pcie_EP_MODE)
    {
        BoardDiag_configurePcieDeviceType(pcieInstance, 0x0);
        UART_printf("This is PCIE EP\n");
    }


    /* Enable DBI_RO_WR_EN */
    *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x18bc)) = 0x00000001;

    /* Set up TARGET_LINK_SPEED */
    if (pcie_gen_type == SERDES_DIAG_PCIE_GEN1)
    {
        *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x10a0)) = 0x00010000;
    }
    if (pcie_gen_type == SERDES_DIAG_PCIE_GEN2)
    {
        *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x10a0)) = 0x00010002;
    }
    if (pcie_gen_type == SERDES_DIAG_PCIE_GEN3)
    {
        *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x10a0)) = 0x00010003;
    }

    /* Configure link training */
    *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x0004)) = 0x00000000;

    *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x1004)) = 0x00100006;
    *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x107c)) = 0x00733723;
    *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x108c)) = 0x00010018;

    *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x1710)) = 0x00010120; //100a2 to 10120
    *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x180c)) = 0x000301F0;

    //0x1004, 0x00100006/0x00100146 should be fine
    BoardDiag_enableMemAndBusMaster(csl_pcie_dat_base);

    *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x18bc)) = 0x00000000;

    // PCIE iatu configure
    if (PcieModeGbl == pcie_RC_MODE) {
        BoardDiag_ConfigureIatuRc(csl_pcie_dat_base);
    }
    if (PcieModeGbl == pcie_EP_MODE) {
        BoardDiag_ConfigureIatuEp(csl_pcie_dat_base);
    }

    /* Enable link training */
    *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x4)) = 0x00000001;

    if (PcieModeGbl == pcie_RC_MODE)
    {
        while (link_up_done != 0x1)
        {
             link_up_done =  CSL_REG32_FEXT(&pcie_core_regs->LINK_CONTROL_LINK_STATUS_REG, PCIE_RC_CORE_LINK_CONTROL_LINK_STATUS_REG_PCIE_CAP_DLL_ACTIVE);            /* Bit 29 */
        }
    }

    //Wait for PCIe state machine moves to state L0
    while (link_state != 0x11)
    {
        link_state = CSL_REG32_FEXT(&pcie_core_regs->PL_DEBUG0_OFF, PCIE_RC_CORE_PL_DEBUG0_OFF_DEB_REG_0);
        link_state = (link_state & 0x1F);
    }

    UART_printf("Link is up\n");
    linkSpeed = *((uint32_t *) (uintptr_t)(csl_pcie_dat_base + 0x1080));
    UART_printf("link status reg =0x%x\n",linkSpeed);
    if( (linkSpeed & (1 << 16)) &&  (linkSpeed & (1 << 17)))
    {
        UART_printf("Link speed:Gen3\n");
    }
    else if( (linkSpeed & (1<< 17)) && (!(linkSpeed & (1 << 16))))
    {
        UART_printf("Link speed:Gen2\n");
    }
    else if( (linkSpeed & (1<< 16)) && (!(linkSpeed & (1 << 17))))
    {
        UART_printf("Link speed:Gen1\n");
    }

	if (PcieModeGbl == pcie_RC_MODE) {
		//Write a pattern to remote side

		UART_printf("RC writes a pattern to EP\n");

		BoardDiag_testObWrite(pcieInstance);
		while (data_arrived != 0xF) {
			data_arrived = *((uint32_t *) (uintptr_t)(BUFFER_ADDR + 0x4*(BUFFER_SIZE - 1)));
		}
		UART_printf("RC received data, loopback test passed\n");
	}
	if (PcieModeGbl == pcie_EP_MODE) {
		//Wait data to coming in
		while (data_arrived != 0xF) {
			data_arrived = *((uint32_t *) (uintptr_t)(BUFFER_ADDR + 0x4*(BUFFER_SIZE - 1)));
		}

		UART_printf("EP received data and will write back\n");

		BoardDiag_testObWrite(pcieInstance);
	}	

    return 0;
}



/**
 * \brief  main function
 *
 *  This function performs board initializations and calls pcie test
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 */
int main(void)
{
    Board_initCfg boardCfg;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO |
               BOARD_INIT_SERDES_PHY;
#else
    boardCfg = BOARD_INIT_UART_STDIO | BOARD_INIT_SERDES_PHY;
#endif  /*  #ifdef PDK_RAW_BOOT */
    Board_init(boardCfg);
    return BoardDiag_pcieTest();
}
