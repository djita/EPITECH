##
## Makefile for my_reader in /home/guillo_e//Documents/working/colles/colle2
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Tue Apr 24 19:07:37 2012 lyoma guillou
## Last update Tue Apr 24 22:47:57 2012 lyoma guillou
##

NAME	=	my_reader

CC	=	gcc -o

SRC	=	src/put_funcs.c 	\
		src/cut_str.c		\
		src/epur_str.c		\
		src/my_strlen.c		\
		src/my_memset.c		\
		src/my_strcmp.c		\
		src/my_strdup.c		\
		src/my_strcpy.c		\
		src/get_next_line.c	\
		src/list.c		\
		src/main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -pedantic -ansi -Iinclude -ggdb3

RM	=	rm -f

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

##		src/get_info.c		\
