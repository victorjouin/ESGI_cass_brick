#include "call.h"

typedef struct tab tab;
typedef struct win win;

void putBomb(tab *tabs, int x, int y)
{
    tabs->tableau[x][y] = '5';
}
