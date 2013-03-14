exception Nul;;

(*
let rec list_mul (x: int list) = match x with
  | head::l::o -> list_mul(l::o) * head
  | head::l -> head
  | _ -> 
    try
      raise Nul
    with
    | Nul -> 0
    | _ -> 1
;;
*)

let rec list_mul x l = 
  try
    match l with
    | [] -> x
    | 0::tail -> raise Nul
    | head::tail -> list_mul (x * head) tail
  with 
  | Nul -> 0
;;

print_endline(string_of_int(list_mul 1 [1; 5; 0; 3]));;
