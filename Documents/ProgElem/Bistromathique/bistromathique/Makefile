##
## Makefile for bistromathique in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique
##
## Made by mickael falck
## Login   <falck_m@epitech.net>
##
## Started on  Mon Oct 24 10:31:25 2011 mickael falck
## Last update Sat Nov  5 14:31:05 2011 lyoma guillou
##

CC=	cc

CFLAGS=	-W -Werror -Wall -pedantic -std=c9x

RM=	rm -f

NAME=	calc

SRC=	main.c \
	bistromathique.c \
	put_funcs.c \
	list_funcs.c \
	my_std/str_manip.c \
	eval_expr.c \
	operators.c \
	out_check.c

LIBDIR=	.
#LIBDIR=	~/dev

OBJ=	$(SRC:.c=.o)

all:	$(SRC) $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

debug:
	$(CC) -ggdb3 $(CFLAGS) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ)
	gdb $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
