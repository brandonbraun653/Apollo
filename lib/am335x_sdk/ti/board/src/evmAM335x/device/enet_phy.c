/**
 * enet_phy.c
 *
 *
 * Copyright (c) 2012 Texas Instruments Incorporated ALL RIGHTS RESERVED
 *
*/

#include <stdio.h>
#include <ti/csl/cslr_mdio.h>
#include <ti/csl/src/ip/mdio/V2/cslr_mdio.h>
#include <ti/csl/csl_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdio.h>
#include <ti/csl/csl_mdioAux.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdioAux.h>
#include <ti/board/src/evmAM335x/device/enet_phy.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/drv/uart/UART_stdio.h>

/* R A N D O M  N U M B E R  S U P P O R T */
#define COMMON_RANDOM_MAX        0xFFFFu

/* Enable the below macro to have prints on the IO Console */
//#define IO_CONSOLE

#ifndef IO_CONSOLE
#define ENET_PHY_log                UART_printf
#else
#define ENET_PHY_log                printf
#endif

static uint32_t RandomSeed = 1u;

static uint32_t cpswRandom(void)
{
  RandomSeed = (RandomSeed * (1103515245u)) + (12345u);
  return ((uint32_t) (RandomSeed/(65536u)) % (COMMON_RANDOM_MAX + 1u));
}


static uint32_t cpswRandomRange(uint32_t min, uint32_t max)
{
  uint32_t iTmp;

  iTmp =  cpswRandom();
  iTmp %= ((max - min) + 1u);
  iTmp += min;
  return(iTmp);
}

static void ENETPHY_DisablePhy(ENETPHY_Handle hPhyDev,uint32_t PhyNum);
static void ENETPHY_PhyTimeOut(ENETPHY_Handle hPhyDev);
static void ENETPHY_ResetPhy(ENETPHY_Handle hPhyDev,uint32_t PhyNum);


static void ENETPHY_DefaultState  (ENETPHY_Handle hPhyDev);
static void ENETPHY_FindingState  (ENETPHY_Handle hPhyDev);
static void ENETPHY_FoundState    (ENETPHY_Handle hPhyDev);
static void ENETPHY_InitState     (ENETPHY_Handle hPhyDev);
static void ENETPHY_LinkedState   (ENETPHY_Handle hPhyDev);
static void ENETPHY_LinkWaitState (ENETPHY_Handle hPhyDev);
static void ENETPHY_LoopbackState (ENETPHY_Handle hPhyDev);
static void ENETPHY_NwayStartState(ENETPHY_Handle hPhyDev);
static void ENETPHY_NwayWaitState (ENETPHY_Handle hPhyDev);

#define   _cpswIsGigPhy(hPhyDev) 	(TRUE)

#define ENETPHY_NOT_FOUND  0xFFFFu    /*  Used in Phy Detection */

/*CHECK:: PhyState field breakup  */
#define ENETPHY_DEV_OFFSET      (0u)
#define ENETPHY_DEV_SIZE        (5u)
#define ENETPHY_DEV_MASK        (0x1f<<ENETPHY_DEV_OFFSET)

#define ENETPHY_STATE_OFFSET    (ENETPHY_DEV_SIZE+ENETPHY_DEV_OFFSET)
#define ENETPHY_STATE_SIZE      (5u)
#define ENETPHY_STATE_MASK      (0x1fu<<ENETPHY_STATE_OFFSET)
    #define INIT       (1u<<ENETPHY_STATE_OFFSET)
    #define FINDING    (2u<<ENETPHY_STATE_OFFSET)
    #define FOUND      (3u<<ENETPHY_STATE_OFFSET)
    #define NWAY_START (4u<<ENETPHY_STATE_OFFSET)
    #define NWAY_WAIT  (5u<<ENETPHY_STATE_OFFSET)
    #define LINK_WAIT  (6u<<ENETPHY_STATE_OFFSET)
    #define LINKED     (7u<<ENETPHY_STATE_OFFSET)
    #define LOOPBACK   (8u<<ENETPHY_STATE_OFFSET)

#define ENETPHY_SPEED_OFFSET    (ENETPHY_STATE_OFFSET+ENETPHY_STATE_SIZE)
#define ENETPHY_SPEED_SIZE      (1u)
#define ENETPHY_SPEED_MASK_NDK      (1u<<ENETPHY_SPEED_OFFSET)

#define ENETPHY_DUPLEX_OFFSET   (ENETPHY_SPEED_OFFSET+ENETPHY_SPEED_SIZE)
#define ENETPHY_DUPLEX_SIZE     (1u)
#define ENETPHY_DUPLEX_MASK     (1u<<ENETPHY_DUPLEX_OFFSET)

#define ENETPHY_TIM_OFFSET      (ENETPHY_DUPLEX_OFFSET+ENETPHY_DUPLEX_SIZE)
#define ENETPHY_TIM_SIZE        (10u)
#define ENETPHY_TIM_MASK        (0x3ffu<<ENETPHY_TIM_OFFSET)

/* we are working with 100ms ticks here */
  #define ENETPHY_FIND_TO (  1u<<ENETPHY_TIM_OFFSET)
    #define ENETPHY_RECK_TO (20u<<ENETPHY_TIM_OFFSET)
    #define ENETPHY_LINK_TO (50u<<ENETPHY_TIM_OFFSET)
    #define ENETPHY_NWST_TO (50u<<ENETPHY_TIM_OFFSET)
    #define ENETPHY_NWDN_TO (80u<<ENETPHY_TIM_OFFSET)
    #define ENETPHY_MDIX_TO (27u<<ENETPHY_TIM_OFFSET) /* 2.74 Seconds <--Spec and empirical */

#define ENETPHY_SMODE_OFFSET    (ENETPHY_TIM_OFFSET+ENETPHY_TIM_SIZE)
#define ENETPHY_SMODE_SIZE      (7u)
#define ENETPHY_SMODE_MASK      (0x7fu<<ENETPHY_SMODE_OFFSET)
    #define SMODE_LPBK   (0x40u<<ENETPHY_SMODE_OFFSET)
    #define SMODE_AUTO   (0x20u<<ENETPHY_SMODE_OFFSET)
    #define SMODE_FD1000 (0x10u<<ENETPHY_SMODE_OFFSET)
    #define SMODE_FD100  (0x08u<<ENETPHY_SMODE_OFFSET)
    #define SMODE_HD100  (0x04u<<ENETPHY_SMODE_OFFSET)
    #define SMODE_FD10   (0x02u<<ENETPHY_SMODE_OFFSET)
    #define SMODE_HD10   (0x01u<<ENETPHY_SMODE_OFFSET)
    #define SMODE_ALL    (0x1fu<<ENETPHY_SMODE_OFFSET)

#define ENETPHY_CHNG_OFFSET    (ENETPHY_SMODE_OFFSET+ENETPHY_SMODE_SIZE)
#define ENETPHY_CHNG_SIZE      (1u)
#define ENETPHY_CHNG_MASK      (1u<<ENETPHY_CHNG_OFFSET)
    #define ENETPHY_CHANGE (1u<<ENETPHY_CHNG_OFFSET)

#define ENETPHY_TIMEDOUT_OFFSET    (ENETPHY_CHNG_OFFSET+ENETPHY_CHNG_SIZE)
#define ENETPHY_TIMEDOUT_SIZE      (1u)     /*  30 Bits used */
#define ENETPHY_TIMEDOUT_MASK   ((uint32_t)(1u<<ENETPHY_TIMEDOUT_OFFSET))
#define ENETPHY_MDIX_SWITCH     ((uint32_t)(1u<<ENETPHY_TIMEDOUT_OFFSET))

#define ENETPHY_MDIX_OFFSET    (ENETPHY_TIMEDOUT_OFFSET+ENETPHY_TIMEDOUT_SIZE)
#define ENETPHY_MDIX_SIZE      (1u)     /*  31 Bits used */
#define ENETPHY_MDIX_MASK      ((uint32_t)(1u<<ENETPHY_MDIX_OFFSET))
#define ENETPHY_MDIX           ((uint32_t)(1u<<ENETPHY_MDIX_OFFSET))


#ifndef VOLATILE32
#define VOLATILE32(addr) (*((volatile uint32_t *)(addr)))
#endif

int32_t cpsw_g_speed_set = 0;
int32_t cpsw_g_soft_reset_status = 0;

/*User Calls*********************************************************       */

/* Updates book-keeping with info provided, programs ControlReg
 * with clkdiv,enable bits*/
int32_t ENETPHY_Init(ENETPHY_Handle hPhyDev, uint32_t miibase, uint32_t inst, uint32_t PhyMask, uint32_t MLinkMask, uint32_t MdixMask, uint32_t PhyAddr, uint32_t ResetBit, uint32_t MdioBusFreq, uint32_t MdioClockFreq,int32_t verbose)
{
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;

  int32_t  ret =0 ;
  uint32_t phy;

  ((ENETPHY_DEVICE *) hPhyDev)->miibase   = miibase;
  ((ENETPHY_DEVICE *) hPhyDev)->inst      = inst;
  ((ENETPHY_DEVICE *) hPhyDev)->PhyMask   = PhyMask;
  ((ENETPHY_DEVICE *) hPhyDev)->MLinkMask = MLinkMask;
  ((ENETPHY_DEVICE *) hPhyDev)->MdixMask  = MdixMask;

  (void)verbose;/* remove if not required */

  *PhyState &= ~ENETPHY_MDIX_MASK;   /* Set initial State to MDI */

  CSL_MDIO_setClkDivVal((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase, (MdioBusFreq/MdioClockFreq - 1));
  CSL_MDIO_enableFaultDetect((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase);
  CSL_MDIO_disablePreamble((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase);
  CSL_MDIO_enableStateMachine((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase);

  ENETPHY_UserAccessRead(hPhyDev, ENETPHY_CNTRL_REG, PhyAddr, &phy);
  phy |= NWAY_AUTOMDIX_ENABLE;
  ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_CNTRL_REG,PhyAddr,phy);

	(void)ResetBit; /* suppress warning */

	*PhyState=INIT;

    ret = 0;

  return ret;
}/* end of function ENETPHY_Init*/

void ENETPHY_SetPhyMode(ENETPHY_Handle hPhyDev,uint32_t PhyMode)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  uint32_t CurrentState;

  ((ENETPHY_DEVICE *) hPhyDev)->PhyMode = PhyMode;   /* used for AUTOMIDX, planned to replace PhyState fields */
  *PhyState &= (~ENETPHY_SMODE_MASK);

  if (0u != (PhyMode & NWAY_LPBK))
    {
    *PhyState |= SMODE_LPBK;
    }
  if (0u != (PhyMode & NWAY_AUTO))
    {
     *PhyState |= SMODE_AUTO;
    }
  if (0u != (PhyMode & NWAY_FD1000) )
    {
    *PhyState |= SMODE_FD1000;
    }
  if (0u!= (PhyMode & NWAY_FD100))
    {
    *PhyState |= SMODE_FD100;
    }
  if (0u != (PhyMode & NWAY_HD100))
    {
    *PhyState |= SMODE_HD100;
    }
  if (0u != (PhyMode & NWAY_FD10))
    {
    *PhyState |= SMODE_FD10;
    }
  if (0u != (PhyMode & NWAY_HD10))
    {
    *PhyState |= SMODE_HD10;
    }

  CurrentState = (*PhyState) & ENETPHY_STATE_MASK;
  if ( ((CurrentState == NWAY_START)|| (CurrentState == NWAY_WAIT)) ||
       ( ((CurrentState == LINK_WAIT) || (CurrentState == LINKED) ) || (CurrentState == LOOPBACK)) )
    {
    *PhyState = ( (*PhyState)&(~ENETPHY_STATE_MASK)) | (FOUND | ENETPHY_CHANGE);
    }

     ENET_PHY_log("SetPhyMode:%08x Auto:%d, FD10:%d, HD10:%d, FD100:%d, HD100:%d, FD1000:%d LPBK:%d\n", (unsigned int)PhyMode,
     (unsigned int)(PhyMode & NWAY_AUTO), (unsigned int)(PhyMode & MII_NWAY_FD10),(unsigned int)(PhyMode & MII_NWAY_HD10),(unsigned int)(PhyMode & MII_NWAY_FD100),
     (unsigned int)(PhyMode & MII_NWAY_HD100), (unsigned int)(PhyMode & NWAY_FD1000),
     (unsigned int)(PhyMode & NWAY_LPBK)  );

	  }

uint32_t ENETPHY_GetPhyMode(ENETPHY_Handle hPhyDev)
{
    uint32_t  PhyMode =0;
    uint32_t  status_reg = 0,control_reg = 0,advertize_reg;
    uint32_t  PhyNum,j;
    uint32_t  PhyMask   = ((ENETPHY_DEVICE *) hPhyDev)->PhyMask;

    PhyNum = 0;
    for(j = 1;PhyNum < 32;PhyNum++)
    {
      if( 0u != ( j & PhyMask))
	{
	break;
	}
      j = j<<1;
    }

    if(0u != _cpswIsGigPhy(hPhyDev))
    {
       /* read gig status */
       ENETPHY_UserAccessRead(hPhyDev, ENETPHY_1000BT_CONTROL, PhyNum, &control_reg);
       /* read gig status */
       ENETPHY_UserAccessRead(hPhyDev, ENETPHY_1000BT_STATUS, PhyNum, &status_reg);
    }
    /* figure out if gig connected at FD 1000 or not first */
    if ((0u != (control_reg & MII_NWAY_MY_FD1000)) && (0u != (status_reg & MII_NWAY_REM_FD1000)) )
    {
        PhyMode |= NWAY_FD1000;
    }

    ENETPHY_UserAccessRead(hPhyDev, ENETPHY_BCR, PhyNum, &control_reg);
    if(0u != (control_reg & MII_AUTO_NEGOTIATE_EN)  )
    {
       PhyMode |= NWAY_AUTO;
    }
    ENETPHY_UserAccessRead(hPhyDev, ENETPHY_BSR, PhyNum, &status_reg);
    ENETPHY_UserAccessRead(hPhyDev, ENETPHY_AUTONEG_ADV, PhyNum, &advertize_reg);

    /* Check for 10/100 capabilities of PHYs */
    if((0u != (control_reg & MII_ENETPHY_100))|| (0u != (PhyMode & NWAY_AUTO)) )
    {
       if(0u != (advertize_reg & MII_NWAY_FD100))
	    {
	    PhyMode |= NWAY_FD100;
	    }
       if(0u != (advertize_reg & MII_NWAY_HD100))
	    {
	    PhyMode |= NWAY_HD100;
	    }

    }

    if(((control_reg & MII_ENETPHY_100) == 0) || (0u != (PhyMode & NWAY_AUTO)) )
    {
       if(0u != (advertize_reg & MII_NWAY_FD10))
	    {
	    PhyMode |= NWAY_FD10;
	    }
       if(0u != (advertize_reg & MII_NWAY_HD10))
	    {
	    PhyMode |= NWAY_HD10;
	    }

    }
    return PhyMode;
}
/* ENETPHY_Tic is called every 10 mili seconds to process Phy states         */

int32_t ENETPHY_Tic(ENETPHY_Handle hPhyDev,uint32_t* mdioStatus)
{
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  uint32_t  CurrentState;
  int32_t   ret = 0;

  *mdioStatus = MDIO_EVENT_NOCHANGE;

  /*Act on current state of the Phy */
  CurrentState=*PhyState;
  switch(CurrentState&ENETPHY_STATE_MASK)
    {
    case INIT:         ENETPHY_InitState(hPhyDev);      break;
    case FINDING:      ENETPHY_FindingState(hPhyDev);   break;
    case FOUND:        ENETPHY_FoundState(hPhyDev);     break;
    case NWAY_START:   ENETPHY_NwayStartState(hPhyDev); break;
    case NWAY_WAIT:    ENETPHY_NwayWaitState(hPhyDev);  break;
    case LINK_WAIT:    ENETPHY_LinkWaitState(hPhyDev);  break;
    case LINKED:       ENETPHY_LinkedState(hPhyDev);    break;
    case LOOPBACK:     ENETPHY_LoopbackState(hPhyDev);  break;
    default:           ENETPHY_DefaultState(hPhyDev);   break;
    }

  /*  Check is MDI/MDIX mode switch is needed */

  if(0u != ((*PhyState) & ENETPHY_MDIX_SWITCH) )
    {

    uint32_t Mdix;

    *PhyState &= (~ENETPHY_MDIX_SWITCH);  /* Clear Mdix Flip indicator */

    if(0u != ((*PhyState) & ENETPHY_MDIX))
	{
      Mdix = 1;
	}
    else
	{
      Mdix = 0;
    }
    ret = (int32_t)(_MIIMDIO_MDIXFLIP | Mdix);

    }
  else
    {

  /*Return state change to user */
  /** CHECK : report MDIO_LINKEVENTS as MDIO_EVENT_NOCHANGE, MDIO_EVENT_LINKDOWN,
   * MDIO_EVENT_PHYERROR,MDIO_EVENT_LINKUP
   * Currently ENETPHY_CHNG_MASK set for any state transition*/

    if (0u != ((*PhyState) & ENETPHY_CHNG_MASK))
   {
	if(  ( ((*PhyState) & ENETPHY_STATE_MASK) == LINKED) && ((CurrentState & ENETPHY_STATE_MASK) != LINKED) )
		{
		/* we have just entered LInked state */
		*mdioStatus = MDIO_EVENT_LINKUP;
		}
	if(  ((CurrentState & ENETPHY_STATE_MASK) == LINKED) && ( ( (*PhyState) & ENETPHY_STATE_MASK) != LINKED))
		{
		/* we started in Linked state and we have a state change */
		*mdioStatus = MDIO_EVENT_LINKDOWN;
		}
	*PhyState &= (~ENETPHY_CHNG_MASK);
	ret = (int32_t)(TRUE);
    }
   else
   {
	ret = (int32_t)(FALSE);
	}
    }

  return ret;

}


void ENETPHY_LinkChange(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  uint32_t  PhyNum,PhyStatus;

  PhyNum = ( (*PhyState) & ENETPHY_DEV_MASK) >> ENETPHY_DEV_OFFSET;

  ENET_PHY_log("ENETPHY_LinkChange: PhyNum = %d\n", (unsigned int)PhyNum);

  if (0u != (ENETPHY_GetLinked(hPhyDev)) )
    {
    ENETPHY_UserAccessRead(hPhyDev, ENETPHY_BSR, PhyNum, &PhyStatus);

    if ((PhyStatus & MII_ENETPHY_LINKED) == 0u)
      {
      *PhyState &= (~(ENETPHY_TIM_MASK | ENETPHY_STATE_MASK));
      if (0u!=((*PhyState) & SMODE_AUTO))
        {
        ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_BCR, PhyNum, MII_AUTO_NEGOTIATE_EN|MII_RENEGOTIATE);
        *PhyState |= ((ENETPHY_CHANGE | ENETPHY_NWST_TO) | NWAY_START);
        }
       else
        {
        *PhyState|= ((ENETPHY_CHANGE | ENETPHY_LINK_TO) | LINK_WAIT);
        }
      }
    }
  }

  /* returns 0 if current Phy has AutoMdix support, otherwise 0 */
static int32_t ENETPHY_MdixSupported(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  uint32_t PhyNum;
  int32_t ret;

  if((((ENETPHY_DEVICE *) hPhyDev)->PhyMode & NWAY_AUTOMDIX) == 0)
  {
    ret = (0);  /* AutoMdix not turned on */
  }
  else
  {
    PhyNum = ((*PhyState) & ENETPHY_DEV_MASK) >> ENETPHY_DEV_OFFSET;
  if( ((1<<PhyNum) & ((ENETPHY_DEVICE *) hPhyDev)->MdixMask) == 0)
    {
	ret = 0;  /*  Phy does not support AutoMdix*/
    }

    ret = 1;
  }
  return ret;
  }

/* If current Phy has AutoMdix support add Mdix Delay to the Timer State Value */
static void ENETPHY_MdixDelay(ENETPHY_Handle hPhyDev)
  {
  uint32_t Delay;
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;


  if(ENETPHY_MdixSupported(hPhyDev) != 0)
    {
  /* Get the Delay value in milli-seconds and convert to ten-milli second value */
  Delay = cpswRandomRange(_AUTOMDIX_DELAY_MIN, _AUTOMDIX_DELAY_MAX);
  Delay /= 10;

  /*  Add AutoMidx Random Switch Delay to AutoMdix Link Delay */

  Delay += (ENETPHY_MDIX_TO>>ENETPHY_TIM_OFFSET);

  /* Change Timeout value to AutoMdix standard */
    *PhyState &= (~(ENETPHY_TIM_MASK));  /* Clear current Time out value */
  *PhyState |=  (Delay<<ENETPHY_TIM_OFFSET);     /* Set new value */
    }
  return;

  }

void ENETPHY_DisablePhy(ENETPHY_Handle hPhyDev,uint32_t PhyNum)
  {
  ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_BCR, PhyNum, (MII_ENETPHY_ISOLATE | MII_ENETPHY_PDOWN) );

  ENET_PHY_log("ENETPHY_DisablePhy(%d)\n",(unsigned int)PhyNum);

  }

void ENETPHY_InitState(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  uint32_t CurrentState;

  CurrentState=*PhyState;
  CurrentState = (CurrentState & (~ENETPHY_TIM_MASK)) | (ENETPHY_FIND_TO);
  CurrentState=(CurrentState & (~ENETPHY_STATE_MASK)) | (FINDING);
  CurrentState=(CurrentState & (~ENETPHY_SPEED_MASK_NDK));
  CurrentState=(CurrentState & (~ENETPHY_DUPLEX_MASK));
  CurrentState|=ENETPHY_CHANGE;

  *PhyState=CurrentState;

  }

void ENETPHY_FindingState(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  uint32_t  PhyMask  = ((ENETPHY_DEVICE *) hPhyDev)->PhyMask;
  uint32_t  PhyNum,i,j;

  PhyNum=ENETPHY_NOT_FOUND;

  if (0u!= ((*PhyState) & ENETPHY_TIM_MASK))
    {
    *PhyState=( (*PhyState) & (~ENETPHY_TIM_MASK) ) | (( (*PhyState) & ENETPHY_TIM_MASK) - (1 << ENETPHY_TIM_OFFSET));
    }
   else
    {
    j =1;
    for(i=0; i<32; i++)
        {
        if( PhyMask & j)
            {
            if( CSL_MDIO_isPhyAlive((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase, i))
                {
                    PhyNum=i;
                    break;
                }
            }
        j = j << 1;
        }
    if (PhyNum!=ENETPHY_NOT_FOUND)
      {
      /*  Phy Found! */
      *PhyState = ((*PhyState) & (~ENETPHY_DEV_MASK) ) | ((PhyNum & ENETPHY_DEV_MASK) << ENETPHY_DEV_OFFSET);
      *PhyState = ( (*PhyState) & (~ENETPHY_STATE_MASK) ) | (FOUND);
      *PhyState|=ENETPHY_CHANGE;

      ENET_PHY_log("ENETPHY_FindingState: PhyNum: %d\n",(unsigned int)PhyNum);

      }
     else
      {

      ENET_PHY_log("ENETPHY_FindingState: Timed Out looking for a Phy!\n");
      *PhyState|=ENETPHY_RECK_TO;  /* Set Timer */
      }
    }
  }

void ENETPHY_FoundState(ENETPHY_Handle hPhyDev)
 {
  uint32_t *PhyState  = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  uint32_t  PhyMask   = ((ENETPHY_DEVICE *) hPhyDev)->PhyMask;
  uint32_t  MLinkMask = ((ENETPHY_DEVICE *) hPhyDev)->MLinkMask;
  uint32_t  PhyNum,PhyStatus,NWAYadvertise,NWAY1000advertise=0,m,phynum,i,j;
  uint32_t PhyDummy;

  static  uint32_t auto_neg1 = 0xFFFFFFFF,auto_neg2= 0xFFFFFFFF;


  if (( (*PhyState) & ENETPHY_SMODE_MASK) == 0)
    {
    return;
    }

  PhyNum = ((*PhyState) & ENETPHY_DEV_MASK) >> ENETPHY_DEV_OFFSET;
    j =1;
    for(phynum=0; phynum<32; phynum++)
        {
        if(0u!= (PhyMask & j))
            {
            if( CSL_MDIO_isPhyAlive((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase, phynum))
                {
                    ENETPHY_DisablePhy(hPhyDev,phynum);
                }
            }
        j = j << 1;
        }
  /* If Aries SWR2 reset then don't reset phy*/
  /*  Reset the Phy and proceed with auto-negotiation */
  if(( 0u != cpsw_g_speed_set) || ((0u ==cpsw_g_soft_reset_status) || ((auto_neg1 & (1 << PhyNum)) == 0) )  )
  {
      ENETPHY_ResetPhy(hPhyDev,PhyNum);
  }

  /*  Set the way Link will be Monitored */
  /* Check the Link Selection Method */
  if (0u != ((1 << PhyNum) & MLinkMask) )
    {
  CSL_MDIO_enableLinkStatusChangeInterrupt((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase,  ((ENETPHY_DEVICE *) hPhyDev)->inst, PhyNum);
    }
    else
    {
  CSL_MDIO_disableLinkStatusChangeInterrupt((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase,  ((ENETPHY_DEVICE *) hPhyDev)->inst, PhyNum);
    }
  /* Get the Phy Status */
  ENETPHY_UserAccessRead(hPhyDev, ENETPHY_BSR, PhyNum, &PhyStatus);


 /*  For Phy Internal loopback test, need to wait until Phy
      found, then set Loopback */
  if (0u != ((*PhyState) & SMODE_LPBK))
    {
    /* Set Phy in Loopback */

    ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_BCR, PhyNum, MII_ENETPHY_LOOP|MII_ENETPHY_FD);
    /* Do a read to ensure ENETPHY_LOOP has completed */
    ENETPHY_UserAccessRead(hPhyDev, ENETPHY_BSR, PhyNum, &PhyDummy);
    *PhyState = ( (*PhyState) & (~ENETPHY_STATE_MASK) ) | (LOOPBACK);
    *PhyState|=ENETPHY_CHANGE;
    return;
    }

  ENET_PHY_log("Enable Phy to negotiate external connection\n");


  NWAYadvertise=MII_NWAY_SEL;
  if (0u != ((*PhyState) & SMODE_FD100))
  {
    NWAYadvertise |= MII_NWAY_FD100;
    }
  if (0u != ((*PhyState) & SMODE_HD100))
    {
    NWAYadvertise |= MII_NWAY_HD100;
    }
  if (0u != ((*PhyState) & SMODE_FD10))
    {
    NWAYadvertise |= MII_NWAY_FD10;
    }
  if (0u != ((*PhyState) & SMODE_HD10))
    {
    NWAYadvertise |= MII_NWAY_HD10;
    }
  if (0u != ((*PhyState) & SMODE_FD1000))
    {
	  NWAY1000advertise= ENETPHY_1000BT_FD;
    }

  *PhyState &= ( ~(ENETPHY_TIM_MASK | ENETPHY_STATE_MASK));
  if ((0u != (PhyStatus & MII_NWAY_CAPABLE)) && (0u != ( (*PhyState) & SMODE_AUTO)) )   /*NWAY Phy Detected*/
  {
    if(( 0u != cpsw_g_speed_set) || ((0u ==cpsw_g_soft_reset_status) || ((auto_neg1 & (1 << PhyNum)) == 0) )  )
    {
       /*For NWAY compliant Phys                                                */
	ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_AUTONEG_ADV, PhyNum, NWAYadvertise);
       /* for gig negotiation */
      if(0u != _cpswIsGigPhy(hPhyDev))
      {
          ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_1000BT_CONTROL, PhyNum, NWAY1000advertise);
      }

      ENET_PHY_log("NWAY Advertising: ");
      if (0u != ((*PhyState) & SMODE_FD1000))
	{
	ENET_PHY_log("FullDuplex-1000 ");
	}
      if (0u != (NWAYadvertise & MII_NWAY_FD100))
	{
	ENET_PHY_log("FullDuplex-100 ");
	}
      if (0u != (NWAYadvertise & MII_NWAY_HD100))
	{
	ENET_PHY_log("HalfDuplex-100 ");
	}
      if (0u != (NWAYadvertise & MII_NWAY_FD10))
	{
	ENET_PHY_log("FullDuplex-10 ");
	}
      if (0u != (NWAYadvertise & MII_NWAY_HD10))
	{
	ENET_PHY_log("HalfDuplex-10 ");
	}

      ENET_PHY_log("\n");

      ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_BCR, PhyNum, MII_AUTO_NEGOTIATE_EN );
      ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_BCR, PhyNum, MII_AUTO_NEGOTIATE_EN|MII_RENEGOTIATE|MII_ENETPHY_FD);
     *PhyState|= ( (ENETPHY_CHANGE | ENETPHY_NWST_TO) | NWAY_START);
    }
    else
    {
      *PhyState |= ( (ENETPHY_CHANGE | ENETPHY_NWST_TO) | NWAY_START);
      auto_neg1 = auto_neg1 & (~(1 << PhyNum));
    }
  }
  else
  {
    *PhyState &= (~SMODE_AUTO);   /*The Phy is not capable of auto negotiation!  */
    m=NWAYadvertise;
    j = 0x8000u;

    for(i=0;(i<16);i++)
    {
	if(0u != (j & m))
	{
	    break;
	}
	j = j >> 1 ;

    }
    m=j;
    j=0;

    /* figure out if gig connected at FD 1000 or not first */
    if ((NWAY1000advertise & MII_NWAY_MY_FD1000)== MII_NWAY_MY_FD1000)
    {
         j = MII_ENETPHY_1000;
         j |= MII_ENETPHY_FD;
    }
    else
    {
        if (0u != (m & (MII_NWAY_FD100 | MII_NWAY_HD100)) )
        {
           j=MII_ENETPHY_100;
           m&=(MII_NWAY_FD100|MII_NWAY_HD100);
        }
        if (0u != (m & (MII_NWAY_FD100 | MII_NWAY_FD10)) )
	    {
           j |= MII_ENETPHY_FD;
    }
    }

    ENET_PHY_log("Requested PHY mode %s Duplex %s Mbps\n",(j & MII_ENETPHY_FD) ? "Full":"Half",
			(j & MII_ENETPHY_1000) ? "1000":((j & MII_ENETPHY_100) ? "100":"10"));

    if((0u != cpsw_g_speed_set) || ( (0u == cpsw_g_soft_reset_status) || ((auto_neg2 & (1 << PhyNum)) == 0) ))
    {
       if(0u != (j & MII_ENETPHY_1000))
       {
          ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_1000BT_CONTROL, PhyNum, j);
       }
       else
       {
           ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_BCR, PhyNum, j);
           ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_AUTONEG_ADV, PhyNum, NWAYadvertise);
       }
       cpsw_g_speed_set = 0;
    }
    else
    {
       auto_neg2 = auto_neg2 & (~(1 << PhyNum));
    }
    *PhyState &= (~ENETPHY_SPEED_MASK_NDK);
    if(0u != (j & MII_ENETPHY_1000) )
    {
        *PhyState|=(1<<ENETPHY_DUPLEX_OFFSET);
        ((ENETPHY_DEVICE *) hPhyDev)->SPEED_1000 = 1;
    }
    else
    {
        ((ENETPHY_DEVICE *) hPhyDev)->SPEED_1000 = 0;
    }
    if (0u != (j & MII_ENETPHY_100) )
    {
       *PhyState|=(1<<ENETPHY_SPEED_OFFSET);
    }
    *PhyState &= (~ENETPHY_DUPLEX_MASK);
    if (0u != (j & MII_ENETPHY_FD) )
    {
       *PhyState|=(1<<ENETPHY_DUPLEX_OFFSET);
    }
    *PhyState |= ((ENETPHY_CHANGE | ENETPHY_LINK_TO) | LINK_WAIT);
  }
    ENETPHY_MdixDelay(hPhyDev);  /* If AutoMdix add delay */

  }

void ENETPHY_ResetPhy(ENETPHY_Handle hPhyDev,uint32_t PhyNum)
  {
    uint32_t data;

    data = MII_ENETPHY_RESET;

    /* Reset the phy */
    ENETPHY_UserAccessWrite(hPhyDev, ENETPHY_BCR, PhyNum, data);

    /* wait till the reset bit is auto cleared */
    while(data & MII_ENETPHY_RESET)
    {
        /* Read the reset */
        if(ENETPHY_UserAccessRead(hPhyDev, ENETPHY_BCR, PhyNum, &data) != TRUE)
        {
            break;
        }
    }

  }

void ENETPHY_NwayStartState(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  uint32_t PhyNum,PhyMode,PhyDummy;

  PhyNum = ( (*PhyState) & ENETPHY_DEV_MASK) >> ENETPHY_DEV_OFFSET;

  /*Wait for Negotiation to start                                            */

  ENETPHY_UserAccessRead(hPhyDev, ENETPHY_BCR, PhyNum, &PhyMode);

  if((PhyMode&MII_RENEGOTIATE)==0)
    {
    ENETPHY_UserAccessRead(hPhyDev, ENETPHY_BSR, PhyNum,&PhyDummy); /*Flush pending latch bits*/
    *PhyState &= (~(ENETPHY_STATE_MASK|ENETPHY_TIM_MASK));
    *PhyState |= ((ENETPHY_CHANGE | NWAY_WAIT) |ENETPHY_NWDN_TO);
    ENETPHY_MdixDelay(hPhyDev);  /* If AutoMdix add delay */
    }
   else
    {
    if (0u != ((*PhyState) & ENETPHY_TIM_MASK) )
	{
	*PhyState=( (*PhyState) & (~ENETPHY_TIM_MASK)) | ( ( (*PhyState) & ENETPHY_TIM_MASK)-(1 << ENETPHY_TIM_OFFSET));
	}
     else
	{
      ENETPHY_PhyTimeOut(hPhyDev);
    }
  }
  }

void ENETPHY_NwayWaitState(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  uint32_t  PhyNum,PhyStatus,NWAYadvertise = 0,NWAYREadvertise = 0,NegMode,i,j;
  uint32_t NWAY1000advertise = 0, NWAY1000REMadvertise = 0;

  PhyNum=( (*PhyState) & ENETPHY_DEV_MASK) >> ENETPHY_DEV_OFFSET;

  ENETPHY_UserAccessRead(hPhyDev, ENETPHY_BSR, PhyNum, &PhyStatus);

  if (0u != (PhyStatus & MII_NWAY_COMPLETE))
    {
    *PhyState|=ENETPHY_CHANGE;
    *PhyState &= (~ENETPHY_SPEED_MASK_NDK);
    *PhyState &= (~ENETPHY_DUPLEX_MASK);

    ENETPHY_UserAccessRead(hPhyDev, ENETPHY_AUTONEG_ADV, PhyNum, &NWAYadvertise);
    ENETPHY_UserAccessRead(hPhyDev, ENETPHY_LINK_PARTNER_ABLTY, PhyNum, &NWAYREadvertise);
    /* read gig status */
    if(0u != _cpswIsGigPhy(hPhyDev))
    {
	ENETPHY_UserAccessRead(hPhyDev, ENETPHY_1000BT_CONTROL, PhyNum, &NWAY1000advertise);
	ENETPHY_UserAccessRead(hPhyDev, ENETPHY_1000BT_STATUS, PhyNum, &NWAY1000REMadvertise);
    }

    /* figure out if gig connected at FD 1000 or not first */
    if ((0u !=(NWAY1000advertise & MII_NWAY_MY_FD1000)) && (0u!=(NWAY1000REMadvertise & MII_NWAY_REM_FD1000)) )
	{
      NegMode = MII_NWAY_MY_FD1000;
	}
    else
	{
	NegMode = 0u;
	}

    if (NegMode == 0u)
      {
	/* continue checking for 100 and 10 connection */

	/* Negotiated mode is we and the remote have in common */
	NegMode = NWAYadvertise & NWAYREadvertise;

	ENET_PHY_log("Phy: %d, ",(unsigned int)( (*PhyState) & ENETPHY_DEV_MASK) >> ENETPHY_DEV_OFFSET);
	ENET_PHY_log("NegMode %04X, NWAYadvertise %04X, NWAYREadvertise %04X\n",
		   (unsigned int)NegMode,  (unsigned int)NWAYadvertise, (unsigned int)NWAYREadvertise);

	/* Limit negotiation to fields below */
	NegMode &= ( (MII_NWAY_FD100|MII_NWAY_HD100) | (MII_NWAY_FD10|MII_NWAY_HD10));

	if (NegMode == 0u)
	  {
	    NegMode=(MII_NWAY_HD100|MII_NWAY_HD10)&NWAYadvertise; /*or 10 ?? who knows, Phy is not MII compliant*/
	  }

	j = 0x8000u;
	for(i = 0; i <16 ; i++)
	{
	    if (0u != (j & NegMode))
	    {
		break;
	    }
	    j = j >> 1;
	}

	NegMode=j;


	ENET_PHY_log("Negotiated connection: ");


	if (0u != (NegMode & MII_NWAY_FD100))
	    {
		ENET_PHY_log("FullDuplex 100 Mbs\n");
	    }
	if (0u != (NegMode & MII_NWAY_HD100))
	    {
	    ENET_PHY_log("HalfDuplex 100 Mbs\n");
	    }
	if (0u != (NegMode & MII_NWAY_FD10))
	    {
	    ENET_PHY_log("FullDuplex 10 Mbs\n");
	    }
	if (0u != (NegMode & MII_NWAY_HD10))
	    {
	    ENET_PHY_log("HalfDuplex 10 Mbs\n");
	    }

	((ENETPHY_DEVICE *) hPhyDev)->SPEED_1000 = 0u;
      }
    else
      {

	/* found 1000 negotiated connection! */
	ENET_PHY_log("Negotiated connection: ");
	ENET_PHY_log("FullDuplex 1000 Mbs\n");

	((ENETPHY_DEVICE *) hPhyDev)->SPEED_1000 = 1u;
      }

    if (NegMode != 0u)
      {
      if (0u != (PhyStatus & MII_ENETPHY_LINKED))
	{
        *PhyState=( (*PhyState) & (~ENETPHY_STATE_MASK)) | LINKED;
	}
       else
	{
        *PhyState=( (*PhyState) & (~ENETPHY_STATE_MASK)) | LINK_WAIT;
	}
      if (0u != (NegMode & (MII_NWAY_FD100 | MII_NWAY_HD100)) )
	{
        *PhyState=( (*PhyState) & (~ENETPHY_SPEED_MASK_NDK)) | (1 << ENETPHY_SPEED_OFFSET);
	}
      if (0u != (NegMode & (MII_NWAY_FD100 | MII_NWAY_FD10 | MII_NWAY_MY_FD1000)))
	{
        *PhyState=( (*PhyState) & (~ENETPHY_DUPLEX_MASK)) | (1 << ENETPHY_DUPLEX_OFFSET);
	}
      }
    }
   else
    {
    if ( 0u != ( (*PhyState) & ENETPHY_TIM_MASK) )
	{
	*PhyState=( (*PhyState) & (~ENETPHY_TIM_MASK)) | (( (*PhyState) & ENETPHY_TIM_MASK)-(1 << ENETPHY_TIM_OFFSET));
	}
     else
	{
      ENETPHY_PhyTimeOut(hPhyDev);
    }
  }

  }

void ENETPHY_LinkWaitState(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  uint32_t  PhyStatus;
  uint32_t  PhyNum;

  PhyNum=( (*PhyState) & ENETPHY_DEV_MASK) >> ENETPHY_DEV_OFFSET;

  ENETPHY_UserAccessRead(hPhyDev, ENETPHY_BSR, PhyNum, &PhyStatus);

  if (0u != (PhyStatus & MII_ENETPHY_LINKED) )
    {
    *PhyState=( (*PhyState) & (~ENETPHY_STATE_MASK) ) | LINKED;
    *PhyState|=ENETPHY_CHANGE;
    }
   else
    {
    if (0u != ( (*PhyState) & ENETPHY_TIM_MASK)  )
	{
      *PhyState=(*PhyState&~ENETPHY_TIM_MASK)|((*PhyState&ENETPHY_TIM_MASK)-(1<<ENETPHY_TIM_OFFSET));
	}
     else
	{
      ENETPHY_PhyTimeOut(hPhyDev);
    }
  }
  }

void ENETPHY_PhyTimeOut(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState;
  if(ENETPHY_MdixSupported(hPhyDev) == 0)
    {
    return;  /* AutoMdix not supported */
    }
  PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;

  /*  Indicate MDI/MDIX mode switch is needed */
  *PhyState|=ENETPHY_MDIX_SWITCH;

  /* Toggle the MDIX mode indicatir */
  if(0u != ( (*PhyState) & ENETPHY_MDIX) )
    {
    *PhyState &= (~ENETPHY_MDIX_MASK);       /* Current State is MDIX, set to MDI */
    }
  else
    {
    *PhyState |=  ENETPHY_MDIX_MASK;      /* Current State is MDI, set to MDIX */
    }
  /* Reset state machine to FOUND */
  *PhyState = ( (*PhyState) & (~ENETPHY_STATE_MASK)) | (FOUND);
  }

void ENETPHY_LoopbackState(ENETPHY_Handle hPhyDev)
{
    (void)((ENETPHY_DEVICE *) hPhyDev); /* remove if not needed, to avoid warning */
  return;
}

void ENETPHY_LinkedState(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  uint32_t  PhyNum   = ( (*PhyState) & ENETPHY_DEV_MASK) >> ENETPHY_DEV_OFFSET;

  if (CSL_MDIO_isPhyLinked((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase, PhyNum))
    {
     return;  /* if still Linked, exit*/
    }

  /* Not Linked */
  *PhyState &= (~(ENETPHY_STATE_MASK | ENETPHY_TIM_MASK));
  if (0u != ( (*PhyState) & SMODE_AUTO) )
  {
    *PhyState |= ( (ENETPHY_CHANGE | NWAY_WAIT) | ENETPHY_NWDN_TO);
  }
   else
    {
    *PhyState |= ( (ENETPHY_CHANGE | ENETPHY_LINK_TO) | LINK_WAIT);
    }
  ENETPHY_MdixDelay(hPhyDev);  /* If AutoMdix add delay */

  }

void ENETPHY_DefaultState(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  /*Awaiting a ENETPHY_Init call                                             */
  *PhyState|=ENETPHY_CHANGE;
  }

/* Simple Query Functions for reporting speed,duplex */
/* ENETPHY_GetDuplex is called to retrieve the Duplex info */
int32_t ENETPHY_GetDuplex(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  return(( (*PhyState) & ENETPHY_DUPLEX_MASK) ? 1:0);  /* return 0 or a 1  */
  }

/* ENETPHY_GetSpeed is called to retreive the Speed info */
int32_t ENETPHY_GetSpeed(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  int32_t ret = 0 ;

  if (((ENETPHY_DEVICE *) hPhyDev)->SPEED_1000 == 1)
    {
    ret = 2; /* if we are linked at 1000, we return a value of 2 */
    }
  else
    {
    ret = ( (*PhyState) & ENETPHY_SPEED_MASK_NDK);
    }

  return ret;
  }

/* ENETPHY_GetPhyNum is called to retreive the Phy Device Adr info*/
int32_t ENETPHY_GetPhyNum(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  return((int32_t)(( (*PhyState) & ENETPHY_DEV_MASK) >> ENETPHY_DEV_OFFSET));
  }

/* ENETPHY_GetLoopback is called to Determine if the LOOPBACK state has been reached*/
int32_t ENETPHY_GetLoopback(ENETPHY_Handle hPhyDev)
  {
  uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
  return(( (*PhyState) & ENETPHY_STATE_MASK) == LOOPBACK);
  }

/* ENETPHY_GetLinked is called to Determine if the LINKED state has been reached*/
int32_t ENETPHY_GetLinked(ENETPHY_Handle hPhyDev)
  {
    uint32_t *PhyState = &((ENETPHY_DEVICE *) hPhyDev)->PhyState;
    return (( (*PhyState) & ENETPHY_STATE_MASK) == LINKED);
  }

/************************************
***
*** Waits for MDIO_USERACCESS to be ready and reads data
*** If 'WaitForData' set, waits for read to complete and returns Data,
*** otherwise returns 0
*** Note: 'data' is 16 bits but we use 32 bits
***        to be consistent with rest of the code.
***
**************************************/
uint32_t ENETPHY_UserAccessRead(ENETPHY_Handle hPhyDev, uint32_t regadr, uint32_t phyadr, uint32_t *data)
  {
    CSL_MDIO_USERACCESS    user_access_reg;

    /* Wait till transaction completion if any */
    do
    {
        CSL_MDIO_getUserAccessRegister((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase, 0, &user_access_reg);
    }
    while(user_access_reg.go);

    user_access_reg.phyAddr = phyadr;
    user_access_reg.regAddr = regadr;
    user_access_reg.write = 0U;
    user_access_reg.go = 1U;

    CSL_MDIO_setUserAccessRegister((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase, 0U, &user_access_reg);

    /* wait for command completion */
    do
    {
        CSL_MDIO_getUserAccessRegister((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase, 0, &user_access_reg);
    }
    while(user_access_reg.go);

    CSL_MDIO_getUserAccessRegister((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase, 0, &user_access_reg);
    /* Store the data if the read is acknowledged */
    if(user_access_reg.ack)
    {
        *data = user_access_reg.data & MDIO_USERACCESS_DATA;
        return 1u;
    }

    return 0u;
  }


/************************************
***
*** Waits for MDIO_USERACCESS to be ready and writes data
***
**************************************/
void ENETPHY_UserAccessWrite(ENETPHY_Handle hPhyDev, uint32_t regadr, uint32_t phyadr, uint32_t data)
  {
    CSL_MDIO_USERACCESS    user_access_reg;

    /* Wait till transaction completion if any */
    do
    {
        CSL_MDIO_getUserAccessRegister((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase, 0, &user_access_reg);
    }
    while(user_access_reg.go);

    user_access_reg.phyAddr = phyadr;
    user_access_reg.regAddr = regadr;
    user_access_reg.write = 1U;
    user_access_reg.go = 1U;
    user_access_reg.data = data;

    CSL_MDIO_setUserAccessRegister((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase, 0U, &user_access_reg);

    /* wait for command completion */
    do
    {
        CSL_MDIO_getUserAccessRegister((CSL_mdioHandle) ((ENETPHY_DEVICE *) hPhyDev)->miibase, 0, &user_access_reg);
    }
    while(user_access_reg.go);
  }
