----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

-----------------------------------------------------------------------------------------------------------
 Introduction
-----------------------------------------------------------------------------------------------------------
This documents explains the procedure to build and run the LCDC display example in TI RTOS environment.
It also provides the steps followed to add TI RTOS support for Display example. Display example 
is supported on AM335x platform and tested on AM335x GP EVM.


-----------------------------------------------------------------------------------------------------------
 Creating CCS Projects
-----------------------------------------------------------------------------------------------------------
Display RTOS example needs to be executed using CCS example projects. However, CCS project files are not
provided as part of the package. CCS project configuration files are provided using which CCS projects
need to be created manually.
Follow below steps to create the CCS projects for Display StarterWare example
 - Open command prompt, go the PDK root folder (<PDK Install Dir>/packages) and run pdksetupenv script
 - Run the pdkProjectCreate script with options as shown below
   pdkProjectCreate.bat <soc> <board> little lcdc all arm
   <soc> is AM335x
   <board> is evmAM335x
 - Successful execution of above command will create Display Example project under the folder
   <PDK Install Dir>/packages/MyExampleProjects


-----------------------------------------------------------------------------------------------------------
 Building LCDC Example for RTOS - Using Makefile
-----------------------------------------------------------------------------------------------------------
Follow below steps to build the LCDC Example for RTOS from Command Line. Ignore the previous section,
as the command to build LCDC example will take care of building the dependent Starterware libraries 
 - Open command prompt, go the PDK root folder (<PDK Install Dir>/packages) and run pdksetupenv script
 - Change the directory StarterWare folder
   cd ti/starterware
 - Build the LCDC example
   gmake lcdc_app_raster PLATFORM=<platform> BOARD=<board> PROFILE=release RTOS_BUILD=yes

   Above step cleans and rebuilds the libraries along with LCDC example
   <platform> is am335x-evm for AM335x
   <board> is evmAM335x for AM335x
 - Upon successful build, the LCDC example binary will be created under the folder
   <PDK Install Dir>/packages/ti/binary/lcdc_app_raster/bin/<soc>/
   > Note:
   Use the following command, to change the default path for the binary
   gmake lcdc_app_raster PLATFORM=<platform> BOARD=<board> PROFILE=release RTOS_BUILD=yes BINDIR=<custom_path>
   > Example:
   To create the binary under the folder <PDK Install Dir>/ti/starterware/binary/examples/lcdc_app_raster use
   the following command
   gmake lcdc_app_raster PLATFORM=<platform> BOARD=<board> PROFILE=release RTOS_BUILD=yes
   BINDIR=<PDK Install Dir>/ti/starterware/binary/examples/lcdc_app_raster
 - The binary can be loaded onto the target device using CCS.
 - The expected output will be same as described in the next section.
 
-----------------------------------------------------------------------------------------------------------
 Running the Display example
-----------------------------------------------------------------------------------------------------------
Follow below steps to build and run the Display example from CCS
 - Open CCS IDE and import the Display example project using 'Project -> Import CCS Projects' menu
 - Build the projects using 'Project -> Build Project' menu
 - Connect the target in CCS and load the Display test binary
 - Run the program and observe the test output on the LCD screen
   -- TI Logo shall be displayed on the LCD screen of the AM335x GP EVM

-----------------------------------------------------------------------------------------------------------
 Procedure to add SYS/BIOS support for Display StarterWare example
-----------------------------------------------------------------------------------------------------------
 Configuring Interrupts
 -----------------------
StarterWare baremetal examples configure the interrupts using INTC and GIC modules. This need to be 
updated to use the OSAL APIs to add support for TI RTOS. Interrupt configurations are updated to use 
OSAL APIs in raster_app_main.c file while adding RTOS support for Display example.

 Using Tasks
 ------------
Create the tasks using TI RTOS API Task_create and start the RTOS execution by calling BIOS_start()
function. The main function in raster_app_main.c (starterware/examples/lcdc/raster) is updated for creating
the tasks and invoking the BIOS execution.

 Creating RTOS config file
 ---------------------------
The TI RTOS configurations are enabled using a config file (.cfg). TI RTOS config file
am335x_app_lcdc_evmam335x.cfg is created under the folder starterware/examples/lcdc/raster/rtos

 Creating CCS project setup files
 --------------------------------
CCS projects files use the project configuration text files and pdkProjectCreate script to create the project. 
Project configuration text file of Display example LCDC_RasterExample_evmAM335x_armTestProject.txt is created 
under the folder starterware/examples/lcdc/raster/rtos.

 Symbols:
  Define below symbols (-D<Symbol Name>) in the project setup file
   - RTOS_BUILD
   - LCD_EVM
   - SOC_AM335X
   - evmAM335x
   - AM335X_FAMILY_BUILD

 Example utils:
  Some of the StarterWare examples use the example utils located at starterware\examples\example_utils.
  Inlcude the example utils source files in the project setup file based on the application need.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------