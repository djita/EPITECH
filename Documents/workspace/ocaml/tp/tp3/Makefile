CAMLC		=	ocamlc
CAMLOPT		=	ocamlopt
CAMLDEP		=	ocamldep

EXEC		=	ex_tp

SRCS		=	tp.ml
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

depend:
	$(CAMLDEP) *.mli *ml > .depend

include .depend

.PHONY:		all clean fclean re
