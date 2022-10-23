#include "call.h"

void bonusGenerator(int x, int y, tab *tabs)
{
    if (rand() % 3 == 1)
        tabs->tableau[x][y] = 'W';
    if (rand() % 3 == 2)
        tabs->tableau[x][y] = 'B';
    if (rand() % 3 == 0)
        tabs->tableau[x][y] = 't';
}

void bonusHandler(tab *tabs, bonus *b1, int x, int y)
{
    if (tabs->tableau[x][y] == 'W')
    {
        b1->power++;
    }
    if (tabs->tableau[x][y] == 'B')
    {
        b1->nbr_bmb++;
    }
    if (tabs->tableau[x][y] == 't')
    {
        b1->turn++;
    }
}