/*
** opt_args.c for opt_args in /home/deleta_m//Projets/Colles/Colle_4
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May  7 19:21:15 2012 marc deletang
** Last update Mon May  7 22:41:26 2012 lyoma guillou
*/

#include <stdlib.h>
#include "opt_get.h"
#include "lib.h"

static int		_is_opt(char c)
{
  return ((c == '-' || c == '['));
}

static int		_is_argopt(t_opt *node)
{
  return (_is_opt(node->arg[0]));
}

static int		_opt_len(t_opt *node)
{
  t_opt			*tmp;
  int			i;

  i = 0;
  tmp = node;
  if (_is_argopt(node))
    while (!_is_argopt(tmp->next))
      {
	tmp = tmp->next;
	++i;
      }
  return (i);
}

static t_opt		*_opt_match(t_opt *options, const char *option)
{
  t_opt			*tmp;
  char			*opt;

  tmp = options;
  opt = (char *) option;
  while (tmp)
    {
      if (!my_strncmp(options->arg + 1, opt, my_strlen(opt)))
	return (tmp);
      tmp = tmp->next;
    }
  return (tmp);
}

const char		**opt_args(t_opt *options, const char *option)
{
  t_opt			*tmp;
  char			**tab;
  int			i;

  i = 0;
  tab = NULL;
  options = _opt_match(options, option);
  if (options != NULL && _is_argopt(options))
    {
      tmp = options->next;
      tab = xmalloc((_opt_len(options) + 1) * sizeof(*tab));
      while (!_is_argopt(tmp))
	{
	  tab[i] = tmp->arg;
	  tmp = tmp->next;
	  ++i;
	}
      tab[i] = NULL;
    }
  return ((const char **) tab);
}
