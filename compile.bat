@echo off

if not exist data (
    mkdir data
)


gcc main.c ./controller/auth/auth.c ./utils/utils.c -o task_manager