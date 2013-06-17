{
  open Parser
  exception Eof
  exception NoParse
}

rule token = parse
[' ' '\t']	{ token lexbuf }
| ['\n']	{ EOL }
| ['0'-'9' 'a'-'f' 'A'-'F' 'x' 'X']+ as num	{ BIGINT(bigint_of_string num) }
| '+'	{ ADD }
| '-'	{ SUB }
| '*'	{ MUL }
| '/'	{ DIV }
| '%'	{ MOD }
| '('	{ L_P }
| ')'	{ R_P }
| eof	{ raise Eof }
| _	{ raise NoParse }
