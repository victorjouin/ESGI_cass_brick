#include "call.h"
#include <ncurses.h>

typedef struct tab tab;
typedef struct win win;
typedef struct game game;
typedef struct bonus bonus;

void main(int *argc, char **argv)
{
    // initialise la fenetre de jeu
    game *play = malloc(sizeof(game));
    printf("mettez le terminal en pleinne écran si vous avez des probleme de segfault au demarrage\n\n");
    initscr();
    curs_set(false);
    refresh();
    win *displays = malloc(sizeof(win));
    displays->h = 60;
    displays->w = 100;
    displays->window = create_newwin(displays->h, displays->w, (LINES - displays->h) / 2, (COLS - displays->w) / 2);
    keypad(displays->window, true);
    // gestion menu
    argv[1] = initMenu(displays, argv[1]);

    // calcule pour la map via le fichier

    FILE *f = fopen(argv[1], "r");
    int x = 0;
    int i = 0;
    int y = 0;
    while (!feof(f))
    {
        i++;
        if (fgetc(f) == '\n')
        {
            y++;
            x = i;
            i = 0;
        }
    }
    fclose(f);

    // printf("number of line: %d \n size of the lines: %d \n\n", y, x);

    int width = x;
    int height = y + 1;
    tab *tabs = initTab(width, height, argv[1]);
    display(tabs, displays);
    printf("test");

    // create players

    player1 *p1 = initplayer1(tabs);
    player1 *p2 = initplayer2(tabs);
    bonus *b1 = malloc(sizeof(bonus));
    b1->power = 2;
    b1->turn = 10;
    b1->nbr_bmb = 1;
    b1->countdown = '5';
    bonus *b2 = malloc(sizeof(bonus));
    b2->power = 2;
    b2->turn = 10;
    b2->nbr_bmb = 1;
    b2->countdown = '5';
    // move
    int win = 0;
    while (win == 0)
    {
        win = play->victory = winCheck(tabs);
        movePlayer2(p2, tabs, displays, b2);
        movePlayer(p1, tabs, displays, b1);
    }
    winner(displays, play);
    endwin();
    freeStock(tabs, displays);
    freeplayer(p1, p2, b1, b2);
}

int winCheck(tab *tabs)
{
    int Palive = 0;
    int Talive = 0;

    for (int i = 0; i != tabs->y; i++)
    {
        for (int j = 0; j != tabs->x; j++)
        {
            if (tabs->tableau[i][j] == 'P')
            {
                Palive++;
            }
            if (tabs->tableau[i][j] == 'T')
            {
                Talive++;
            }
        }
    }
    if (Palive == 0 && Talive != 0)
        return 2;
    if (Palive != 0 && Talive == 0)
        return 1;
    return 0;
}