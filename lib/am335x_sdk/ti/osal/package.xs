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

    var name = this.$name + ".a" + suffix;
	
    var soc  = this.Settings.socType;	
    
    var osType = this.Settings.osType;
	
    soc = soc.toLowerCase();
    osType = osType.toLowerCase();
	
    /* Read LIBDIR variable */
    var lib = java.lang.System.getenv("LIBDIR");

    /* If NULL, default to "lib" folder */
    if (lib == null)
    {
        lib = "./lib";
    } else {
        print ("\tSystem environment LIBDIR variable defined : " + lib);
    }

	/* Get the Soc layer for bare metal case */
    if (osType.equals("tirtos")) 
    {
        lib = lib + "/" + osType;
        if (!soc)
        {
            
        }
        else if (soc.substring(0, 2) == "am")
        {

          if( soc.substring(0, 3) != "am6") 
          {

            /* replace the last charecter in soc to x */
            soc = soc.substring(0, soc.length - 1);
            soc = soc.concat("x");
          }
          lib = lib + "/" + soc;
        }
        else 
        {
            lib = lib + "/" + soc;
        }
    }
	
	/* Get the Soc layer for bare metal case */
    if (osType.equals("nonos")) 
    {
        lib = lib + "/" + osType;
        if (!soc)
        {
             throw new Error ("Soc is not defined");
        }
        else if (soc.substring(0, 2) == "am")
        {
            /* replace the last charecter in soc to x */
            soc = soc.substring(0, soc.length - 1);
            soc = soc.concat("x");
            lib = lib + "/" + soc;
        }
        else 
        {
            lib = lib + "/" + soc;
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
    else if (java.lang.String(suffix).contains('674') )
        lib = lib + "/c674";
    else if (java.lang.String(suffix).contains('e9') )
        lib = lib + "/arm9";
    else if (java.lang.String(suffix).contains('a8') )
        lib = lib + "/a8";  
    else if (java.lang.String(suffix).contains('a53'))
	lib = lib + "/a53";
    else if (java.lang.String(suffix).contains('r5f'))
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
    xdc.loadPackage("ti.csl");
    xdc.loadPackage("ti.sysbios");
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
