

module Settings
{
    /*! This is the CSL Version */
    config string cslVersionString = "03.03.00.17";

    /*! The flag is used to indicate if the CSL INTC Library needs to be built or not.
     * This flag is FALSE by default since most operating systems provide INTC support and 
     * do not need to use this library. 
     * To ensure that the INTC library is also returned; add the following lines to the
     * configuration file
     * 
     *      var cslSettings = xdc.useModule ('ti.csl.Settings');
     *      cslSettings.useCSLIntcLib = true;
     * 
     */
    config Bool useCSLIntcLib = false;

    /*! This variable is to control the device type selection.
     * By default this variable is set to NULL.
     * 
     * To use CSL for the selected device, add the following lines to config
     * file and set the deviceType correctly:
     * 
     *      var cslSettings = xdc.useModule ('ti.csl.Settings');
     *      cslSettings.deviceType = "k2k";
     * 
     */
    metaonly config string deviceType = "";
	
    /*! This variable is to control the device library type selection.
     * By default this variable is set to release.
     * 
     * To use CSL to use the debug/release library, add the following lines to config
     * file and set the library profile accordingly:
     * 
     *      var cslSettings = xdc.useModule ('ti.csl.Settings');
     *      cslSettings.libProfile = "debug";
     * 
     */
    metaonly config string libProfile = "release";	
}

