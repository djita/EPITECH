##
## Makefile for Makefile in /home/guillo_e/Documents/working/tek2/unix/my_script
## 
## Made by Lyoma Guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Sat Mar  2 21:35:54 2013 Lyoma Guillou
## Last update Sun Mar  3 19:34:42 2013 Lyoma Guillou
##

NAME	=	my_script

SRCDIR	=	./src
HDFDIR	=	./include

SRCS	=	$(SRCDIR)/my_script.c \
		$(SRCDIR)/pts_util.c \
		$(SRCDIR)/tty_util.c \
		$(SRCDIR)/check_args.c \
		$(SRCDIR)/main.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-ansi -pedantic -W -Wall -Werror -Wextra 
CFLAGS	+=	-I$(HDFDIR)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re