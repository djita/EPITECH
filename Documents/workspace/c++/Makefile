##
## Makefile for opengl test in /home/guillo_e/Documents/workspace/c++
## 
## Made by Lyoma Guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Thu Jun 13 13:23:07 2013 Lyoma Guillou
## Last update Thu Jun 13 13:27:01 2013 Lyoma Guillou
##

CPP	=	g++
RM	=	rm -f

NAME	=	my_test

SRCS	=	main.cpp
OBJS	=	$(SRCS:.cpp=.o)

CFLAGS	=	-W -Wall -Wextra -ggdb3

LFLAGS	=	-lSDL -lGL -lGLU


all:		$(NAME)

$(NAME):	$(OBJS)
	$(CPP) $^ $(LFLAGS) -o $@

%.o:		%.cpp
	$(CPP) -c $< $(CFLAGS) -o $@

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re