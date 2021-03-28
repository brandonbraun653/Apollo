
 /**
  * Include files
  */
#include "ti/transport/ndk/nimu/example/ftpApp/modules.h"

#ifdef FTP_SERVER_MODULE_INCLUDED

#include <ti/csl/csl_error.h>
#include <ti/fs/fatfs/ff.h>
#include <ti/transport/ndk/nimu/example/ftpApp/ftpserver/ftpserver.h>

/**
 * Local functions
 */
static int32_t func_opts (io_handler_t *ioh);
static int32_t func_user (io_handler_t *ioh);
static int32_t func_pass (io_handler_t *ioh);
static int32_t func_stor (io_handler_t *ioh);
static int32_t func_dele (io_handler_t *ioh);
static int32_t func_xrmd (io_handler_t *ioh);
static int32_t func_cwd (io_handler_t *ioh);
static int32_t func_xpwd (io_handler_t *ioh);
static int32_t func_retr (io_handler_t *ioh);
static int32_t func_list (io_handler_t *ioh);
static int32_t func_port (io_handler_t *ioh);
static int32_t func_nlst (io_handler_t *ioh);
static int32_t func_quit (io_handler_t *ioh);

/**
 * Local variables
 */
ftp_cmd_handler_t cmd_handler[] =
{
    {"OPTS", 4, func_opts },
    {"USER", 4, func_user },
    {"PASS", 4, func_pass },
    {"STOR", 4, func_stor },
    {"DELE", 4, func_dele },
    {"XRMD", 4, func_xrmd },
    {"CWD",  3, func_cwd },
    {"XPWD", 4, func_xpwd },
    {"RETR", 4, func_retr },
    {"LIST", 4, func_list },
    {"PORT", 4, func_port },
    {"NLST", 4, func_nlst },
    {"LIST", 4, func_nlst },
    {"QUIT", 4, func_quit },
    {NULL, 0, NULL }
};

extern char ftpUser[NAME_AND_PASSWD_LEN];
extern char ftpPassword[NAME_AND_PASSWD_LEN];

/**
 * @brief  Return second argument from input string.
 */
static void argument_collector(char *_buffer, char  *_nameBuffer)
{
    /* TODO: Use malloc */
    char bf[1024];
    char sep[2] = " ";
    char *word;
    int32_t  wcount=0;

    strcpy(bf, _buffer);
    for (word = strtok(bf, sep);word;word = strtok(NULL, sep))
    {
        wcount++;
        if(wcount == 2)
        {
            strcpy(_nameBuffer, word);
        }
    }
}

/**
 * check_authentificated
 */
static boolean_t check_authentificated (io_handler_t *ioh)
{
    if (!ioh->authenticated)
    {
        sprintf(ioh->send_buffer,"530 Please log in with USER and PASS first. \r\n");
        send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);
        return FALSE;
    }

    return TRUE;
}

/**
 * func_opts
 */
static int32_t func_opts (io_handler_t *ioh)
{
    int32_t bytes;

    argument_collector (ioh->receive_buffer, ioh->temp);

    sprintf(ioh->send_buffer,"530 Please log in with USER and PASS first.\r\n");
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}


/**
 * func_user
 */
static int32_t func_user (io_handler_t *ioh)
{
    int32_t bytes;

    argument_collector (ioh->receive_buffer, ioh->user);

    sprintf(ioh->send_buffer,"331 Password required \r\n");
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}

/**
 * func_pass
 */
static int32_t func_pass (io_handler_t *ioh)
{
    int32_t bytes;

    argument_collector (ioh->receive_buffer, ioh->password);
    if (strcmp (ioh->user, ftpUser) == 0 && strcmp (ioh->password, ftpPassword) == 0)
    {
        sprintf(ioh->send_buffer,"230 Public login successful \r\n");
        bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);
        if (bytes < 0) return -1;
        ioh->authenticated = 1;
    }
    else
    {
        sprintf(ioh->send_buffer,"530 Invalid username or password \r\n");
        bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);
        if (bytes < 0) return -1;
        ioh->authenticated = 0;
    }

    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}

/**
 * func_dele
 */
static int32_t func_dele (io_handler_t *ioh)
{
    int32_t bytes;
    char path[64];

    if (!check_authentificated (ioh)) return -1;
    argument_collector(ioh->receive_buffer, path);

    if(0)
    {
        sprintf(ioh->send_buffer, "550 File not found\r\n");
    }
    else
    {
        sprintf(ioh->send_buffer, "200 Ok\r\n");
    }
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}

/**
 * func_xrmd
 */
static int32_t func_xrmd (io_handler_t *ioh)
{
    int32_t bytes;
    char path[64];

    if (!check_authentificated (ioh)) return -1;
    argument_collector(ioh->receive_buffer, path);

    if (0)
    {
        sprintf(ioh->send_buffer, "550 Directory not found\r\n");
    }
    else
    {
        sprintf(ioh->send_buffer, "200 Ok\r\n");
    }
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}

/**
 * func_stor
 */
static int32_t func_stor (io_handler_t *ioh)
{
    int32_t bytes;
    char filename[64];

    if (!check_authentificated (ioh)) return -1;

    argument_collector(ioh->receive_buffer, filename);

    sprintf(ioh->send_buffer,"150 OK\r\n");
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    if (ftp_filerout_write (ioh, filename) == 0)
    {
        sprintf(ioh->send_buffer, "226 File transfer completed\r\n");
    }
    else
    {
        sprintf(ioh->send_buffer, "450 Requested file action not taken\r\n");
    }

    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);
    if (bytes > 0) return ERROR_SUCCESS;

    return -1;
}

/**
 * func_cwd
 */
static int32_t func_cwd (io_handler_t *ioh)
{
    int32_t bytes;
    char path[64];

    if (!check_authentificated (ioh)) return -1;
    argument_collector(ioh->receive_buffer, path);

    if (0)
    {
        sprintf(ioh->send_buffer, "250 CWD successful. %s is current directory\r\n", ioh->current_working_dir_path);
    }
    else
    {
        sprintf(ioh->send_buffer, "550 CWD failed.\r\n");
    }
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}

/**
 * func_xpwd
 */
static int32_t func_xpwd (io_handler_t *ioh)
{
    int32_t bytes;
    if (!check_authentificated (ioh)) return -1;

    sprintf(ioh->send_buffer, "257 \"%s\" is current directory\r\n", ioh->current_working_dir_path);
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);
    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}

/**
 * func_retr
 */
static int32_t func_retr (io_handler_t *ioh)
{
    int32_t bytes;
    char filename[64];
    if (!check_authentificated (ioh)) return -1;

    argument_collector(ioh->receive_buffer, filename);

    sprintf(ioh->send_buffer,"150 Transfering... \r\n");
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    if (ftp_filerout_read (ioh, filename) == CSL_SOK)
    {
        sprintf(ioh->send_buffer,"226 File transfer completed... \r\n");
    }
    else
    {
        sprintf(ioh->send_buffer,"450 Requested file action not taken\r\n");
    }
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    fdClose(ioh->data_socket);

    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}

/**
 * func_list
 */
static int32_t func_list (io_handler_t *ioh)
{
    int32_t bytes;
    char *buffer;

    if (!check_authentificated (ioh)) return -1;

    if ((buffer = malloc (16384)) != NULL)
    {
        sprintf(ioh->send_buffer,"150 Transfering... \r\n");
        bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);
        send(ioh->data_socket, buffer, strlen(buffer), 0);
        free (buffer);
    }

    sprintf(ioh->send_buffer,"226 File transfer completed... \r\n");
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    fdClose(ioh->data_socket);

    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}

/**
 * func_port
 */
static int32_t func_port (io_handler_t *ioh)
{
    int act_port[2];
    int act_ip[4], port_dec;
    char ip_decimal[40];
    struct sockaddr_in remoteaddr_act;
    int32_t bytes;

    if (!check_authentificated (ioh)) return -1;

    if (ioh->data_socket) fdClose(ioh->data_socket);
    ioh->data_socket = socket(AF_INET, SOCK_STREAMNC, IPPROTO_TCP);

    /* local variables */
    sscanf(ioh->receive_buffer, "PORT %d,%d,%d,%d,%d,%d", &act_ip[0], &act_ip[1], &act_ip[2], &act_ip[3], &act_port[0], &act_port[1]);
    sprintf(ip_decimal, "%d.%d.%d.%d", act_ip[0], act_ip[1], act_ip[2],act_ip[3]);
    port_dec = (act_port[0] * 256) + act_port[1];

    /* Prepare address for connect */
    memset( &remoteaddr_act,0, sizeof(struct sockaddr_in) );
    remoteaddr_act.sin_family = AF_INET;
    remoteaddr_act.sin_addr.s_addr = inet_addr(ip_decimal);
    remoteaddr_act.sin_port = NDK_htons(port_dec);

    if (connect (ioh->data_socket, (struct sockaddr *)&remoteaddr_act, (int32_t) sizeof(struct sockaddr_in)) == SOCKET_ERROR)
    {
        sprintf(ioh->send_buffer, "425 Something is wrong, can't start the active connection... \r\n");
        bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);
        fdClose(ioh->data_socket);
    }
    else
    {
        sprintf(ioh->send_buffer, "200 Ok\r\n");
        bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);
    }

    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}

/**
 * func_nlst
 */
static int32_t func_nlst (io_handler_t *ioh)
{
    char *buffer;
    int32_t bytes;

    if (!check_authentificated (ioh)) return -1;
    if ((buffer = malloc (16384)) != NULL) /* Todo: User realloc () */
    {
        sprintf(ioh->send_buffer,"150 Transfering... \r\n");
        bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);
        send(ioh->data_socket, buffer, strlen(buffer), 0);
        free (buffer);
    }

    sprintf(ioh->send_buffer,"226 File transfer completed... \r\n");
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    fdClose(ioh->data_socket);

    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}

/**
 * func_quit
 */
static int32_t func_quit (io_handler_t *ioh)
{
    int32_t bytes;
    sprintf(ioh->send_buffer,"221 Connection closed by the FTP client\r\n");
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    ioh->running = FALSE;

    if (bytes > 0) return ERROR_SUCCESS;
    return -1;
}

#endif
