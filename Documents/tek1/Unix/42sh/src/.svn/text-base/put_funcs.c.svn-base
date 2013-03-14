/*
** put_funcs.c for mysh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Apr 26 15:43:27 2012 lyoma guillou
** Last update Mon May 14 14:44:20 2012 lyoma guillou
*/

#include <string.h>

#include "my.h"

int		my_putchar(char c)
{
  return(write(1, &c, 1));
}

int    		my_putstr(char *str)
{
  return(write(1, str, strlen(str)));
}

int		my_puterr(char *err)
{
  return(write(2, err, strlen(err)));
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    my_putchar('-');
  if (nb < 0 ? nb <= -10 : nb > 10)
    my_putnbr(nb < 0 ? nb / -10 : nb / 10);
  my_putchar((nb < 0 ? nb % -10 : nb % 10) + '0');
}
