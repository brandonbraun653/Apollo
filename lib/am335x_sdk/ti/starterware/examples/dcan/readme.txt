----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

-----------------------------------------------------------------------------------------------------------
 Introduction
-----------------------------------------------------------------------------------------------------------
This documents explains the procedure to build and run the DCAN loopback example
in TI RTOS environment. It also provides the steps followed to add TI RTOS
support for DCAN loopback example which can be used as guidelines for adding RTOS support
for other StarterWare examples. DCAN loopback example is supported on AM335x, AM437x platforms and tested
on AM335x GP EVM and AM437x GP EVM.


-----------------------------------------------------------------------------------------------------------
 Creating CCS Projects
-----------------------------------------------------------------------------------------------------------
DCAN RTOS example needs to be executed using CCS example projects. However, CCS project files are not
provided as part of the package. CCS project configuration files are provided using which CCS projects
need to be created manually.
Follow below steps to create the CCS projects for DCAN StarterWare example
 - Open command prompt, go the PDK root folder (<PDK Install Dir>/packages) and run pdksetupenv script
 - Run the pdkProjectCreate script with options as shown below
   pdkProjectCreate.bat <soc> <board> little dcan all arm
   <soc> can be AM335x or AM437x
   <board> can be evmAM335x or evmAM437x
 - Successful execution of above command will create DCAN project under the folder
   <PDK Install Dir>/packages/MyExampleProjects


-----------------------------------------------------------------------------------------------------------
 Building DCAN Loopback Example for RTOS - Using Makefile
-----------------------------------------------------------------------------------------------------------
Follow below steps to build DCAN Loopback Example for RTOS from Command Line
 - Open command prompt, go the PDK root folder (<PDK Install Dir>/packages) and run pdksetupenv script
 - Change the directory to StarterWare folder
   cd ti/starterware
 - Build the dcan loopback example
   gmake  dcan_app_loopback PLATFORM=<platform> BOARD=<board> PROFILE=release RTOS_BUILD=yes

    Above step cleans and rebuilds the libraries along with DCAN loopback example
    <platform> is am335x-evm for AM335x and am43xx-evm for AM437x
    <board> is evmAM335x for AM335x and evmAM437x for AM437x
 - Upon successful build, the dcan example binary will be created under the folder
   <PDK Install Dir>/packages/ti/binary/dcan_app_loopback/bin/<soc>/
   > Note:
   Use the following command, to change the default path for the binary
   gmake dcan_app_loopback PLATFORM=<platform> BOARD=<board> PROFILE=release RTOS_BUILD=yes BINDIR=<custom_path>
   > Example:
   To create the binary under the folder <PDK Install Dir>/ti/starterware/binary/examples/dcan_app_loopback use
   the following command
   gmake dcan_app_loopback PLATFORM=<platform> BOARD=<board> PROFILE=release RTOS_BUILD=yes
   BINDIR=<PDK Install Dir>/ti/starterware/binary/examples/dcan_app_loopback
 - The binary can be loaded onto the target device using CCS.
 - The expected output will be same as described in the next section.

-----------------------------------------------------------------------------------------------------------
 Running the DCAN example
-----------------------------------------------------------------------------------------------------------
Follow below steps to build and run the DCAN example from CCS
 - Open CCS IDE and import the DCAN example project using 'Project -> Import CCS Projects' menu
 - Build the projects using 'Project -> Build Project' menu
 - Launch the target config file for the platform under test - evmAM335x/evmAM437x
 - Connect the serial port of the board to host PC and setup the serial port application on host PC
 - Connect the target in CCS and load the DCAN test binary
 - Run the program and observe the test output in serial console application on host PC
   -- Enter the number frames to transfer
   -- Enter the frame data
   -- Data received in loopback mode shall be displayed on the serial console

Below is the sample log for DCAN loopback example
 ---------------------------------------------------------------------------
|     StarterWare DCAN loopback Application!!                               |
|                                                                           |
|     Please enter the number of frames (from 1 to 10) to transmit: 2       |
|                                                                           |
|     Please enter exactly 8 characters for frame 01: 12345678              |
|     Please enter exactly 8 characters for frame 02: abcdeabc              |
|                                                                           |
|     Frame reception complete                                              |
|     Frame 01 data: 12345678                                               |
|     Frame 02 data: abcdeabc                                               |
 ---------------------------------------------------------------------------


-----------------------------------------------------------------------------------------------------------
 Procedure to add SYS/BIOS support for StarterWare examples
-----------------------------------------------------------------------------------------------------------
 Configuring Interrupts
 -----------------------
Major difference for running the StarterWare examples in the baremetal and RTOS environment is the way
interrupts are configured and dispatched. StarterWare baremetal examples configure the interrupts
using INTC and GIC modules. This need to be updated to use the RTOS APIs to add support for TI RTOS.
TI OSAL library should be used to configure the interrupts. All the functions doing the interrupt
configuration shall be updated to use OSAL library APIs.

Interrupt configurations in edma_utils.c and dcan_app.c are updated to use OSAL APIs while adding RTOS
support for DCAN example which can be used as reference.

 Using Tasks
 ------------
RTOS based examples can use tasks to run the test. This is not a mandatory requirement but can be
used if multithread execution is needed. Create the tasks using TI RTOS API Task_create and start
the RTOS execution by calling BIOS_start() function.

Refer to main function in loopback_app_main.c (starterware/examples/dcan/loopback) for creating
the tasks and invoking the BIOS execution.

 Creating RTOS config files
 ---------------------------
All the TI RTOS configurations are enabled using a config file (.cfg). TI RTOS config files
am335x_app_dcan_evmam335x.cfg and am437x_app_dcan_evmam437x.cfg(starterware/examples/dcan/loopback/rtos)
added for DCAN examples can be used as reference.

 Creating CCS project setup files
 --------------------------------
CCS projects files can be created manually from CCS IDE or use the project configuration text files and
pdkProjectCreate script to create the project. Project configuration text files(starterware/examples/dcan/loopback/rtos)
added for DCAN example can be used as reference.

 Symbols:
  Define below symbols (-D<Symbol Name>) in the project setup file
   Platform independent symbols
    - RTOS_BUILD
   AM335x platform specific symbols
    - SOC_AM335X
    - evmAM335x
    - AM335X_FAMILY_BUILD
   AM437x Platform specific symbols
    - SOC_AM437X
    - evmAM437x
    - AM43XX_FAMILY_BUILD

 Example utils:
  Some of the StarterWare examples use the example utils located at starterware\examples\example_utils.
  Inlcude the example utils source files in the project setup file based on the application need.

 Header files
 -------------
Some of TI RTOS header files related to interrupts and tasks need to be included in order to build
the project in RTOS environment. Refer to loopback_app_main.c (starterware/examples/dcan/loopback)
for the details of header files needed.

All the code modifications done for enabling TI RTOS support for DCAN loopback example are
under the flag 'RTOS_BUILD'. Search for this flag in the StarterWare to see all the changes
done for enabling RTOS support for DCAN loopback example.


TI RTOS configuration files and project setup files for DCAN loopback example are available at
starterware/examples/dcan/loopback/rtos
