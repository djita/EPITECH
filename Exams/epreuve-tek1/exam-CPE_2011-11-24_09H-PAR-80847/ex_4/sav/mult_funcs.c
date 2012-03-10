/*
** mult_func.c for infin_mult in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 24 10:38:17 2011 exam_user
** Last update Thu Nov 24 10:47:27 2011 exam_user
*/

#include <stdlib.h>

char		*my_memset(unsigned char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      str[i] = 0;
      i++;
    }
  return (str);
}

char		*carry_add(unsigned char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 10)
	{
	  str[i + 1] = str[i + 1] + (str[i] / 10);
	  str[i] = str[i] % 10;
	}
      str[i] = str[i] + '0';
      i++;
    }
  str = my_revstr(str);
  return (str);
}

char		*mult_to_res(unsigned char *x, unsigned char *y, unsigned char *res)
{
  int		i;
  int		j;

  i = 0;
  while (is_num(x[i]))
    {
      j = 0;
      while (is_num(y[j]))
	{
	  res[i + j] = res[i + j] + ((x[i] - '0') * (y[j] -'0'));
	  j++;
	}
      i++;
    }
  return (res);
}

void		infin_mult(char *av1, char *av2)
{
  unsigned char	*res;
  unsigned char	*x;
  unsigned char	*y;
  int		len;

  len = (my_numlen(av1) + my_numlen(av2));
  if ((res = malloc(len * sizeof(*res))) == NULL)
    return;
  res = my_memset(res);
  x = my_revstr(av1);
  y = my_revstr(av2);
  res = carry_add(mult_to_res(x, y, res));
  if (av1[0] == '-' ^ av2[0] == '-')
    my_putchar('-');
  my_putstr(res);
}
