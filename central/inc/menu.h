#include <monitoring.h>

#ifndef MENU_H_
#define MENU_H_


void* main_menu();
void print_data(Output output);
void print_entry(Input input);
Output get_output();
Input get_input();
void print_temperature(float temperature, float humidity);

#endif /* MENU_H_ */