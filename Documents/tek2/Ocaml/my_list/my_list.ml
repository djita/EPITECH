type 'a my_list = 
  | Item of ('a * 'a my_list)
  | Empty
;;

let length li =
  let rec len list size = match list with
    | Empty -> size
    | Item (h, t) -> len t (size + 1)
  in
  len li 0
;;

let hd = function
  | Empty -> failwith "hd"
  | Item (h, t) -> h
;;

let tl = function
  | Empty -> failwith "tl"
  | Item (h, t) -> t
;;

let rec nth list x = match list with
  | Empty -> failwith "nth"
  | Item (h, t) when x < 0 -> invalid_arg "nth"
  | Item (h, t) when x = 0 -> h
  | Item (h, t) -> nth t (x - 1)
;;

let rev list =
  let rec it list acc = match list with
    | Empty -> acc
    | Item (h, t) -> it t (Item (h, acc))
  in
  it list Empty
;;

let rec append fli sli = match fli with
  | Empty -> sli
  | Item (h, t) -> Item (h, append t sli)
;;

let rev_append fli sli = 
  let rec rev_it fli sli acc = match fli with
    | Empty -> append acc sli
    | Item (h, t) -> rev_it t sli (Item (h, acc))
  in
  rev_it fli sli Empty
;;

let rec flatten = function
  | Empty -> Empty
  | Item (hd, tl) -> append hd (flatten tl)
;;

let rec iter fnc list = match list with
  | Empty -> ()
  | Item (hd, tl) -> 
    begin
      fnc hd;
      iter fnc tl
    end
;;

let rec map fnc list = match list with
  | Empty -> Empty
  | Item (hd, tl) -> Item (fnc hd, map fnc tl)
;;

let rec fold_left fnc item list = match list with
  | Empty -> item
  | Item (hd, tl) -> fold_left fnc (fnc item hd) tl
;;

let for_all fnc list =
  let rec loop list acc = match list with
    | Empty -> acc
    | Item (hd, tl) -> loop tl (acc && fnc hd)
  in
  loop list true
;;

let exists fnc list =
  let rec loop list acc = match list with
    | Empty -> acc
    | Item (hd, tl) -> loop tl (acc || fnc hd)
  in
  loop list false
;;

let mem item list =
  let rec struct_eq list acc = match list with
    | Empty -> acc
    | Item (hd, tl) -> struct_eq tl (acc || hd = item)
  in
  struct_eq list false
;;

let memq item list =
  let rec physic_eq list acc = match list with
    | Empty -> acc
    | Item (hd, tl) -> physic_eq tl (acc || hd == item)
  in
  physic_eq list false
;;

let filter fnc list = 
  let rec search list acc = match list with
    | Empty -> acc
    | Item (hd, tl) -> 
      if fnc hd
      then search tl (Item (hd, acc)) 
      else search tl acc
  in
  search list Empty
;;

let mem_assoc item list = 
  let rec catch list acc = match list with
    | Empty -> acc
    | Item ((hd1, hd2), tl) -> catch tl (acc || (hd1 = item))
  in
  catch list false
;;

let rec assoc item list = match list with
  | Empty -> raise Not_found
  | Item ((hd1, hd2), tl) ->
    if hd1 = item
    then hd2
    else assoc item tl
;;

let split list =
  let rec cut list x y = match list with
    | Empty -> (x, y)
    | Item ((hd1, hd2), tl) -> cut tl (append x (Item (hd1, Empty))) (append y (Item (hd2, Empty)))
  in
  cut list Empty Empty
;;

let remove_assoc item list =
  let rec search list acc = match list with
    | Empty -> list
    | Item ((hd1, hd2), tl) ->
      if hd1 = item
      then append acc tl
      else search tl (append acc (Item ((hd1, hd2), Empty)))
  in
  search list Empty
;;

length (Item (1, Item (2, Item (3, Empty))));;
hd (Item (1, Item (2, Empty)));;
tl (Item (1, Item (2, Empty)));;
nth (Item (1, Item (2, Item (3, Empty)))) 2;;
rev (Item (1, Item (2, Item (3, Empty))));;
append (Item (1, Item (2, Item (3, Empty)))) (Item (4, Item (5, Empty)));;
rev_append (Item (1, Item (2, Item (3, Empty)))) (Item (4, Item (5, Empty)));;

let newtest = 
Item (Item (1, Item (12, Empty)), 
Item (Item (2, Item (22, Empty)), Empty));;

let test = 
Item (Item (1, Empty), 
Item (Item (2, Empty), 
Item (Item (3, Empty), 
Item (Item (4, Empty), Empty))));;

let test2 =
Item (Item (1, Empty),
Item (Item (2, Item (22, Item (23, Empty))),
Item (Item (3, Empty),
Item (Item (4, Item (42, Empty)), Empty))));;

flatten newtest;;
flatten test;;
flatten test2;;

iter print_int (Item (1, Item (2, Item (3, Item (4, Empty)))));;

map string_of_int (Item (1, Item (2, Item (3, Item (4, Empty)))));;

fold_left (fun a b -> a + b) 2 (Item (1, Item (2, Item (3, Empty))));;
fold_left (fun a b -> a ^ b) "hi" (Item (", have", Item (" some", Item (" tea.", Empty))));;

for_all (fun a -> a > 0) (Item (1, Item (2, Item (1, Empty))));;
for_all (fun a -> a > 0) (Item (1, Item (-1, Item (1, Empty))));;
for_all (fun a -> a > 0) Empty;;

exists (fun a -> a > 0) (Item (1, Item (-1, Item (-1, Empty))));;
exists (fun a -> a > 0) (Item (-1, Item (-1, Item (-1, Empty))));;
exists (fun a -> a > 0) Empty;;

mem "a" (Item ("a", Item ("b", Item ("c", Empty))));;
mem "a" (Item ("z", Item ("b", Item ("c", Empty))));;

memq "a" (Item ("a", Item ("b", Item ("c", Empty))));;
memq "a" (Item ("z", Item ("b", Item ("c", Empty))));;
memq (hd newtest) newtest;;

filter (fun a -> a <= 0) (Item (-1, Item (1, Item (0, Item (2, Item (-2, Item (-1, Empty)))))));;

mem_assoc 1 (Item ((0, 1), Empty));;
mem_assoc 1 (Item ((1, 0), Empty));;

assoc 1 (Item ((0, 1), Empty));;
assoc 1 (Item ((1, 0), Empty));;

split (Item ((0, "a"), Item ((1, "b"), Item ((2, "c"), Empty))));;

remove_assoc 1 (Item ((0, "a"), Item ((1, "b"), Item ((2, "c"), Item ((3, "d"), Empty)))));;

(*
fold_right (fun a b -> a + b) (Item (1, Item (2, Item (3, Empty)))) 2;;
fold_right (fun a b -> a ^ b) (Item ("1", Item ("2", Item ("3", Empty)))) "2";;
*)
