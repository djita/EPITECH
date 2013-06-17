let print_upto n = 
  let rec print_to acc n = match n with
    | 0 -> ()
    | _ -> begin print_int acc;	print_to (acc + 1) (n - 1) end
  in
  print_to 1 n
;;

let func_fact n =
  let rec fact_it acc n = match n with
    | 0 -> acc
    | _ -> fact_it (acc * n) (n - 1)
  in
  fact_it 1 n
;;

