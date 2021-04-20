#include <wiringPi.h>
#include <softPwm.h>
#include <client.h>
#include <GPIO.h>
#include <stdio.h>

Output output;

void init_GPIO(){
    output.lamp1 = 0;
    output.lamp2 = 0;
    output.lamp3 = 0;
    output.lamp4 = 0;
    output.ac1 = 0;
    output.ac2 = 0;
    wiringPiSetup();
}

void handle_abr1(void){
    printf("Alteração no: abr1...\n");
    send_GPIO_toggle(ABR1);
}

void handle_abr2(void){
    printf("Alteração no: abr2...\n");
    send_GPIO_toggle(ABR2);
}
void handle_abr3(void){
    printf("Alteração no: abr3...\n");
    send_GPIO_toggle(ABR3);
}
void handle_abr4(void){
    printf("Alteração no: abr4...\n");
    send_GPIO_toggle(ABR4);
}
void handle_abr5(void){
    printf("Alteração no: abr5...\n");
    send_GPIO_toggle(ABR5);
}
void handle_abr6(void){
    printf("Alteração no: abr6...\n");
    send_GPIO_toggle(ABR6);
}
void handle_pres1(void){
    printf("Alteração no: pres1...\n");
    send_GPIO_toggle(PRES1);
}

void handle_pres2(void){
    printf("Alteração no: pres2...\n");
    send_GPIO_toggle(PRES2);
}

void* main_GPIO(){
    pinMode(ABR1, OUTPUT);
    wiringPiISR(ABR1, INT_EDGE_BOTH, &handle_abr1);

    pinMode(ABR2, OUTPUT);
    wiringPiISR(ABR2, INT_EDGE_BOTH, &handle_abr2);

    pinMode(ABR3, OUTPUT);
    wiringPiISR(ABR3, INT_EDGE_BOTH, &handle_abr3);

    pinMode(ABR4, OUTPUT);
    wiringPiISR(ABR4, INT_EDGE_BOTH, &handle_abr4);
    
    pinMode(ABR5, OUTPUT);
    wiringPiISR(ABR5, INT_EDGE_BOTH, &handle_abr5);

    pinMode(ABR6, OUTPUT);
    wiringPiISR(ABR6, INT_EDGE_BOTH, &handle_abr6);

    pinMode(PRES1, OUTPUT);
    wiringPiISR(PRES1, INT_EDGE_BOTH, &handle_pres1);

    pinMode(PRES2, OUTPUT);
    wiringPiISR(PRES2, INT_EDGE_BOTH, &handle_pres2);

    // return NULL;
}

void GPIO_toggle(int port)
{
    if (port == 0){
        output.lamp1 = output.lamp1 ? 0 : 1;
        pinMode(port, OUTPUT);
        digitalWrite(port, output.lamp1);
    }
    if (port == 1){
        output.lamp2 = output.lamp2 ? 0 : 1;
        pinMode(port, OUTPUT);
        digitalWrite(port, output.lamp2);
    }
    if (port == 2){
        output.lamp3 = output.lamp3 ? 0 : 1;
        pinMode(port, OUTPUT);
        digitalWrite(port, output.lamp3);
    }
    if (port == 3){
        output.lamp4 = output.lamp4 ? 0 : 1;
        pinMode(port, OUTPUT);
        digitalWrite(port, output.lamp4);
    }
    if (port == 23){
        output.ac1 = output.ac1 ? 0 : 1;
        pinMode(port, OUTPUT);
        digitalWrite(port, output.ac1);
    }
    if (port == 24){
        output.ac2 = output.ac2 ? 0 : 1;
        pinMode(port, OUTPUT);
        digitalWrite(port, output.ac2);
    }
}