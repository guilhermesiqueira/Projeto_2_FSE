#include <stdio.h>
#include <ncurses.h>
#include <menu.h>
#include <monitoring.h>

#define WIDTH 100
#define HEIGHT 30

int startx = 0;
int starty = 0;
WINDOW *menu_win;

char *choices[] = {
    "Lampada 1:",
    "Lampada 2:",
    "Lampada 3:",
    "Lampada 4:",
    "Ar-condicionado 1:",
    "Ar-condicionado 2:",
    "Alarme:",
    "Sair",
};
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

void* main_menu()
{
    int highlight = 1;
    int choice = 0;
    int c;

    initscr();
    clear();
    noecho();
    cbreak(); 
    curs_set(0);
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;

    menu_win = newwin(HEIGHT, WIDTH, 0, 0);
    keypad(menu_win, TRUE);
    // mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    refresh();
    while (1)
    {
        print_menu(menu_win, highlight);
        c = wgetch(menu_win);
        switch (c)
        {
        case KEY_UP:
            if (highlight == 1)
                highlight = n_choices;
            else
                --highlight;
            break;
        case KEY_DOWN:
            if (highlight == n_choices)
                highlight = 1;
            else
                ++highlight;
            break;
        case 10:
            choice = highlight;
            // mvwprintw(menu_win, 28, 2, "You chose choice %d with choice string %s", choice, choices[choice - 1]); //debug
            set_output(choice);
            break;
        default:
            refresh();
            break;
        }
        print_menu(menu_win, highlight);
        if (choice == 8)
            break;
    }
    clrtoeol();
    refresh();
    endwin();
}

void print_menu(WINDOW *menu_win, int highlight)
{
    int x, y, i;

    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for (i = 0; i < n_choices; ++i)
    {
        if (highlight == i + 1)
        {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        }
        else
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        ++y;
    }
    wrefresh(menu_win);
}

void print_data(Output output)
{
    mvwprintw(menu_win, 2, 21, "%s", output.lamp1 == 1 ? "LIGADO        " : "DESLIGADO");
    mvwprintw(menu_win, 3, 21, "%s", output.lamp2 == 1 ? "LIGADO        " : "DESLIGADO");
    mvwprintw(menu_win, 4, 21, "%s", output.lamp3 == 1 ? "LIGADO        " : "DESLIGADO");
    mvwprintw(menu_win, 5, 21, "%s", output.lamp4 == 1 ? "LIGADO        " : "DESLIGADO");
    mvwprintw(menu_win, 6, 21, "%s", output.ac1 == 1 ? "LIGADO        " : "DESLIGADO");
    mvwprintw(menu_win, 7, 21, "%s", output.ac2 == 1 ? "LIGADO        " : "DESLIGADO");
    mvwprintw(menu_win, 8, 21, "%s", output.alarm == 1 ? "LIGADO        " : "DESLIGADO");
    wrefresh(menu_win);
}

void print_temperature(double temperature, double humidity) {
    mvwprintw(menu_win, 10, 2, "Temperatura: %lf", temperature);
    mvwprintw(menu_win, 11, 2, "Umidade: %lf", humidity);    
    wrefresh(menu_win);
}

void print_entry(Input input) {
	mvwprintw(menu_win, 13, 2, "Sensor de Presença 01 (Sala): ");
	mvwprintw(menu_win, 13, 65, input.pres1 == 1 ? "LIGADO   " : "DESLIGADO");

	mvwprintw(menu_win, 14, 2, "Sensor de Presença 02 (Cozinha):");
	mvwprintw(menu_win, 14, 65, input.pres2 == 1 ? "LIGADO   " : "DESLIGADO");

	mvwprintw(menu_win, 15, 2, "Sensor Abertura 01 (Porta Cozinha):");
	mvwprintw(menu_win, 15, 65, input.abr1 == 1 ? "LIGADO   " : "DESLIGADO");

	mvwprintw(menu_win, 16, 2, "Sensor Abertura 02 (Janela Cozinha):");
	mvwprintw(menu_win, 16, 65, input.abr2 == 1 ? "LIGADO   " : "DESLIGADO");

	mvwprintw(menu_win, 17, 2, "Sensor Abertura 03 (Porta Sala):");
	mvwprintw(menu_win, 17, 65, input.abr3 == 1 ? "LIGADO   " : "DESLIGADO");

	mvwprintw(menu_win, 18, 2, "Sensor Abertura 04 (Janela Sala):");
	mvwprintw(menu_win, 18, 65, input.abr4 == 1 ? "LIGADO   " : "DESLIGADO");

	mvwprintw(menu_win, 19, 2, "Sensor Abertura 05 (Janela Quarto 01):");
	mvwprintw(menu_win, 19, 65, input.abr5 == 1 ? "LIGADO      " : "DESLIGADO");

	mvwprintw(menu_win, 20, 2, "Sensor Abertura 06 (Janela Quarto 02):");
	mvwprintw(menu_win, 20, 65, input.abr6 == 1 ? "LIGADO      " : "DESLIGADO");

    wrefresh(menu_win);
}