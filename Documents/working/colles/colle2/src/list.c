/*
** list.c for reader in /home/guillo_e//Documents/working/colles/colle2
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Apr 24 20:32:47 2012 lyoma guillou
** Last update Tue Apr 24 22:44:17 2012 lyoma guillou
*/

#include <stdlib.h>
#include "reader.h"

t_obj		*new_elem()
{
  t_obj		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->type = NULL;
  new->content = NULL;
  new->next = NULL;
  return (new);
}

t_obj		*append_obj(t_obj *list, t_obj *new)
{
  t_obj		*tmp;

  tmp = list;
  while (tmp)
    tmp = tmp->next;
  tmp->next = new;
  return (list);
}

t_data		*new_data()
{
  t_data	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->name = NULL;
  new->item = NULL;
  new->next = NULL;
  return (new);
}

t_data		*append_data(t_data *list, t_data *new)
{
  t_data	*tmp;

  tmp = list;
  while (tmp)
    tmp = tmp->next;
  tmp->next = new;
  return (list);
}
