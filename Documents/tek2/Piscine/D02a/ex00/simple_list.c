/*
** simple_list.c for simple_list in /home/guillo_e//Documents/working/tek2/piscine/D02a/ex00
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 15:21:20 2013 lyoma guillou
** Last update Thu Jan 10 19:05:02 2013 lyoma guillou
*/

#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

unsigned int	list_get_size(t_list list)
{
  if (!list)
    return 0;
  return (1 + list_get_size(list->next));
}

t_bool		list_is_empty(t_list list)
{
  return (!list ? TRUE : FALSE);
}

void		list_dump(t_list list)
{
  if (NULL != list)
    {
      printf("%f\n", list->value);
      list_dump(list->next);
    }
}

t_bool		list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_list	new = malloc(sizeof(*new));

  if (NULL != new)
    {
      new->value = elem;
      new->next = *front_ptr;
      *front_ptr = new;
      return TRUE;
    }
  return FALSE;
}

t_bool		list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_list	new = malloc(sizeof(*new));
  t_list	tmp;

  if (NULL != new)
    {
      tmp = *front_ptr;
      new->value = elem;
      new->next = NULL;
      if (NULL != tmp)
	{
	  while (NULL != tmp->next)
	    tmp = tmp->next;
	  tmp->next = new;
	}
      else
	*front_ptr = new;
      return TRUE;
    }
  return FALSE;
}

t_bool		list_add_elem_at_position(t_list *front_ptr, double elem, unsigned int position)
{
  t_list	new = malloc(sizeof(*new));
  t_list	tmp;
  unsigned int	i;

  if (position == 0)
    return list_add_elem_at_front(front_ptr, elem);	
  if (NULL != new)
    {
      tmp = *front_ptr;
      for (i = 1; i < position && NULL != tmp; ++i)
	tmp = tmp->next;
      if (i == position)
	{
	  if (NULL != tmp)
	    {
	      new->value = elem;
	      new->next = tmp->next;
	      tmp->next = new;
	    }
	  return TRUE;
	}
    }
  return FALSE;
}

t_bool		list_del_elem_at_front(t_list *front_ptr)
{
  t_list	tmp;

  tmp = *front_ptr;
  if (NULL != tmp)
    {
      tmp = tmp->next;
      *front_ptr = tmp;
      return TRUE;
    }
  return FALSE;
}

t_bool		list_del_elem_at_back(t_list *front_ptr)
{
  t_list	tmp;

  tmp = *front_ptr;
  if (NULL != tmp)
    {
      while (NULL != tmp->next->next)
	tmp = tmp->next;
      tmp->next = NULL;
      return TRUE;
    }
  return FALSE;
}

t_bool		list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  t_list	tail;
  t_list	tmp;

  if (*front_ptr)
    {
      tmp = *front_ptr;
      for (unsigned int i = 0; i < position - 1 && NULL != tmp; ++i)
	{
	  tail = tmp;
	  tmp = tmp->next;
	}
      tail->next = NULL;
      if (NULL != tmp->next)
	tail->next = tmp->next;
      return list_del_elem_at_front(&tmp);
    }
  return FALSE;
}

double		list_get_elem_at_front(t_list list)
{
  if (NULL != list)
    return list->value;
  return 0;
}

double		list_get_elem_at_back(t_list list)
{
  t_list	tmp;

  if (NULL != list)
    {
      tmp = list;
      while (NULL != tmp->next)
	tmp = tmp->next;
      return tmp->value;
    }
  return 0;
}

double		list_get_elem_at_position(t_list list, unsigned int position)
{
  t_list	tmp;
  unsigned int	i;

  if (NULL != list)
    {
      for (i = 0; i < position && NULL != tmp; ++i)
	tmp = tmp->next;
      if (i == position && NULL != tmp)
	return tmp->value;
    }
  return 0;
}

t_node		*list_get_first_node_with_value(t_list list, double value)
{
  t_list	tmp;

  if (NULL != list)
    {
      tmp = list;
      while (NULL != tmp && value != tmp->value)
	tmp = tmp->next;
      if (NULL != tmp)
	return tmp;
    }
  return NULL;
}
