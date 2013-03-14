type frac = Undef | Frac of (int * int)

let frac_of_int x = Frac (x, 1);;

let get_num = function
  | Undef -> 0
  | Frac (n, m) -> n
;;

let get_denom = function
  | Undef -> 0
  | Frac (n, m) -> m
;;

let print_frac = function
  | Frac (n, m) when m = 0 -> print_endline "NaN"
  | Frac (n, m) when m <> 1 -> print_endline(string_of_int n ^ "/" ^ string_of_int m)
  | Frac (n, m) when m = 1 -> print_endline(string_of_int n)
  | _ -> print_endline "NaN"
;;

let plus x y = match x, y with
  | (Frac (n, m), Frac (o, p)) when m = p -> Frac (n + o, m)
  | (Frac (n, m), Frac (o, p)) when m <> p -> Frac ((n * p) + (o * m) , m * p)
  | _ -> Undef
;;

let div x y = match x, y with
  | (Frac (n, m), Frac (o, p)) -> Frac (n * p, m * o)
  | _ -> Undef
;;

print_frac(plus (Frac (1, 2)) (Frac (1, 0)));;
print_frac (plus (div (frac_of_int 3) (frac_of_int 6))
	      (div (frac_of_int 5) (frac_of_int 4)));;
print_frac (div (frac_of_int 42)
	      (plus (div (frac_of_int 3) (frac_of_int 6))
		 (div (frac_of_int (-1)) (frac_of_int 2))));;
