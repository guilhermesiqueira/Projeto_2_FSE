#include <temperature.h>
#include <unistd.h>
#include <client.h>
#include <stdio.h>
#include <stdlib.h>

void* main_temperature(){
    while (1)
    {
        char response[16];
        float temperature, hum
        request_BME280_data(response);
        sscanf(response, "%c %f %f", );
        usleep(1000000);
    }
}