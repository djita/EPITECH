/*
** malloc.c for malloc in /home/lastmikoi/Work/malloc
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  jeu. janv. 31 15:08:20 2013 mickael falck
** Last update jeu. janv. 31 18:28:59 2013 mickael falck
*/

#include <unistd.h>

#include "my_malloc.h"

static t_g_mymalloc	g_malloc = {NULL, NULL, NULL};

void		*malloc(size_t size)
{
  void		*ptr;
  t_chunk_list	*last_chunk;

  if (!g_malloc.chunk_start)
    g_malloc.chunk_start = sbrk(0);
  /* TODO HERE : ALLOCATION ALGORITHM */
  ptr = sbrk(size);
  if (ptr == (void *)-1)
    return (NULL); /* TODO: Error handling */
  last_chunk = g_malloc.chunks;
  while (last_chunk && last_chunk->next)
    last_chunk = last_chunk->next;
  last_chunk = new_link(last_chunk, size, ptr);
  if (!g_malloc.chunks)
    g_malloc.chunks = last_chunk;
  /*  */
  g_malloc.chunk_end = sbrk(0);
  return (ptr);
}

void	free(void *to_free)
{
  t_chunk_list	*chunk;
  size_t	size;

  if ((chunk = is_allocated(to_free)))
    {
      size = chunk->size;
      g_malloc.chunk_end = remove_link(chunk);
      if (to_free + size == g_malloc.chunk_end)
	brk(to_free);
      g_malloc.chunk_end = sbrk(0);
    }
  else
    {
    }
}

t_chunk_list	*is_allocated(void *ptr)
{
  t_chunk_list	*cur;

  cur = g_malloc.chunks;
  while (cur)
    {
      if (ptr == cur->ptr)
	return (cur);
      cur = cur->next;
    }
  return (cur);
}
