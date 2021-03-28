
 /**
  * Include files
  */
#include "ti/transport/ndk/nimu/example/ftpApp/modules.h"

#ifdef FTP_SERVER_MODULE_INCLUDED

#include <ti/csl/csl_error.h>
#include <ti/fs/fatfs/ff.h>
#include <ti/transport/ndk/nimu/example/ftpApp/ftpserver/ftpserver.h>

int32_t ftp_filerout_read(io_handler_t *ioh, char *path)
{
    int32_t i;

    for (i=0; i<5000;i++)
    {
        send(ioh->data_socket, ioh->DataBuf, DATA_BUFFER_SIZE, 0);
        Task_yield();
    }

    return CSL_SOK;
}

int32_t ftp_filerout_write(io_handler_t *ioh, char *path)
{
    int32_t bytesRead = 0;
    char *pBuf;
    void* hBuffer;

    do
    {
        bytesRead = (int)recvnc(ioh->data_socket, (void**)&pBuf, 0, &hBuffer);

        if (bytesRead > 0)
        {
            recvncfree(hBuffer);
        }
    } while (bytesRead > 0);

    return 0;
}

#endif
