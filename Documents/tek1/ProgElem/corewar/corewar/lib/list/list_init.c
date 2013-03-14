/*
** list_init.c for mysh in /home/duverd_l/Documents/Projets/mysh
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Tue Jan 31 12:56:40 2012 louis duverdier
** Last update Wed Mar 14 16:05:51 2012 louis duverdier
*/

#include "list.h"

t_list		*list_create()
{
  t_list	*list;

  list = xmalloc(sizeof(*list));
  list->first = NULL;
  list->last = NULL;
  list->size = 0;
  return (list);
}

t_node		*node_create()
{
  t_node	*node;

  node = xmalloc(sizeof(*node));
  node->data = NULL;
  node->next = NULL;
  node->prev = NULL;
  return (node);
}

t_node		*node_create_from(void *data)
{
  t_node	*node;

  node = node_create();
  node->data = data;
  return (node);
}

void		list_free(t_list *list, int free_data)
{
  t_node	*node;
  t_node	*tmp;

  node = list->first;
  while (node)
    {
      tmp = node;
      node = node->next;
      if (free_data)
        free(tmp->data);
      free(tmp);
    }
  free(list);
}
