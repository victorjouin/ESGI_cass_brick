#include "call.h"

typedef struct tab tab;
typedef struct win win;

char *initMenu(win *displays, char *path)
{
    mvwprintw(displays->window, 10, 10, "CASSE BRICK UN JEU PAS SUPER FUN !\n\nPRESS 'Y' To Play classic mode\n\nPRESS 'M' To Create a gameRoom online\n\nPRESS 'J' To Join a gameRoom online\n");
    int c = wgetch(displays->window);
    if (c == 'y')
    {
        wclear(displays->window);
        mvwprintw(displays->window, 10, 10, "Selectionnez une map !\n\n map1 PRESS '1'\n\n map2 PRESS '2'\n\n map3 PRESS '3'");
        c = wgetch(displays->window);
        if (c == '1')
        {
            return ("map1.txt");
        }
        if (c == '2')
        {
            return ("map2.txt");
        }
        if (c == '3')
        {
            return ("map3.txt");
        }
    }
    if (c == 'm')
    {
        wclear(displays->window);
        mvwprintw(displays->window, 10, 10, "Ce mode n'est pas disponible pour l'instant \nPRESS ANY KEY TO CONTINUE");
        wgetch(displays->window);
        initMenu(displays, path);
    }
    if (c == 'j')
    {
        wclear(displays->window);
        mvwprintw(displays->window, 10, 10, "Ce mode n'est pas disponible pour l'instant \nPRESS ANY KEY TO CONTINUE");
        wgetch(displays->window);
        initMenu(displays, path);
    }
}