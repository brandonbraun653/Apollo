function getAllFiles(dir)
{     
    var srcFile = [];
    var d;

    /* If recurse parameter is not specified we default to recursive search. */
    //if (recurse == null)
    var recurse = true;

    if (dir == undefined) 
        d = ".";
    else 
        d = dir;

    /* Get access to the current directory. */
    var file = new java.io.File(d);

    /* Check if the file exists and it is a directory. */
    if (file.exists() && file.isDirectory()) 
    {
        /* Get a list of all files in the specific directory. */
        var fileList = file.listFiles();
        for (var i = 0; i < fileList.length; i++) 
        {
            /* Dont add the generated directory 'package' and any of its files 
             * to the list here. */
            if ((fileList[i].getName().matches("package") == false) && (fileList[i].getName().matches(".git") == false))
            {
                /* Check if the detected file is a directory */
                if (fileList[i].isDirectory())
                {
                    /* We will recurse into the subdirectory only if required to do so. */
                    if (recurse == true)
                    {
                        /* Generate the directory Name in which we will recurse. */ 
                        var directoryName = d + "/" + fileList[i].getName();

                        /* Get a list of all files in this directory */
                        var fileListing = getAllFiles(directoryName);
                        if (fileListing != null)
                        {
                            /* Return a list of all file names in the directory. */
                            for (var j = 0 ; j < fileListing.length; j++) 
                                srcFile[srcFile.length++] = fileListing[j];
                        }
                    }
                }
                else
                {
                    /* This was a file. Check if the file name matches the extension */
                    //if (fileList[i].getName().endsWith(ext) == true)
                    srcFile[srcFile.length++] = d + "/" + fileList[i].getName();
                }
            }
        }

        return srcFile;
    }
    return null;
}
