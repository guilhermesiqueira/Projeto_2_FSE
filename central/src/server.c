#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <monitoring.h>

#define SERVER_CENTRAL_PORT 10012

void *create_server()
{
    struct sockaddr_in server, client;

    int serverid = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server, '0', sizeof(server));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(SERVER_CENTRAL_PORT);

    bind(serverid, (struct sockaddr *)&server, sizeof(server));

    if (listen(serverid, 10) == -1)
    {
        exit(1);
    }

    while (1)
    {
        unsigned int len = sizeof(client);
        int clientid = accept(serverid, (struct sockaddr *)&client, &len);

        char buffer[16];
        int size = recv(clientid, buffer, 16, 0);

        if (size < 0)
        {
            exit(1);
        }

        buffer[15] = '\0';
        printf("\n\n\n\n\n\\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n BUFFER: %s\n", buffer);
        int code;
        sscanf(buffer, "%d", &code);
        set_input(code);
        close(clientid);
    }

    close(serverid);
}