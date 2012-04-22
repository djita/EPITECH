/*
** eval_expr.c for bistromathique in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Wed Nov 02 15:40:12 2011 mickael falck
** Last update Wed Nov  9 11:28:29 2011 lyoma guillou
*/

#include "eval_expr.h"

/*int	check_base_ops(char *expr, char *base, char *ops)
{
  int	ind;

  ind = 0;
  while (expr[ind])
    {
      (is_ops(expr[ind], ops) == -1)
	return (-2);
      (is_base(expr[ind], base) == -1)
	return (-1);
      ind++;
    }
  ind = 0;
  while (base[ind])
    {
      if (is_ops(base[ind], ops) != -1)
	return (-3);
      ind++;
    }
  return (1);
  }*/

void	check_base(char *b)
{
 if (my_strlen(b) < 2)
    {
      my_putstr("Bad base\n");
      exit(1);
    }
}

char	*get_expr(unsigned int size)
{
  char	*expr;

  if (size <= 0)
      my_putstr("Bad expr len\n");
  else if ((expr = malloc(size + 1)) == 0)
      my_put_estr("could not alloc\n");
  else if (read(0, expr, size) != size)
      my_put_estr("could not read\n");
  else
    {
      expr[size] = '\0';
      return (expr);
    }
  exit(1);
}

void	check_ops(char *ops)
{
  if (my_strlen(ops) != 7)
    {
      my_putstr("Bad ops\n");
      exit(1);
    }
}
