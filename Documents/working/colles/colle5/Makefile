##
## Makefile for gameoflife in /home/guillo_e//Documents/working/colles/colle5
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Mon May 14 19:09:09 2012 lyoma guillou
## Last update Tue May 29 18:46:29 2012 lyoma guillou
##

CC	=	cc

NAME	=	game_of_life

SRCS	=	generate_rand.c	\
		cell_in_tab.c	\
		game_of_life.c	\
		life_check.c	\
		my_getnbr.c	\
		put_funcs.c	\
		utils.c		\
		main.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wextra -Wall -pedantic -ansi -I./ -ggdb3

RM	=	rm -f


all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all re clean fclean