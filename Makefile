SRC_DIRS = . controller/auth controller/todo utils
OBJECT_FOLDER = build

# Source Code - C Files
CODE_SOURCE = main.c controller/auth/auth.c controller/todo/todo.c utils/utils.c

# Object Code - Compiled Obj Files
OBJ_SOURCE = $(OBJECT_FOLDER)/main.o $(OBJECT_FOLDER)/controller/auth/auth.o $(OBJECT_FOLDER)/controller/todo/todo.o $(OBJECT_FOLDER)/utils/utils.o


all: taskie

taskie: $(OBJ_SOURCE)
	gcc $(OBJ_SOURCE) -o taskie.exe
	clear
	@echo Taskie was built successfully!

# $@ -> Object Files | Target | (%.o)
# $< -> Source Files | Dependencies | (.%c)

${OBJECT_FOLDER}/%.o: %.c
	@mkdir -p $(dir $@)
	gcc -c $< -o $@

clean:
	rm -rf ${OBJECT_FOLDER} *.exe
	clear
	@echo ./build and taskie.exe was cleaned from the directory!

run: taskie
	./taskie.exe