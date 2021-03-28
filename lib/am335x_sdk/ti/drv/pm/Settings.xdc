

module Settings
{
    config string pmVersionString = "01.04.00.05";

    /*! This variable is to control the SoC type selection.
     * By default this variable is set to NULL.
     *
     * To use PM for the selected device, add the following lines to config
     * file and set the deviceType correctly:
     *
     *      var pmSettings = xdc.useModule ('ti.drv.pm.Settings');
     *      pmSettings.socType = "am572x";
     *
     */
    metaonly config string socType = "";

    /*! This variable is to control the device library type selection.
     * By default this variable is set to release.
     *
     * To use the debug/release library, add the following lines to config
     * file and set the library profile accordingly:
     *
     *      var pm Settings = xdc.useModule ('ti.drv.pm.Settings');
     *      pmSettings.libProfile = "debug";
     *
     */
    metaonly config string libProfile = "release";
}
