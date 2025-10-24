echo cd ../
mkdir -p data
gcc main.c ./controller/auth/auth.c ./controller/todo/todo.c ./utils/utils.c -o task_manager
