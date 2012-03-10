/*
** main.c for bistromathique in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Mon Oct 31 14:25:42 2011 mickael falck
** Last update Thu Nov 10 14:22:42 2011 lyoma guillou
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromathique.h"
#include "eval_expr.h"
#include "list_funcs.h"
#include "operators.h"

void		print_usage(char *path)
{
  my_putstr("Usage : ");
  my_putstr(path);
  my_putstr(" base ops\"()+-*/%\" exp_len\n");
  exit(1);
}

int		main(int ac, char **av)
{
  t_oper	*a;
  t_oper	*b;
  t_oper	*result;

  if (ac < 2)
    return (0);

  //if (ac != 4)
  //  print_usage(av[0]);
  //check_base(av[1]);
  //check_ops(av[2]);
  //expr = get_expr(size = atoi(av[3]));
  a = operand_to_list(av[1]);
  b = operand_to_list(av[2]);
  result = do_sub(a, b);
  read_list(a);
  my_putchar('-');
  read_list(b);
  my_putchar('=');
  read_list(result);
  my_putchar('\n');

  //my_putstr(eval_expr(av[1], av[2], expr, size));
  my_putchar('\n');
  return (0);
}
