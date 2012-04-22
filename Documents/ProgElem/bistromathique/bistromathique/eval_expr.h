/*
** eval_expr.h for bistromathique in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Wed Nov 02 15:40:54 2011 mickael falck
** Last update Wed Nov 02 15:51:38 2011 mickael falck
*/

#ifndef EVAL_EXPR_H_
#  define EVAL_EXPR_H_
#  include <stdlib.h>
#  include "my_std/str_manip.h"

void	check_base(char *b);
char	*get_expr(unsigned int size);
void	check_ops(char *ops);

#endif /* !EVAL_EXPR_H_ */
