/*
** opt_parse.c for text_count in /home/guillo_e//Documents/working/colles/colle7
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue May 29 20:15:09 2012 lyoma guillou
** Last update Tue May 29 22:20:51 2012 lyoma guillou
*/

#include <stdlib.h>
#include "txtcnt.h"

static t_opts	_is_other_opt(char *str, t_opts opt)
{
  char		*tmp;

  tmp = my_strdup(str);
  if (tmp != NULL)
    {
      if (!my_strcmp(tmp, "-reverse") || !my_strcmp(tmp, "-reverse=on"))
	opt.flag |= REV;
      if (!my_strcmp(tmp, "-reverse=off"))
	opt.flag &= ~REV;
      if (!my_strcmp(tmp, "--fullstat"))
	opt.flag |= FULL;
      if (!my_strcmp(tmp, "-on_the_fly"))
	opt.flag |= OTF;
      free(tmp);
    }
  return (opt);
}

t_opts		get_opt(int ac, char **av)
{
  t_opts	opt;
  int		i;

  opt.flag = 0;
  i = 0;
  opt.start = 1;
  while (opt.start < ac)
    {
      if (av[opt.start][0] == '-')
	{
	  if (!my_strcmp(av[opt.start], "-t"))
	    opt.flag |= SORT;
	  else if (!my_strcmp(av[opt.start], "-r"))
	    opt.flag |= ORD;
	  else
	    opt = _is_other_opt(av[opt.start], opt);
	  ++opt.start;
	}
      else
	return (opt);
    }
  return (opt);
}
