/*
** ptr_tricks.c for ptr_tricks in /home/guillo_e//Documents/working/tek2/piscine/D02m/ex05
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 12:22:21 2013 lyoma guillou
** Last update Thu Jan 10 14:19:46 2013 lyoma guillou
*/

#include <stdint.h>
#include <stdio.h>
#include "ptr_tricks.h"

int		get_array_nb_elem(int *ptr1, int *ptr2)
{
  int		*first;
  int		*last;

  first = (ptr1 > ptr2) ? ptr2 : ptr1;
  last = (ptr1 > ptr2) ? ptr1 : ptr2;
  return (last - first);
}

t_whatever	*get_struct_ptr(int *member_ptr)
{
  t_whatever	tmp;
  uint64_t	i;

  i = (void *) &tmp - (void *) &tmp.member;
  printf("%p\n", (void *) member_ptr + i);
  return (t_whatever *) ((void *) member_ptr + i);
}
