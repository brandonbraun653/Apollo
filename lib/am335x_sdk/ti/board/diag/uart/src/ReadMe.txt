Follow below steps to run UART stress test on AM65xx platform using the ttl script.

This test runs on 3 or 4 UART ports based on the platform as listed below
AM65xx EVM:
    1)SoC MAIN UART0
    2)SoC MAIN UART1
    3)MCU UART
    4)Wakeup UART
    
AM65xx IDK:
    1)SoC MAIN UART0
    2)MCU UART
    3)Wakeup UART

Test Procedure
---------------
 - Connect USB cable to the AM65xx EVM JTAG port (J23)
 - Connect USB cable between AM65xx EVM serial port (J42) and host PC.
 - Open serial console (Teraterm) on host PC, connect to COM port on which EVM UART port is connected
 - There will be four COM ports displayed on the host PC which are mapped to SoC UART ports in below order
   -- First COM port : SoC MAIN UART0
   -- Second COM port : MCU UART
   -- Third COM port : Wakeup UART
   -- Fourth COM port : SoC MAIN UART1
 - Configure serial console for all the ports as applicable (4 for AM65xx EVM and 3 for AM65xx IDK).
  - setup for following configurations for all the ports.
    Baud rate    -    115200 
    Data length  -    8 bit
    Parity       -    None
    Stop bits    -    1
    Flow control -    None
 - Run the TTL script from all the Teraterm consoles by selecting menu 'Control->Macro' and select the script file "am65xx_uart_stress_test_script.ttl"
 - Load and run the UART diagnostic stress test binary (uartStress_diagExample_<Board>_armv8.xa53fg) on A53 core.
 - Test script shall start displaying the messages on Teraterm consoles.
 - Test shall take few hours to complete and displays final result on the console.
 


   

