#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef CSV_H_
#define CSV_H_

typedef struct {
  char* command;
  int state;
} Data;

void csv_init();
void write_data(Data data);

#endif /* CSV_H_ */
