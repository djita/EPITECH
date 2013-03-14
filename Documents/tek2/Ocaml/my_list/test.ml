let length list =
  let rec size list acc = match list with
    | [] -> acc
    | hd::tl -> size tl (acc + 1)
  in
  size list 0
;;

let rec fold_left fnc item list = match list with
  | [] -> item
  | hd::tl -> fold_left fnc (fnc item hd) tl
;;

