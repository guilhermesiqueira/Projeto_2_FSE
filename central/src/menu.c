#include <stdio.h>
#include <ncurses.h>
#include <menu.h>
#include <monitor.h>

#define WIDTH 50
#define HEIGHT 25

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
    "Exit",
};
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

void *main_menu()
{
    int highlight = 1;
    int choice = 0;
    int c;

    initscr();
    clear();
    noecho();
    cbreak(); /* Line buffering disabled. pass on everything */
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
        Output output = get_output();
        print_data(output);
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
    mvwprintw(menu_win, 2, 21, "%s", output.lamp1 ? "LIGADO   " : "DESLIGADO");
    mvwprintw(menu_win, 3, 21, "%s", output.lamp2 ? "LIGADO   " : "DESLIGADO");
    mvwprintw(menu_win, 4, 21, "%s", output.lamp3 ? "LIGADO   " : "DESLIGADO");
    mvwprintw(menu_win, 5, 21, "%s", output.lamp4 ? "LIGADO   " : "DESLIGADO");
    mvwprintw(menu_win, 6, 21, "%s", output.ac1 ? "LIGADO   " : "DESLIGADO");
    mvwprintw(menu_win, 7, 21, "%s", output.ac2 ? "LIGADO   " : "DESLIGADO");
    mvwprintw(menu_win, 8, 21, "%s", output.alarm ? "LIGADO   " : "DESLIGADO");
    wrefresh(menu_win);
}

void print_temperature(float temperature, float humidity) {
    mvwprintw(menu_win, 9, 2, "Temperatura: %4.2f", temperature);
    mvwprintw(menu_win, 10, 2, "Umidade: %4.2f", humidity);    
    wrefresh(menu_win);
}