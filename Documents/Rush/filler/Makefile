##
## Makefile for filler in /home/guillo_e//Documents/working/rush/filler
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Sun Feb 26 10:52:30 2012 lyoma guillou
## Last update Sun Feb 26 10:52:33 2012 lyoma guillou
##

CC=	gcc
NAME=	filler
SRC=	src/x_funcs.c \
	src/tab_funcs.c \
	src/get_funcs.c \
	src/free_funcs.c \
	src/checker.c \
	src/main.c

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
