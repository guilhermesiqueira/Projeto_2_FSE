#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <menu.h>


int main() {
    pthread_t menu;
	pthread_create(&menu, NULL, main_menu, NULL);
    pthread_join(menu, NULL);
    
    return 0;
}