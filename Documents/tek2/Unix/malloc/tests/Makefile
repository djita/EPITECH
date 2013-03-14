##
## Makefile for tests in /home/lastmikoi/Work/malloc/tests
## 
## Made by mickael falck
## Login   <falck_m@epitech.net>
## 
## Started on  ven. janv. 25 09:08:54 2013 mickael falck
## Last update jeu. janv. 31 17:39:28 2013 mickael falck
##

# Das Makefile v3.0 by falck_m

NAME	=	test
DEBUG	=	yes

CC	:=	$(if $(filter yes, $(DEBUG)),clang,g)
RM	=	rm -f
SRCDIR	=	.

ifeq ($(wildcard $(SRCDIR)/testmain.c),)
  SRC	=	$(SRCDIR)/main.c
else
  SRC	=	$(SRCDIR)/$(if $(filter yes, $(DEBUG)),testmain.c,main.c)
endif
#SRC	+=	$(SRCDIR)/.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	:=	$(if $(filter yes, $(DEBUG)),-g -ggdb -O0,)
CFLAGS	+=	-Wall -Wextra -Werror
LDFLAGS	:=	-ldl -I../ -L../

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
