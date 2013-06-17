OCAMLLEX	=	ocamllex
OCAMLYACC	=	ocamlyacc
OCAMLC		=	ocamlc
OCAMLOPT	=	ocamlopt
OCAMLDEP	=	ocamldep

EXEC		=	bistro

SRCS		=	lexer.mll	\
			parser.mly	\
			calc.ml

SRCSPARS	=	$(SRCS:.mly=.ml)
SRCSLEXR	=	$(SRCSPARS:.mll=.ml)

OBJS		=	$(SRCSLEXR:.ml=.cmo)
OBJSOPT		=	$(SRCSLEXR:.ml=.cmx)

FLAGS		=	-w Aelz -warn-error A
FLAGS		+=	-g

RM		=	rm -rf

$(EXEC).opt:	$(OBJSOPT)
	$(OCAMLOPT) -o $(EXEC) $(OBJSOPT) $(FLAGS)

$(EXEC):	$(OBJS)
	$(OCAMLC) -custom -o $(EXEC) $(OBJS) $(FLAGS)

.SUFFIXES: .ml .mli .cmo .cmi .cmx .mll .mly

all: 	depend $(EXEC).opt

byte:	$(EXEC)

.ml.cmo:
	$(OCAMLC) -c $<

.mli.cmi:
	$(OCAMLC) -c $<

.ml.cmx:
	$(OCAMLOPT) -c $<

.mll.cmo:
	$(OCAMLLEX) $<
	$(OCAMLC) -c $*.ml

.mll.cmx:
	$(OCAMLLEX) $<
	$(OCAMLOPT) -c $*.ml

.mly.cmo:
	$(OCAMLYACC) $<
	$(OCAMLC) -c $*.mli
	$(OCAMLC) -c $*.ml

.mly.cmx:
	$(OCAMLYACC) $<
	$(OCAMLOPT) -c $*.mli
	$(OCAMLOPT) -c $*.ml

.mly.cmi:
	$(OCAMLYACC) $<
	$(OCAMLC) -c $*.mli

.mll.ml:
	$(OCAMLLEX) $<

.mly.ml:
	$(OCAMLYACC) $<

clean:
	$(RM) $(EXEC)
	$(RM) $(EXEC).opt

fclean:	clean
	$(RM) *.cm[iox]
	$(RM) *.o

re:	fclean all

depend:	$(SRCSLEX)
	$(OCAMLDEP) *.mli *.ml > .depend

include .depend

.PHONY: all clean fclean re
