##
## Makefile for ocaml tp in /home/guillo_e/Documents/workspace/ocaml/tp
## 
## Made by Lyoma Guillou
## Login   <guillo_e@epitech.net>
## 
## Started on  Tue Mar 19 18:25:32 2013 Lyoma Guillou
## Last update Mon Mar 25 19:16:12 2013 Lyoma Guillou
##

CAMLC		=	ocamlc
CAMLOPT		=	ocamlopt
CAMLDEP		=	ocamldep

EXEC		=	ex_tp

SRCS		=	*.ml
OBJSOPT		=	$(SRCS:.ml=.cmx)
OBJS		=	$(SRCS:.ml=.cmo)

FLAGS		=	-w Aelz -warn-error A
FLAGS		+=	-g

RM		=	rm -f

.SUFFIXES: .ml .mli .cmo .cmi .cmx

all:		$(EXEC)

byte:		$(EXEC).c

.ml.cmo:
	$(CAMLC) $(FLAGS) -c $<

.ml.cmi:
	$(CAMLC) $(FLAGS) -c $<

.ml.cmx:
	$(CAMLOPT) $(FLAGS) -c $<

$(EXEC):	$(OBJSOPT)
	$(CAMLOPT) -o $(EXEC) $(FLAGS) $(OBJSOPT)

$(EXEC).c:	$(OBJS)
	$(CAMLC) -o $(EXEC) $(FLAGS) $(OBJS)

clean:
	$(RM) $(EXEC)

fclean:		clean
	$(RM) *.cm[iox]
	$(RM) *.o


re:		fclean all

depend:		create
	$(CAMLDEP) *.mli *ml > .depend

include .depend

.PHONY:		all clean fclean re
