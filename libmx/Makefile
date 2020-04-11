NAME = libmx.a

CC = clang

INC = libmx.h

FILES = $(wildcard src/*.c)

SRCD = src
OBJD = obj
OBJ = $(FILES:$(SRCD)%.c=$(OBJD)%.o)
COMPILE = $(CC) $(CFLAGS) -c -o $@ $< -Iinc
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install

install: $(OBJD) compile_lib

compile_lib: $(OBJ)
	@ar rcs $(NAME) $^ inc/$(INC)

$(OBJD):
	@mkdir -p $@

$(OBJD)/%.o: $(SRCD)/%.c $(addprefix inc/, $(INC))
	@$(COMPILE)

uninstall: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(OBJD)

reinstall: uninstall install
