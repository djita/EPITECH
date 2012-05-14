/*
** my_getnbr_base.c for 42sh in /home/guillo_e//Documents/working/test/unix
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat May 12 15:18:47 2012 lyoma guillou
** Last update Sat May 12 16:26:49 2012 lyoma guillou
*/

#include <string.h>

static int	_is_num(char c)
{
  return ((c >= '0' && c <= '9'));
}

static int	_is_base(char c, char *base)
{
  int		i;

  i = 0;
  while (c != base[i])
    ++i;
  return ((!base[i]));
}

static int	_my_power_it(int nb, int pow)
{
  int		x;

  x = 1;
  while (pow > 0)
    {
      x = x * nb;
      pow--;
    }
  return (x);
}

int		numlen(char *str, char *base)
{
  int		i;

  i = 0;
  if (str[0] == '-')
    str = str + 1;
  while (_is_num(str[i]) || _is_base(str[i], base))
    ++i;
  return (i);
}

int		my_getnbr_base(char *str, char *base)
{
  int		x;
  int		i;
  int		j;
  int		b_len;
  int		n_len;

  x = 0;
  i = str[0] == '-' ? 1 : 0 ;
  b_len = strlen(base);
  n_len = numlen(str) - 1;
  while (str[i] && (_is_num(str[i]) || _is_base(str[i], base)))
    {
      j = 0;
      while (str[i] != base[j])
	++j;
      x = x + (j * _my_power_it(b_len, n_len));
      ++i;
      --n_len;
    }
  return (str[0] == '-' ? -x : x);
}

