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
#include <GPIO.h>
#include <bme280.h>

#define SERVER_CENTRAL_IP "192.168.0.53"
#define SERVER_CENTRAL_PORT 10012

void send_GPIO_toggle(int port)
{
    struct sockaddr_in client;

    int socketid = socket(AF_INET, SOCK_STREAM, 0);
    if (socketid == -1)
    {
        exit(1);
    }

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr(SERVER_CENTRAL_IP);
    client.sin_port = htons(SERVER_CENTRAL_PORT);

    if (connect(socketid, (struct sockaddr *)&client, sizeof(client)) < 0)
    {
        exit(1);
    }

    char buf[2];
    snprintf(buf, 2, "%d", port);
    int size = strlen(buf);
    if (send(socketid, buf, size, 0) != size)
    {
        exit(1);
    }

    close(socketid);

}
