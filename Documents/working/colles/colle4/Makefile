##
## Makefile for opt_get in /home/guillo_e//Documents/working/colles/colle4
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Mon May  7 19:10:45 2012 lyoma guillou
## Last update Mon May  7 22:59:16 2012 lyoma guillou
##

CC	=	gcc

NAME	=	opt_get

SRCS	=	opt_get_main.c 	\
		opt_get.c 	\
		opt_free.c	\
		opt_args.c	\
		opt_isset.c	\
		opt_list.c	\
		opt_pos.c	\
		parser.c	\
		fmt_list.c	\
		utils.c		\
		utils2.c	\
		xfunctions.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -ansi -pedantic -I. 

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(CLAGS) 

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all re fclean clean