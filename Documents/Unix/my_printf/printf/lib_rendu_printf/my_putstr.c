/*
** my_putstr.c for my_printf in /home/guillo_e//working/test/printf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 10 18:57:08 2011 lyoma guillou
** Last update Wed Nov 16 14:42:43 2011 lyoma guillou
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_put_oct(char *num)
{
  int	len;
  int	ind;
  int	i;

  len = my_strlen(num);
  ind = 0;
  i = 0;
  ind = ind + my_putchar('\\');
  while (len + i < 3)
    {
      ind = ind + my_putchar('0');
      i++;
    }
  return (ind);
}

int	my_putoctal(char c, char *base_to)
{
  int	ind;
  char	*dst;
  int   base_len;
  int	i;
  int	x;

  base_len = my_strlen(base_to);
  x = 0;
  ind = 0;
  i = my_numlen(c, base_len) - 1;
  dst = malloc((my_numlen(c, base_len) + 1) * sizeof(*dst));
  if (NULL == dst)
    return (0);
  while (i >= 0)
    {
      x = c % base_len;
      dst[i] = base_to[x];
      c = c / base_len;
      i--;
    }
  dst[my_strlen(dst)] = '\0';
  if (base_len == 8)
    ind = ind + my_put_oct(dst);
  ind = ind + my_putstr(dst);
  return (ind);
}

int	my_putcstr(char *str)
{
  int	i;
  int	ind;

  i = 0;
  ind = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] >= 127)
	ind = ind + my_putoctal(str[i], "01234567");
      else
	ind = ind + my_putchar(str[i]);
      i++;
    }
  return (ind);
}

int	my_putstr(char *str)
{
  int	i;
  int	len;

  i = 0;
  while (str[i])
    i++;
  len = write(1, str, i);
  return (len);
}
