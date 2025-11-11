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
