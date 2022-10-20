#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef POP_H
#define POP_H

typedef struct player1
{
    int x;
    int y;
    int nbrBomb;
    int power;
    int live;
} player1;

typedef struct game
{
    int victory;
} game;

typedef struct bomb
{
    int x;
    int y;
    int count;
} bomb;

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

char *initMenu(win *displays, char *arg);
tab *initTab(int width, int height, char *file);
void display(tab *tabs, win *win);
void freeStock(tab *tabs, win *win);
WINDOW *create_newwin(int height, int width, int start_y, int start_x);
player1 *initplayer1(tab *tabs);
player1 *initplayer2(tab *tabs);
void movePlayer(player1 *p1, tab *tabs, win *displays);
void movePlayer2(player1 *p2, tab *tabs, win *displays);
void putBomb(tab *tabs, int x, int y);
void bombChecker(tab *tabs);
void bombExplosion(tab *tabs, int x, int y);
int winCheck(tab *tabs);
void randFallout(tab *tabs);
#endif