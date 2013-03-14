##
## Makefile for  in /home/guillo_e//Documents/working/colles/colle7
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Tue May 29 19:07:44 2012 lyoma guillou
## Last update Mon Jan 14 14:29:58 2013 lyoma guillou
##

CC	=	g++

NAME	=	my_cat

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

CFLAGS	=	-W -Wall -Wextra

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
