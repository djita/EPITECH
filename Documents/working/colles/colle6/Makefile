##
## Makefile for carre in /home/guillo_e//Documents/working/colles/colle6
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Mon May 21 19:10:10 2012 lyoma guillou
## Last update Tue May 29 18:46:51 2012 lyoma guillou
##

CC	=	gcc

NAME	=	carre

SRCS	=	move.c			\
		my_getnbr.c		\
		parser.c		\
		utils.c			\
		utils2.c		\
		draw_segment.c		\
		my_getnbr_base.c	\
		create_tab.c		\
		game_sqr.c		\
		main.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -ansi -pedantic -I./include

LIB	=	-L/usr/X11/lib -lmlx -lX11 -lXext

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(CFLAGS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all re fclean clean
