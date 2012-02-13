/*
** x_funcs.c for alum1 in /home/guillo_e//Documents/working/prog_elem/Alum-1
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb  6 10:13:57 2012 lyoma guillou
** Last update Mon Feb  6 17:54:08 2012 lyoma guillou
*/

#include <alum.h>

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      my_putstr("Malloc error.\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
