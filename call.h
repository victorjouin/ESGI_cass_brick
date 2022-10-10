#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#ifndef POP_H
#define POP_H

typedef struct tab
{
    int y;         // nombre de column
    int x;         // nombre de ligne
    int **tableau; // on y sotckera les fichiers map
};

#endif