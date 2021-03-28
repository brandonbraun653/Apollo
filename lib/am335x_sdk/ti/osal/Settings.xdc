

module Settings
{
    /*! This is the OSAL Version */
    config string osalVersionString = "01.00.00.16";

    /*! This variable is to control the Os type selection.
     * By default this variable is set to NULL.
     * 
     * To use CSL for the selected device, add the following lines to config
     * file and set the deviceType correctly:
	 *
     *      var osalSettings = xdc.useModule ('ti.drv.osal.Settings');
     *      osalSettings.osType = "tirtos";
     * 
     */
    metaonly config string osType = "tirtos";
    /*! This variable is to control the SoC type selection.
     * By default this variable is set to NULL.
     * 
     * To use CSL for the selected device, add the following lines to config
     * file and set the deviceType correctly:
	 *
     *      var osalSettings = xdc.useModule ('ti.drv.osal.Settings');
     *      osalSettings.socType = "am572x";
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

