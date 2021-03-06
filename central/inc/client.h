#define LAMP1 0
#define LAMP2 1
#define LAMP3 2
#define LAMP4 3
#define AC1 23
#define AC2 24

#define PRES1 6
#define PRES2 25
#define ABR1 21
#define ABR2 22
#define ABR3 26
#define ABR4 27
#define ABR5 28
#define ABR6 29

#ifndef CLIENT_H_
#define CLIENT_H_

void request_GPIO_toggle(int port, char* response);
void request_BME280_data(char* response);

#endif /* CLIENT_H_ */
