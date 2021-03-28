EMAC LLD LOOPBACK EXAMPLE 
=========================

The files/folders in this directory contain an example that demonstrates the usage of EMAC driver API's.

The loopback test can only be run on one core. It opens 8 channels on each EMAC port,
and assign 4 MAC addresses to each channel. The test code performs Ethernet packets loopback on 
each channel and print the # of packets sent/received at the end of the test.

Data cache is by default enabled.

Note:
The TX/RX ports should be connected via a local Ethernet switch, no other network (LANs or PCs) should be 
connected to the switch.

Example test files:
-------------------

test_main.c  - main loopback test code
test_loc.h   - test code local header 
test_osal.c  - contains OS Abstraction Layer used by the EMAC driver


Global test configurations:
---------------------------

* pktbuf_extmem       - packet buffer allocated in external memory, by default set to FALSE
                        (packet buffer allocated in local L2 data memory)
  

Tools required to build project:
------------------------------------

* XDC v3.23.2.47 and above
* CCS Code Gen v7.3.1 and above
* BIOS v6.33.4.39 and above
* C6657 CSL v1.0.0.3 and above


To Run the Example in the little endian mode:
---------------------------------------------

1. Import the loopback project in CCSv5. 
   Project is located in pdk_C6657_X_x_x_x/packages/ti/drv/exampleProjects/EMACLoopback_testProject

2. Choose the little endian configuration in the CCS Build setup
   Note: By default, the project is configured in little endian mode.

3. Build the project.

4. Launch your target configuration and connect to core 0. 

5. Load the OUTPUT file.

8. Execute and check the result printed on console.


To Run the Example in the big endian mode:
------------------------------------------

Run the same steps except step 2:

2. Choose the big endian configuration in project properties (in General tab)
   Note: changing the endianness will prompt you to change the RTSC platform.
         Please choose:
	 Target:	ti.targets.elf.C66_big_endian
	 Platform:	ti.platforms.evm6657
