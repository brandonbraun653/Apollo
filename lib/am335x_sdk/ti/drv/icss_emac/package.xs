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
    var name = "";
    var socType = this.Settings.socType;
    var profilingTag = "";

    socType = socType.toLowerCase();
    /* Replace the last charecter in SoC am#### to am###x */
    if (socType.substring(0, 2) == "am")
    {
        socType = socType.substring(0, socType.length - 1);
        socType = socType.concat("x");
    }

    if (this.Settings.enableProfiling == true)
    {
        profilingTag = ".profiling"
    }
    name = this.$name + profilingTag + ".a" + suffix;
    
    /* Read LIBDIR variable */
    var lib = java.lang.System.getenv("LIBDIR");

    /* If NULL, default to "lib" folder */
    if (lib == null)
    {
        lib = "./lib";
    } else {
        print ("\tSystem environment LIBDIR variable defined : " + lib);
    }
	
    var socTypes = [ 
                     'am571x',
                     'am572x',
                     'am574x',
                     'am335x',
                     'am437x',
                     'k2g',
                     'am65xx'
                   ];

    /* Get the SOC */
    for each (var soc in socTypes)
    {
        if (socType.equals(soc))
        {
            lib = lib + "/" + soc;
            name = this.$name + profilingTag + ".a" + suffix;	 
            break;
        }
    }

    /* Get target folder, if applicable */
    if ( java.lang.String(suffix).contains('66') )
        lib = lib + "/c66";
    else if (java.lang.String(suffix).contains('a15') )
        lib = lib + "/a15";
    else if (java.lang.String(suffix).contains('m4') )
        lib = lib + "/m4";
    else if (java.lang.String(suffix).contains('a9') )
        lib = lib + "/a9";
    else if (java.lang.String(suffix).contains('a8') )
        lib = lib + "/a8";        
    else if (java.lang.String(suffix).contains('a53') )
        lib = lib + "/a53";
    else if (java.lang.String(suffix).contains('r5f') )
        lib = lib + "/r5f";
    else
        throw new Error("\tUnknown target for: " + this.packageBase + lib);
    
    var libProfiles = ["debug", "release"];
    /* get the configured library profile */
    for each(var profile in libProfiles)
    {
        if (this.Settings.libProfile.equals(profile))
        {
            lib = lib + "/" + profile;
            break;
        }
    }	

    /* Get library name with path */
    lib = lib + "/" + name;
    if (java.io.File(this.packageBase + lib).exists()) {
       print ("\tLinking with library " + this.$name + ":" + lib);
       return lib;
    }

    /* Could not find any library, throw exception */
    throw new Error("\tLibrary not found: " + this.packageBase + lib);
}

function init() {
xdc.loadPackage("ti.osal");
xdc.loadPackage("ti.csl");
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
