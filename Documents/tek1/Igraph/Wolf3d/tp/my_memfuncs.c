/*
** my_memfuncs.c for wolf3d in /home/guillo_e//working/igraph/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 11 10:16:43 2012 lyoma guillou
** Last update Sat Jan 14 17:27:08 2012 lyoma guillou
*/

#include "get_next_line.h"
#include "map.h"

void            *my_memset(void *ptr, int size)
{
  int           i;

  i = 0;
  while (i < size)
    ptr[i++] = 0;
  return (ptr);
}
