/*
** list_handlers.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Tue Feb 21 11:29:19 2012 louis duverdier
** Last update Wed Mar 14 16:05:44 2012 louis duverdier
*/

#include "list.h"

t_node		*node_at(t_list *list, int pos)
{
  int		i;
  int		tmp;
  t_node	*node;

  if (pos < 0 || pos >= list->size)
    return (NULL);
  tmp = list->size - pos - 1 < pos;
  node = tmp ? list->last : list->first;
  i = tmp ? list->size - 1 : 0;
  while (i != pos)
    {
      node = tmp ? node->prev : node->next;
      i = tmp ? i - 1 : i + 1;
    }
  return (node);
}

void	list_append(t_list *list, t_node *node)
{
  if (list->last)
    {
      list->last->next = node;
      node->prev = list->last;
      node->next = NULL;
      list->last = node;
    }
  else
    {
      list->first = node;
      list->last = node;
      node->next = NULL;
      node->prev = NULL;
    }
  ++(list->size);
}

void	list_prepend(t_list *list, t_node *node)
{
  if (list->first)
    {
      list->first->prev = node;
      node->next = list->first;
      node->prev = NULL;
      list->first = node;
    }
  else
    {
      list->first = node;
      list->last = node;
      node->next = NULL;
      node->prev = NULL;
    }
  ++(list->size);
}

void		list_insert(t_list *list, t_node *node, int pos)
{
  int		i;
  t_node	*prev;

  if (pos <= 0)
    list_prepend(list, node);
  else if (pos >= list->size)
    list_append(list, node);
  else
    {
      i = 0;
      prev = list->first;
      while (prev && i < pos - 1)
        {
          prev = prev->next;
          ++i;
        }
      if (!prev)
        return;
      node->prev = prev;
      node->next = prev->next;
      prev->next = node;
      if (node->next)
        node->next->prev = node;
      ++(list->size);
    }
}

t_node	*list_pop(t_list *list, t_node *node)
{
  if (node->prev)
    {
      node->prev->next = node->next;
      if (node->next)
        node->next->prev = node->prev;
      else
        list->last = node->prev;
    }
  else
    {
      list->first = node->next;
      if (node->next)
        node->next->prev = NULL;
      else
        list->last = NULL;
    }
  --(list->size);
  return (node);
}
