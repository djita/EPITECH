/*
** do_op.c for do_op in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Feb 11 10:57:54 2012 exam_user
** Last update Sat Feb 11 11:06:27 2012 exam_user
*/

#include <stdio.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	do_op(int a, int b, char op)
{
  if (op == '+')
    return (a + b);
  if (op == '-')
    return (a - b);
  if (op == '*')
    return (a * b);
  if (op == '/')
    return (a / b);
  if (op == '%')
    return (a % b);
}

int	main(int ac, char **av)
{
  if (ac == 4)
    printf("%d\n", do_op(atoi(av[1]), atoi(av[3]), av[2][0]));
  else
    my_putchar('\n');
  return (0);
}
