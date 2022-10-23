#include "call.h"

typedef struct tab tab;
typedef struct win win;
typedef struct bomb bomb;

void putBomb(tab *tabs, int x, int y)
{
    tabs->tableau[x][y] = '5';
}

void bombChecker(tab *tabs, bonus *b1)
{
    for (int i = 0; i != tabs->y; i++)
    {
        for (int j = 0; j != tabs->x; j++)
        {
            if (tabs->tableau[i][j] <= '5' && tabs->tableau[i][j] >= '1')
                tabs->tableau[i][j]--;
            if (tabs->tableau[i][j] == '0')
            {
                bombExplosion(tabs, b1, i, j);
            }
        }
    }
}

void bombExplosion(tab *tabs, bonus *b1, int x, int y)
{
    tabs->tableau[x][y] = 'X';
    for (int i = 0; i != b1->power; i++)
    {
        bonusHandler(tabs, b1, x, (y + i));
        if (tabs->tableau[x][y + i] == 'M')
        {
            if (rand() % 5 == 1)
            {
                bonusGenerator(x, (y + i), tabs);
                break;
            }
            else
            {
                tabs->tableau[x][y + i] = ' '; // bonus
                break;
            }
        }
        if (tabs->tableau[x][y + i] >= '1' && tabs->tableau[x][y + i] <= '5')
        {
            tabs->tableau[x][y + i] = '0';
            break;
        }
        if (tabs->tableau[x][y + i] == 'H')
        {
            tabs->tableau[x][y + i] = 'H';
            break;
        }
        tabs->tableau[x][y + i] = 'X';
    }

    for (int i = 0; i != b1->power; i++)
    {
        if (y - i > 0)
        {
            bonusHandler(tabs, b1, x, (y - i));
            if (tabs->tableau[x][y - i] == 'M')
            {
                if (rand() % 5 == 1)
                {
                    bonusGenerator(x, (y - i), tabs);
                    break;
                }
                else
                {
                    tabs->tableau[x][y - i] = ' ';
                    break;
                }
            }
            if (tabs->tableau[x][y - i] >= '1' && tabs->tableau[x][y - i] <= '5')
            {
                tabs->tableau[x][y - i] = '0';
                break;
            }
            if (tabs->tableau[x][y - i] == 'H')
            {
                tabs->tableau[x][y - i] = 'H';
                break;
            }
            tabs->tableau[x][y - i] = 'X';
        }
    }

    for (int i = 0; i != b1->power; i++)
    {
        bonusHandler(tabs, b1, (x + i), y);
        if (tabs->tableau[x + i][y] == 'M')
        {
            if (rand() % 5 == 1)
            {
                bonusGenerator((x + i), y, tabs);
                break;
            }
            else
            {
                tabs->tableau[x + i][y] = ' ';
                break;
            }
        }
        if (tabs->tableau[x + i][y] >= '1' && tabs->tableau[x + i][y] <= '5')
        {
            tabs->tableau[x + i][y] = '0';
            break;
        }
        if (tabs->tableau[x + i][y] == 'H')
        {
            tabs->tableau[x + i][y] = 'H';
            break;
        }
        tabs->tableau[x + i][y] = 'X';
    }

    for (int i = 0; i != b1->power; i++)
    {
        if (x - i > 0)
        {
            bonusHandler(tabs, b1, (x - 1), y);
            if (tabs->tableau[x - i][y] == 'M')
            {
                if (rand() % 5 == 1)
                {
                    bonusGenerator((x - i), y, tabs);
                    break;
                }
                else
                {
                    tabs->tableau[x - i][y] = ' ';
                    break;
                }
            }
            if (tabs->tableau[x - i][y] >= '1' && tabs->tableau[x - i][y] <= '5')
            {
                tabs->tableau[x - i][y] = '0';
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
