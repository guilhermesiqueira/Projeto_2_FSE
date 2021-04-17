#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <GPIO.h>
#include <bme280.h>
#include <server.h>

int main() {
    init_bme280();
    init_GPIO();

    pthread_t server, gpio;
	pthread_create(&server, NULL, create_server, NULL);
    pthread_create(&gpio, NULL, main_GPIO, NULL);
    pthread_join(server, NULL);
    pthread_join(gpio, NULL);

    return 0;
}