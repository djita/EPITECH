/*
** my_swap.c for my_swap in /home/guillo_e//afs/rendu/piscine/Jour_04
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 16 10:27:14 2010 lyoma guillou
** Last update Wed Nov 16 14:35:46 2011 lyoma guillou
*/

#include "my.h"

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *b;
  *b = *a;
  *a = tmp;
}
