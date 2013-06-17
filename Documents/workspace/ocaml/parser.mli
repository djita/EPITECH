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

val main :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> int
