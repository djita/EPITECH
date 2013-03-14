##
## Makefile for 42sh in /home/falck_m/Work/42sh
##
## Made by mickael falck
## Login   <falck_m@epitech.net>
##
## Started on  Tue Mar 06 20:46:37 2012 mickael falck
## Last update Tue Mar 06 21:29:54 2012 mickael falck
##

DEBUG=	no
RISKY=	yes
CC:=	$(if $(filter yes, $(DEBUG)), clang, gcc)

RM=	rm -f

NAME=	42sh

SRC=	main.c

CFLAGS:=$(if $(filter yes, $(DEBUG)), -ggdb3, -O2)
CFLAGS+=-W -Wextra -Wall -ansi -pedantic

OBJ=	$(SRC:.c=.o)

all:	$(SRC) $(NAME)

$(NAME):	$(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
