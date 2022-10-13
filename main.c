#include "call.h"
#include <ncurses.h>

typedef struct tab tab;
typedef struct win win;

void main(int *argc, char **argv)
{
    // initialise la fenetre de jeu

    initscr();
    curs_set(false);
    refresh();
    win *displays = malloc(sizeof(win));
    displays->h = 40;
    displays->w = 70;
    displays->window = create_newwin(displays->h, displays->w, (LINES - displays->h) / 2, (COLS - displays->w) / 2);
    keypad(displays->window, true);

    // calcule pour la map via le fichier

    FILE *f = fopen(argv[1], "r");
    int x = 0;
    int i = 0;
    int y = 0;
    while (!feof(f))
    {
        i++;
        if (fgetc(f) == '\n')
        {
            y++;
            x = i;
            i = 0;
        }
    }
    fclose(f);

    // printf("number of line: %d \n size of the lines: %d \n\n", y, x);

    int width = x;
    int height = y + 1;
    tab *tabs = initTab(width, height, argv[1]);
    display(tabs, displays);
    wgetch(displays->window);
    endwin();
    freeStock(tabs, displays);
}