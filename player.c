#include "call.h"

typedef struct player1 player1;
typedef struct tab tab;

player1 *initplayer1(tab *tabs)
{
    // find player 'P'
    player1 *p1 = malloc(sizeof(player1));
    tabs->tableau;
    for (int i = 0; i != tabs->y; i++)
    {
        for (int j = 0; j != tabs->x; j++)
        {
            if (tabs->tableau[i][j] == 'P')
            {
                p1->x = i;
                p1->y = j;
            }
        }
    }
    return p1;
}
player1 *initplayer2(tab *tabs)
{
    // find player 'T'
    player1 *p2 = malloc(sizeof(player1));
    tabs->tableau;
    for (int i = 0; i != tabs->y; i++)
    {
        for (int j = 0; j != tabs->x; j++)
        {
            if (tabs->tableau[i][j] == 'T')
            {
                p2->x = i;
                p2->y = j;
            }
        }
    }
    return p2;
}

void movePlayer(player1 *p1, tab *tabs, win *displays)
{
    int c;
    int turn = 0;
    while (turn != 10)
    {
        c = wgetch(displays->window);
        if (c == 'z' && tabs->tableau[(p1->x) - 1][(p1->y)] == ' ')
        {
            tabs->tableau[(p1->x)][(p1->y)] = ' ';
            tabs->tableau[(p1->x) - 1][(p1->y)] = 'P';
            p1->x -= 1;
            display(tabs, displays);
            turn++;
        }

        if (c == 'q' && tabs->tableau[(p1->x)][(p1->y) - 1] == ' ')
        {
            tabs->tableau[(p1->x)][(p1->y)] = ' ';
            tabs->tableau[(p1->x)][(p1->y) - 1] = 'P';
            p1->y -= 1;
            display(tabs, displays);
            turn++;
        }

        if (c == 's' && tabs->tableau[(p1->x) + 1][(p1->y)] == ' ')
        {
            tabs->tableau[(p1->x)][(p1->y)] = ' ';
            tabs->tableau[(p1->x) + 1][(p1->y)] = 'P';
            p1->x += 1;
            display(tabs, displays);
            turn++;
        }

        if (c == 'd' && tabs->tableau[(p1->x)][(p1->y) + 1] == ' ')
        {
            tabs->tableau[(p1->x)][(p1->y)] = ' ';
            tabs->tableau[(p1->x)][(p1->y) + 1] = 'P';
            p1->y += 1;
            display(tabs, displays);
            turn++;
        }
        display(tabs, displays);
    }
    mvwprintw(displays->window, 0, 0, "joueur 1 ton tour est fini a toi joueur 2 !");
}

void movePlayer2(player1 *p1, tab *tabs, win *displays)
{
    int c;
    int turn = 0;
    while (turn != 10)
    {
        c = wgetch(displays->window);
        if (c == 'z' && tabs->tableau[(p1->x) - 1][(p1->y)] == ' ')
        {
            tabs->tableau[(p1->x)][(p1->y)] = ' ';
            tabs->tableau[(p1->x) - 1][(p1->y)] = 'T';
            p1->x -= 1;
            display(tabs, displays);
            turn++;
        }

        if (c == 'q' && tabs->tableau[(p1->x)][(p1->y) - 1] == ' ')
        {
            tabs->tableau[(p1->x)][(p1->y)] = ' ';
            tabs->tableau[(p1->x)][(p1->y) - 1] = 'T';
            p1->y -= 1;
            display(tabs, displays);
            turn++;
        }

        if (c == 's' && tabs->tableau[(p1->x) + 1][(p1->y)] == ' ')
        {
            tabs->tableau[(p1->x)][(p1->y)] = ' ';
            tabs->tableau[(p1->x) + 1][(p1->y)] = 'T';
            p1->x += 1;
            display(tabs, displays);
            turn++;
        }

        if (c == 'd' && tabs->tableau[(p1->x)][(p1->y) + 1] == ' ')
        {
            tabs->tableau[(p1->x)][(p1->y)] = ' ';
            tabs->tableau[(p1->x)][(p1->y) + 1] = 'T';
            p1->y += 1;
            display(tabs, displays);
            turn++;
        }
    }
    mvwprintw(displays->window, 0, 0, "joueur 2 ton tour est fini a toi joueur 1 !");
}