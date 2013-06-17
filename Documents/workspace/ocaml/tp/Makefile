SOURCES		=	lexer.mll parser.mly bigint.ml

EXEC		=	bistro

OCAMLC		=	ocamlc
OCAMLOPT	=	ocamlopt
OCAMLDEP	=	ocamldep
OCAMLLEX	=	ocamllex
OCAMLYACC	=	ocamlyacc

CUSTOM		=	-custom

all:	depend $(EXEC)

opt:	$(EXEC).opt

SRCSPARS	=	$(SRCS:.mly=.ml)
SRCSLEXR	=	$(SRCSPARS:.mll=.ml)
OBJS		=	$(SRCSLEXR:.ml=.cmo)
OPTOBJS		=	$(SRCSLEXR:.ml=.cmx)

$(EXEC):	$(OBJS)
	$(OCAMLC) $(CUSTOM) -o $(EXEC) $(LIBS) $(OBJS)

$(EXEC).opt:	$(OPTOBJS)
	$(OCAMLOPT) -o $(EXEC) $(LIBS:.cma=.cmxa) $(OPTOBJS)

.SUFFIXES: .ml .mli .cmo .cmi .cmx .mll .mly

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
	rm -f $(EXEC)
	rm -f $(EXEC).opt

fclean:		clean
	rm -f *.cm[iox] *~ .*~ #*#

depend:		$(SRCSLEXR)
	$(OCAMLDEP) *.mli *.ml > .depend

include .depend