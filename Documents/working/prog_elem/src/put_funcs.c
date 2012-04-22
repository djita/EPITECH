/*
** put_funcs.c for lem-in in /home/guillo_e//Documents/working/prog_elem/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr  2 17:07:59 2012 lyoma guillou
** Last update Thu Apr  5 16:16:43 2012 lyoma guillou
*/

#include <string.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_puterr(char *str)
{
  xwrite(2, str, my_strlen(str));
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    my_putchar('-');
  if ((nb < 0) ? nb >= 10 : nb <= -10)
    my_putnbr((nb < 0) ? nb / 10 : nb / -10);
  my_putchar((nb < 0 ? nb % 10 : nb % -10) + '0');
}
