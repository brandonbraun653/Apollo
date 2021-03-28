The SORTE MASTER is written in PRU assembly language and consists of different file modules:

firm_main.asm: contains the initialization routine and SORTE master state machine. 
	PRU register initialization
	Resetting and configuring of the MII_RT module
	Configuration of IEP timer and IEP timer events
       Implements SORTE master state machine which consists of the following states in this order
		- Discovery: in this state, MASTER send out DISCOVERY frames to the SLAVE to detect number of SLAVES in the network.
		– Parameterization: in this state, MASTER sends out network configuration parameters to SLAVE devices
		– Synchronization: in this state,  line delay measurement and slave IEP timer synchronization with SLAVE devices will occur.
		– IO exchange: in this state, master will send out IOEX frames with SLAVE devices.

discovery.asm: contains implemenataion of DISCOVERY frame responses from the SLAVE 
device. Should not re-enter this state unless there is link down events 
detected.


High Level State Machine:

		firm_main: entry point of firmware: PRU register init, configure MII_RT module, IEP timer and event config
                     |
                     |
                     |
                     V
		IDLE_WAIT_FOR_LINK_ACTIVE :wait for mdio link to come up, when up transition to STATE_DISCOVER
                     |
                     |
                     |
                     V
		STATE_DISCOVERY : send 9 DISCOVER frames with status byte bit 3 clear, process responses, send 1 DISCOVER frame with status byte bit 3 set, transition to STATE_PARAM
                     |
                     |
                     |
                     V
		STATE_PARAM : send out PARAM frame, wait for PARAM frame from slave with status byte bit 1 set, make state transition to STATE_DELAYM 
                     |
                     |
                     |
                     V
		STATE_DELAYM : start the port-to-port delay measurement between MASTER and first SLAVE by sending our DELAY_REQ_P frame. The measurement is repeated 16 times
                     |
                     |
                     |
                     V
		STATE_SYNC  : send out SYNC frame to synchronize the SLAVES IEP timer the master IEP timer. Synchronization is done by SLAVES. This is repeated 1024 
		times (translates to 10 ms)
                     |
                     |
                     |
                     V
		STATE_IOEXHANGE : MASTER and SLAVE devices being cyclic exchange of IO packets.
		        



Prior to reviewing the SORTE firmware sources, its essenstial to have a good understanding of the PRU-ICSS subsystem and the PRU Assembly instruction set.

In order to gain an understanding of the PRU-ICSSS subsystem please refer to the Technical reference manual for the respective SOC.

Link to PRU Assembly document: http://processors.wiki.ti.com/index.php/PRU_Assembly_Instructions

Additional information abouthe PRU-ICSS subsystem can be found at: http://processors.wiki.ti.com/index.php/PRU-ICSS

Please refer to details of the SORTE MASTER at http://www.ti.com/tool/tidep-0085

NOTE: The current SORTE example as provided by the SDK does not implement CNC application as referenced by http://www.ti.com/tool/tidep-0061
