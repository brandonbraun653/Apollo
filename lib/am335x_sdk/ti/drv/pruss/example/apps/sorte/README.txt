The Simple Open Real-time Ethernet protocol (SORTE) serves as an example for Texas Instruments programmable approach 
to real-time communication for input/output (IO) networks with a maximum of 254 devices. This protocol is fully documented 
and released in source code. It is open to customers to learn, adapt and enhance the protocol for their application requirements. 
SORTE is not bound to a given communication standard and breaks some of the limits of existing standards such as minimum Ethernet 
frame size, addressing and error detection. The primary use case of the protocol is to connect different end-equipment using 
Ethernet physical layer devices and 100 Mbit Ethernet cable.

Directory Layout:

firmware:
        bin:               SORTE firmware binaries
        src/include:       SORTE firmware common header files
        src/master:        SORTE firmware sources and header files for MASTER device
        src/slave:         SORTE firmware sources and header files for SLAVE device

master:                    SORTE makefile for MASTER application running on ARM

slave:                     SORTE makefile for SLAVE application running on ARM

src:                       SORTE ARM application source and build related files 

