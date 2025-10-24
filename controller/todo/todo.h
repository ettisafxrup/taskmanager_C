#ifndef TODO_H
#define TODO_H

#define MAX_TASK_LEN 200
#define MAX_TASKS 100

typedef struct
{
    char description[MAX_TASK_LEN];
    int completed;
} Task;

void showTodoMenu(const char *username);
void addTask(const char *username);
void viewTasks(const char *username);
void editTask(const char *username);
void markTaskCompleted(const char *username);
void deleteTask(const char *username);
void resetTasks(const char *username);

#endif
