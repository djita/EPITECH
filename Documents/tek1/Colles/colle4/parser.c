/*
** parser.c for parser in /home/deleta_m//Projets/Colles/Colle_4
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May  7 20:10:42 2012 marc deletang
** Last update Mon May  7 22:23:29 2012 lyoma guillou
*/

#include <stdio.h>
#include "parsing.h"

static int	is_space(char c)
{
  if (c <= ' ')
    return (1);
  return (0);
}

static int	find_nb_arg(char *str, int *i)
{
  int		nb_min;

  nb_min = 0;
  if (str[*i] == ']')
    *i = *i + 1;
  while (str[*i] && str[*i] != '-')
    {
      while (is_space(str[*i]) && str[*i] && str[*i] != '-')
        *i = *i + 1;
      if (str[*i] == '[')
	while (!is_space(str[*i]) && str[*i] && str[*i] != '-')
	  *i = *i + 1;
      if (!is_space(str[*i]) && str[*i] && str[*i] != '-')
	nb_min++;
      while (!is_space(str[*i]) && str[*i] && str[*i] != '-')
	*i = *i + 1;
    }
  return (nb_min);
}

static void	create_option(t_option *elem, char *str, int *i)
{
  int		nb_var;

  elem->needed = 1;
  elem->compress = 1;
  if (str[*i - 1] && str[*i - 1] == '[')
    elem->needed = 0;
  if (str[*i + 1] == '-')
    {
      elem->compress--;
      *i = *i + 2;
    }
  else
    *i = *i + 1;
  if (str[*i])
    elem->name = str[*i];
  *i = *i + 1;
  nb_var = find_nb_arg(str, i);
  elem->arg_min = nb_var;
}

t_option	*create_options(char *str)
{
  int		i;
  t_option	*opts;
  t_option	*tmp;

  opts = NULL;
  i = 0;
  while (str[i])
    {
      if (str[i] == '-')
	{
	  tmp = new_elem();
	  create_option(tmp, str, &i);
	  opts = append_to_opt(opts, tmp);
	}
      i = (str[i] == '-' ? i : i + 1);
    }
  return (opts);
}
