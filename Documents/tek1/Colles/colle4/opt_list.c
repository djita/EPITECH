/*
** opt_list.c for opt_get in /home/guillo_e//Documents/working/colles/colle4
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May  7 19:31:48 2012 lyoma guillou
** Last update Mon May  7 21:43:46 2012 lyoma guillou
*/

#include <stdlib.h>
#include "opt_get.h"
#include "lib.h"

static t_opt	*_init_new()
{
  t_opt		*new;

  new = xmalloc(sizeof(*new));
  new->arg = NULL;
  new->next = NULL;
  return (new);
}

static t_opt	*_append_to_list(t_opt *list, t_opt *new)
{
  t_opt		*tmp;

  if (list != NULL)
    {
      tmp = list;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = new;
    }
  else
    list = new;
  return (list);
}

t_opt		*list_create(int ac, char **av)
{
  int		i;
  t_opt		*list;
  t_opt		*tmp;

  i = 1;
  list = NULL;
  tmp = NULL;
  while (i < ac && av[i])
    {
      tmp = _init_new();
      tmp->arg = my_strdup(av[i]);
      list = _append_to_list(list, tmp);
      ++i;
    }
  return (list);
}
