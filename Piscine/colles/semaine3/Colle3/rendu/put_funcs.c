/*
** my_putfuncs.c for putfuncs in /home/guillo_e//working/colle
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Oct 30 01:59:08 2011 lyoma guillou
** Last update Sun Oct 30 05:52:07 2011 lyoma guillou
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void     my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

void     my_put_nbr(int nb)
{
  int           ten;
  int           neg;
  char          zero;

  ten = 10;
  neg = -1;
  zero = '0';
  if (nb < 0)
    {
      my_putchar('-');
      if (nb <= -ten)
        my_put_nbr(nb / -ten);
      my_putchar((neg * (nb % -ten)) + zero);
    }
  else
    {
      if (nb >= ten)
        my_put_nbr(nb / ten);
      my_putchar((nb % ten) + zero);
    }
}
