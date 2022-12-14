#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

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

typedef struct bonus
{
    int power;
    int nbr_bmb;
    int turn;
    char countdown;
} bonus;

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

tab *generationMap(win *displays);
tab *mapFill(tab *tabs, win *displays);
char *initMenu(win *displays, char *arg);
tab *initTab(int width, int height, char *file);
void display(tab *tabs, win *win);
void freeStock(tab *tabs, win *win);
void freeplayer(player1 *p1, player1 *p2, bonus *b1, bonus *b2);
WINDOW *create_newwin(int height, int width, int start_y, int start_x);
player1 *initplayer1(tab *tabs);
player1 *initplayer2(tab *tabs);
void movePlayer(player1 *p1, tab *tabs, win *displays, bonus *b1);
void movePlayer2(player1 *p2, tab *tabs, win *displays, bonus *b2);
void putBomb(tab *tabs, int x, int y, bonus *b1);
void bombChecker(tab *tabs, bonus *b1);
void bombExplosion(tab *tabs, bonus *b1, int x, int y);
int winCheck(tab *tabs);
void randFallout(tab *tabs);
void winner(win *displays, game *play);
void interfaceGame(win *displays, bonus *b1, tab *tabs, int turn, int player, int nbrBomb);
void bonusGenerator(int x, int y, tab *tabs);
void bonusHandler(tab *tabs, bonus *b1, int x, int y);
#endif