##
## Makefile for 42sh in /home/falck_m/Work/42sh
##
## Made by mickael falck
## Login   <falck_m@epitech.net>
##
## Started on  Sun Apr 15 15:12:57 2012 mickael falck
## Last update Mon May 14 14:43:42 2012 lyoma guillou
##

# Das Makefile v2.0 by falck_m

NAME	=	HIsh
DEBUG	=	no

CC	:=	$(if $(filter yes, $(DEBUG)),clang,gcc)
RM	=	rm -f
SRCDIR	=	./src

ifeq ($(wildcard $(SRCDIR)/testmain.c),)
  SRC	=	$(SRCDIR)/main.c
else
  SRC	=	$(SRCDIR)/$(if $(filter yes, $(DEBUG)),testmain.c,main.c)
endif
SRC	+=	$(SRCDIR)/termcaps.c		\
		$(SRCDIR)/readline.c		\
		$(SRCDIR)/errors.c		\
		$(SRCDIR)/history.c		\
		$(SRCDIR)/list.c		\
		$(SRCDIR)/funny.c		\
		$(SRCDIR)/put_funcs.c		\
		$(SRCDIR)/char_type.c		\
		$(SRCDIR)/l2c.c			\
		$(SRCDIR)/tokenise.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	:=	$(if $(filter yes, $(DEBUG)),-ggdb3,-O2)
CFLAGS	+=	-W -Wall -Wextra -pedantic -ansi -I./include
CFLAGS	+=	-D_BSD_SOURCE
LDFLAGS	=	-lncurses

all:		$(SRC) $(NAME)

$(NAME):	$(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@

%.o:		%.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
