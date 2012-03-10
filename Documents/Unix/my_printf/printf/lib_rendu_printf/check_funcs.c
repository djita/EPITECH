/*
** my_numlen.c for  in /home/guillo_e//working/test/printf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Nov  9 21:23:43 2011 lyoma guillou
** Last update Wed Nov 16 14:42:43 2011 lyoma guillou
*/

#include "my.h"

int     my_numlen(unsigned int nb, int base_len)
{
  int   i;

  i = 0;
  while (nb != 0)
    {
      nb = nb / base_len;
      i = i + 1;
    }
  return (i);
}
