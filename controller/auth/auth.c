#define _GNU_SOURCE
#include <direct.h>
#define mkdir(path, mode) _mkdir(path)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"
#include "../../utils/utils.h"

#define USERS_FILE "data/users.txt"

int loginUser(char username[])
{
    char inputUser[50], inputPass[50];
    char storedUser[50], storedPass[50];
    FILE *fp = fopen(USERS_FILE, "r");

    if (fp == NULL)
    {
        printf("No users found. Please register first.\n");
        pauseScreen();
        return 0;
    }

    printf("\nUsername: ");
    scanf("%s", inputUser);
    printf("Password: ");
    scanf("%s", inputPass);

    while (fscanf(fp, "%s %s", storedUser, storedPass) != EOF)
    {
        if (strcmp(storedUser, inputUser) == 0 && strcmp(storedPass, inputPass) == 0)
        {
            fclose(fp);
            strcpy(username, inputUser);

            char path[100];
            sprintf(path, "data/%s", username);
            mkdir(path, 0777);

            printf("Login successful! Welcome, %s.\n", username);
            pauseScreen();
            return 1;
        }
    }

    fclose(fp);
    clearScreen();
    printf("Invalid credentials! Please check your inputs and try again.\n");
    return 0;
}

void registerUser()
{
    char username[50], password[50];
    FILE *fp = fopen(USERS_FILE, "a+");

    printf("\nUsername: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);

    char path[100];
    sprintf(path, "data/%s", username);
    mkdir(path, 0777);
    clearScreen();
    printf("Registration successful! You can now login.\n");
    pauseScreen();
}
