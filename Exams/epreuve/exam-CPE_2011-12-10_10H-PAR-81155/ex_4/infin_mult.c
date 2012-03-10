/*
** infin_mult.c for infin_mult in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 10 11:04:41 2011 exam_user
** Last update Sat Dec 10 12:15:14 2011 exam_user
*/

#include <stdlib.h>

int		is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

void		show_res(char *num)
{
  int		is_num;
  int		i;

  i = 0;
  is_num = 0;
  while (num[i])
    {
      if (num[i] > '0')
	{
	  is_num = 1;
	  my_putchar(num[i]);
	}
      if (num[i] == '0' && is_num == 1)
	my_putchar(num[i]);
      i = i + 1;
    }
}

char		*operate(char *x, char *y, char *res)
{
  int		i;
  int		j;

  i = 0;
  while (x[i])
    {
      j = 0;
      while (y[j])
	{
	  res[i + j] = res[i + j] + (x[i] - '0') * (y[j] - '0');
	  if (res[i + j] >= 10)
	    {
	      res[i + j + 1] = res[i + j + 1] + (res[i + j] / 10);
	      res[i + j] = res[i + j] % 10;
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  return (res);
}

char		*infin_mult(char *nb1, char *nb2)
{
  char		*x;
  char		*y;
  char		*res;
  int		i;

  x = my_revstr(nb1);
  y = my_revstr(nb2);
  if (nb1[0] == '-')
    x[my_strlen(nb1) - 1] = 0;
  if (nb2[0] == '-')
    y[my_strlen(nb2) - 1] = 0;
  if (nb1[0] == '-' ^ nb2[0] == '-')
    my_putchar('-');
  if ((res = malloc((my_strlen(nb1) + my_strlen(nb2) + 1) * sizeof(*res))) == NULL)
    return (0);
  res = my_strset(res, (my_strlen(nb1) + my_strlen(nb2) + 1));
  res = operate(x, y, res);
  i = 0;
  while (i < (my_strlen(x) + my_strlen(y)))
    {
      res[i] = res[i] + '0';
      i = i + 1;
    }
  res = my_revstr(res);
  return (res);
}

int		main(int ac, char **av)
{
  if (ac == 3)
    show_res(infin_mult(av[1], av[2]));
  my_putchar('\n');
  return (0);
}
