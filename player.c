#include "call.h"

typedef struct player1 player1;
typedef struct tab tab;
typedef struct bonus bonus;

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

void movePlayer(player1 *p1, tab *tabs, win *displays, bonus *b1)
{
    int c;
    int turn = 0;
    int nbrBomb = b1->nbr_bmb;
    int checkwin = winCheck(tabs);
    if (checkwin == 0)
    {
        randFallout(tabs);
        while (turn != b1->turn)
        {
            c = wgetch(displays->window);
            if (c == 'z' && tabs->tableau[(p1->x) - 1][(p1->y)] == ' ')
            {
                if (tabs->tableau[(p1->x)][(p1->y)] == 'P')
                    tabs->tableau[(p1->x)][(p1->y)] = ' ';
                tabs->tableau[(p1->x) - 1][(p1->y)] = 'P';
                p1->x -= 1;

                display(tabs, displays);
                turn++;
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 1, nbrBomb);
            }

            if (c == 'q' && tabs->tableau[(p1->x)][(p1->y) - 1] == ' ' || p1->y - 1 <= 0)
            {
                if (tabs->tableau[(p1->x)][(p1->y)] == 'P')
                    tabs->tableau[(p1->x)][(p1->y)] = ' ';
                if (p1->y - 1 == 0)
                {
                    tabs->tableau[(p1->x)][(tabs->x) - 1] = 'P';
                    p1->y = tabs->x - 1;
                }
                else
                {
                    tabs->tableau[(p1->x)][(p1->y) - 1] = 'P';
                    p1->y -= 1;
                }
                display(tabs, displays);
                turn++;
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 1, nbrBomb);
            }

            if (c == 's' && tabs->tableau[(p1->x) + 1][(p1->y)] == ' ')
            {
                if (tabs->tableau[(p1->x)][(p1->y)] == 'P')
                    tabs->tableau[(p1->x)][(p1->y)] = ' ';
                tabs->tableau[(p1->x) + 1][(p1->y)] = 'P';
                p1->x += 1;

                display(tabs, displays);
                turn++;
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 1, nbrBomb);
            }

            if (c == 'd' && tabs->tableau[(p1->x)][(p1->y) + 1] == ' ' || p1->y == tabs->x)
            {
                if (tabs->tableau[(p1->x)][(p1->y)] == 'P')
                    tabs->tableau[(p1->x)][(p1->y)] = ' ';
                if (p1->y >= tabs->x - 1)
                {
                    tabs->tableau[(p1->x)][2] = 'P';
                    p1->y = 2;
                }
                else
                {
                    tabs->tableau[(p1->x)][(p1->y) + 1] = 'P';
                    p1->y += 1;
                }

                display(tabs, displays);
                turn++;
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 1, nbrBomb);
            }
            if (c == 'p')
            {
                display(tabs, displays);
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 1, nbrBomb);
                turn++;
            }
            if (c == ' ' && nbrBomb != 0)
            {
                nbrBomb--;
                putBomb(tabs, p1->x, p1->y);
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 1, nbrBomb);
            }
        }
        mvwprintw(displays->window, 0, 0, "A toi joueur 2 ! y= %d", p1->y);
    }
}

void movePlayer2(player1 *p1, tab *tabs, win *displays, bonus *b1)
{
    int c;
    int turn = 0;
    int nbrBomb = b1->nbr_bmb;
    int checkwin = winCheck(tabs);
    if (checkwin == 0)
    {
        randFallout(tabs);
        while (turn != b1->turn)
        {
            c = wgetch(displays->window);
            if (c == 'z' && tabs->tableau[(p1->x) - 1][(p1->y)] == ' ')
            {
                if (tabs->tableau[(p1->x)][(p1->y)] == 'T')
                    tabs->tableau[(p1->x)][(p1->y)] = ' ';
                tabs->tableau[(p1->x) - 1][(p1->y)] = 'T';
                p1->x -= 1;
                display(tabs, displays);
                turn++;
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 2, nbrBomb);
            }

            if (c == 'q' && tabs->tableau[(p1->x)][(p1->y) - 1] == ' ' || p1->y - 1 <= 0)
            {
                if (tabs->tableau[(p1->x)][(p1->y)] == 'T')
                    tabs->tableau[(p1->x)][(p1->y)] = ' ';
                if (p1->y - 1 == 0)
                {
                    tabs->tableau[(p1->x)][(tabs->x) - 1] = 'T';
                    p1->y = tabs->x - 1;
                }
                else
                {
                    tabs->tableau[(p1->x)][(p1->y) - 1] = 'T';
                    p1->y -= 1;
                }
                display(tabs, displays);
                turn++;
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 2, nbrBomb);
            }

            if (c == 's' && tabs->tableau[(p1->x) + 1][(p1->y)] == ' ')
            {
                if (tabs->tableau[(p1->x)][(p1->y)] == 'T')
                    tabs->tableau[(p1->x)][(p1->y)] = ' ';
                tabs->tableau[(p1->x) + 1][(p1->y)] = 'T';
                p1->x += 1;
                display(tabs, displays);
                turn++;
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 2, nbrBomb);
            }

            if (c == 'd' && tabs->tableau[(p1->x)][(p1->y) + 1] == ' ' || p1->y == tabs->x)
            {
                if (tabs->tableau[(p1->x)][(p1->y)] == 'T')
                    tabs->tableau[(p1->x)][(p1->y)] = ' ';
                if (p1->y >= tabs->x - 1)
                {
                    tabs->tableau[(p1->x)][2] = 'T';
                    p1->y = 2;
                }
                else
                {
                    tabs->tableau[(p1->x)][(p1->y) + 1] = 'T';
                    p1->y += 1;
                }

                display(tabs, displays);
                turn++;
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 2, nbrBomb);
            }
            if (c == 'p')
            {
                display(tabs, displays);
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 2, nbrBomb);
                turn++;
            }
            if (c == ' ' && nbrBomb != 0)
            {
                putBomb(tabs, p1->x, p1->y);
                bombChecker(tabs, b1);
                interfaceGame(displays, b1, tabs, turn, 2, nbrBomb);
                nbrBomb--;
            }
        }
        mvwprintw(displays->window, 0, 0, "A toi joueur 1 !");
    }
}