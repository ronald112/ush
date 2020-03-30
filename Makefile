NAME = ush

CC = gcc

INC = ./inc/ush.h ./libmx/inc/libmx.h\

INCL = ./libmx/inc/libmx.h \

FILES = mx_main \

SRC = $(addsuffix .c, $(FILES))

SRCS = $(addprefix src/, $(SRC))

OBJ = $(addsuffix .o, $(FILES))

OBJO = $(addprefix obj/, $(OBJ))

CFLGS = -std=c11 -Wall -Wpedantic -Wextra #-Werror

all: crt_dir install

crt_dir:
	@mkdir -p obj

install: $(OBJO)
	@make -C libmx -f Makefile install
	@$(CC) -o $(CFLGS) $^ libmx/libmx.a $(NAME)

obj/%.o: src/%.c $(INC)
	@$(CC) $(CFLGS) -c -o $@ -Ilibmx/inc/ -Iinc

uninstall: clean
	@rm $(NAME)
	@make -C libmx -f Makefile uninstall

clean:
	@make -C libmx -f Makefile clean
	@rm -rf ./obj

reinstall: uninstall all


