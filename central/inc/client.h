#ifndef CLIENT_H_
#define CLIENT_H_

void request_GPIO_toggle(int port, char* response);
void request_BME280_data(char* response);

#endif /* CLIENT_H_ */
