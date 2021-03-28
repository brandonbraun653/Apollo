*************************************************************************
*	CPSW Rate Limit Example 
*	---------------------------------
*
*	(C) Copyright 2015, Texas Instruments, Inc.
*
*	Use of this software is controlled by the terms and conditions found 
*	in the license agreement under which this software has been supplied.
*************************************************************************

The CPSW Rate Limit example demonstrates the use of CPSW CSL APIs to 
configure the CPSW Receive Rate Limit for the EMAC traffic generated or
forwarded by the host on target (silicon only).
The test consists of multiple test scenarios. For each test scenario, it
performs the following tasks:
1. Configure the CPSW Rate Limit register set according to the desired
   bandwidth (in Mbps) of each priority stream
2. Configure and run the packet generators according to the deisred packet
   rates and packet sizes to generate the packet streams to the CPSW queues
   and process the received packets. There is one packet stream for each 
   active priority.
3. Calculate the received bandwith and compare it against the expected 
   result for each priority packet stream.      

The example is designed to run in loopback modes, i.e. it expects to 
receive the transmitted packet.
The following two loopback modes are supported:
    CPSW_LOOPBACK_INTERNAL(default): The transmitted packet is loopbacked 
                                     at the SGMII (RGMII) through SGMII (EMAC) 
                                     internal loopback
    CPSW_LOOPBACK_EXTERNAL: The transmitted packet should bo loopbacked by 
                            application outsite the SoC
                            
Please note that CPSW does not discard egress packets due to rate limiting, instead, 
all packets will pile up in the transmitted queues. It is up to the application
to detect the congestion condition and stop sending packets. Ihis operation is also
demonstrated at this example.                            
    
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
2b. To disable the auto detect logic, please set 'autodetectLogic' variable to 
    '0' using CCS. When this is done, the all the steps as mentioned 
    in 'Execute' section are mandatory.
	
2. Result

The application will output to the console its status progress and test results
and declare pass/fail.

    
    
    
    
