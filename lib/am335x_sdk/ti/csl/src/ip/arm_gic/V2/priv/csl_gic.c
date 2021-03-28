/**
 * @file csl_gic.c
 *
 * @brief
 * CSL-FL implementation file for the gic module.
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016, Texas Instruments, Inc.
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
*/
#include <ti/csl/cslr_gic500.h>
#include <ti/csl/src/ip/arm_gic/V2/csl_gic.h>
#include <ti/csl/csl_types.h>

bool CSL_gicIsGrp0Disabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP0 ) == CSL_GIC_GRP0_DISABLED )
	{
		retVal=true;
	}
	return retVal;
}

bool CSL_gicIsGrp0Enabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP0 ) == CSL_GIC_GRP0_ENABLED )
	{
		retVal=true;
	}
	return retVal;
}

int32_t CSL_gicDisableGrp0( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP0 , CSL_GIC_GRP0_DISABLE);
	return CSL_PASS;
}

int32_t CSL_gicEnableGrp0( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP0 , CSL_GIC_GRP0_ENABLE);
	return CSL_PASS;
}

bool CSL_gicIsGrp1_NSDisabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP1_NS ) == CSL_GIC_GRP1_NS_DISABLED )
	{
		retVal=true;
	}
	return retVal;
}

bool CSL_gicIsGrp1_NSEnabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP1_NS ) == CSL_GIC_GRP1_NS_ENABLED )
	{
		retVal=true;
	}
	return retVal;
}

int32_t CSL_gicDisableGrp1_NS( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP1_NS , CSL_GIC_GRP1_NS_DISABLE);
	return CSL_PASS;
}

int32_t CSL_gicEnableGrp1_NS( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP1_NS , CSL_GIC_GRP1_NS_ENABLE);
	return CSL_PASS;
}

bool CSL_gicIsGrp1_SDisabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP1_S ) == CSL_GIC_GRP1_S_DISABLED )
	{
		retVal=true;
	}
	return retVal;
}

bool CSL_gicIsGrp1_SEnabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP1_S ) == CSL_GIC_GRP1_S_ENABLED )
	{
		retVal=true;
	}
	return retVal;
}

int32_t CSL_gicDisableGrp1_S( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP1_S , CSL_GIC_GRP1_S_DISABLE);
	return CSL_PASS;
}

int32_t CSL_gicEnableGrp1_S( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ENABLEGRP1_S , CSL_GIC_GRP1_S_ENABLE);
	return CSL_PASS;
}

bool CSL_gicIsARE_SDisabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ARE ) == CSL_GIC_ARE_S_DISABLED )
	{
		retVal=true;
	}
	return retVal;
}

bool CSL_gicIsARE_SEnabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ARE ) == CSL_GIC_ARE_S_ENABLED )
	{
		retVal=true;
	}
	return retVal;
}

int32_t CSL_gicDisableARE_S( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ARE , CSL_GIC_ARE_S_DISABLE);
	return CSL_PASS;
}

int32_t CSL_gicEnableARE_S( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ARE , CSL_GIC_ARE_S_ENABLE);
	return CSL_PASS;
}

bool CSL_gicIsARE_NSDisabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ARE_NS ) == CSL_GIC_ARE_NS_DISABLED )
	{
		retVal=true;
	}
	return retVal;
}

bool CSL_gicIsARE_NSEnabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ARE_NS ) == CSL_GIC_ARE_NS_ENABLED )
	{
		retVal=true;
	}
	return retVal;
}

int32_t CSL_gicDisableARE_NS( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ARE_NS , CSL_GIC_ARE_NS_DISABLE);
	return CSL_PASS;
}

int32_t CSL_gicEnableARE_NS( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_ARE_NS , CSL_GIC_ARE_NS_ENABLE);
	return CSL_PASS;
}

bool CSL_gicIsSecurityDisabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_DS ) == CSL_GIC_SECURITY_DISABLED )
	{
		retVal=true;
	}
	return retVal;
}

bool CSL_gicIsSecurityEnabled( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_DS ) == CSL_GIC_SECURITY_ENABLED )
	{
		retVal=true;
	}
	return retVal;
}

int32_t CSL_gicDisableSecurity( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_DS , CSL_GIC_SECURITY_DISABLE);
	return CSL_PASS;
}

int32_t CSL_gicEnableSecurity( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_DS , CSL_GIC_SECURITY_ENABLE);
	return CSL_PASS;
}

bool CSL_gicIsRegisterWriteComplete( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_RWP ) == CSL_GIC_REGISTERWRITE_COMPLETE )
	{
		retVal=true;
	}
	return retVal;
}

bool CSL_gicIsRegisterWritePending( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->CTLR, GIC500_GICD_CTLR_RWP ) == CSL_GIC_REGISTERWRITE_PENDING )
	{
		retVal=true;
	}
	return retVal;
}

uint32_t CSL_gicGetImplementerID( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	uint32_t retVal;
	retVal = CSL_REG32_RD( &pGic500GicdRegs->IIDR);
	return retVal;
}

bool CSL_gicIsReadReservedSet( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_RRD ) == CSL_GIC_READRESERVED_SET )
	{
		retVal=true;
	}
	return retVal;
}

bool CSL_gicIsReadReservedCleared( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_RRD ) == CSL_GIC_READRESERVED_CLEARED )
	{
		retVal=true;
	}
	return retVal;
}

int32_t CSL_gicClearReadReserved( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_RRD , CSL_GIC_READRESERVED_CLEAR);
	return CSL_PASS;
}

bool CSL_gicIsWriteReservedSet( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_WRD ) == CSL_GIC_WRITERESERVED_SET )
	{
		retVal=true;
	}
	return retVal;
}

bool CSL_gicIsWriteReservedCleared( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_WRD ) == CSL_GIC_WRITERESERVED_CLEARED )
	{
		retVal=true;
	}
	return retVal;
}

int32_t CSL_gicClearWriteReserved( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_WRD , CSL_GIC_WRITERESERVED_CLEAR);
	return CSL_PASS;
}

bool CSL_gicIsReadToWriteOnlySet( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_RWOD ) == CSL_GIC_READTOWRITEONLY_SET )
	{
		retVal=true;
	}
	return retVal;
}

bool CSL_gicIsReadToWriteOnlyCleared( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_RWOD ) == CSL_GIC_READTOWRITEONLY_CLEARED )
	{
		retVal=true;
	}
	return retVal;
}

int32_t CSL_gicClearReadToWriteOnly( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_RWOD , CSL_GIC_READTOWRITEONLY_CLEAR);
	return CSL_PASS;
}

bool CSL_gicIsWriteToReadOnlySet( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_WROD ) == CSL_GIC_WRITETOREADONLY_SET )
	{
		retVal=true;
	}
	return retVal;
}

bool CSL_gicIsWriteToReadOnlyCleared( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	bool retVal=false;
	if ( CSL_REG32_FEXT( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_WROD ) == CSL_GIC_WRITETOREADONLY_CLEARED )
	{
		retVal=true;
	}
	return retVal;
}

int32_t CSL_gicClearWriteToReadOnly( CSL_gic500_gicdRegs *pGic500GicdRegs )
{
	CSL_REG32_FINS( &pGic500GicdRegs->STATUSR, GIC500_GICD_STATUSR_WROD , CSL_GIC_WRITETOREADONLY_CLEAR);
	return CSL_PASS;
}

bool CSL_gicIsSgiPpiIntrGroupARE0Clear( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupARE0Index )
{
	bool retVal=false;
	if ( sgiPpiIntrGroupARE0Index < CSL_GIC_NUM_GICD_IGROUPR_SGI_PPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGROUPR_SGI_PPI, GIC500_GICD_IGROUPR_SGI_PPI_GROUP );
		t =  t >> ( sgiPpiIntrGroupARE0Index );
		t = t & 1u;
		if ( t == CSL_GIC_SGIPPIINTRGROUPARE0_CLEAR )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrGroupARE0Set( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupARE0Index )
{
	bool retVal=false;
	if ( sgiPpiIntrGroupARE0Index < CSL_GIC_NUM_GICD_IGROUPR_SGI_PPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGROUPR_SGI_PPI, GIC500_GICD_IGROUPR_SGI_PPI_GROUP );
		t =  t >> ( sgiPpiIntrGroupARE0Index );
		t = t & 1u;
		if ( t == CSL_GIC_SGIPPIINTRGROUPARE0_SET )
		{
			retVal=true;
		}
	}
	return retVal;
}

int32_t CSL_gicClearSgiPpiIntrGroupARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupARE0Index )
{
	if ( sgiPpiIntrGroupARE0Index < CSL_GIC_NUM_GICD_IGROUPR_SGI_PPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGROUPR_SGI_PPI, GIC500_GICD_IGROUPR_SGI_PPI_GROUP );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << sgiPpiIntrGroupARE0Index ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SGIPPIINTRGROUPARE0_CLEAR << sgiPpiIntrGroupARE0Index ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->IGROUPR_SGI_PPI, GIC500_GICD_IGROUPR_SGI_PPI_GROUP , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicSetSgiPpiIntrGroupARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupARE0Index )
{
	if ( sgiPpiIntrGroupARE0Index < CSL_GIC_NUM_GICD_IGROUPR_SGI_PPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGROUPR_SGI_PPI, GIC500_GICD_IGROUPR_SGI_PPI_GROUP );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << sgiPpiIntrGroupARE0Index ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SGIPPIINTRGROUPARE0_SET << sgiPpiIntrGroupARE0Index ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->IGROUPR_SGI_PPI, GIC500_GICD_IGROUPR_SGI_PPI_GROUP , t );
	}
	return CSL_PASS;
}

bool CSL_gicIsSpiIntrGroupClear( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupIndex )
{
	bool retVal=false;
	spiIntrGroupIndex -= 32u;
	if ( spiIntrGroupIndex < CSL_GIC_NUM_GICD_IGROUPR_SPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGROUPR_SPI[( spiIntrGroupIndex/32u )], GIC500_GICD_IGROUPR_SPI_GROUP );
		t =  t >> ( ( spiIntrGroupIndex % 32u ) );
		t = t & 1u;
		if ( t == CSL_GIC_SPIINTRGROUP_CLEAR )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSpiIntrGroupSet( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupIndex )
{
	bool retVal=false;
	spiIntrGroupIndex -= 32u;
	if ( spiIntrGroupIndex < CSL_GIC_NUM_GICD_IGROUPR_SPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGROUPR_SPI[( spiIntrGroupIndex/32u )], GIC500_GICD_IGROUPR_SPI_GROUP );
		t =  t >> ( ( spiIntrGroupIndex % 32u ) );
		t = t & 1u;
		if ( t == CSL_GIC_SPIINTRGROUP_SET )
		{
			retVal=true;
		}
	}
	return retVal;
}

int32_t CSL_gicClearSpiIntrGroup( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupIndex )
{
	spiIntrGroupIndex -= 32u;
	if ( spiIntrGroupIndex < CSL_GIC_NUM_GICD_IGROUPR_SPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGROUPR_SPI[( spiIntrGroupIndex/32u )], GIC500_GICD_IGROUPR_SPI_GROUP );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << ( spiIntrGroupIndex % 32u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTRGROUP_CLEAR << ( spiIntrGroupIndex % 32u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->IGROUPR_SPI[( spiIntrGroupIndex/32u )], GIC500_GICD_IGROUPR_SPI_GROUP , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicSetSpiIntrGroup( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupIndex )
{
	spiIntrGroupIndex -= 32u;
	if ( spiIntrGroupIndex < CSL_GIC_NUM_GICD_IGROUPR_SPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGROUPR_SPI[( spiIntrGroupIndex/32u )], GIC500_GICD_IGROUPR_SPI_GROUP );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << ( spiIntrGroupIndex % 32u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTRGROUP_SET << ( spiIntrGroupIndex % 32u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->IGROUPR_SPI[( spiIntrGroupIndex/32u )], GIC500_GICD_IGROUPR_SPI_GROUP , t );
	}
	return CSL_PASS;
}

bool CSL_gicIsSgiPpiIntrARE0Enabled( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	bool retVal=false;
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ISENABLER_SGI_PPI_ENABLE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISENABLER_SGI_PPI, GIC500_GICD_ISENABLER_SGI_PPI_ENABLE );
		t =  t >> ( sgiPpiIntrARE0Index );
		t = t & 1u;
		if ( t == CSL_GIC_SGIPPIINTRARE0_ENABLED )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrARE0Disabled( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	bool retVal=false;
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ISENABLER_SGI_PPI_ENABLE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISENABLER_SGI_PPI, GIC500_GICD_ISENABLER_SGI_PPI_ENABLE );
		t =  t >> ( sgiPpiIntrARE0Index );
		t = t & 1u;
		if ( t == CSL_GIC_SGIPPIINTRARE0_DISABLED )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrARE0Pending( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	bool retVal=false;
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ISPENDR_SGI_PPI_PEND )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISPENDR_SGI_PPI, GIC500_GICD_ISPENDR_SGI_PPI_PEND );
		t =  t >> ( sgiPpiIntrARE0Index );
		t = t & 1u;
		if ( t == CSL_GIC_SGIPPIINTRARE0_PENDING )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrARE0NotPending( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	bool retVal=false;
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ISPENDR_SGI_PPI_PEND )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISPENDR_SGI_PPI, GIC500_GICD_ISPENDR_SGI_PPI_PEND );
		t =  t >> ( sgiPpiIntrARE0Index );
		t = t & 1u;
		if ( t == CSL_GIC_SGIPPIINTRARE0_NOTPENDING )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrARE0Active( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	bool retVal=false;
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ISACTIVER_SGI_PPI_SET )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISACTIVER_SGI_PPI, GIC500_GICD_ISACTIVER_SGI_PPI_SET );
		t =  t >> ( sgiPpiIntrARE0Index );
		t = t & 1u;
		if ( t == CSL_GIC_SGIPPIINTRARE0_ACTIVE )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrARE0Inactive( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	bool retVal=false;
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ISACTIVER_SGI_PPI_SET )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISACTIVER_SGI_PPI, GIC500_GICD_ISACTIVER_SGI_PPI_SET );
		t =  t >> ( sgiPpiIntrARE0Index );
		t = t & 1u;
		if ( t == CSL_GIC_SGIPPIINTRARE0_INACTIVE )
		{
			retVal=true;
		}
	}
	return retVal;
}

int32_t CSL_gicEnableSgiPpiIntrARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ISENABLER_SGI_PPI_ENABLE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISENABLER_SGI_PPI, GIC500_GICD_ISENABLER_SGI_PPI_ENABLE );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << sgiPpiIntrARE0Index ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SGIPPIINTRARE0_ENABLE << sgiPpiIntrARE0Index ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ISENABLER_SGI_PPI, GIC500_GICD_ISENABLER_SGI_PPI_ENABLE , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicDisableSgiPpiIntrARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ICENABLER_SGI_PPI_ENABLE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ICENABLER_SGI_PPI, GIC500_GICD_ICENABLER_SGI_PPI_ENABLE );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << sgiPpiIntrARE0Index ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SGIPPIINTRARE0_DISABLE << sgiPpiIntrARE0Index ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ICENABLER_SGI_PPI, GIC500_GICD_ICENABLER_SGI_PPI_ENABLE , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicSetPendingSgiPpiIntrARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ISPENDR_SGI_PPI_PEND )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISPENDR_SGI_PPI, GIC500_GICD_ISPENDR_SGI_PPI_PEND );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << sgiPpiIntrARE0Index ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SGIPPIINTRARE0_SETPENDING << sgiPpiIntrARE0Index ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ISPENDR_SGI_PPI, GIC500_GICD_ISPENDR_SGI_PPI_PEND , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicClearPendingSgiPpiIntrARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ICPENDR_SGI_PPI_PEND )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ICPENDR_SGI_PPI, GIC500_GICD_ICPENDR_SGI_PPI_PEND );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << sgiPpiIntrARE0Index ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SGIPPIINTRARE0_CLEARPENDING << sgiPpiIntrARE0Index ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ICPENDR_SGI_PPI, GIC500_GICD_ICPENDR_SGI_PPI_PEND , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicSetActiveSgiPpiIntrARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ISACTIVER_SGI_PPI_SET )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISACTIVER_SGI_PPI, GIC500_GICD_ISACTIVER_SGI_PPI_SET );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << sgiPpiIntrARE0Index ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SGIPPIINTRARE0_SETACTIVE << sgiPpiIntrARE0Index ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ISACTIVER_SGI_PPI, GIC500_GICD_ISACTIVER_SGI_PPI_SET , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicDeactivateSgiPpiIntrARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrARE0Index )
{
	if ( sgiPpiIntrARE0Index < CSL_GIC_NUM_GICD_ICACTIVER_SGI_PPI_SET )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ICACTIVER_SGI_PPI, GIC500_GICD_ICACTIVER_SGI_PPI_SET );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << sgiPpiIntrARE0Index ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SGIPPIINTRARE0_DEACTIVATE << sgiPpiIntrARE0Index ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ICACTIVER_SGI_PPI, GIC500_GICD_ICACTIVER_SGI_PPI_SET , t );
	}
	return CSL_PASS;
}

bool CSL_gicIsSpiIntrEnabled( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	bool retVal=false;
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ISENABLER_SPI_ENABLE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISENABLER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISENABLER_SPI_ENABLE );
		t =  t >> ( ( spiIntrIndex % 32u ) );
		t = t & 1u;
		if ( t == CSL_GIC_SPIINTR_ENABLED )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSpiIntrDisabled( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	bool retVal=false;
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ISENABLER_SPI_ENABLE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISENABLER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISENABLER_SPI_ENABLE );
		t =  t >> ( ( spiIntrIndex % 32u ) );
		t = t & 1u;
		if ( t == CSL_GIC_SPIINTR_DISABLED )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSpiIntrPending( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	bool retVal=false;
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ISPENDR_SPI_PEND )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISPENDR_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISPENDR_SPI_PEND );
		t =  t >> ( ( spiIntrIndex % 32u ) );
		t = t & 1u;
		if ( t == CSL_GIC_SPIINTR_PENDING )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSpiIntrNotPending( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	bool retVal=false;
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ISPENDR_SPI_PEND )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISPENDR_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISPENDR_SPI_PEND );
		t =  t >> ( ( spiIntrIndex % 32u ) );
		t = t & 1u;
		if ( t == CSL_GIC_SPIINTR_NOTPENDING )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSpiIntrActive( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	bool retVal=false;
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ISACTIVER_SPI_SET )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISACTIVER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISACTIVER_SPI_SET );
		t =  t >> ( ( spiIntrIndex % 32u ) );
		t = t & 1u;
		if ( t == CSL_GIC_SPIINTR_ACTIVE )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSpiIntrInactive( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	bool retVal=false;
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ISACTIVER_SPI_SET )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISACTIVER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISACTIVER_SPI_SET );
		t =  t >> ( ( spiIntrIndex % 32u ) );
		t = t & 1u;
		if ( t == CSL_GIC_SPIINTR_INACTIVE )
		{
			retVal=true;
		}
	}
	return retVal;
}

int32_t CSL_gicEnableSpiIntr( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ISENABLER_SPI_ENABLE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISENABLER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISENABLER_SPI_ENABLE );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << ( spiIntrIndex % 32u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTR_ENABLE << ( spiIntrIndex % 32u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ISENABLER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISENABLER_SPI_ENABLE , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicDisableSpiIntr( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ICENABLER_SPI_ENABLE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ICENABLER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ICENABLER_SPI_ENABLE );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << ( spiIntrIndex % 32u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTR_DISABLE << ( spiIntrIndex % 32u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ICENABLER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ICENABLER_SPI_ENABLE , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicSetPendingSpiIntr( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ISPENDR_SPI_PEND )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISPENDR_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISPENDR_SPI_PEND );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << ( spiIntrIndex % 32u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTR_SETPENDING << ( spiIntrIndex % 32u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ISPENDR_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISPENDR_SPI_PEND , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicClearPendingSpiIntr( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ICPENDR_SPI_PEND )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ICPENDR_SPI[( spiIntrIndex/32u )], GIC500_GICD_ICPENDR_SPI_PEND );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << ( spiIntrIndex % 32u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTR_CLEARPENDING << ( spiIntrIndex % 32u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ICPENDR_SPI[( spiIntrIndex/32u )], GIC500_GICD_ICPENDR_SPI_PEND , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicSetActiveSpiIntr( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ISACTIVER_SPI_SET )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ISACTIVER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISACTIVER_SPI_SET );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << ( spiIntrIndex % 32u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTR_SETACTIVE << ( spiIntrIndex % 32u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ISACTIVER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ISACTIVER_SPI_SET , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicDeactivateSpiIntr( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrIndex )
{
	spiIntrIndex -= 32u;
	if ( spiIntrIndex < CSL_GIC_NUM_GICD_ICACTIVER_SPI_SET )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ICACTIVER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ICACTIVER_SPI_SET );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << ( spiIntrIndex % 32u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTR_DEACTIVATE << ( spiIntrIndex % 32u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ICACTIVER_SPI[( spiIntrIndex/32u )], GIC500_GICD_ICACTIVER_SPI_SET , t );
	}
	return CSL_PASS;
}

uint32_t CSL_gicGetSgiPpiIntrPriorityARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrPriorityARE0IpriorityrSgiPpiIndex, uint32_t sgiPpiIntrPriorityARE0PrioIndex )
{
	uint32_t retVal = 0U;
	if ( sgiPpiIntrPriorityARE0IpriorityrSgiPpiIndex < CSL_GIC_NUM_GICD_IPRIORITYR_SGI_PPI )
	{
		if ( sgiPpiIntrPriorityARE0PrioIndex < CSL_GIC_NUM_GICD_IPRIORITYR_SGI_PPI_PRIO )
		{
			retVal = CSL_REG32_FEXT( &pGic500GicdRegs->IPRIORITYR_SGI_PPI[sgiPpiIntrPriorityARE0IpriorityrSgiPpiIndex], GIC500_GICD_IPRIORITYR_SGI_PPI_PRIO );
			retVal =  retVal >> ( sgiPpiIntrPriorityARE0PrioIndex * 8u );
			retVal = retVal & 255u;
		}
	}
	return retVal;
}

int32_t CSL_gicSetSgiPpiIntrPriorityARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrPriorityARE0IpriorityrSgiPpiIndex, uint32_t sgiPpiIntrPriorityARE0PrioIndex, uint32_t value )
{
	if ( sgiPpiIntrPriorityARE0IpriorityrSgiPpiIndex < CSL_GIC_NUM_GICD_IPRIORITYR_SGI_PPI )
	{
		if ( sgiPpiIntrPriorityARE0PrioIndex < CSL_GIC_NUM_GICD_IPRIORITYR_SGI_PPI_PRIO )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicdRegs->IPRIORITYR_SGI_PPI[sgiPpiIntrPriorityARE0IpriorityrSgiPpiIndex], GIC500_GICD_IPRIORITYR_SGI_PPI_PRIO );
			uint32_t mask;
			uint32_t m;
			mask = 255u;
			m = t & ( mask << sgiPpiIntrPriorityARE0PrioIndex ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero out the bits to be updated. */
			t = t | ( value << sgiPpiIntrPriorityARE0PrioIndex ); /* insert new value. */
;			CSL_REG32_FINS( &pGic500GicdRegs->IPRIORITYR_SGI_PPI[sgiPpiIntrPriorityARE0IpriorityrSgiPpiIndex], GIC500_GICD_IPRIORITYR_SGI_PPI_PRIO , t );
		}
	}
	return CSL_PASS;
}

uint32_t CSL_gicGetSpiIntrPriority( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrPriorityIndex )
{
	uint32_t retVal = 0U;
	spiIntrPriorityIndex -= 32u;
	if ( spiIntrPriorityIndex < CSL_GIC_NUM_GICD_IPRIORITYR_SPI_PRIO )
	{
		retVal = CSL_REG32_FEXT( &pGic500GicdRegs->IPRIORITYR_SPI[( spiIntrPriorityIndex/4u )], GIC500_GICD_IPRIORITYR_SPI_PRIO );
		retVal =  retVal >> ( ( spiIntrPriorityIndex % 4u ) * 8u );
		retVal = retVal & 255u;
	}
	return retVal;
}

int32_t CSL_gicSetSpiIntrPriority( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrPriorityIndex, uint32_t value )
{
	spiIntrPriorityIndex -= 32u;
	if ( spiIntrPriorityIndex < CSL_GIC_NUM_GICD_IPRIORITYR_SPI_PRIO )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IPRIORITYR_SPI[( spiIntrPriorityIndex/4u )], GIC500_GICD_IPRIORITYR_SPI_PRIO );
		uint32_t mask;
		uint32_t m;
		mask = 255u;
		m = t & ( mask << ( spiIntrPriorityIndex % 4u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero out the bits to be updated. */
		t = t | ( value << ( spiIntrPriorityIndex % 4u ) ); /* insert new value. */
;		CSL_REG32_FINS( &pGic500GicdRegs->IPRIORITYR_SPI[( spiIntrPriorityIndex/4u )], GIC500_GICD_IPRIORITYR_SPI_PRIO , t );
	}
	return CSL_PASS;
}

bool CSL_gicIsCPU0BitSetInSgiPpiDestCPU( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiDestCPUItargetsrSgiPpiIndex, uint32_t sgiPpiDestCPUCpuIdIndex )
{
	bool retVal=false;
	if ( sgiPpiDestCPUItargetsrSgiPpiIndex < CSL_GIC_NUM_GICD_ITARGETSR_SGI_PPI )
	{
		if ( sgiPpiDestCPUCpuIdIndex < CSL_GIC_NUM_GICD_ITARGETSR_SGI_PPI_CPU_ID )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicdRegs->ITARGETSR_SGI_PPI[sgiPpiDestCPUItargetsrSgiPpiIndex], GIC500_GICD_ITARGETSR_SGI_PPI_CPU_ID );
			t =  t >> ( sgiPpiDestCPUCpuIdIndex * 8u );
			t = t & 255u;
			if ( t  & CSL_GIC_SGIPPIDESTCPU_CPU0 )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsCPU1BitSetInSgiPpiDestCPU( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiDestCPUItargetsrSgiPpiIndex, uint32_t sgiPpiDestCPUCpuIdIndex )
{
	bool retVal=false;
	if ( sgiPpiDestCPUItargetsrSgiPpiIndex < CSL_GIC_NUM_GICD_ITARGETSR_SGI_PPI )
	{
		if ( sgiPpiDestCPUCpuIdIndex < CSL_GIC_NUM_GICD_ITARGETSR_SGI_PPI_CPU_ID )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicdRegs->ITARGETSR_SGI_PPI[sgiPpiDestCPUItargetsrSgiPpiIndex], GIC500_GICD_ITARGETSR_SGI_PPI_CPU_ID );
			t =  t >> ( sgiPpiDestCPUCpuIdIndex * 8u );
			t = t & 255u;
			if ( t  & CSL_GIC_SGIPPIDESTCPU_CPU1 )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsCPU2BitSetInSgiPpiDestCPU( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiDestCPUItargetsrSgiPpiIndex, uint32_t sgiPpiDestCPUCpuIdIndex )
{
	bool retVal=false;
	if ( sgiPpiDestCPUItargetsrSgiPpiIndex < CSL_GIC_NUM_GICD_ITARGETSR_SGI_PPI )
	{
		if ( sgiPpiDestCPUCpuIdIndex < CSL_GIC_NUM_GICD_ITARGETSR_SGI_PPI_CPU_ID )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicdRegs->ITARGETSR_SGI_PPI[sgiPpiDestCPUItargetsrSgiPpiIndex], GIC500_GICD_ITARGETSR_SGI_PPI_CPU_ID );
			t =  t >> ( sgiPpiDestCPUCpuIdIndex * 8u );
			t = t & 255u;
			if ( t  & CSL_GIC_SGIPPIDESTCPU_CPU2 )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsCPU3BitSetInSgiPpiDestCPU( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiDestCPUItargetsrSgiPpiIndex, uint32_t sgiPpiDestCPUCpuIdIndex )
{
	bool retVal=false;
	if ( sgiPpiDestCPUItargetsrSgiPpiIndex < CSL_GIC_NUM_GICD_ITARGETSR_SGI_PPI )
	{
		if ( sgiPpiDestCPUCpuIdIndex < CSL_GIC_NUM_GICD_ITARGETSR_SGI_PPI_CPU_ID )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicdRegs->ITARGETSR_SGI_PPI[sgiPpiDestCPUItargetsrSgiPpiIndex], GIC500_GICD_ITARGETSR_SGI_PPI_CPU_ID );
			t =  t >> ( sgiPpiDestCPUCpuIdIndex * 8u );
			t = t & 255u;
			if ( t  & CSL_GIC_SGIPPIDESTCPU_CPU3 )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsCPU0BitSetInSpiDestCPUList( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiDestCPUListIndex )
{
	bool retVal=false;
	spiDestCPUListIndex -= 32u;
	if ( spiDestCPUListIndex < CSL_GIC_NUM_GICD_ITARGETSR_SPI_CPU_ID )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ITARGETSR_SPI[( spiDestCPUListIndex/4u )], GIC500_GICD_ITARGETSR_SPI_CPU_ID );
		t =  t >> ( ( spiDestCPUListIndex % 4u ) * 8u );
		t = t & 255u;
		if ( t  & CSL_GIC_SPIDESTCPULIST_CPU0 )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsCPU1BitSetInSpiDestCPUList( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiDestCPUListIndex )
{
	bool retVal=false;
	spiDestCPUListIndex -= 32u;
	if ( spiDestCPUListIndex < CSL_GIC_NUM_GICD_ITARGETSR_SPI_CPU_ID )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ITARGETSR_SPI[( spiDestCPUListIndex/4u )], GIC500_GICD_ITARGETSR_SPI_CPU_ID );
		t =  t >> ( ( spiDestCPUListIndex % 4u ) * 8u );
		t = t & 255u;
		if ( t  & CSL_GIC_SPIDESTCPULIST_CPU1 )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsCPU2BitSetInSpiDestCPUList( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiDestCPUListIndex )
{
	bool retVal=false;
	spiDestCPUListIndex -= 32u;
	if ( spiDestCPUListIndex < CSL_GIC_NUM_GICD_ITARGETSR_SPI_CPU_ID )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ITARGETSR_SPI[( spiDestCPUListIndex/4u )], GIC500_GICD_ITARGETSR_SPI_CPU_ID );
		t =  t >> ( ( spiDestCPUListIndex % 4u ) * 8u );
		t = t & 255u;
		if ( t  & CSL_GIC_SPIDESTCPULIST_CPU2 )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsCPU3BitSetInSpiDestCPUList( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiDestCPUListIndex )
{
	bool retVal=false;
	spiDestCPUListIndex -= 32u;
	if ( spiDestCPUListIndex < CSL_GIC_NUM_GICD_ITARGETSR_SPI_CPU_ID )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ITARGETSR_SPI[( spiDestCPUListIndex/4u )], GIC500_GICD_ITARGETSR_SPI_CPU_ID );
		t =  t >> ( ( spiDestCPUListIndex % 4u ) * 8u );
		t = t & 255u;
		if ( t  & CSL_GIC_SPIDESTCPULIST_CPU3 )
		{
			retVal=true;
		}
	}
	return retVal;
}

int32_t CSL_gicSetSpiDestCPUList( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiDestCPUListIndex, uint32_t value )
{
	spiDestCPUListIndex -= 32u;
	if ( spiDestCPUListIndex < CSL_GIC_NUM_GICD_ITARGETSR_SPI_CPU_ID )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ITARGETSR_SPI[( spiDestCPUListIndex/4u )], GIC500_GICD_ITARGETSR_SPI_CPU_ID );
		uint32_t mask;
		uint32_t m;
		mask = 255u;
		m = t & ( mask << ( spiDestCPUListIndex % 4u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero out the bits to be updated. */
		t = t | ( value << ( spiDestCPUListIndex % 4u ) ); /* insert new value. */
;		CSL_REG32_FINS( &pGic500GicdRegs->ITARGETSR_SPI[( spiDestCPUListIndex/4u )], GIC500_GICD_ITARGETSR_SPI_CPU_ID , t );
	}
	return CSL_PASS;
}

bool CSL_gicIsSPIIntTypeLevel( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sPIIntTypeIndex )
{
	bool retVal=false;
	sPIIntTypeIndex -= 32u;
	if ( sPIIntTypeIndex < CSL_GIC_NUM_GICD_ICFGR_SPI_INT_TYPE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ICFGR_SPI[( sPIIntTypeIndex/16u )], GIC500_GICD_ICFGR_SPI_INT_TYPE );
		t =  t >> ( ( sPIIntTypeIndex % 16u ) * 2u );
		t = t & 3u;
		if ( t == CSL_GIC_SPIINTTYPE_LEVEL )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSPIIntTypeEdge( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sPIIntTypeIndex )
{
	bool retVal=false;
	sPIIntTypeIndex -= 32u;
	if ( sPIIntTypeIndex < CSL_GIC_NUM_GICD_ICFGR_SPI_INT_TYPE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ICFGR_SPI[( sPIIntTypeIndex/16u )], GIC500_GICD_ICFGR_SPI_INT_TYPE );
		t =  t >> ( ( sPIIntTypeIndex % 16u ) * 2u );
		t = t & 3u;
		if ( t == CSL_GIC_SPIINTTYPE_EDGE )
		{
			retVal=true;
		}
	}
	return retVal;
}

int32_t CSL_gicAssignLevelSPIIntType( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sPIIntTypeIndex )
{
	sPIIntTypeIndex -= 32u;
	if ( sPIIntTypeIndex < CSL_GIC_NUM_GICD_ICFGR_SPI_INT_TYPE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ICFGR_SPI[( sPIIntTypeIndex/16u )], GIC500_GICD_ICFGR_SPI_INT_TYPE );
		uint32_t mask;
		uint32_t m;
		mask = 3u;
		m = t & ( mask << ( (sPIIntTypeIndex % 16u) * 2u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTTYPE_ASSIGNLEVEL << ( (sPIIntTypeIndex % 16u) * 2u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ICFGR_SPI[( sPIIntTypeIndex/16u )], GIC500_GICD_ICFGR_SPI_INT_TYPE , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicAssignEdgeSPIIntType( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sPIIntTypeIndex )
{
	sPIIntTypeIndex -= 32u;
	if ( sPIIntTypeIndex < CSL_GIC_NUM_GICD_ICFGR_SPI_INT_TYPE )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->ICFGR_SPI[( sPIIntTypeIndex/16u )], GIC500_GICD_ICFGR_SPI_INT_TYPE );
		uint32_t mask;
		uint32_t m;
		mask = 3u;
		m = t & ( mask << ( (sPIIntTypeIndex % 16u) *2u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTTYPE_ASSIGNEDGE << ( (sPIIntTypeIndex % 16u) * 2u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->ICFGR_SPI[( sPIIntTypeIndex/16u )], GIC500_GICD_ICFGR_SPI_INT_TYPE , t );
	}
	return CSL_PASS;
}

bool CSL_gicIsSgiPpiIntrGroupModifierARE0Clear( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupModifierARE0Index )
{
	bool retVal=false;
	if ( sgiPpiIntrGroupModifierARE0Index < CSL_GIC_NUM_GICD_IGRPMODR_SGI_PPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGRPMODR_SGI_PPI, GIC500_GICD_IGRPMODR_SGI_PPI_GROUP );
		t =  t >> ( sgiPpiIntrGroupModifierARE0Index );
		t = t & 1u;
		if ( t == CSL_GIC_SGIPPIINTRGROUPMODIFIERARE0_CLEAR )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrGroupModifierARE0Set( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupModifierARE0Index )
{
	bool retVal=false;
	if ( sgiPpiIntrGroupModifierARE0Index < CSL_GIC_NUM_GICD_IGRPMODR_SGI_PPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGRPMODR_SGI_PPI, GIC500_GICD_IGRPMODR_SGI_PPI_GROUP );
		t =  t >> ( sgiPpiIntrGroupModifierARE0Index );
		t = t & 1u;
		if ( t == CSL_GIC_SGIPPIINTRGROUPMODIFIERARE0_SET )
		{
			retVal=true;
		}
	}
	return retVal;
}

int32_t CSL_gicClearSgiPpiIntrGroupModifierARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupModifierARE0Index )
{
	if ( sgiPpiIntrGroupModifierARE0Index < CSL_GIC_NUM_GICD_IGRPMODR_SGI_PPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGRPMODR_SGI_PPI, GIC500_GICD_IGRPMODR_SGI_PPI_GROUP );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << sgiPpiIntrGroupModifierARE0Index ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SGIPPIINTRGROUPMODIFIERARE0_CLEAR << sgiPpiIntrGroupModifierARE0Index ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->IGRPMODR_SGI_PPI, GIC500_GICD_IGRPMODR_SGI_PPI_GROUP , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicSetSgiPpiIntrGroupModifierARE0( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t sgiPpiIntrGroupModifierARE0Index )
{
	if ( sgiPpiIntrGroupModifierARE0Index < CSL_GIC_NUM_GICD_IGRPMODR_SGI_PPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGRPMODR_SGI_PPI, GIC500_GICD_IGRPMODR_SGI_PPI_GROUP );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << sgiPpiIntrGroupModifierARE0Index ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SGIPPIINTRGROUPMODIFIERARE0_SET << sgiPpiIntrGroupModifierARE0Index ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->IGRPMODR_SGI_PPI, GIC500_GICD_IGRPMODR_SGI_PPI_GROUP , t );
	}
	return CSL_PASS;
}

bool CSL_gicIsSpiIntrGroupModifierClear( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupModifierIndex )
{
	bool retVal=false;
	spiIntrGroupModifierIndex -= 32u;
	if ( spiIntrGroupModifierIndex < CSL_GIC_NUM_GICD_IGRPMODR_SPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGRPMODR_SPI[( spiIntrGroupModifierIndex/32u )], GIC500_GICD_IGRPMODR_SPI_GROUP );
		t =  t >> ( ( spiIntrGroupModifierIndex % 32u ) );
		t = t & 1u;
		if ( t == CSL_GIC_SPIINTRGROUPMODIFIER_CLEAR )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSpiIntrGroupModifierSet( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupModifierIndex )
{
	bool retVal=false;
	spiIntrGroupModifierIndex -= 32u;
	if ( spiIntrGroupModifierIndex < CSL_GIC_NUM_GICD_IGRPMODR_SPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGRPMODR_SPI[( spiIntrGroupModifierIndex/32u )], GIC500_GICD_IGRPMODR_SPI_GROUP );
		t =  t >> ( ( spiIntrGroupModifierIndex % 32u ) );
		t = t & 1u;
		if ( t == CSL_GIC_SPIINTRGROUPMODIFIER_SET )
		{
			retVal=true;
		}
	}
	return retVal;
}

int32_t CSL_gicClearSpiIntrGroupModifier( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupModifierIndex )
{
	spiIntrGroupModifierIndex -= 32u;
	if ( spiIntrGroupModifierIndex < CSL_GIC_NUM_GICD_IGRPMODR_SPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGRPMODR_SPI[( spiIntrGroupModifierIndex/32u )], GIC500_GICD_IGRPMODR_SPI_GROUP );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << ( spiIntrGroupModifierIndex % 32u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTRGROUPMODIFIER_CLEAR << ( spiIntrGroupModifierIndex % 32u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->IGRPMODR_SPI[( spiIntrGroupModifierIndex/32u )], GIC500_GICD_IGRPMODR_SPI_GROUP , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicSetSpiIntrGroupModifier( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t spiIntrGroupModifierIndex )
{
	spiIntrGroupModifierIndex -= 32u;
	if ( spiIntrGroupModifierIndex < CSL_GIC_NUM_GICD_IGRPMODR_SPI_GROUP )
	{
		uint32_t t;
		t = CSL_REG32_FEXT( &pGic500GicdRegs->IGRPMODR_SPI[( spiIntrGroupModifierIndex/32u )], GIC500_GICD_IGRPMODR_SPI_GROUP );
		uint32_t mask;
		uint32_t m;
		mask = 1u;
		m = t & ( mask << ( spiIntrGroupModifierIndex % 32u ) ); /* mask out other bits and extract the bits to be updated. */
		t = t ^ m; /* zero-out the bits to be updated. */
		t = t | ( CSL_GIC_SPIINTRGROUPMODIFIER_SET << ( spiIntrGroupModifierIndex % 32u ) ); /* write new value. */
		CSL_REG32_FINS( &pGic500GicdRegs->IGRPMODR_SPI[( spiIntrGroupModifierIndex/32u )], GIC500_GICD_IGRPMODR_SPI_GROUP , t );
	}
	return CSL_PASS;
}

int32_t CSL_gicGetComponentId( CSL_gic500_gicdRegs *pGic500GicdRegs, CSL_GicComponentId_t *pCSL_GicComponentId_t )
{
	return CSL_PASS;
}

int32_t CSL_gicGetAffinity( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t affinityIndex, CSL_GicAffinity_t *pCSL_GicAffinity_t )
{
	if ( affinityIndex < CSL_GIC_NUM_GICD_IROUTER )
	{
		pCSL_GicAffinity_t->a0 = CSL_REG32_FEXT( &pGic500GicdRegs->IROUTER[affinityIndex].LOWER, GIC500_GICD_IROUTER_LOWER_A0 );
		pCSL_GicAffinity_t->a1 = CSL_REG32_FEXT( &pGic500GicdRegs->IROUTER[affinityIndex].LOWER, GIC500_GICD_IROUTER_LOWER_A1 );
		pCSL_GicAffinity_t->iRM = CSL_REG32_FEXT( &pGic500GicdRegs->IROUTER[affinityIndex].LOWER, GIC500_GICD_IROUTER_LOWER_IRM );
		pCSL_GicAffinity_t->a2 = CSL_REG32_FEXT( &pGic500GicdRegs->IROUTER[affinityIndex].LOWER, GIC500_GICD_IROUTER_LOWER_A2 );
		pCSL_GicAffinity_t->a3 = CSL_REG32_FEXT( &pGic500GicdRegs->IROUTER[affinityIndex].UPPER, GIC500_GICD_IROUTER_UPPER_A3 );
	}
	return CSL_PASS;
}

int32_t CSL_gicSetAffinity( CSL_gic500_gicdRegs *pGic500GicdRegs, uint32_t affinityIndex, CSL_GicAffinity_t *pCSL_GicAffinity_t )
{
	if ( affinityIndex < CSL_GIC_NUM_GICD_IROUTER )
	{
		CSL_REG32_FINS( &pGic500GicdRegs->IROUTER[affinityIndex].LOWER, GIC500_GICD_IROUTER_LOWER_A0, pCSL_GicAffinity_t->a0 );
		CSL_REG32_FINS( &pGic500GicdRegs->IROUTER[affinityIndex].LOWER, GIC500_GICD_IROUTER_LOWER_A1, pCSL_GicAffinity_t->a1 );
		CSL_REG32_FINS( &pGic500GicdRegs->IROUTER[affinityIndex].LOWER, GIC500_GICD_IROUTER_LOWER_IRM, pCSL_GicAffinity_t->iRM );
		CSL_REG32_FINS( &pGic500GicdRegs->IROUTER[affinityIndex].LOWER, GIC500_GICD_IROUTER_LOWER_A2, pCSL_GicAffinity_t->a2 );
		CSL_REG32_FINS( &pGic500GicdRegs->IROUTER[affinityIndex].UPPER, GIC500_GICD_IROUTER_UPPER_A3, pCSL_GicAffinity_t->a3 );
	}
	return CSL_PASS;
}

bool CSL_gicIsCoreActive( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreIndex )
{
	bool retVal=false;
	if ( coreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( CSL_REG32_FEXT( &pGic500GicrRegs->CORE[coreIndex].CONTROL.WAKER, GIC500_GICR_CORE_CONTROL_WAKER_PROCESSORSLEEP ) == CSL_GIC_CORE_ACTIVE )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsCoreInactive( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreIndex )
{
	bool retVal=false;
	if ( coreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( CSL_REG32_FEXT( &pGic500GicrRegs->CORE[coreIndex].CONTROL.WAKER, GIC500_GICR_CORE_CONTROL_WAKER_PROCESSORSLEEP ) == CSL_GIC_CORE_INACTIVE )
		{
			retVal=true;
		}
	}
	return retVal;
}

int32_t CSL_gicPowerUpCore( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreIndex )
{
	if ( coreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		CSL_REG32_FINS( &pGic500GicrRegs->CORE[coreIndex].CONTROL.WAKER, GIC500_GICR_CORE_CONTROL_WAKER_PROCESSORSLEEP , CSL_GIC_CORE_POWERUP);
	}
	return CSL_PASS;
}

int32_t CSL_gicPowerDownCore( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreIndex )
{
	if ( coreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		CSL_REG32_FINS( &pGic500GicrRegs->CORE[coreIndex].CONTROL.WAKER, GIC500_GICR_CORE_CONTROL_WAKER_PROCESSORSLEEP , CSL_GIC_CORE_POWERDOWN);
	}
	return CSL_PASS;
}

bool CSL_gicIsCoreChildIfActive( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreChildIfIndex )
{
	bool retVal=false;
	if ( coreChildIfIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( CSL_REG32_FEXT( &pGic500GicrRegs->CORE[coreChildIfIndex].CONTROL.WAKER, GIC500_GICR_CORE_CONTROL_WAKER_CHILDRENASLEEP ) == CSL_GIC_CORECHILDIF_ACTIVE )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsCoreChildIfInactive( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t coreChildIfIndex )
{
	bool retVal=false;
	if ( coreChildIfIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( CSL_REG32_FEXT( &pGic500GicrRegs->CORE[coreChildIfIndex].CONTROL.WAKER, GIC500_GICR_CORE_CONTROL_WAKER_CHILDRENASLEEP ) == CSL_GIC_CORECHILDIF_INACTIVE )
		{
			retVal=true;
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrGroupClear( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrGroupCoreIndex, uint32_t sgiPpiIntrGroupGroupIndex )
{
	bool retVal=false;
	if ( sgiPpiIntrGroupCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrGroupGroupIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_IGROUPR_SGI_PPI_GROUP )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrGroupCoreIndex].SGI_PPI.IGROUPR_SGI_PPI, GIC500_GICR_CORE_SGI_PPI_IGROUPR_SGI_PPI_GROUP );
			t =  t >> ( sgiPpiIntrGroupGroupIndex );
			t = t & 1u;
			if ( t == CSL_GIC_SGIPPIINTRGROUP_CLEAR )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

int32_t CSL_gicClearSgiPpiIntrGroup( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrGroupCoreIndex, uint32_t sgiPpiIntrGroupGroupIndex )
{
	if ( sgiPpiIntrGroupCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrGroupGroupIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_IGROUPR_SGI_PPI_GROUP )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrGroupCoreIndex].SGI_PPI.IGROUPR_SGI_PPI, GIC500_GICR_CORE_SGI_PPI_IGROUPR_SGI_PPI_GROUP );
			uint32_t mask;
			uint32_t m;
			mask = 1u;
			m = t & ( mask << sgiPpiIntrGroupGroupIndex ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero-out the bits to be updated. */
			t = t | ( CSL_GIC_SGIPPIINTRGROUP_CLEAR << sgiPpiIntrGroupGroupIndex ); /* write new value. */
			CSL_REG32_FINS( &pGic500GicrRegs->CORE[sgiPpiIntrGroupCoreIndex].SGI_PPI.IGROUPR_SGI_PPI, GIC500_GICR_CORE_SGI_PPI_IGROUPR_SGI_PPI_GROUP , t );
		}
	}
	return CSL_PASS;
}

bool CSL_gicIsSgiPpiIntrEnabled( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrEnableIndex )
{
	bool retVal=false;
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrEnableIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISENABLER0_ENABLE )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISENABLER0, GIC500_GICR_CORE_SGI_PPI_ISENABLER0_ENABLE );
			t =  t >> ( sgiPpiIntrEnableIndex );
			t = t & 1u;
			if ( t == CSL_GIC_SGIPPIINTR_ENABLED )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrDisabled( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrEnableIndex )
{
	bool retVal=false;
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrEnableIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISENABLER0_ENABLE )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISENABLER0, GIC500_GICR_CORE_SGI_PPI_ISENABLER0_ENABLE );
			t =  t >> ( sgiPpiIntrEnableIndex );
			t = t & 1u;
			if ( t == CSL_GIC_SGIPPIINTR_DISABLED )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrPending( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrPendIndex )
{
	bool retVal=false;
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrPendIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISPENDR0_PEND )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISPENDR0, GIC500_GICR_CORE_SGI_PPI_ISPENDR0_PEND );
			t =  t >> ( sgiPpiIntrPendIndex );
			t = t & 1u;
			if ( t == CSL_GIC_SGIPPIINTR_PENDING )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrNotPending( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrPendIndex )
{
	bool retVal=false;
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrPendIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISPENDR0_PEND )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISPENDR0, GIC500_GICR_CORE_SGI_PPI_ISPENDR0_PEND );
			t =  t >> ( sgiPpiIntrPendIndex );
			t = t & 1u;
			if ( t == CSL_GIC_SGIPPIINTR_NOTPENDING )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrActive( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrSetIndex )
{
	bool retVal=false;
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrSetIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISACTIVER0_SET )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISACTIVER0, GIC500_GICR_CORE_SGI_PPI_ISACTIVER0_SET );
			t =  t >> ( sgiPpiIntrSetIndex );
			t = t & 1u;
			if ( t == CSL_GIC_SGIPPIINTR_ACTIVE )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsSgiPpiIntrInactive( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrSetIndex )
{
	bool retVal=false;
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrSetIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISACTIVER0_SET )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISACTIVER0, GIC500_GICR_CORE_SGI_PPI_ISACTIVER0_SET );
			t =  t >> ( sgiPpiIntrSetIndex );
			t = t & 1u;
			if ( t == CSL_GIC_SGIPPIINTR_INACTIVE )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

int32_t CSL_gicEnableSgiPpiIntr( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrEnableIndex )
{
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrEnableIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISENABLER0_ENABLE )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISENABLER0, GIC500_GICR_CORE_SGI_PPI_ISENABLER0_ENABLE );
			uint32_t mask;
			uint32_t m;
			mask = 1u;
			m = t & ( mask << sgiPpiIntrEnableIndex ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero-out the bits to be updated. */
			t = t | ( CSL_GIC_SGIPPIINTR_ENABLE << sgiPpiIntrEnableIndex ); /* write new value. */
			CSL_REG32_FINS( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISENABLER0, GIC500_GICR_CORE_SGI_PPI_ISENABLER0_ENABLE , t );
		}
	}
	return CSL_PASS;
}

int32_t CSL_gicDisableSgiPpiIntr( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrEnableIndex )
{
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrEnableIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICENABLER0_ENABLE )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ICENABLER0, GIC500_GICR_CORE_SGI_PPI_ICENABLER0_ENABLE );
			uint32_t mask;
			uint32_t m;
			mask = 1u;
			m = t & ( mask << sgiPpiIntrEnableIndex ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero-out the bits to be updated. */
			t = t | ( CSL_GIC_SGIPPIINTR_DISABLE << sgiPpiIntrEnableIndex ); /* write new value. */
			CSL_REG32_FINS( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ICENABLER0, GIC500_GICR_CORE_SGI_PPI_ICENABLER0_ENABLE , t );
		}
	}
	return CSL_PASS;
}

int32_t CSL_gicSetPendingSgiPpiIntr( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrPendIndex )
{
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrPendIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISPENDR0_PEND )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISPENDR0, GIC500_GICR_CORE_SGI_PPI_ISPENDR0_PEND );
			uint32_t mask;
			uint32_t m;
			mask = 1u;
			m = t & ( mask << sgiPpiIntrPendIndex ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero-out the bits to be updated. */
			t = t | ( CSL_GIC_SGIPPIINTR_SETPENDING << sgiPpiIntrPendIndex ); /* write new value. */
			CSL_REG32_FINS( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISPENDR0, GIC500_GICR_CORE_SGI_PPI_ISPENDR0_PEND , t );
		}
	}
	return CSL_PASS;
}

int32_t CSL_gicClearPendingSgiPpiIntr( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrPendIndex )
{
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrPendIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICPENDR0_PEND )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ICPENDR0, GIC500_GICR_CORE_SGI_PPI_ICPENDR0_PEND );
			uint32_t mask;
			uint32_t m;
			mask = 1u;
			m = t & ( mask << sgiPpiIntrPendIndex ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero-out the bits to be updated. */
			t = t | ( CSL_GIC_SGIPPIINTR_CLEARPENDING << sgiPpiIntrPendIndex ); /* write new value. */
			CSL_REG32_FINS( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ICPENDR0, GIC500_GICR_CORE_SGI_PPI_ICPENDR0_PEND , t );
		}
	}
	return CSL_PASS;
}

int32_t CSL_gicSetActiveSgiPpiIntr( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrSetIndex )
{
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrSetIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ISACTIVER0_SET )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISACTIVER0, GIC500_GICR_CORE_SGI_PPI_ISACTIVER0_SET );
			uint32_t mask;
			uint32_t m;
			mask = 1u;
			m = t & ( mask << sgiPpiIntrSetIndex ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero-out the bits to be updated. */
			t = t | ( CSL_GIC_SGIPPIINTR_SETACTIVE << sgiPpiIntrSetIndex ); /* write new value. */
			CSL_REG32_FINS( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ISACTIVER0, GIC500_GICR_CORE_SGI_PPI_ISACTIVER0_SET , t );
		}
	}
	return CSL_PASS;
}

int32_t CSL_gicDeactivateSgiPpiIntr( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrCoreIndex, uint32_t sgiPpiIntrSetIndex )
{
	if ( sgiPpiIntrCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrSetIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICACTIVER0_SET )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ICACTIVER0, GIC500_GICR_CORE_SGI_PPI_ICACTIVER0_SET );
			uint32_t mask;
			uint32_t m;
			mask = 1u;
			m = t & ( mask << sgiPpiIntrSetIndex ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero-out the bits to be updated. */
			t = t | ( CSL_GIC_SGIPPIINTR_DEACTIVATE << sgiPpiIntrSetIndex ); /* write new value. */
			CSL_REG32_FINS( &pGic500GicrRegs->CORE[sgiPpiIntrCoreIndex].SGI_PPI.ICACTIVER0, GIC500_GICR_CORE_SGI_PPI_ICACTIVER0_SET , t );
		}
	}
	return CSL_PASS;
}

uint32_t CSL_gicGetSgiPpiIntrPriority( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrPriorityCoreIndex, uint32_t sgiPpiIntrPriorityIpriorityrIndex )
{
	uint32_t retVal = 0U;
	if ( sgiPpiIntrPriorityCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrPriorityIpriorityrIndex < CSL_GIC_NUM_GICR_CORE_IPRIORITYR_SET )
		{
			retVal = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrPriorityCoreIndex].SGI_PPI.IPRIORITYR[( sgiPpiIntrPriorityIpriorityrIndex/4u )], GIC500_GICR_CORE_SGI_PPI_IPRIORITYR_PRIO );
			retVal =  retVal >> ( ( sgiPpiIntrPriorityIpriorityrIndex % 4u ) * 8u );
			retVal = retVal & 255u;
		}
	}
	return retVal;
}

int32_t CSL_gicSetSgiPpiIntrPriority( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrPriorityCoreIndex, uint32_t sgiPpiIntrPriorityIpriorityrIndex, uint32_t value )
{
	if ( sgiPpiIntrPriorityCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrPriorityIpriorityrIndex < CSL_GIC_NUM_GICR_CORE_IPRIORITYR_SET )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrPriorityCoreIndex].SGI_PPI.IPRIORITYR[( sgiPpiIntrPriorityIpriorityrIndex/4u )], GIC500_GICR_CORE_SGI_PPI_IPRIORITYR_PRIO );
			uint32_t mask;
			uint32_t m;
			mask = 255u;
			m = t & ( mask << ( sgiPpiIntrPriorityIpriorityrIndex % 4u ) ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero out the bits to be updated. */
			t = t | ( value << ( sgiPpiIntrPriorityIpriorityrIndex % 4u ) ); /* insert new value. */
;			CSL_REG32_FINS( &pGic500GicrRegs->CORE[sgiPpiIntrPriorityCoreIndex].SGI_PPI.IPRIORITYR[( sgiPpiIntrPriorityIpriorityrIndex/4u )], GIC500_GICR_CORE_SGI_PPI_IPRIORITYR_PRIO , t );
		}
	}
	return CSL_PASS;
}

bool CSL_gicIsSGIIntTypeLevel( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sGIIntTypeCoreIndex, uint32_t sGIIntTypeIntTypeIndex )
{
	bool retVal=false;
	if ( sGIIntTypeCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sGIIntTypeIntTypeIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICFGR0_INT_TYPE )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sGIIntTypeCoreIndex].SGI_PPI.ICFGR0, GIC500_GICR_CORE_SGI_PPI_ICFGR0_INT_TYPE );
			t =  t >> ( sGIIntTypeIntTypeIndex * 2u );
			t = t & 3u;
			if ( t == CSL_GIC_SGIINTTYPE_LEVEL )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsSGIIntTypeEdge( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sGIIntTypeCoreIndex, uint32_t sGIIntTypeIntTypeIndex )
{
	bool retVal=false;
	if ( sGIIntTypeCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sGIIntTypeIntTypeIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICFGR0_INT_TYPE )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sGIIntTypeCoreIndex].SGI_PPI.ICFGR0, GIC500_GICR_CORE_SGI_PPI_ICFGR0_INT_TYPE );
			t =  t >> ( sGIIntTypeIntTypeIndex * 2u );
			t = t & 3u;
			if ( t == CSL_GIC_SGIINTTYPE_EDGE )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsPPIIntTypeLevel( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t pPIIntTypeCoreIndex, uint32_t pPIIntTypeIntTypeIndex )
{
	bool retVal=false;
	if ( pPIIntTypeCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( pPIIntTypeIntTypeIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICFGR1_INT_TYPE )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[pPIIntTypeCoreIndex].SGI_PPI.ICFGR1, GIC500_GICR_CORE_SGI_PPI_ICFGR1_INT_TYPE );
			t =  t >> ( pPIIntTypeIntTypeIndex * 2u );
			t = t & 3u;
			if ( t == CSL_GIC_PPIINTTYPE_LEVEL )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

bool CSL_gicIsPPIIntTypeEdge( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t pPIIntTypeCoreIndex, uint32_t pPIIntTypeIntTypeIndex )
{
	bool retVal=false;
	if ( pPIIntTypeCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( pPIIntTypeIntTypeIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICFGR1_INT_TYPE )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[pPIIntTypeCoreIndex].SGI_PPI.ICFGR1, GIC500_GICR_CORE_SGI_PPI_ICFGR1_INT_TYPE );
			t =  t >> ( pPIIntTypeIntTypeIndex * 2u );
			t = t & 3u;
			if ( t == CSL_GIC_PPIINTTYPE_EDGE )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

int32_t CSL_gicAssignLevelPPIIntType( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t pPIIntTypeCoreIndex, uint32_t pPIIntTypeIntTypeIndex )
{
	if ( pPIIntTypeCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( pPIIntTypeIntTypeIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICFGR1_INT_TYPE )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[pPIIntTypeCoreIndex].SGI_PPI.ICFGR1, GIC500_GICR_CORE_SGI_PPI_ICFGR1_INT_TYPE );
			uint32_t mask;
			uint32_t m;
			mask = 3u;
			m = t & ( mask << pPIIntTypeIntTypeIndex ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero-out the bits to be updated. */
			t = t | ( CSL_GIC_PPIINTTYPE_ASSIGNLEVEL << pPIIntTypeIntTypeIndex ); /* write new value. */
			CSL_REG32_FINS( &pGic500GicrRegs->CORE[pPIIntTypeCoreIndex].SGI_PPI.ICFGR1, GIC500_GICR_CORE_SGI_PPI_ICFGR1_INT_TYPE , t );
		}
	}
	return CSL_PASS;
}

int32_t CSL_gicAssignEdgePPIIntType( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t pPIIntTypeCoreIndex, uint32_t pPIIntTypeIntTypeIndex )
{
	if ( pPIIntTypeCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( pPIIntTypeIntTypeIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_ICFGR1_INT_TYPE )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[pPIIntTypeCoreIndex].SGI_PPI.ICFGR1, GIC500_GICR_CORE_SGI_PPI_ICFGR1_INT_TYPE );
			uint32_t mask;
			uint32_t m;
			mask = 3u;
			m = t & ( mask << pPIIntTypeIntTypeIndex ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero-out the bits to be updated. */
			t = t | ( CSL_GIC_PPIINTTYPE_ASSIGNEDGE << pPIIntTypeIntTypeIndex ); /* write new value. */
			CSL_REG32_FINS( &pGic500GicrRegs->CORE[pPIIntTypeCoreIndex].SGI_PPI.ICFGR1, GIC500_GICR_CORE_SGI_PPI_ICFGR1_INT_TYPE , t );
		}
	}
	return CSL_PASS;
}

bool CSL_gicIsSgiPpiIntrGroupModifierSet( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrGroupModifierCoreIndex, uint32_t sgiPpiIntrGroupModifierGroupIndex )
{
	bool retVal=false;
	if ( sgiPpiIntrGroupModifierCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrGroupModifierGroupIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_IGRPMODR_SGI_PPI_GROUP )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrGroupModifierCoreIndex].SGI_PPI.IGRPMODR_SGI_PPI, GIC500_GICR_CORE_SGI_PPI_IGRPMODR_SGI_PPI_GROUP );
			t =  t >> ( sgiPpiIntrGroupModifierGroupIndex );
			t = t & 1u;
			if ( t == CSL_GIC_SGIPPIINTRGROUPMODIFIER_SET )
			{
				retVal=true;
			}
		}
	}
	return retVal;
}

int32_t CSL_gicSetSgiPpiIntrGroupModifier( CSL_gic500_gicrRegs *pGic500GicrRegs, uint32_t sgiPpiIntrGroupModifierCoreIndex, uint32_t sgiPpiIntrGroupModifierGroupIndex )
{
	if ( sgiPpiIntrGroupModifierCoreIndex < CSL_GIC_NUM_GICR_CORE )
	{
		if ( sgiPpiIntrGroupModifierGroupIndex < CSL_GIC_NUM_GICR_CORE_SGI_PPI_IGRPMODR_SGI_PPI_GROUP )
		{
			uint32_t t;
			t = CSL_REG32_FEXT( &pGic500GicrRegs->CORE[sgiPpiIntrGroupModifierCoreIndex].SGI_PPI.IGRPMODR_SGI_PPI, GIC500_GICR_CORE_SGI_PPI_IGRPMODR_SGI_PPI_GROUP );
			uint32_t mask;
			uint32_t m;
			mask = 1u;
			m = t & ( mask << sgiPpiIntrGroupModifierGroupIndex ); /* mask out other bits and extract the bits to be updated. */
			t = t ^ m; /* zero-out the bits to be updated. */
			t = t | ( CSL_GIC_SGIPPIINTRGROUPMODIFIER_SET << sgiPpiIntrGroupModifierGroupIndex ); /* write new value. */
			CSL_REG32_FINS( &pGic500GicrRegs->CORE[sgiPpiIntrGroupModifierCoreIndex].SGI_PPI.IGRPMODR_SGI_PPI, GIC500_GICR_CORE_SGI_PPI_IGRPMODR_SGI_PPI_GROUP , t );
		}
	}
	return CSL_PASS;
}
