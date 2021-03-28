*************************************************************************
*	CPTS Event Processing Example 
*	---------------------------------
*
*	(C) Copyright 2015, Texas Instruments, Inc.
*
*	Use of this software is controlled by the terms and conditions found 
*	in the license agreement under which this software has been supplied.
*************************************************************************

The CPTS Event Processing example demonstrates the use of CPSW CSL APIs to 
configure the ethernet switch and CPTS on target (silicon only). It further demonstrates 
the use of CPPI/QMSS LLDs to send/receive IEEE1588 event packets and process the corresponding 
CPTS events through the ethernet switch using Host descriptors on any given DSP core.

The example is designed to run in loopback modes, i.e. it expects to receive the transmitted packet.
The following two loopback modes are supported:
    CPSW_LOOPBACK_INTERNAL(default): The transmitted packet is loopbacked at the SGMII (RGMII) through SGMII (EMAC) internal loopback
    CPSW_LOOPBACK_EXTERNAL: The transmitted packet should bo loopbacked by application outsite the SoC
    
Check the release notes for prerequisites, version information and steps on how to 
run examples

-------------------------
Execute Project
-------------------------

1. Execute using CCS
    
Launch the CCS Debugger and go to the Debug Perspective.

To execute the project ensure the following is done:-
    a) System reset (applicable for EVM under NO_BOOT mode only)
    b) Run EVM specific GEL scripts (applicable for EVM under NO_BOOT mode only)
    b) Load Program
    c) Once the project is loaded; Run to execute it.
    
NOTE:
If EVM is *NOT* running in NO_BOOT mode, the below assumptions are made
2a. CPSW Switch is configured outside the example
2b. To disable the auto detect logic, please set 'autodetectLogic' variable to '0' using CCS. When this is done, the all the steps as mentioned in 'Execute' section are mandatory.
	
2. Result

The application will output to the console its status progress and CPTS events of the received IEEE1588 event packets
and declare pass/fail.

    
    
    
    
