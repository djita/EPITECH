let rec iter (fnc:'a->unit) l = match l with
  | [] -> ()
  | head::tail ->
    begin
      fnc head;
      iter fnc tail
    end
;;

iter print_endline ["Bonjour"; "les"; "tek2!!"];;
iter (fun n -> print_int n) [0; 1; 2; 3];;

hd ["voici" ,"une" ,"liste"];;
