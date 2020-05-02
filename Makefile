NAME = ush

CC = clang

INC = $(wildcard inc/*.h) $(wildcard libmx/inc/*.h)

INCLIST = -Ilibmx/inc/ -Iinc

LIBA = libmx.a

OBJD = obj

FILES = $(wildcard src/*.c) \
		$(wildcard src/list_pack/*.c) \
		$(wildcard src/built_in_fnc/*.c) \
		$(wildcard src/error_print/*.c)

OBJO = $(FILES:src%.c=obj%.o)

CFLGS = -std=c11 -Wall -Wpedantic -Wextra #-Werror

COMPILE = $(CC) $(CFLGS) libmx/libmx.a $(OBJO) -o $(NAME)

all: install

$(OBJD):
	@mkdir -p $@
	@mkdir -p $@/list_pack
	@mkdir -p $@/built_in_fnc
	@mkdir -p $@/error_print

install: $(OBJD) $(LIBA) $(OBJO)
	@$(COMPILE)

$(LIBA):
	@make -C libmx -f Makefile install

$(OBJD)/%.o: src/%.c $(INC)
	@$(CC) $(CFLGS) -c -o $@ $< $(INCLIST)

uninstall: clean
	@rm -rf $(NAME)
	@make -C libmx -f Makefile uninstall

clean:
	@make -C libmx -f Makefile clean
	@rm -rf obj

reinstall: uninstall all


