function getLibs(prog)
{
    var libList = null;
	var suffix = prog.build.target.suffix;
	/*var name = this.$name + ".a";*/
	var name = "utils.a";
	var lib = "../binary/utils/lib";
	
	var socType = this.Settings.socType;
	socType = socType.toLowerCase();
	
	lib = lib + "/" + socType;
	if (java.lang.String(suffix).contains('a8') )
        lib = lib + "/a8";        
    else if (java.lang.String(suffix).contains('a9') )
		lib = lib + "/a9";
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
	
	lib = lib + "/gcc";

	/* Get library name with path */
    lib = lib + "/" + "lib" + name;
    /*if (java.io.File(this.packageBase + lib).exists()) {*/
       print ("\tLinking with library " + this.$name + ":" + lib);
       return lib;
    /*}*/

}