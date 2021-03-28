

module Settings
{
    /*! This is the EMAC Version */
    config string emaclldVersionString = "01.00.03.18";

    /*! This variable is to control the device type selection.
     * By default this variable is set to NULL.
     * 
     * To use EMAC for the selected device, add the following lines to config
     * file and set the socType correctly:
     * 
     *      var emacSettings = xdc.useModule ('ti.drv.emac.Settings');
     *      emacSettings.socType = "k2g";
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


