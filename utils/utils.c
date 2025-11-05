#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

void clearScreen()
{
    system("cls");
}

void pauseScreen()
{
    printf("Press Enter to Continue:");
    getchar();
}

void showProgressBar(int percent)
{
    int barWidth = 50;
    int pos = (barWidth * percent) / 100;
    printf("[");
    for (int i = 0; i < barWidth; ++i)
    {
        if (i < pos)
            printf("█");
        else
            printf("░");
    }
    printf("] %d%%\n", percent);
}
