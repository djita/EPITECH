/*
** put_funcs.c for alum1 in /home/guillo_e//Documents/working/prog_elem/Alum-1
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb  6 08:50:15 2012 lyoma guillou
** Last update Sat Feb 11 15:09:01 2012 lyoma guillou
*/

#include <alum.h>

int		my_putchar(int c)
{
  write(1, &c, 1);
  return (1);
}

int		my_putstr(char *s)
{
  int		i;

  i = 0;
  while (s[i++]);
  write(1, s, i);
  return (i);
}

int		my_putnbr(int nb)
{
  int		x;

  x = 0;
  if (nb < 0)
    my_putchar('-');
  if (nb < 0 ? (nb <= -10) : (nb >= 10))
    x += my_putnbr(nb / ((nb < 0) ? -10 : 10));
  x+= my_putchar((nb < 0 ? (-(nb % -10)) : (nb % 10)) + '0');
  return (x);
}
