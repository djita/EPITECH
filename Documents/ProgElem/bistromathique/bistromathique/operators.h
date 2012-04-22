/*
** operators.h for bistromathique in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri Nov 04 11:39:26 2011 mickael falck
** Last update Sat Nov  5 19:55:52 2011 lyoma guillou
*/

#ifndef OPERATORS_H_
#  define OPERATORS_H_
#  include "bistromathique.h"

//static t_oper*	(*operators[7])(t_oper*, t_oper*);

t_oper		*do_add(t_oper *a, t_oper *b);
t_oper		*do_sub(t_oper *a, t_oper *b);
//t_oper		*do_mul(t_oper *a, t_oper *b);
//t_oper		*do_div(t_oper *a, t_oper *b);
//t_oper		*do_mod(t_oper *a, t_oper *b);

//operators[OP_PLUS_IDX] = &do_add;
//operators[OP_SUB_IDX] = &do_sub;
//operators[OP_MULT_IDX] = &do_mul;
//operators[OP_DIV_IDX] = &do_div;
//operators[OP_MOD_IDX] = &do_mod;

#endif /* !OPERATORS_H_ */
