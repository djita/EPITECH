/*
** put_funcs.c for printf in /home/guillo_e//working/test/printf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Nov  9 20:58:28 2011 lyoma guillou
** Last update Wed Nov 16 14:42:43 2011 lyoma guillou
*/

#include <stdlib.h>
#include "my.h"

int	my_putunnbr(unsigned nb)
{
  int	i;

  i = 0;
  if (nb >= 10)
    my_putunnbr(nb / 10);
  i = i + my_putchar((nb % 10) + '0');
  return (i);
}

int	my_putnbr(int nb)
{
  int	i;

  i = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb <= -10)
	my_putnbr(nb / -10);
      i = i + my_putchar((nb % -10) + '0');
    }
  else
    {
      if (nb >= 10)
	my_putnbr(nb / 10);
      i = i + my_putchar((nb % 10) + '0');
    }
  return (i);
}

int	my_put_hexa(char *num)
{
  int	len;
  int	id;
  int	i;

  len = my_strlen(num);
  i = 0;
  id = 0;
  while (len + i < 8)
    {
      id = id + my_putchar('0');
      i++;
    }
  return (id);
}

int	my_putnbr_base(unsigned int nb, char *base_to, int opt)
{
  char	*dst;
  int   base_len;
  int   x;
  int	i;

  base_len = my_strlen(base_to);
  x = 0;
  i = my_numlen(nb, base_len) - 1;
  dst = malloc((my_numlen(nb, base_len) + 1) * sizeof(*dst));
  if (NULL == dst)
    return (0);
  while (i >= 0)
    {
      x = nb % base_len;
      dst[i] = base_to[x];
      nb = nb / base_len;
      i--;
    }
  dst[my_strlen(dst)] = '\0';
  if (base_len == 16 && opt == 1)
    x = my_put_hexa(dst);
  x = x + my_putstr(dst);
  return (x);
}
