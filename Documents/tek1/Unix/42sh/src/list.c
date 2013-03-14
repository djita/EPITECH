/*
** list.c for src in /home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 11 17:39:16 2012 mickael falck
** Last update Fri May 11 17:56:35 2012 mickael falck
*/

#include <stdlib.h>
#include "list.h"

t_list		*add_link(t_list *prev, void *data)
{
  t_list	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->prev = prev;
  new->next = NULL;
  new->data = data;
  if (prev)
    prev->next = new;
  return (new);
}

t_list		*pop_link(t_list *link, void (*free_func)(void *))
{
  t_list	*tmp;

  tmp = (link) ? link->next : link;
  if (link)
    {
      if (free_func)
	free_func(link->data);
      free(link);
    }
  return (tmp);
}

void		flush_list(t_list *first, void (*free_func)(void *))
{
  t_list	*cur;

  cur = first;
  while (cur)
    cur = pop_link(cur, free_func);
}
