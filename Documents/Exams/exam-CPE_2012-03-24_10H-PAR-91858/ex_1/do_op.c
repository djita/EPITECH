/*
** do_op.c for do_op in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 24 10:03:52 2012 exam_user
** Last update Sat Mar 24 10:08:18 2012 exam_user
*/

#include <stdio.h>
#include <stdlib.h>

int		do_op(char **av)
{
  int		x;
  int		y;

  x = atoi(av[1]);
  y = atoi(av[3]);
  if (av[2][0] == '+')
    return (x + y);
  if (av[2][0] == '-')
    return (x - y);
  if (av[2][0] == '*')
    return (x * y);
  if (av[2][0] == '/')
    return (x / y);
  if (av[2][0] == '%')
    return (x % y);
}

int		main(int ac, char **av)
{
  if (ac == 4)
    printf("%d", do_op(av));
  printf("\n");
  return (0);
}
