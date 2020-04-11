NAME = ush

CC = gcc

INC = ./inc/ush.h ./libmx/inc/libmx.h\

LIBA = libmx.a

OBJD = obj

FILES = $(wildcard src/*.c)

OBJO = $(FILES:src%.c=obj%.o)

CFLGS = -std=c11 -Wall -Wpedantic -Wextra -Werror

all: install

$(OBJD):
	@mkdir -p $@

install: $(OBJD) $(LIBA) $(OBJO)
	@$(CC) $(CFLGS) libmx/libmx.a $(OBJO) -o $(NAME)

$(LIBA):
	@make -C libmx -f Makefile install

$(OBJD)/%.o: src/%.c $(INC)
	@$(CC) $(CFLGS) -c -o $@ $< -Ilibmx/inc/ -Iinc

uninstall: clean
	@rm -rf $(NAME)
	@make -C libmx -f Makefile uninstall

clean:
	@make -C libmx -f Makefile clean
	@rm -rf obj

reinstall: uninstall all


