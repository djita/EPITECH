/*
** list_funcs.c for push_swap in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Jan  3 16:48:47 2012 lyoma guillou
** Last update Fri Jan  6 17:30:51 2012 lyoma guillou
*/

#include <stdlib.h>
#include "push_swap.h"

t_list		*init_elem(int value, char list_name)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (NULL);
  elem->val = value;
  elem->name = list_name;
  elem->next = NULL;
  elem->prev = NULL;
  return (elem);
}

t_list		*add_to_list(t_list *list, t_list *elem)
{
  t_list	*tmp;

  tmp = list;
  if (tmp == NULL)
    return (elem);
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  return (elem);
}

t_list		*circle_list(int *val, int len, char name)
{
  t_list	*first;
  t_list	*last;
  int		i;

  i = 0;
  first = NULL;
  while (i < len)
    {
      last = add_to_list(first, init_elem(val[i], name));
      if (NULL == first)
	first = last;
      ++i;
    }
  first->prev = last;
  last->next = first;
  return (first);
}
