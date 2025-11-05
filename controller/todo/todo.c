#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "../../utils/utils.h"
#include "todo.h"

void getTaskFilePath(const char *username, char *path)
{
    sprintf(path, "data/%s/tasks.txt", username);
}

int loadTasks(const char *username, Task tasks[])
{
    char path[200];
    getTaskFilePath(username, path);

    FILE *fp = fopen(path, "r");
    if (!fp)
        return 0;

    int count = 0;
    while (fscanf(fp, " %[^\t]\t%d\n", tasks[count].description, &tasks[count].completed) == 2)
    {
        count++;
    }

    fclose(fp);
    return count;
}

void saveTasks(const char *username, Task tasks[], int count)
{
    char path[200];
    getTaskFilePath(username, path);

    FILE *fp = fopen(path, "w");
    if (!fp)
    {
        printf("Error saving tasks!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s\t%d\n", tasks[i].description, tasks[i].completed);
    }

    fclose(fp);
}

void addTask(const char *username)
{
    Task tasks[MAX_TASKS];
    int count = loadTasks(username, tasks);

    if (count >= MAX_TASKS)
    {
        printf("Task limit reached!\n");
        return;
    }

    printf("Enter new task: ");
    getchar(); // clear newline
    fgets(tasks[count].description, MAX_TASK_LEN, stdin);
    tasks[count].description[strcspn(tasks[count].description, "\n")] = '\0';
    tasks[count].completed = 0;
    count++;

    saveTasks(username, tasks, count);
    printf("Task added successfully!\n");
}

void viewTasks(const char *username)
{
    Task tasks[MAX_TASKS];
    int count = loadTasks(username, tasks);

    if (count == 0)
    {
        printf("Task Desk Clean!\n");
        return;
    }

    printf("\nToday's Tasks :\n");
    for (int i = 0; i < count; i++)
    {
        printf("\t [%d] %s %s\n", i + 1, tasks[i].description,
               tasks[i].completed ? "(Completed)" : "(Pending)");
    }
}

void editTask(const char *username)
{
    Task tasks[MAX_TASKS];
    int count = loadTasks(username, tasks);

    if (count == 0)
    {
        printf("No tasks to edit!\n");
        return;
    }

    viewTasks(username);
    printf("\nEnter task number to edit: ");
    int num;
    scanf("%d", &num);

    if (num < 1 || num > count)
    {
        printf("Invalid task number!\n");
        return;
    }

    getchar(); // clear newline
    printf("Enter new description: ");
    fgets(tasks[num - 1].description, MAX_TASK_LEN, stdin);
    tasks[num - 1].description[strcspn(tasks[num - 1].description, "\n")] = '\0';

    saveTasks(username, tasks, count);
    printf("Task updated successfully!\n");
}

void markTaskCompleted(const char *username)
{
    Task tasks[MAX_TASKS];
    int count = loadTasks(username, tasks);

    if (count == 0)
    {
        printf("No tasks to mark as completed!\n");
        return;
    }

    viewTasks(username);
    printf("\nEnter task number to mark as completed: ");
    int num;
    scanf("%d", &num);

    if (num < 1 || num > count)
    {
        printf("Invalid task number!\n");
        return;
    }

    tasks[num - 1].completed = 1;
    saveTasks(username, tasks, count);
    printf("Task marked as completed!\n");

    // Check if all tasks completed
    int allDone = 1;
    for (int i = 0; i < count; i++)
    {
        if (!tasks[i].completed)
        {
            allDone = 0;
            break;
        }
    }

    if (allDone)
    {
        printf("\n🎉 All tasks completed! Great job!\n");
        printf("Do you want to reset and add new tasks? (y/n): ");
        char choice;
        getchar();
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            resetTasks(username);
            printf("Tasks reset successfully. You can add new ones now!\n");
        }
    }
}

void deleteTask(const char *username)
{
    Task tasks[MAX_TASKS];
    int count = loadTasks(username, tasks);

    if (count == 0)
    {
        printf("No tasks to delete!\n");
        return;
    }

    viewTasks(username);
    printf("\nEnter task number to delete: ");
    int num;
    scanf("%d", &num);

    if (num < 1 || num > count)
    {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = num - 1; i < count - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }
    count--;

    saveTasks(username, tasks, count);
    printf("Task deleted successfully!\n");
}

void resetTasks(const char *username)
{
    char path[200];
    getTaskFilePath(username, path);
    FILE *fp = fopen(path, "w");
    if (fp)
        fclose(fp);
}

void showTodoMenu(const char *username)
{
    int choice;

    while (1)
    {
        clearScreen();
        viewTasks(username);
        printf("\n===== TODO MENU =====\n");
        printf("\t1. Add Task\n");
        printf("\t2. Edit Task\n");
        printf("\t3. Mark Task as Completed\n");
        printf("\t4. Delete Task\n");
        printf("\t5. Exit to Main Menu\n\n");
        printf("======================\n");
        printf("\t>> ");
        scanf("%d", &choice);

        clearScreen();

        switch (choice)
        {
        case 1:
            addTask(username);
            break;
        case 2:
            editTask(username);
            break;
        case 3:
            markTaskCompleted(username);
            break;
        case 4:
            deleteTask(username);
            break;
        case 5:
            return;
        default:
            printf("Invalid choice!\n");
        }

        pauseScreen();
    }
}
