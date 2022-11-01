#include "call.h"

// va donné un bonus selon le nombre aleatoire

void bonusGenerator(int x, int y, tab *tabs)
{
    int numb = rand() % 60;
    if (numb % 5 == 1)
        tabs->tableau[x][y] = 'W';
    if (numb % 5 == 2)
        tabs->tableau[x][y] = 'B';
    if (numb % 5 == 3)
        tabs->tableau[x][y] = 't';
    if (numb % 5 == 4)
        tabs->tableau[x][y] = 'c';
    if (numb % 5 == 0)
        tabs->tableau[x][y] = 'C';
}

// bonus handler permet de donnée le bonus au joueur

void bonusHandler(tab *tabs, bonus *b1, int x, int y)
{
    if (tabs->tableau[x][y] == 'W')
    {
        b1->power++;
    }
    if (tabs->tableau[x][y] == 'B')
    {
        b1->nbr_bmb++;
    }
    if (tabs->tableau[x][y] == 't')
    {
        b1->turn = b1->turn + 3;
    }
    if (tabs->tableau[x][y] == 'c')
    {
        if (b1->countdown > '2' && b1->countdown < ':')
            b1->countdown--;
    }
    if (tabs->tableau[x][y] == 'C')
    {
        if (b1->countdown > '2' && b1->countdown < ':')
            b1->countdown++;
    }
}