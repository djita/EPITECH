(*
  Utilisation de Arg.parse:
  Arg.parse | Liste d'option qui doivent etre gerees | Le reste qui est non gere | message sur -help
*)


Arg.parse 
  [("-s", Arg.String (fun a -> print_endline ("-s was called with " ^ a)), "useless msg")]
  (fun str -> print_endline ("was not expected: " ^ str))
  "help message"

(*
List.iter print_endline (Array.to_list Sys.argv);;
*)

(* type expr =
  | Operator of (string * expr * expr)
  | Expression of int

let rec eval_expr = function 
  | Expression x -> x
  | Operator ("+", l, r) -> eval_expr l + eval_expr r
  | Operator ("-", l, r) -> eval_expr l - eval_expr r
  | Operator ("*", l, r) -> eval_expr l - eval_expr r
  | Operator ("/", l, r) -> eval_expr l - eval_expr r
  | Operator ("%", l, r) -> eval_expr l - eval_expr r
;;
*)
