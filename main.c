#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include "./controller/auth/auth.h"
#include "./utils/utils.h"

void mainMenu(const char *username);

int main()
{
    mkdir("data");

    int choice;
    char username[50];

    while (1)
    {
        printf("=== Personal Task & Finance Manager ===\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");
        printf("--------------------------------------\n");
        printf(">> ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            if (loginUser(username))
            {
                mainMenu(username);
            }
            break;
        case 2:
            registerUser();
            break;
        case 3:
            printf("Exiting...\n");
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
        printf("=== Welcome, %s ===\n", username);
        printf("1. To-Do Task Manager\n");
        printf("2. Monthly Budget Tracker\n");
        printf("3. Bank Balance Control\n");
        printf("4. Weight Tracker\n");
        printf("5. Logout\n");
        printf("----------------------------\n");
        printf(">> ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("To-Do feature coming soon!\n");
            pauseScreen();
            break;
        case 2:
            printf("Budget Tracker coming soon!\n");
            pauseScreen();
            break;
        case 3:
            printf("Bank Control coming soon!\n");
            pauseScreen();
            break;
        case 4:
            printf("Health Tracker coming soon!\n");
            pauseScreen();
            break;
        case 5:
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
