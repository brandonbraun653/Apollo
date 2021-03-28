/*
 * \file     cpsw_test.h
 *
 * \brief
 *
 */

/* Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/*****************************************************************************
**                   MACRO DEFINITIONS
*****************************************************************************/
#define MDIO_FREQ_INPUT       125000000
#define MDIO_FREQ_OUTPUT        1000000

#define CPPI_RAM_SIZE         0x2000
#define BUFFER_BASE           0x88000000
#define BUFFER_SIZE           0x7ff

#define SOF_BIT               (1u<<31)
#define EOF_BIT               (1<<30)
#define SOF_AND_EOF_BIT       (SOF_BIT|EOF_BIT)
#define OWNERSHIP_BIT         (1<<29)
#define EOQ_BIT               (1<<28)
#define PASSCRC_BIT           (1<<26)
#define TOPORT_EN_BIT         (1<<20)
#define SIZE_MASK             0x0000ffff
#define ERRORS_MASK           0x03fe0000

#define TX_NUM_DESC           32
#define RX_NUM_DESC           32

#define NUM_RX_SERVICE        128
#define NUM_TX_SERVICE        128

#define RX                    0
#define TX                    1

#define TEST_NUM_PACKETS      TX_NUM_DESC

#define CPSW_MII_SEL_MODE           0x0
#define CPSW_RMII_SEL_MODE          0x1
#define CPSW_RGMII_SEL_MODE         0x2
#define CPSW_MDIO_SEL_MODE          0x0
#define CPSW_RMII1_REFCLK_SEL_MODE  0x0

//link setup speed options
#define SPEED_10H           0x0
#define SPEED_10F           0x1
#define SPEED_100H          0x2
#define SPEED_100F          0x3
#define SPEED_1000F         0x4
#define SPEED_LB            0x5 //loopback


//phy clock generator I2C addresses
#define PHY_CLK_GEN_0_I2C_ADDR          0x65 //PRU1ETH0, PRU1ETH1, ETH0GB
#define PHY_CLK_GEN_1_I2C_ADDR          0x65 //PRU2ETH0, PRU2ETH1, ETH1GB

/* Clock Synthesizer Registers*/
/*Generic Configuration Register*/
#define ID_REG    0x00
#define XCSEL     0x05

/*PLL1 Configuration Register*/
#define MUX_REG   0x14
#define PDIV2_REG 0x16
#define PDIV3_REG 0x17

//phy types
#define PHY_MICREL_KSZ9031RNX   0x0
#define PHY_ATHEROS_AR8031      0x1
#define PHY_TI_DP83848J         0x2
#define PHY_TI_TLK110           0x3
#define PHY_SMSC_LAN8710        0x4

typedef struct Desc
{
  Uint32 NextDesc;
  Uint32 BufPtr;
  Uint32 Off_BufLen;
  Uint32 Flags_PktLen;

  // original queue to help keep track to return descriptor after rx/tx
  Uint32 OrigQueue;
}Desc;

typedef struct
{
  Uint16 UpperDstMac;
  Uint32 LowerDstMac;
  Uint16 UpperSrcMac;
  Uint32 LowerSrcMac;
  Uint16 Type;
}  __attribute__ ((__packed__)) ETH_HEADER;

typedef struct
{
  ETH_HEADER    Eth;
  Uint8         Data;
} __attribute__ ((__packed__)) ETH_PKT;


//****************************************************************************
// Cpsw Functions
//****************************************************************************
Uint32 LinkSetup(Uint32 port, Uint32 speed);
void CPSWAleWriteEntry(Uint32 entry, Uint32 w2, Uint32 w1, Uint32 w0);
void CPSWAleDumpTable(void);
void CPSWStatsDump(void);
void CPSWStatsClear(void);
void CpswInit(Uint32 base);
void CpgmacSlInit(Uint32 base);
void AleInit(Uint32 base);
void CpswCpdmaInit(Uint32 base);
void CpswWrInit(Uint32 base);
void DescInit(void);
void ServiceRx(void *arg); //unsigned int intrNum, unsigned int cpuId, unsigned int applnParam);
void ServiceTx(void *arg); //unsigned int intrNum, unsigned int cpuId, unsigned int applnParam);
void HostStats(void);
void TxPacket(Desc *TxDesc);
void CpswIntEnable(Uint32 dir);
int CpswIntDisable(Uint32 dir);
void DumpQueue(Uint32 channel);
void DebugStats(void);
void CPSWALELearnModeEnable(unsigned int baseAddr, unsigned int  portNum);
void CPSWWrIntPacingEnable(unsigned int baseAddr, unsigned int pacFlag);
void CPSWWrIntTxPerMsSet(unsigned int baseAddr, unsigned int core, unsigned int txIntPerMs);
void CPSWWrIntRxPerMsSet(unsigned int baseAddr, unsigned int core, unsigned int rxIntPerMs);
void CPSWWrIntPacingDisable(unsigned int baseAddr, unsigned int pacFlag);
void mdioDump(void);

//****************************************************************************
// cycle counter Functions
//****************************************************************************
extern void CycleCountEnable(void);
extern unsigned int CycleCounterRegRead(void);
