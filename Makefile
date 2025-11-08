SRC_DIRS = . controller/auth controller/todo utils
OBJ_DIR = build

SRCS = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
# main.c controller/auth/auth.c controller/todo/todo.c utils/utils.c

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
# main.o controller/auth/auth.o controller/todo/todo.o utils/utils.o

all: taskie

taskie: $(OBJS)
	gcc $(OBJS) -o taskie.exe
	clear
	@echo Taskie was built successfully!

${OBJ_DIR}/%.o: %.c
	@mkdir -p $(dir $@)
	gcc -c $< -o $@

clean:
	rm -rf ${OBJ_DIR} *.exe
	clear
	@echo Everything was cleaned from the directory!
