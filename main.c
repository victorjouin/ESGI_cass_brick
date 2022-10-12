#include "call.h"

typedef struct tab tab;

void main(int *argc, char **argv)
{
    printf("%s \n", argv[1]);
    // FILE * f = fopen();
    int width = 50;
    int height = 8;
    tab *tabs = initTab(width, height);
    printf("hello world");
}