##
## Makefile for asm in /home/duverd_l/
## 
## Made by louis duverdier
## Login   <duverd_l@epitech.net>
## 
## Started on  Wed Jan 18 14:39:02 2012 louis duverdier
## Last update Sat Feb 11 15:18:10 2012 lyoma guillou
##

CC=	gcc
NAME=	allum1
SRC=	src/main.c \
	src/get_funcs.c \
	src/put_funcs.c \
	src/x_funcs.c \
	src/len_funcs.c \
	src/my_memset.c \
	src/my_str_to_wordtab.c \
	src/alum.c \
	src/ia_alum.c

OBJ=	$(SRC:.c=.o)
CFLAGS=	-W -Wall -Wextra -Werror -Iinclude -I. -pedantic -ggdb3

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -lcurses $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re:	fclean all
