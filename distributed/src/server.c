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
#include <bme280.h>
#include <GPIO.h>

#define SERVER_DISTRIBUTED_PORT 10112

void *create_server()
{
    struct sockaddr_in server, client;

    int serverid = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server, '0', sizeof(server));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(SERVER_DISTRIBUTED_PORT);

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
        printf("BUFFER: %s\n", buffer);
        char code;
        sscanf(buffer, "%c", &code);
        if(code == 'B'){
            struct bme280_data data = bme280_read();
            char response[16];
            snprintf(response, 16, "%c %lf %lf", code, data.temperature, data.humidity);
            int size = strlen(response);
            send(clientid, response, size, 0);
        }

        if(code == 'G'){
            int port;
            sscanf(buffer, "%c %d", &code, &port);
            GPIO_toggle(port);
            send(clientid, &code, 2, 0);
        }
        close(clientid);
    }

    close(serverid);
}