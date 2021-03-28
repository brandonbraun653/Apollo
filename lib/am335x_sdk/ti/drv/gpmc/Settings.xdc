

module Settings
{
    config string gpmcVersionString = "01.00.00.03";
    /*! This variable is to control the SoC type selection.
     * By default this variable is set to NULL.
     *
     * To use LLD for the selected device, add the following lines to config
     * file and set the deviceType correctly:
     *
     *      var gpmcSettings = xdc.useModule ('ti.drv.gpmc.Settings');
     *      gpmcSettings.socType = "am437x";
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
     *      var GpmcSettings = xdc.useModule ('ti.Gpmc.Settings');
     *      GpmcSettings.libProfile = "debug";
     * 
     */
    metaonly config string libProfile = "release";	

}

