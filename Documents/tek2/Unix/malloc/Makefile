##
## Makefile for malloc in /home/lastmikoi/Work/malloc
## 
## Made by mickael falck
## Login   <falck_m@epitech.net>
## 
## Started on  jeu. janv. 31 13:39:57 2013 mickael falck
## Last update jeu. janv. 31 17:02:59 2013 mickael falck
##

# Das Makefile v3.0 by falck_m

NAME	=	libmy_malloc_$(HOSTTYPE).so
DEBUG	=	no

CC	:=	$(if $(filter yes, $(DEBUG)),clang,gcc)
RM	=	rm -f
SRCDIR	=	.

SRC	+=	$(SRCDIR)/malloc.c
SRC	+=	$(SRCDIR)/realloc.c

SRC	+=	$(SRCDIR)/chunk_list.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	:=	$(if $(filter yes, $(DEBUG)),-g -ggdb -O0,)
CFLAGS	+=	-Wall -Wextra -Werror -fPIC
LDFLAGS	:=	-shared

all:		$(SRC) $(NAME)

$(NAME):	$(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@
	ln -fs libmy_malloc_$(HOSTTYPE).so libmy_malloc.so

%.o:		%.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) libmy_malloc.so
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
