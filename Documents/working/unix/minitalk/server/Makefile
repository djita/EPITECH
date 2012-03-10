##
## Makefile for minitalk server in /home/guillo_e//Documents/working/unix/minitalk/server
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Mon Mar  5 17:38:45 2012 lyoma guillou
## Last update Mon Mar  5 17:39:00 2012 lyoma guillou
##

CC=	gcc
NAME=	server
SRC=	src/main.c

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
