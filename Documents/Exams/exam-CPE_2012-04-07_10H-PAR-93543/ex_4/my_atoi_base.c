/*
** my_atoi_base.c for my_atoi_base in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Apr  7 11:12:21 2012 exam_user
** Last update Sat Apr  7 11:35:49 2012 exam_user
*/

#include <stdio.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

int		my_power_it(int nb, int power)
{
  int		x;

  x = 1;
  while (power != 0)
    {
      x = x * nb;
      --power;
    }
  return (x);
}

int		my_atoi_base(char *str, char *base)
{
  int		i;
  int		j;
  int		x;

  i = my_strlen(str) - 1;
  x = 0;
  j = 0;
  while (i >= 0)
    {
      j = 0;
      while (base[j] && str[i] != base[j])
	++j;
      x = x + j * my_power_it(my_strlen(base), (my_strlen(str) - 1) - i);
      --i;
    }
  return (x);
}
