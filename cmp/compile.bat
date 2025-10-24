@echo off

if not exist ../data (
    mkdir ../data
)

cd ../
gcc main.c ./controller/auth/auth.c ./controller/todo/todo.c ./utils/utils.c -o task_manager
