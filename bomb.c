#include "call.h"

typedef struct tab tab;
typedef struct win win;
typedef struct bomb bomb;

void putBomb(tab *tabs, int x, int y)
{
    /*bomb *bmb = malloc(sizeof(bomb));
    bmb->x = x;
    bmb->y = y;
    bmb->count = 5;*/
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
        }
    }
}