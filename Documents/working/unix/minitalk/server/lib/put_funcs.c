/*
** put_funcs.c for minitalk in /home/guillo_e//Documents/working/unix/minitalk/server/lib
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Mar  5 17:44:49 2012 lyoma guillou
** Last update Mon Mar  5 17:54:13 2012 lyoma guillou
*/

#include	<serv.h>

void		my_putchar(char c)
{
  xwrite(1, &c, 1);
}

void		my_putstr(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    ++i;
  xwrite(1, s, i);
}

void		my_puterr(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    ++i;
  xwrite(2, s, i);
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    my_putchar('-');
  if (nb < 0 ? nb <= -10 : nb >= 10)
    my_putnbr(nb / ((nb < 0) ? -10 : 10));
  my_putchar((nb % 10) + '0');
}
