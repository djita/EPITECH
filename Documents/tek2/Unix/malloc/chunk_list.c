/*
** chunk_list.c for malloc in /home/lastmikoi/Work/malloc
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  jeu. janv. 31 16:25:13 2013 mickael falck
** Last update jeu. janv. 31 17:32:03 2013 mickael falck
*/

#include <unistd.h>
#include "chunk_list.h"
#include "my_malloc.h"

t_chunk_list	*new_link(t_chunk_list *prev, size_t size, void *ptr)
{
  t_chunk_list	*link;

  link = sbrk(sizeof(*link));
  if (link == (void *)-1)
    return (NULL); /* TODO: Error handling */
  if (prev)
    prev->next = link;
  link->prev = prev;
  link->next = NULL;
  link->size = size;
  link->ptr = ptr;
  return (link);
}

void	*remove_link(t_chunk_list *toremove)
{
  t_chunk_list	*prev;

  prev = toremove->prev;
  if (prev)
    prev->next = toremove->next;
  if ((void *)toremove + sizeof(*link) == sbrk(0))
    brk((void *)toremove);
  return (sbrk(0));
}
