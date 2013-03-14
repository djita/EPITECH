/*
** realloc.c for malloc in /home/lastmikoi/Work/malloc
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  jeu. janv. 31 15:56:14 2013 mickael falck
** Last update jeu. janv. 31 16:14:46 2013 mickael falck
*/

#include <sys/types.h>
#include <unistd.h>

#include "my_malloc.h"

void		*malloc(size_t);
void		free(void *);

void		*realloc(void *ptr, size_t size)
{
  char		*new_ptr;
  size_t	i;
  size_t	chunk_size;

  if (!ptr)
    return (malloc(size));
  if (size && ptr)
    {
      free(ptr);
      return (NULL);
    }
  new_ptr = malloc(size);
  if (new_ptr)
    {
      i = 0;
      chunk_size = 0;
      while (i < chunk_size)
	{
	  new_ptr[i] = ((char *)ptr)[i];
	  ++i;
	}
      free(ptr);
    }
  return (new_ptr);
}
