/*
** list_init.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Fri Jan 20 10:57:25 2012 louis duverdier
** Last update Mon Jan 23 10:58:19 2012 louis duverdier
*/

#include <asm.h>

t_node		*node_create(int type, char *label, char *label_ref, char *data)
{
  t_node	*node;

  node = xmalloc(sizeof(*node));
  node->type = type;
  node->label = label;
  node->label_ref = label_ref;
  node->data = data;
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
