##
## Makefile for img in /home/guillo_e//working/igraph/img
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Thu Dec  8 17:45:16 2011 lyoma guillou
## Last update Thu Dec  8 18:10:09 2011 lyoma guillou
##

CC 	= 	cc

RM 	= 	rm -f

LIB 	= 	-L /usr/X11/lib -lmlx -lXext -lX11

NAME 	= 	img

SRCS 	= 	main.c \

OBJS 	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re: 		fclean all
