#include "call.h"

typedef struct tab tab;

WINDOW *create_newwin(int height, int width, int start_y, int start_x)
{
    WINDOW *local_win;
    local_win = newwin(height, width, start_y, start_x);
    wrefresh(local_win);

    return local_win;
}

void freeStock(tab *tabs, win *win)
{
    free(win);
    free(tabs->tableau);
    free(tabs);
}

void display(tab *tabs, win *win)
{
    // nettoyage
    wclear(win->window);

    // affichage du tableau
    int size = ((tabs->x) * (tabs->y));
    char *mapping = malloc(sizeof(char) * ((tabs->x) * (tabs->y)));
    int k = 0;
    for (int i = 0; i != tabs->y; i++)
    {
        for (int j = 0; j != tabs->x; j++)
        {
            mapping[k] = tabs->tableau[i][j];
            k++;
        }
    }
    mapping[k] = '\0';
    mvwprintw(win->window, 0, 0, mapping);
}

tab *initTab(int width, int height, char *file)
{
    //  open the file

    FILE *f = fopen(file, "r");

    // malloc et initialisation du tableau

    tab *tabs = malloc(sizeof(tab));
    tabs->x = width;
    tabs->y = height;
    tabs->tableau = malloc(sizeof(char *) * tabs->y);
    for (int i = 0; i != tabs->y; i++)
    {
        tabs->tableau[i] = malloc(sizeof(char) * tabs->x);
    }

    // remplissage du tableau

    int i = 0;
    int j = 0;
    char c;
    while (!feof(f))
    {
        c = fgetc(f);
        if (c == '\n')
        {
            i++;
            j = 0;
            tabs->tableau[i][j] = '\n';
        }
        else
        {
            tabs->tableau[i][j] = c;
        }
        j++;
    }
    fclose(f);

    return tabs;
}