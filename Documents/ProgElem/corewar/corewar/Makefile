##
## Makefile for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
## 
## Made by louis duverdier
## Login   <duverd_l@epitech.net>
## 
## Started on  Tue Feb 21 13:56:51 2012 louis duverdier
## Last update Fri Mar 23 11:28:13 2012 louis duverdier
##

CC	= gcc
NAME	= corewar
RM	= rm -f
SRC	= op.c \
	lib/list/list_handlers.c \
	lib/list/list_init.c \
	lib/misc/my_char_type.c \
	lib/misc/my_getnbr.c \
	lib/misc/my_memset.c \
	lib/misc/my_putchar.c \
	lib/misc/my_putnbr.c \
	lib/misc/my_putstr.c \
	lib/misc/my_strcat.c \
	lib/misc/my_strcmp.c \
	lib/misc/my_strcpy.c \
	lib/misc/my_strdup.c \
	lib/misc/my_strlen.c \
	lib/xfnc/xclose.c \
	lib/xfnc/xmalloc.c \
	lib/xfnc/xopen.c \
	lib/xfnc/xwrite.c \
	src/act_aff.c \
	src/act_cond.c \
	src/act_fork.c \
	src/act_jmp.c \
	src/act_live.c \
	src/act_load.c \
	src/act_loadi.c \
	src/act_op.c \
	src/act_store.c \
	src/check.c \
	src/dump.c \
	src/extract.c \
	src/init.c \
	src/main.c \
	src/main_loop.c \
	src/misc.c \
	src/parse.c \
	src/type.c \
	src/utils.c
OBJ	= $(SRC:.c=.o)
CFLAGS	= -W -Wall -Wextra -Iinclude -I. -ggdb3

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
