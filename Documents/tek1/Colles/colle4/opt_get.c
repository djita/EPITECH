/*
** opt_get.c for opt_get in /home/guillo_e//Documents/working/colles/colle4
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May  7 19:19:27 2012 lyoma guillou
** Last update Mon May  7 22:57:05 2012 lyoma guillou
*/

#include <stdlib.h>
#include "opt_get.h"
#include "opt_fnc.h"
#include "parsing.h"
#include "lib.h"

static void	_match_opts(t_opt *list, t_option *format)
{
  t_option	*fmt;
  t_opt		*tmp;

  fmt = format;
  tmp = list;
  while (fmt)
    {
      if ((opt_isset(tmp, fmt->name) 
	   && fmt->arg_min >= my_tablen(opt_args(list, &(fmt->name))))
	  || fmt->needed == 0)
	fmt->find = 1;
      fmt = fmt->next;
    }
}

static int	_is_valid(t_option *format)
{
  t_option	*tmp;

  tmp = format;
  while (tmp)
    {
      if (tmp->find == 0)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

t_opt		*opt_get(int ac, char **av, const char *format)
{
  t_opt		*list;
  t_option	*opts;
  char		*str;

  str = (char *) format;
  if (ac > 1)
    {
      list = list_create(ac, av);
      opts = create_options(str);
      _match_opts(list, opts);
      if (_is_valid(opts))
	return (list);
      opt_free(list);
      free_opts(opts);
    }
  return (NULL);
}
