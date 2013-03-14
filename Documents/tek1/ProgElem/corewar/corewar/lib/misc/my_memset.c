/*
** my_memset.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 16:23:07 2012 louis duverdier
** Last update Wed Mar 14 16:06:04 2012 louis duverdier
*/

#include "my.h"

void		*my_memset(void *d, int c, size_t n)
{
  size_t	i;
  char		*tmp;

  tmp = (char *)d;
  i = 0;
  while (i < n)
    {
      *tmp = c;
      ++tmp;
      ++i;
    }
  return (d);
}
