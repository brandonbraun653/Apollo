

module Settings
{
    config string nimuVersionString = "01.00.00.17";
    /*! This variable is to control the SoC type selection.
     * By default this variable is set to NULL.
     * 
     * To use LLD for the selected device, add the following lines to config
     * file and set the deviceType correctly:
	 *
     *      var nimuSettings = xdc.useModule ('ti.transport.ndk.nimu.Settings');
     *      nimuSettings.socType = "am572x";
     * 
     */
    metaonly config string socType = "";
	
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

