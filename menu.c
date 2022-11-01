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
        mvwprintw(displays->window, 10, 10, "Selectionnez une map !\n\n map1 PRESS '1'\n\n map2 PRESS '2'\n\n map3 PRESS '3'\n\n map3 PRESS '4'");
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
        if (c == '4')
        {
            return ("map4.txt");
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
    else
    {
        initMenu(displays, path);
    }
}

void winner(win *displays, game *play)
{
    wclear(displays->window);
    if (play->victory == 1)
    {
        mvwprintw(displays->window, 10, 10, "PLAYER 1 'P' WIN ! ! ! GG \nPRESS ANY KEY TO QUITE");
        wgetch(displays->window);
    }
    if (play->victory == 2)
    {
        mvwprintw(displays->window, 10, 10, "PLAYER 2 'T' WIN ! ! ! GG \nPRESS ANY KEY TO QUITE");
        wgetch(displays->window);
    }
}
void interfaceGame(win *displays, bonus *b1, tab *tabs, int turn, int player, int bomb)
{
    if (player == 1)
    {
        mvwprintw(displays->window, 0, tabs->x + 5, "tour du joueur 1");
        mvwprintw(displays->window, 2, tabs->x + 5, "tour effectué [%d / %d]", turn, b1->turn);
        mvwprintw(displays->window, 4, tabs->x + 5, "Info bonus:");
        mvwprintw(displays->window, 6, tabs->x + 5, "puissance: %d ", b1->power);
        mvwprintw(displays->window, 8, tabs->x + 5, "nombre bomb: %d ", bomb);
        mvwprintw(displays->window, 10, tabs->x + 5, "minteur bomb: %c ", b1->countdown);
    }
    if (player == 2)
    {
        mvwprintw(displays->window, 0, tabs->x + 5, "tour du joueur 2");
        mvwprintw(displays->window, 2, tabs->x + 5, "tour effectué [%d / %d]", turn, b1->turn);
        mvwprintw(displays->window, 4, tabs->x + 5, "Info bonus:");
        mvwprintw(displays->window, 6, tabs->x + 5, "puissance: %d ", b1->power);
        mvwprintw(displays->window, 8, tabs->x + 5, "nombre bomb: %d ", bomb);
        mvwprintw(displays->window, 10, tabs->x + 5, "minteur bomb: %c ", b1->countdown);
    }
}