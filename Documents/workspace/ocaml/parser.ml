type token =
  | BIGINT of (int)
  | ADD
  | SUB
  | MUL
  | DIV
  | MOD
  | L_P
  | R_P
  | EOL

open Parsing;;
let yytransl_const = [|
  258 (* ADD *);
  259 (* SUB *);
  260 (* MUL *);
  261 (* DIV *);
  262 (* MOD *);
  263 (* L_P *);
  264 (* R_P *);
  265 (* EOL *);
    0|]

let yytransl_block = [|
  257 (* BIGINT *);
    0|]

let yylhs = "\255\255\
\001\000\002\000\002\000\002\000\002\000\002\000\002\000\002\000\
\002\000\000\000"

let yylen = "\002\000\
\002\000\001\000\003\000\003\000\003\000\003\000\003\000\003\000\
\002\000\002\000"

let yydefred = "\000\000\
\000\000\000\000\002\000\000\000\000\000\010\000\000\000\009\000\
\000\000\000\000\000\000\000\000\000\000\000\000\001\000\003\000\
\000\000\000\000\006\000\007\000\008\000"

let yydgoto = "\002\000\
\006\000\007\000"

let yysindex = "\004\000\
\031\255\000\000\000\000\031\255\031\255\000\000\009\255\000\000\
\025\255\031\255\031\255\031\255\031\255\031\255\000\000\000\000\
\254\254\254\254\000\000\000\000\000\000"

let yyrindex = "\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\014\255\017\255\000\000\000\000\000\000"

let yygindex = "\000\000\
\000\000\252\255"

let yytablesize = 38
let yytable = "\008\000\
\009\000\012\000\013\000\014\000\001\000\017\000\018\000\019\000\
\020\000\021\000\010\000\011\000\012\000\013\000\014\000\004\000\
\004\000\015\000\005\000\005\000\000\000\004\000\004\000\000\000\
\005\000\005\000\010\000\011\000\012\000\013\000\014\000\003\000\
\016\000\004\000\000\000\000\000\000\000\005\000"

let yycheck = "\004\000\
\005\000\004\001\005\001\006\001\001\000\010\000\011\000\012\000\
\013\000\014\000\002\001\003\001\004\001\005\001\006\001\002\001\
\003\001\009\001\002\001\003\001\255\255\008\001\009\001\255\255\
\008\001\009\001\002\001\003\001\004\001\005\001\006\001\001\001\
\008\001\003\001\255\255\255\255\255\255\007\001"

let yynames_const = "\
  ADD\000\
  SUB\000\
  MUL\000\
  DIV\000\
  MOD\000\
  L_P\000\
  R_P\000\
  EOL\000\
  "

let yynames_block = "\
  BIGINT\000\
  "

let yyact = [|
  (fun _ -> failwith "parser")
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 1 : 'expr) in
    Obj.repr(
# 12 "parser.mly"
          ( _1 )
# 95 "parser.ml"
               : int))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : int) in
    Obj.repr(
# 15 "parser.mly"
            ( _1 )
# 102 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 1 : 'expr) in
    Obj.repr(
# 16 "parser.mly"
                 ( _2 )
# 109 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'expr) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'expr) in
    Obj.repr(
# 17 "parser.mly"
                  ( add (string_of_bigint _1) (string_of_bigint _3) )
# 117 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'expr) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'expr) in
    Obj.repr(
# 18 "parser.mly"
                  ( sub (string_of_bigint _1) (string_of_bigint _3) )
# 125 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'expr) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'expr) in
    Obj.repr(
# 19 "parser.mly"
                  ( mul (string_of_bigint _1) (string_of_bigint _3) )
# 133 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'expr) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'expr) in
    Obj.repr(
# 20 "parser.mly"
                  ( div (string_of_bigint _1) (string_of_bigint _3) )
# 141 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'expr) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'expr) in
    Obj.repr(
# 21 "parser.mly"
                  ( modulo (string_of_bigint _1) (string_of_bigint _3) )
# 149 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 0 : 'expr) in
    Obj.repr(
# 22 "parser.mly"
                        ( - _2 )
# 156 "parser.ml"
               : 'expr))
(* Entry main *)
; (fun __caml_parser_env -> raise (Parsing.YYexit (Parsing.peek_val __caml_parser_env 0)))
|]
let yytables =
  { Parsing.actions=yyact;
    Parsing.transl_const=yytransl_const;
    Parsing.transl_block=yytransl_block;
    Parsing.lhs=yylhs;
    Parsing.len=yylen;
    Parsing.defred=yydefred;
    Parsing.dgoto=yydgoto;
    Parsing.sindex=yysindex;
    Parsing.rindex=yyrindex;
    Parsing.gindex=yygindex;
    Parsing.tablesize=yytablesize;
    Parsing.table=yytable;
    Parsing.check=yycheck;
    Parsing.error_function=parse_error;
    Parsing.names_const=yynames_const;
    Parsing.names_block=yynames_block }
let main (lexfun : Lexing.lexbuf -> token) (lexbuf : Lexing.lexbuf) =
   (Parsing.yyparse yytables 1 lexfun lexbuf : int)
