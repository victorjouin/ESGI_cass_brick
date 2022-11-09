#include "call.h"

typedef struct tab tab;
typedef struct win win;
typedef struct game game;
typedef struct bonus bonus;

tab *generationMap(win *displays)
{
    tab *tabs = malloc(sizeof(tab));
    int width = rand() % 60;
    int height = rand() % 30;
    if (height < 8)
    {
        height *= 2;
    }
    if (width < 10)
    {
        width *= 2;
    }
    if (height % 2 == 0)
    {
        height += 1;
    }
    if (width % 2 == 0)
    {
        width += 1;
    }

    tabs->x = width;
    tabs->y = height;
    tabs->tableau = malloc(sizeof(char *) * tabs->y);
    for (int i = 0; i != tabs->y; i++)
    {
        tabs->tableau[i] = malloc(sizeof(char) * tabs->x);
    }

    // fill with space

    for (int i = 0; i != tabs->y; i++)
    {
        for (int j = 0; j != tabs->x; j++)
        {
            tabs->tableau[i][j] = ' ';
        }
    }

    // fill border left and right
    for (int i = 0; i != tabs->y; i++)
    {
        tabs->tableau[i][1] = 'H';
        tabs->tableau[i][(tabs->x) - 2] = 'H';
        tabs->tableau[i][(tabs->x) - 1] = '\n';
    }
    for (int i = 1; i != tabs->x - 2; i++)
    {
        tabs->tableau[0][i] = 'H';
        tabs->tableau[tabs->y - 1][i] = 'H';
    }
    tabs = mapFill(tabs, displays);
    tabs->tableau[3][3] = 'P';
    tabs->tableau[tabs->y - 5][tabs->x - 5] = 'T';
    for (int i = 0; i != tabs->y; i++)
    {
        tabs->tableau[i][0] = ' ';
    }
    return tabs;
}

tab *mapFill(tab *tabs, win *displays)
{
    for (int i = 0; i != tabs->y; i++)
    {
        for (int j = 0; j != tabs->x; j++)
        {
            if (tabs->tableau[i][j] == ' ')
            {
                if (rand() % 2 == 0)
                    tabs->tableau[i][j] = 'M';
            }
        }
    }
    for (int i = 0; i != tabs->y; i++)
    {
        for (int j = 0; j != tabs->x; j++)
        {
            if (tabs->tableau[i][j] == ' ')
            {
                if (rand() % 10 == 0)
                    tabs->tableau[i][j] = 'H';
            }
        }
    }
    return tabs;
}