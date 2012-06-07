##
## Makefile for  in /home/guillo_e//Documents/working/colles/colle7
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Tue May 29 19:07:44 2012 lyoma guillou
## Last update Tue May 29 22:47:48 2012 lyoma guillou
##

CC	=	gcc

NAME	=	text_count

SRCS	=	opt_parse.c	\
		utils.c		\
		utils2.c	\
		utils3.c	\
		part3.c		\
		part4.c		\
		text_count.c	\
		main.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -ansi -pedantic -Iinclude

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