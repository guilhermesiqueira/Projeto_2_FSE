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

#define SERVER_DISTRIBUTED_IP "192.168.0.4"
#define SERVER_DISTRIBUTED_PORT 10112

void request_GPIO_toggle(int port, char* response)
{
    printf("----------- PORTA: %d --------------\n", port);
    struct sockaddr_in client;

    int socketid = socket(AF_INET, SOCK_STREAM, 0);
    if (socketid == -1)
    {
        close(socketid);
        exit(1);
    }

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr(SERVER_DISTRIBUTED_IP);
    client.sin_port = htons(SERVER_DISTRIBUTED_PORT);

    if (connect(socketid, (struct sockaddr *)&client, sizeof(client)) < 0)
    {
        close(socketid);
        exit(1);
    }

    char buf[5];
    snprintf(buf, 5, "%c %d", 'G', port);
    int size = strlen(buf);
    if (send(socketid, buf, size, 0) != size)
    {
        close(socketid);
        exit(1);
    }

    int size_rec = recv(socketid, response, 16, 0);
    if (size_rec < 0)
    {
        close(socketid);
        exit(1);
    }

    response[15] = '\0';
    close(socketid);

}

void request_BME280_data(char* response)
{
    struct sockaddr_in client;

    int socketid = socket(AF_INET, SOCK_STREAM, 0);
    if (socketid == -1)
    {
        exit(1);
    }

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr(SERVER_DISTRIBUTED_IP);
    client.sin_port = htons(SERVER_DISTRIBUTED_PORT);

    if (connect(socketid, (struct sockaddr *)&client, sizeof(client)) < 0)
    {
        exit(1);
    }

    char buf[3];
    snprintf(buf, 3, "%c", 'B');
    int size = strlen(buf);
    if (send(socketid, buf, size, 0) != size)
    {
        close(socketid);
        exit(1);
    }

    int size_rec = recv(socketid, response, 16, 0);
    if (size_rec < 0)
    {
        close(socketid);
        exit(1);
    }
    response[15] = '\0';

    close(socketid);

}
