#include "csv.h"

#define BUF 256

char buffer[BUF];

void time_generate() {
  time_t current_time;
  struct tm* time_info;

  time(&current_time);
  time_info = localtime(&current_time);

  strftime(buffer, BUF, "%c", time_info);
}

void csv_init() {
  FILE *file = fopen("data.csv", "w");
  fprintf(file, "HORA, COMANDO, ESTADO\n");
  fclose(file);
}

void write_data(Data data) {
  // Update Datetime
  time_generate();

  // Write file
  FILE *file = fopen("data.csv", "a");
  char *state = data.state == 1 ? "ON" : "OFF";
  fprintf(
    file,
    "%s,%s,%s\r\n",
    buffer,
    data.command,
    state
  );
  fclose(file);
}
