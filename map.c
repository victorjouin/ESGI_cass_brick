#include "call.h"

typedef struct tab tab;

tab *initTab(int width, int height)
{
    // malloc et initialisation du tableau

    tab *tabs = malloc(sizeof(tab));
    tabs->x = width;
    tabs->y = height;
    tabs->tableau = malloc(sizeof(int *) * tabs->y);
    for (int i = 0; i != tabs->y; i++)
    {
        tabs->tableau[i] = malloc(sizeof(int) * tabs->x);
    }

    // remplissage du tableau

    for (int i = 0; i != tabs->y; i++)
    {
        for (int j = 0; j != tabs->x; j++)
        {
            tabs->tableau[i][j] = 0;
            printf("%d ", tabs->tableau[i][j]);
        }
        printf("\n");
    }
    return tabs;
}