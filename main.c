#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include "./controller/auth/auth.h"
#include "./utils/utils.h"
#include "./controller/todo/todo.h"

void mainMenu(const char *username);

int main()
{
    mkdir("data");

    int choice;
    char username[50];

    while (1)
    {
        printf("===== Personal Task & Finance Manager =====\n\n");
        printf("\t1. Login\n");
        printf("\t2. Register\n");
        printf("\t3. Exit\n\n");
        printf("--------------------------------------\n");
        printf("\t>> ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            if (loginUser(username))
                mainMenu(username);
            break;
        case 2:
            registerUser();
            break;
        case 3:
            printf("Exiting Task Manager, Thank you for using our application...\n");
            printf("\t2407109, 2407093, 2407101\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
            pauseScreen();
        }
    }

    return 0;
}

void mainMenu(const char *username)
{
    int choice;

    while (1)
    {
        clearScreen();
        printf("===== Welcome, %s =====\n\n", username);
        printf("\t1. To-Do Task Manager\n");
        printf("\t2. Bank Balance\n");
        printf("\t3. Logout\n\n");
        printf("----------------------------\n");
        printf(">> ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            showTodoMenu(username);
            break;
        case 2:
            printf("Bank Balance!\n");
            pauseScreen();
            break;
        case 3:
            clearScreen();
            printf("\t Logged out successfully!\n");
            pauseScreen();
            return;
        default:
            printf("Invalid choice!\n");
            pauseScreen();
        }
    }
}
