/*
** my_isneg.c for my_isneg in /home/guillo_e//Jour_03_alpha
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Oct  6 18:58:56 2010 lyoma guillou
** Last update Wed Nov 16 14:35:50 2011 lyoma guillou
*/

#include "my.h"

int	my_isneg(int n)
{
  if (n >= 0)
    my_putchar('P');
  else
    my_putchar('N');
}
