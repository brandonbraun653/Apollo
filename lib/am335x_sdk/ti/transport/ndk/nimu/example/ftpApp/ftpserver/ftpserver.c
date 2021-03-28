/**
 * ftpserver.c
 *
 *   This file contains:
 *   - FTP Server and client implementation
 *   .
 *   which are relevant for the ftpserver module.
 *
 *   Used Registry entries:
 *        "NETWORK/FTPSERVER/CONFIG/PORT"
 *        "NETWORK/FTPSERVER/CONFIG/LISTEN_TIMEOUT"
 *        "NETWORK/FTPSERVER/USERNAME"
 *        "NETWORK/FTPSERVER/PASSWORD"
 *
 *     Registry write callback:
 *
 */

 /**
  * Include files
  */
#include "ti/transport/ndk/nimu/example/ftpApp/modules.h"

#ifdef FTP_SERVER_MODULE_INCLUDED

#include <ti/csl/csl_error.h>
#include <ti/fs/fatfs/ff.h>
#include <ti/transport/ndk/nimu/example/ftpApp/ftpserver/ftpserver.h>

/*
 * Defines
 */
#define LISTEN_TIMEOUT                        (10000)
#define FTPSERVER_PORT                        (21)

/* Ftpserver task definitions */
#define TASK_FTP_SERVER_STACK_SIZE            (4096)
#define TASK_FTP_SERVER_PRIO                (5)
#define TASK_FTP_SERVER_NAME                "FTP Task"

/* Ftpserver client connection task definitions */
#define TASK_FTP_SERVER_CLIENT_STACK_SIZE    (16384)
#define TASK_FTP_SERVER_CLIENT_PRIO            (5)
#define TASK_FTP_SERVER_CLIENT_NAME            "FTP-Client Task"

/*
 * Local functions
 */
static void ftpserver_thread_entry(UArg a0, UArg a1);
static void ftpserver_client_thread_entry (UArg a0, UArg a1);
static int32_t ftpserver_parser (io_handler_t *ioh);
static uint16_t port;
static uint32_t listen_timeout;

extern ftp_cmd_handler_t cmd_handler[];

char ftpUser[NAME_AND_PASSWD_LEN];
char ftpPassword[NAME_AND_PASSWD_LEN];

/*
 * ftpserver_init
 */
int32_t ftpserver_init(void)
{
    Task_Handle task;
    Task_Params params;
    Error_Block eb;

    Task_Params_init(&params);
    Error_init(&eb);

    params.priority = TASK_FTP_SERVER_PRIO;
    params.stackSize = TASK_FTP_SERVER_STACK_SIZE;
    params.arg0 = 0;
    params.arg1 = 0;
    
    /* Read data from config (or default values) */
    port = FTPSERVER_PORT;
    listen_timeout = LISTEN_TIMEOUT;

    task = Task_create(ftpserver_thread_entry, &params, &eb);
    if (task == NULL)
    {
        UART_printf("Task '%s', creation failed for ftpserver_thread!, Error %s\n", Error_getMsg(&eb));
        return ERROR_TASK_CREATE;
    }

    return ERROR_SUCCESS;
}

/**
 * ftpserver_thread_entry
 *
 * @brief     FTP server main thread. Listen on new connections and spawnes of client connection tasks.
 *
 * @param a0    Not used
 * @param a1    Not used
 *
 * @return        -
 */
void ftpserver_thread_entry(UArg a0, UArg a1)
{

    Task_Params params;
    Error_Block eb;

    struct sockaddr_in server_addr, client_addr;
    SOCKET listen_sock, client_sock;
    int len = sizeof(struct sockaddr_in);
    struct timeval timeout = {10, 0};



    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = NDK_htonl(INADDR_ANY);
    server_addr.sin_port = NDK_htons(port);

    fdOpenSession (TaskSelf ());

    if ((listen_sock = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
    {
        return;
    }

    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    server_addr.sin_port = NDK_htons(port);

    if (bind(listen_sock, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_in)) == SOCKET_ERROR)
    {
        fdClose(listen_sock);
        return;
    }

    if (listen(listen_sock, 5) == SOCKET_ERROR)
    {
        fdClose(listen_sock);
        return;
    }

    /* Set listen timeout to make watchdog work */
    timeout.tv_sec = listen_timeout;
    if (setsockopt(listen_sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == SOCKET_ERROR)
    {
        fdClose(listen_sock);
        return;
    }
    UART_printStatus("\n All tests have passed.\n");

    for (;;)
    {
        Task_Handle task;

        if( (client_sock = accept(listen_sock, (struct sockaddr*)&client_addr, &len)) == INVALID_SOCKET)
        {
            /* Timeout, Wait a short time and try again */
            fdClose (listen_sock);
            Task_sleep (100);
            break;
        }


        Task_Params_init(&params);
        Error_init(&eb);
    
        params.priority = TASK_FTP_SERVER_CLIENT_PRIO;
        params.stackSize = TASK_FTP_SERVER_CLIENT_STACK_SIZE;
        params.arg0 = (UArg)client_sock;
        params.arg1 = 0;


        task = Task_create(ftpserver_client_thread_entry, &params, &eb);
        if (task == NULL)
        {
            fdClose(client_sock);
            Task_sleep (100);
            continue;
        }
    }

    // Close the file session
    fdCloseSession(TaskSelf());
}

/**
 * ftpserver_client_thread_entry
 *
 * @brief     FTP server client connection task. Spawned of from the ftp server task
 *          when a new connection is established
 *
 * @param a0    client socket
 * @param a1    Not used
 *
 * @return        -
 */
static void ftpserver_client_thread_entry (UArg a0, UArg a1)
{
    io_handler_t ftpserver;
    SOCKET socket = (SOCKET)a0;
    int32_t opt = 1;

    strcpy (ftpUser, "user");
    strcpy (ftpPassword, "password");

    // Close the file session
    fdOpenSession(TaskSelf());

    memset (&ftpserver, 0, sizeof (ftpserver));

    /* Disables the Nagle algorithm for TCP sockets */
    if (setsockopt(socket, IPPROTO_TCP, NDK_TCP_NODELAY, &opt, sizeof(opt)) != SOCKET_ERROR)
    {
        ftpserver.authenticated = 0;
        ftpserver.socket = (void *)socket;
        ftpserver.send_buffer = malloc(BUFFER_SIZES);
        ftpserver.receive_buffer = malloc(BUFFER_SIZES);
        ftpserver.current_working_dir_path = malloc(DATA_BUFFER_SIZE);
        ftpserver.DataBuf = malloc (DATA_BUFFER_SIZE);
        ftpserver.temp = malloc(DATA_BUFFER_SIZE);

        sprintf (ftpserver.current_working_dir_path, "0:");

        if (ftpserver.send_buffer &&
            ftpserver.receive_buffer &&
            ftpserver.current_working_dir_path &&
            ftpserver.DataBuf &&
            ftpserver.temp)
        {
            ftpserver_parser (&ftpserver);

            if (ftpserver.send_buffer) free (ftpserver.send_buffer);
            if (ftpserver.receive_buffer) free (ftpserver.receive_buffer);
            if (ftpserver.current_working_dir_path) free (ftpserver.current_working_dir_path);
            if (ftpserver.temp) free (ftpserver.temp);
            if (ftpserver.DataBuf) free (ftpserver.DataBuf);
        }
    }
    
    /* Close the client socket */
    fdClose(socket);
    
    /* Close the file session */
    fdCloseSession(TaskSelf());
}

/**
 * ftpserver_parser()
 *
 * @brief FTP Server comand parser
 *
 * @params ioh    Pointer to io-structure that contains buffers, socket etc, see
 *              io_handler_t structure definition.
 *
 * @return ERROR_SUCCESS
 */
static int32_t ftpserver_parser (io_handler_t *ioh)
{
    int32_t n, bytes;
    ftp_cmd_handler_t *p;

    /* Respond with welcome message */
    sprintf(ioh->send_buffer,"220 Welcome to TCP-TEST FTP server \r\n");
    bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);

    ioh->running = TRUE;
    while (ioh->running)
    {
        n = 0;
        while (1)
        {
            if (n > (BUFFER_SIZES - 2)) break;
            
            bytes = recv(ioh->socket, &ioh->receive_buffer[n], 1, 0);//receive byte by byte...

            if ( bytes <= 0 ) break;
            if (ioh->receive_buffer[n] == '\n')
            {
                ioh->receive_buffer[n] = '\0';
                break;
            }
            if (ioh->receive_buffer[n] != '\r') n++; /*ignore CRs*/
        }
        if ( bytes <= 0 ) break;

        /* Process requested command */
        for (p = &cmd_handler[0]; p->func != NULL; p++)
        {
            if (strncmp(ioh->receive_buffer, p->cmd, p->len) == 0)
            {
                if (p->func) p->func(ioh);
                break;
            }
        }

        /* Command NOT found! */
        if (p->func == NULL)
        {
            sprintf(ioh->send_buffer,"202 Command not implemented (%s), superfluous at this site. \r\n", ioh->receive_buffer);
            bytes = send(ioh->socket, ioh->send_buffer, strlen(ioh->send_buffer), 0);
        }

    }

    return ERROR_SUCCESS;
}

#endif
