/*
** bistromathique.h for bistromathique in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Tue Nov 01 16:09:10 2011 mickael falck
** Last update Sat Nov  5 20:04:39 2011 lyoma guillou
*/

#ifndef BISTROMATHIQUE_H_
#  define BISTROMATHIQUE_H_
#  define OP_OPEN_PARENT_IDX	0
#  define OP_CLOSE_PARENT_IDX	1
#  define OP_PLUS_IDX		2
#  define OP_SUB_IDX		3
#  define OP_NEG_IDX		3
#  define OP_MULT_IDX		4
#  define OP_DIV_IDX		5
#  define OP_MOD_IDX		6
#  define SYNTAXE_ERROR_MSG	"syntax error\n"
#  include <stdlib.h>

/* typedef struct	s_val
{
  char		*base;
  char		*ops;
  char		base_i;
  char		ops_i;
  struct s_oper	*next;
  }		t_val; */

typedef struct	s_oper
{
  char		data;
  int		sign;
  struct s_oper	*prev;
  struct s_oper *next;
}		t_oper;

char	*eval_expr(char *base,char *ops,char *expr,unsigned int size);

#endif /* !BISTROMATHIQUE_H_ */
