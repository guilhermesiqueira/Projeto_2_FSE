#include <temperature.h>
#include <unistd.h>
#include <client.h>
#include <stdio.h>
#include <stdlib.h>
#include <menu.h>

void* main_temperature(){
    while (1)
    {
        char response[16];
        double temperature, humidity;
        char res;
        
        request_BME280_data(response);
        printf("response: %s\n", response);
        sscanf(response, "%1c %lf %lf", &res, &temperature, &humidity);
        printf("UMIDADE: %lf\n", humidity);
        print_temperature(temperature, humidity);

        usleep(1000000);
    }
}