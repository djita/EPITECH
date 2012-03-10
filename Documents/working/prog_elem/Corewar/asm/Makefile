##
## Makefile for asm in /home/czegan_g/project/current/corewar/asm
##
## Made by louis duverdier
## Login   <duverd_l@epitech.net>
##
## Started on  Wed Jan 18 14:39:02 2012 louis duverdier
## Last update mar. févr. 21 14:14:14 2012 gaby czegany
##

CC=	gcc
NAME=	asm
SRC=	op.c \
	lib/misc/my_char_type.c \
	lib/misc/my_putchar.c \
	lib/misc/my_putnbr.c \
	lib/misc/my_putstr.c \
	lib/misc/my_strcat.c \
	lib/misc/my_strcmp.c \
	lib/misc/my_strcpy.c \
	lib/misc/my_strdup.c \
	lib/misc/my_strlen.c \
	lib/misc/my_memset.c \
	lib/misc/my_memcpy.c \
	lib/xfnc/xclose.c \
	lib/xfnc/xmalloc.c \
	lib/xfnc/xopen.c \
	lib/xfnc/xwrite.c \
	src/get_next_line.c \
	src/labels.c \
	src/list_handlers.c \
	src/list_init.c \
	src/misc.c \
	src/parser.c \
	src/parser_handlers.c \
	src/check_list.c \
	src/check_param.c \
	src/build.c	\
	src/build_param.c	\
	src/build_handlers.c	\
	src/asm.c

OBJ=	$(SRC:%.c=%.o)
CFLAGS=	-W -Wall -Wextra -Iinclude -I. -pedantic -ggdb3

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re:	fclean all
