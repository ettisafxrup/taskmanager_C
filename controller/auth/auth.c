#define _GNU_SOURCE
#include <direct.h>
#define mkdir(path, mode) _mkdir(path)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"
#include "../../utils/utils.h"

#define USERS_FILE "data/users.dat"

int loginUser(char username[])
{
    char inputUser[50], inputPass[50];
    char storedUser[50], storedPass[50];
    FILE *fp = fopen(USERS_FILE, "rb");

    if (fp == NULL)
    {
        printf("No users found. Please register first.\n");
        pauseScreen();
        return 0;
    }

    printf("\nUsername >> ");
    scanf("%s", inputUser);
    printf("Password >> ");
    scanf("%s", inputPass);

    while (fscanf(fp, "%s %s", storedUser, storedPass) != EOF)
    {
        if (strcmp(storedUser, inputUser) == 0 && strcmp(storedPass, inputPass) == 0)
        {
            fclose(fp);
            strcpy(username, inputUser);

            char path[100];
            sprintf(path, "data/%s", username);

            printf("\nLogin successful! \n\t Welcome, %s.\n", username);
            pauseScreen();
            getchar();
            clearScreen();
            return 1;
        }
    }

    fclose(fp);
    printf("\nInvalid credentials! Please check your inputs and try again.\n");
    pauseScreen();
    getchar();
    clearScreen();
    return 0;
}

void registerUser()
{
    char username[50], password[50];
    FILE *fp = fopen(USERS_FILE, "ab+");

    printf("\nUsername >> ");
    scanf("%s", username);
    printf("Password >> ");
    scanf("%s", password);

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);

    char path[100];
    sprintf(path, "data/%s", username);
    mkdir(path, 0777);

    printf("\n\n Registration successful! You can now login.\n");
    pauseScreen();
    getchar();
}

int argsLogin(char *argv[])
{
    char storedUser[50], storedPass[50];
    char username[50];
    FILE *fp = fopen("data/users.dat", "rb");

    while (fscanf(fp, "%s %s", storedUser, storedPass) != EOF)
    {
        if (strcmp(storedUser, argv[2]) == 0 && strcmp(storedPass, argv[3]) == 0)
        {
            fclose(fp);
            strcpy(username, argv[2]);

            char path[100];
            sprintf(path, "data/%s", username);

            printf("\nLogin successful! \n\t Welcome, %s.\n", username);
            pauseScreen();
            clearScreen();

            return 1;
        }
    }

    fclose(fp);
    printf("Invalid credentials!\n");
    printf("Please re-check your credentials.\n");
    exit(0);
}