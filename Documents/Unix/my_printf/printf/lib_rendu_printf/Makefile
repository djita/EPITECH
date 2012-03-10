##
## Makefile for Makfile in /home/guillo_e//afs/rendu/lib/my
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Mon Oct 24 09:10:01 2011 lyoma guillou
## Last update Wed Nov 16 14:39:41 2011 lyoma guillou
##

CC = cc -c

SRC = *.c

OBJ = *.o

INC = -I.

NAME = libmy.a

RM = rm -f

all: 	ranlib header

binary:
	@$(CC) $(INC) $(SRC)

lib:	binary
	@ar rc $(NAME) $(OBJ)

ranlib: lib
	@ranlib $(NAME)

header:	
	cp libmy.a /afs/epitech.net/users/epitech_2015/guillo_e/rendu/lib
	cp my.h /afs/epitech.net/users/epitech_2015/guillo_e/rendu/include

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)