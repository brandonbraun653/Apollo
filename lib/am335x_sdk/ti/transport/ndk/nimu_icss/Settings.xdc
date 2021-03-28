

module Settings
{
    config string nimu_icssVersionString = "01.00.00.17";
	
    /*! This variable is to control the device library type selection.
     * By default this variable is set to release.
     * 
     * To use NIMU-ICSS to use the debug/release library, add the following lines to config
     * file and set the library profile accordingly:
     * 
     *      var Nimu_Icss  = xdc.loadPackage('ti.transport.ndk.nimu_icss');
     *      Nimu_Icss.Settings.libProfile = "debug";
     * 
     */
    metaonly config string libProfile = "release";	
}

