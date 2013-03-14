##
## Makefile for  in /home/guillo_e//Documents/working/colles/colle7
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Tue May 29 19:07:44 2012 lyoma guillou
## Last update Wed Jan  9 15:14:42 2013 lyoma guillou
##

CC	=	gcc

NAME	=	menger

SRCS	=	menger.c \
		main.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -std=gnu99

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
