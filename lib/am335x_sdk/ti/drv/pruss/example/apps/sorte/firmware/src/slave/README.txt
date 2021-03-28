The SORTE SLAVE firmware consists of the following files:

fw_main.asm: contains the initialization routine and the main control loop. Performs following tasks:
	PRU register initialization
	Resetting and configuring of the MII_RT module
	Generating MDIO LINK event to read in current Ethernet link status	
	Configuration of IEP timer and IEP timer events
	Control loop, which calls INTC event handler and the SORTE state machine

state.asm: SORTE device state machine
	Depending on the current SORTE device and PRU port state, calls the SORTE 
	state handler function:
		- Discovery
		– Parameterization
		– Synchronization
		– IO exchange	
	
discovery.asm: contains the discovery state implementation. Performs following tasks:
	Detection of which port is the forward direction port and the backward direction port
	Assignment of device address
	Exchange the amount of I/O data that are transmitted in IO exchange state

event_handler.asm: INTC event handler service routines. Performs following tasks:
	Checks if an PRU INTC event is pending
	Reads out the INTC event and executes the event handler routing
		– MDIO link event - occurs with Ethernet port link change
		– IEP event - occurs when compare register value match with IEP counter
		– PRU to PRU event - occurs when one PRU needs to trigger an event in the second PRU
		– RX EOF event - occurs when a frame was completely received. This event validates CRC 
		checksum in some SORTE states. The event does also trigger the start of a SORTE state 
		transition.

state.asm: SORTE slave device state machine. Performs following tasks:
	Depending on the current SORTE device and PRU port state, calls the SORTE state handler function:
		- Discovery
		– Parameterization
		– Synchronization
		– IO exchange	

param.asm: Contains the parameterization state implementation. Performs following tasks:
	Both PRU port directions are in AF mode
	PRU in forward direction receives the param frame from the master and stores the frame content in
	PRU shared memory
	PRU in backward direction ignore the frame
	Last device loops back the param frame to the master


line_delay.asm: Contains the line delay measurement of the synchronization state implementation. Performs following tasks:
	The port of forward direction is configured as HS.
	The port in backward direction is configured as AFLP.
	PRU measures the line delay between the forward direction port and the next SORTE device.

sync.asm: Contains the timer synchronization state implementation. Performs following tasks:
	Both ports are in AF and HR mode
	Time stamping of SYNC frame
	Synchronization of the device time to the master time

ioexm.asm: Contains the IO exchange state implementation. Performs following tasks:
	The port of forward direction is configured in AF with HR.
	The port of backward direction is dynamically switched between TTS and AF.
	PRU in forward direction receives the master data frame and extracts the devices process data and
	stores it in PRU shared memory.
	PRU in backward direction starts with TTS of the process input data and switches to AF after TTS data
	has been sent. With cycle time, the wrap-around switches back to TTS.

High Level State Transition Flow:

		firm_main: entry point of firmware: PRU register init, configure MII_RT module, IEP timer and event config, kick off main control loop for state/interrupt processing
                     |
                     |
                     |
                     V
		STATE_IDLE : wait for DISCOVERY FRAME, then determine which pru-icss port is connected to the MASTER ,transition to DISCOVERY state.
                     |
                     |
                     |
                     V
		STATE_DISCOVERY : respond to DISCOVERY frame sent by MASTER, each SLAVE will increment slave count field in payload and insert specific IO data length.
                     |		  when DISCOVERY frame received with Bit 3 of status field set, transition to STATE_PARAM.
                     |
                     |
                     V
		STATE_PARAM : receives PARAM frame from MASTER, store payload in pru data memory, forward to next slave, last slave will send back PARAM frame
                     |        to MASTER, This is not modified by any SLAVE. when  PARAM frame received with Bit 3 of status field set, transition to STATE_LINEDELAY
                     |
                     |
                     V
		STATE_LINEDELAY: SLAVE connected to MASTER will receive LINE_DELAY frame. This frame returned to MASTER who the determines line delay.
                     |           Slave is programmed with fixed forward delay. 1st SLAVE generates new LINE_DELAY frame and sends to next SLAVE to determine line delay.
                     |           This sequence is repeated between all SLAVES until end of SLAVE chain is reached.
                     |           when LINE_DELAY frame received with Bit 3 of status field set, transition to STATE_SYNC.
                     V
		SYNC_SYNC  : receives SYNC frame to synchronize its IEP timer with master IEP timer. each SLAVE will forward this frame to next SLAVE in chain.  
                     |           last SLAVE in chain will return this frame back towards MASTER. 
                     |           when SYNC frame received with Bit 3 of status field set, transition to STATE_IOEXHANGE.
                     |
                     V
		STATE_IOEXHANGE : master and slave devices being cyclic exchange of IO packets.


Prior to reviewing the SORTE firmware sources, its essenstial to have a good understanding of the PRU-ICSS subsystem and the PRU Assembly instruction set.

In order to gain an understanding of the PRU-ICSSS subsystem please refer to the Technical reference manual for the respective SOC. 

Link to PRU Assembly document: http://processors.wiki.ti.com/index.php/PRU_Assembly_Instructions

Additional information abouthe PRU-ICSS subsystem can be found at: http://processors.wiki.ti.com/index.php/PRU-ICSS

Please refer to details of the SORTE SLAVE at http://www.ti.com/tool/tidep-0086

NOTE: The current SORTE example as provided by the SDK does not implement CNC application as referenced by http://www.ti.com/tool/tidep-0061