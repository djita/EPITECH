##
## Makefile for igraph in /home/guillo_e//working/test/igraph
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Thu Oct 27 10:36:31 2011 lyoma guillou
## Last update Thu Oct 27 18:21:59 2011 lyoma guillou
##

CC = cc

SRC = *.c

OBJ = *.o

NAME = graph

LIB = -L /usr/X11/lib -lmlx -lXext -lX11

RMF = rm -f

all:	
	$(CC) -o $(NAME) $(SRC) $(LIB)

clean:	
	$(RMF) $(OBJ)

fclean: clean
	$(RMF) $(NAME)