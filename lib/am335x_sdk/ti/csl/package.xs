/*
 *  ======== package.xs ========
 *
 */


/*
 *  ======== Package.getLibs ========
 *  This function is called when a program's configuration files are
 *  being generated and it returns the name of a library appropriate
 *  for the program's configuration.
 */

function getLibs(prog)
{

    var suffix = prog.build.target.suffix;

    /* Default CSL library */
    var name = this.$name + ".a" + suffix;

    /* Check if intc library needs to be returned */
    var name_intc = "";
    if (this.Settings.useCSLIntcLib == true)
    {
       name_intc = this.$name + ".intc" + ".a" + suffix;
    }    

    /* Read LIBDIR variable */
    var lib_dir = java.lang.System.getenv("LIBDIR");

    /* If NULL, default to "lib" folder */
    if (lib_dir == null)
    {
        lib_dir = "./lib";
    } else {
        print ("\tSystem environment LIBDIR variable defined : " + lib_dir);
    }

   if (this.Settings.deviceType.equals(""))
   {
        var deviceType = "";
        print ("\tCSL deviceType is set to null - deriving the SOC name from RTSC platform ");
        var platform_lc = prog.platform;

        print ("\t RTSC platform ID is " + platform_lc );

        if ( java.lang.String(platform_lc).contains('K2K') )
            deviceType = "k2k";
        else if ( java.lang.String(platform_lc).contains('K2H') )
            deviceType = "k2h";
        else if (java.lang.String(platform_lc).contains('K2L'))
            deviceType = "k2l";
        else if (java.lang.String(platform_lc).contains('K2E'))
            deviceType = "k2e";
        else if (java.lang.String(platform_lc).contains('K2G'))
            deviceType = "k2g";
        else if (java.lang.String(platform_lc).contains('c6678'))
            deviceType = "c6678";
        else if (java.lang.String(platform_lc).contains('c6747'))
            deviceType = "c6747";
        else if (java.lang.String(platform_lc).contains('c6657'))
            deviceType = "c6657";
        else if (java.lang.String(platform_lc).contains('AM3'))
            deviceType = "am335x";
        else if (java.lang.String(platform_lc).contains('AM437X'))
            deviceType = "am437x";
        else if (java.lang.String(platform_lc).contains('DRA7'))
            deviceType = "dra72x";
        else if (java.lang.String(platform_lc).contains('AM572X'))
            deviceType = "am572x";
        else if (java.lang.String(platform_lc).contains('AM571X'))
            deviceType = "am571x";
        else if (java.lang.String(platform_lc).contains('OMAPL137'))
            deviceType = "omapl137";
        else if (java.lang.String(platform_lc).contains('OMAPL138'))
            deviceType = "omapl138";
        else if (java.lang.String(platform_lc).contains('AM65X'))
            deviceType = "am65xx";
        else if (java.lang.String(platform_lc).contains('J721E'))
            deviceType = "j721e";
        else if (java.lang.String(platform_lc).contains('TPR12'))
            deviceType = "tpr12";

        print ("\t discovered deviceType is " + deviceType );
        this.Settings.deviceType = deviceType;
   }

    /* Device types supported */
    var deviceTypes = [
                        'k2k',
                        'k2h',
                        'k2e',
                        'k2l',
                        'k2g',
                        'dra72x',
                        'dra75x',
                        'dra78x',
                        'am572x',
                        'am571x',
                        'am574x',
                        'c6678',
                        'c6657',
                        'am335x',
                        'am437x',
                        'omapl137',
                        'omapl138',
                        'c6747',
                        'am65xx',
                        'j721e',
                        'tpr12'
                      ];
    
    /* Search for the supported devices (defined in config.bld) */
    for each(var device in deviceTypes)
    {
        if (this.Settings.deviceType.equals(device))
        {
            lib_dir = lib_dir + "/" + device;
            break;
        }
    }

    /* Get target folder, if applicable */
    if ( java.lang.String(suffix).contains('66') )
        lib_dir = lib_dir + "/c66";
	else if ( java.lang.String(suffix).contains('674') )
        lib_dir = lib_dir + "/c674";
	else if (java.lang.String(suffix).contains('a15'))
		lib_dir = lib_dir + "/a15";
	else if (java.lang.String(suffix).contains('m4'))
		lib_dir = lib_dir + "/m4";
	else if (java.lang.String(suffix).contains('a8'))
		lib_dir = lib_dir + "/a8";
	else if (java.lang.String(suffix).contains('a9'))
		lib_dir = lib_dir + "/a9";
	else if (java.lang.String(suffix).contains('e9'))
		lib_dir = lib_dir + "/arm9";
	else if (java.lang.String(suffix).contains('r5'))
		lib_dir = lib_dir + "/r5f";
	else if (java.lang.String(suffix).contains('a53'))
		lib_dir = lib_dir + "/a53";

	var libProfiles = ["debug", "release"];
    /* get the configured library profile */
    for each(var profile in libProfiles)
    {
        if (this.Settings.libProfile.equals(profile))
        {
            lib_dir = lib_dir + "/" + profile;
            break;
        }
    }	
	
    if ((java.io.File(this.packageBase + lib_dir + "/" + name).exists()) || 
        (java.io.File(this.packageBase + lib_dir + "/" + name_intc).exists())) 
    {
        /* CSL library */
        var lib = lib_dir + "/" + name;

        /* CSL INTC library, if exist */
        if(name_intc != "")
        {
            lib = lib + ";" + lib_dir +"/" + name_intc;
        }

        print ("\tLinking with library " + this.$name + ":" + lib);
        return lib;
    }
    
    /* Could not find any library, throw exception */
    if(name_intc != "")
        throw new Error("\tLibrary not found : " + name + ", " + name_intc);
    else
        throw new Error("\tLibrary not found : " + name);
}

/*
 *  ======== package.close ========
 */
function close()
{    
    if (xdc.om.$name != 'cfg') {
        return;
    }
}

