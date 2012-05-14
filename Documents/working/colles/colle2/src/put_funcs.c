/*
** put_funcs.c for reader in /home/guillo_e//Documents/working/colles/colle2/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Apr 24 19:49:07 2012 lyoma guillou
** Last update Tue Apr 24 20:18:39 2012 lyoma guillou
*/

#include <unistd.h>
#include "my.h"

void		my_putchar(char c)
{
  if ((write(1, &c, 1)) < 0)
    return;
}

void		my_putstr(char *str)
{
  if ((write(1, str, my_strlen(str))) < 0)
    return;
}

void		my_puterr(char *err)
{
  if ((write(2, err, my_strlen(err))) < 0)
    return;
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    my_putchar('-');
  if (nb <= -10 || nb >= 10)
    my_putnbr(nb < 0 ? nb / -10 : nb / 10);
  my_putchar((nb < 0 ? nb % -10 : nb % 10) + '0');
}
