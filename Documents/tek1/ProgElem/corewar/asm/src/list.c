/*
** list.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Wed Jan 18 15:43:58 2012 louis duverdier
** Last update Thu Jan 19 16:17:43 2012 louis duverdier
*/

#include <asm.h>

t_node		*node_create()
{
  t_node	*node;

  node = xmalloc(sizeof(*node));
  node->type = 0;
  node->label = NULL;
  node->data = NULL;
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


void		list_free(t_list *list)
{
  t_node	*node;
  t_node	*tmp;

  node = list->first;
  while (node)
    {
      tmp = node;
      node = node->next;
      free(tmp);
    }
  free(list);
}

void	list_append(t_list *list, t_node *node)
{
  if (!list->first)
    {
      list->first = node;
      list->last = node;
      node->next = NULL;
      node->prev = NULL;
    }
  else
    {
      node->prev = list->last;
      node->next = NULL;
      list->last->next = node;
      list->last = node;
    }
  list->size += 1;
}

void	list_prepend(t_list *list, t_node *node)
{
  if (!list->first)
    {
      list->first = node;
      list->last = node;
      node->prev = NULL;
      node->next = NULL;
    }
  else
    {
      node->next = list->first;
      node->prev = NULL;
      list->first->prev = node;
      list->first = node;
    }
  list->size += 1;
}
