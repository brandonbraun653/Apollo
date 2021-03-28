

module Settings
{
    config string gpioVersionString = "01.00.00.16";
    /*! This variable is to control the SoC type selection.
     * By default this variable is set to NULL.
     * 
     * To use LLD for the selected device, add the following lines to config
     * file and set the deviceType correctly:
	 *
     *      var gpioSettings = xdc.useModule ('ti.drv.gpio.Settings');
     *      gpioSettings.socType = "am572x";
     * 
     */
    metaonly config string socType = "";

    /*! This flag is used to indicate whether or not the benchmarking code
     * (defined in the profilingHooks class) will be used in the project.
     * Note that a separate library has been compiled and will be used
     * ($NAME).profiling.a($SUFFIX). This is set in the *.cfg file.
     */
    config Bool enableProfiling = false;
	
    /*! This variable is to control the device library type selection.
     * By default this variable is set to release.
     * 
     * To use CSL to use the debug/release library, add the following lines to config
     * file and set the library profile accordingly:
     * 
     *      var Uart Settings = xdc.useModule ('ti.Uart.Settings');
     *      UartSettings.libProfile = "debug";
     * 
     */
    metaonly config string libProfile = "release";	

}

