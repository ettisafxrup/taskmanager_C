#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include "./controller/auth/auth.h"
#include "./utils/utils.h"
#include "./controller/todo/todo.h"

enum
{
    LOGIN = 1,
    REGISTER,
    EXIT
};

void mainMenu(const char *username);

int main()
{

    int choice;
    char username[50];

    while (1)
    {
        printf("===== University Project - Taskie =====\n\n");
        printf(">> 2407093 2407101 2407109 <<\n\n");
        printf("\t1. Login\n");
        printf("\t2. Register\n");
        printf("\t3. Exit\n\n");

        printf("\t>> ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case LOGIN:
            if (loginUser(username))
                mainMenu(username);
            break;
        case REGISTER:
            registerUser();
            break;
        case EXIT:
            printf("Exiting Taskie, Thank you for using our application...\n");
            printf("\t >> 2407093, 2407109,2407101 << \n");
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
