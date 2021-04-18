
#ifndef MONITORING_H_
#define MONITORING_H_


typedef struct {
  int lamp1;
  int lamp2;
  int lamp3;
  int lamp4;
  int ac1;
  int ac2;
  int alarm;
} Output;

typedef struct {
  int pres1;
  int pres2;
  int abr1;
  int abr2;
  int abr3;
  int abr4;
  int abr5;
  int abr6;
} Input;

void monitor();
void set_input(int code);
void set_output(int code);
Input get_input();
Output get_output();

#endif /* MONITORING_H_ */