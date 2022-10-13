#include "call.h"
#include <ncurses.h>

typedef struct tab tab;
typedef struct win win;

WINDOW *create_newwin(int height, int width, int start_y, int start_x)
{
    WINDOW *local_win;

    local_win = newwin(height, width, start_y, start_x);
    wrefresh(local_win);

    return local_win;
}

void main(int *argc, char **argv)
{
    initscr();
    curs_set(false);
    refresh();
    win *displays = malloc(sizeof(win));
    displays->h = 40;
    displays->w = 70;
    displays->window = create_newwin(displays->h, displays->w, (LINES - displays->h) / 2, (COLS - displays->w) / 2);
    keypad(displays->window, true);
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
}