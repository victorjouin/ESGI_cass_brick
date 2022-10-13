#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef POP_H
#define POP_H

typedef struct tab
{
    int y;          // nombre de column
    int x;          // nombre de ligne
    char **tableau; // on y sotckera les fichiers map

} tab;

typedef struct win
{
    WINDOW *window;
    int h;
    int w;

} win;

tab *initTab(int width, int height, char *file);
void display(tab *tabs, win *win);
void freeStock(tab *tabs, win *win);
WINDOW *create_newwin(int height, int width, int start_y, int start_x);
#endif