/*
** list_init.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 15:56:00 2012 louis duverdier
** Last update Thu Jan 26 16:35:23 2012 louis duverdier
*/

#include <corewar.h>

t_node		*node_create()
{
  t_node	*node;

  node = xmalloc(sizeof(*node));
  node->head = xmalloc(sizeof(*(node->head)));
  node->last_live = 0;
  node->prev = NULL;
  node->next = NULL;
  return (node);
}

t_list		*list_create()
{
  t_list	*list;

  list = xmalloc(sizeof(*list));
  list->first = NULL;
  list->last = NULL;
  list->size = 0;
  return (list);
}
