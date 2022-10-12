#include "call.h"

typedef struct tab tab;

void main(int *argc, char **argv)
{
    printf("%s \n", argv[1]);

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
    printf("number of line: %d \n size of the lines: %d \n\n", y, x);

    int width = x;
    int height = y + 1;
    tab *tabs = initTab(width, height, argv[1]);
}