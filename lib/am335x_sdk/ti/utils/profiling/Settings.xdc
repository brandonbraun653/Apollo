

module Settings
{
    config string profilingversionString = "01.00.00.08";
	
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
