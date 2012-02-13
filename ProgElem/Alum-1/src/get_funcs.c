/*
** get_funcs.c for alum1 in /home/guillo_e//Documents/working/prog_elem/Alum-1
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb  6 09:10:45 2012 lyoma guillou
** Last update Mon Feb  6 14:11:00 2012 lyoma guillou
*/

#include <alum.h>

static int	_is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

static int	_is_numeric(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int		char_alpha(char c)
{
  if (_is_alpha(c) ^ _is_numeric(c))
    return (1);
  return (0);
}

int		my_getnbr(char *s)
{
  int		i;
  int		x;

  i = 0;
  x = 0;
  while (_is_numeric(s[i]))
    x = (x * 10) + (s[i++] - '0');
  if (_is_alpha(s[i]))
    my_putstr("Number may be in wrong format\n");
  return (x);
}
