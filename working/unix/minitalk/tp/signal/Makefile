##
## Makefile for asm in /home/czegan_g/project/current/corewar/asm
##
## Made by louis duverdier
## Login   <duverd_l@epitech.net>
##
## Started on  Wed Jan 18 14:39:02 2012 louis duverdier
## Last update Thu Mar  8 15:02:04 2012 lyoma guillou
##

CC=	gcc
NAME=	my_signal
SRC=	my_signal.c

OBJ=	$(SRC:%.c=%.o)
CFLAGS=	-W -Wall -Wextra -Werror -Iinclude -I. -ansi -pedantic -ggdb3

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
