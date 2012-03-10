/*
** list_handlers.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 15:38:02 2012 louis duverdier
** Last update Thu Jan 26 16:35:31 2012 louis duverdier
*/

#include <corewar.h>

void		list_free(t_list *list)
{
  t_node	*node;
  t_node	*tmp;

  node = list->first;
  while (node)
    {
      tmp = node;
      node = node->next;
      free(tmp->head);
      free(tmp);
    }
  free(list);
}

void	list_remove(t_list *list, t_node *node)
{
  if (node->prev)
    {
      node->prev->next = node->next;
      if (node->next)
        node->next->prev = node->prev;
      free(node->head);
      free(node);
    }
  else
    {
      list->first = node->next;
      if (node->next)
        node->next->prev = NULL;
      free(node->head);
      free(node);
    }
  list->size -= 1;
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
