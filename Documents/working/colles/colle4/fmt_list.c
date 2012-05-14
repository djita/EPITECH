/*
** fmt_list.c for opt_get in /home/guillo_e//Documents/working/colles/colle4
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May  7 21:52:05 2012 lyoma guillou
** Last update Mon May  7 22:25:43 2012 lyoma guillou
*/

#include <stdlib.h>
#include "parsing.h"
#include "lib.h"

void		free_opts(t_option *list)
{
  t_option	*tmp;
  t_option	*tmp_free;

  tmp = list;
  while (tmp)
    {
      tmp_free = tmp;
      tmp = tmp->next;
      free(tmp_free);
    }
}

t_option	*new_elem()
{
  t_option	*new;

  new = xmalloc(sizeof(*new));
  new->name = 0;
  new->needed = 0;
  new->compress = 0;
  new->arg_min = 0;
  new->find = 0;
  new->next = NULL;
  return (new);
}

t_option	*append_to_opt(t_option *list, t_option *new)
{
  t_option	*tmp;

  if (list != NULL)
    {
      tmp = list;
      while (tmp->next)
	{
	  if (tmp->name == new->name)
	    {
	      free(new);
	      return (list);
	    }
	  tmp = tmp->next;
	}
      tmp->next = new;
    }
  else
    list = new;
  return (list);
}
