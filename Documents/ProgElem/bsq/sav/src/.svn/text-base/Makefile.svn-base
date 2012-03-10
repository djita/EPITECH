##
## Makefile for bsq in /home/guillo_e//working/prog_elem/bsq
## 
## Made by lyoma guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Mon Dec  5 13:26:53 2011 lyoma guillou
## Last update Mon Dec  5 19:29:25 2011 lyoma guillou
##

CC 	= 	gcc

RM 	= 	rm -f

CFLAGS += 	-Wextra -Wall -Werror
CFLAGS += 	-ansi -pedantic
CFLAGS += 	-I.

NAME 	= 	bsq

SRCS 	= 	main.c \
		put_funcs.c \
		get_next_line.c \
		str_funcs.c \
		bsq.c \

OBJS 	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

debug:		
	$(CC) $(SRCS) -ggdb3

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re: fclean all
