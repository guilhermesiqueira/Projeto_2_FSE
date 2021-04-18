#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <menu.h>
#include <monitoring.h>
#include <server.h>
#include <temperature.h>

int main() {
    monitor();
    pthread_t menu, server, temperature;
	pthread_create(&menu, NULL, main_menu, NULL);
    pthread_create(&server, NULL, create_server, NULL);
	pthread_create(&temperature, NULL, main_temperature, NULL);
    pthread_join(menu, NULL);
    pthread_join(server, NULL);
    pthread_join(temperature, NULL);

    return 0;
}