##
## Makefile for filler_baby in /home/guillo_e//SVNdepot/cpe-rush2-2016-guillo_e/filler_baby
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Sun Feb 26 10:49:24 2012 lyoma guillou
## Last update Sun Feb 26 10:49:26 2012 lyoma guillou
##


CC=	gcc
NAME=	filler_baby
SRC=	src/x_funcs.c \
	src/get_funcs.c \
	src/tab_funcs.c \
	src/free_funcs.c \
	src/checker.c \
	src/main.c

OBJ=	$(SRC:%.c=%.o)
CFLAGS=	-W -Wall -Wextra -Iinclude -I. -pedantic

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
