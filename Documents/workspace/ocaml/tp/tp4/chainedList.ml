type 'a t : { data : (('a elem) option) ref; len : int ref }

type 'a elem : { content 'a; next (('a elem) option) ref }

