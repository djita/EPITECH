/*
** xmalloc.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Thu Jan 26 16:35:55 2012 louis duverdier
*/

#include <my.h>

void	*xmalloc(size_t size)
{
  void	*data;

  if (!(data = malloc(size)))
    {
      my_puterr("Cannot perform malloc.\n");
      exit(EXIT_FAILURE);
    }
  return (data);
}
