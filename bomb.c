#include "call.h"

typedef struct tab tab;
typedef struct win win;
typedef struct bomb bomb;

void putBomb(tab *tabs, int x, int y)
{
    tabs->tableau[x][y] = '5';
}

void bombChecker(tab *tabs)
{
    for (int i = 0; i != tabs->y; i++)
    {
        for (int j = 0; j != tabs->x; j++)
        {
            if (tabs->tableau[i][j] <= '5' && tabs->tableau[i][j] >= '1')
                tabs->tableau[i][j]--;
            if (tabs->tableau[i][j] == '0')
            {
                bombExplosion(tabs, i, j);
            }
        }
    }
}

void bombExplosion(tab *tabs, int x, int y)
{
    tabs->tableau[x][y] = 'X';
    for (int i = 0; i != 2; i++)
    {
        if (tabs->tableau[x][y + i] == 'M')
        {
            tabs->tableau[x][y + i] = ' ';
            break;
        }
        if (tabs->tableau[x][y + i] == 'H')
        {
            tabs->tableau[x][y + i] = 'H';
            break;
        }
        tabs->tableau[x][y + i] = 'X';
    }

    for (int i = 0; i != 2; i++)
    {
        if (tabs->tableau[x][y - i] == 'M')
        {
            tabs->tableau[x][y - i] = ' ';
            break;
        }
        if (tabs->tableau[x][y - i] == 'H')
        {
            tabs->tableau[x][y - i] = 'H';
            break;
        }
        tabs->tableau[x][y - i] = 'X';
    }

    for (int i = 0; i != 2; i++)
    {
        if (tabs->tableau[x + i][y] == 'M')
        {
            tabs->tableau[x + i][y] = ' ';
            break;
        }
        if (tabs->tableau[x + i][y] == 'H')
        {
            tabs->tableau[x + i][y] = 'H';
            break;
        }
        tabs->tableau[x + i][y] = 'X';
    }

    for (int i = 0; i != 2; i++)
    {
        if (x - i > 0)
        {
            if (tabs->tableau[x - i][y] == 'M')
            {
                tabs->tableau[x - i][y] = ' ';
                break;
            }
            if (tabs->tableau[x - i][y] == 'H')
            {
                tabs->tableau[x - i][y] = 'H';
                break;
            }
            tabs->tableau[x - i][y] = 'X';
        }
    }
}

void randFallout(tab *tabs)
{
    for (int i = 0; i != tabs->y; i++)
    {
        for (int j = 0; j != tabs->x; j++)
        {
            if (tabs->tableau[i][j] == 'X')
            {
                tabs->tableau[i][j] = ' ';
            }
        }
    }
}