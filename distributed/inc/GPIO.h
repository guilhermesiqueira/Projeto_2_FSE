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

#ifndef GPIO_H_
#define GPIO_H_

typedef struct {
  int lamp1;
  int lamp2;
  int lamp3;
  int lamp4;
  int ac1;
  int ac2;
} Output;

void init_GPIO();
void* main_GPIO();
void GPIO_toggle(int port);

#endif /* GPIO_H_ */
