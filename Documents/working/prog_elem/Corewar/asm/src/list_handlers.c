/*
** list_handlers.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Wed Jan 18 15:43:58 2012 louis duverdier
** Last update Tue Jan 24 17:42:51 2012 louis duverdier
*/

#include <asm.h>

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

void	list_remove(t_list *list, t_node *node)
{
  if (node->prev)
    {
      node->prev->next = node->next;
      if (node->next)
        node->next->prev = node->prev;
      free(node);
    }
  else
    {
      list->first = node->next;
      if (node->next)
        node->next->prev = NULL;
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
