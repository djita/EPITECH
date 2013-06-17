%token <int> BIGINT
%token ADD SUB MUL DIV MOD
%token L_P R_P
%token EOL
%left ADD SUB
%left MUL DIV MOD
%nonassoc USUB
%start main
%type <int> main
%%
main:
expr EOL		{ $1 }
  ;
  expr:
    BIGINT		{ $1 }
  | L_P expr R_P	{ $2 }
  | expr ADD expr	{ add (string_of_bigint $1) (string_of_bigint $3) }
  | expr SUB expr	{ sub (string_of_bigint $1) (string_of_bigint $3) }
  | expr MUL expr	{ mul (string_of_bigint $1) (string_of_bigint $3) }
  | expr DIV expr	{ div (string_of_bigint $1) (string_of_bigint $3) }
  | expr MOD expr	{ modulo (string_of_bigint $1) (string_of_bigint $3) }
  | SUB expr %prec USUB	{ - $2 }
  ;
