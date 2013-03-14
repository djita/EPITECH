/*
** get_info.c for get_info in /home/deleta_m//Projets/Colles/Colle_2
**
** Made by marc deletang
** Login   <deleta_m@epitech.net>
**
** Started on  Tue Apr 24 19:36:41 2012 marc deletang
** Last update Tue Apr 24 22:41:21 2012 lyoma guillou
*/

#include <stdlib.h>
#include "reader.h"

static enum dat	_is_item(char *str)
{
  if (str[0] == '<')
    {
      if (str[1] == '/')
	return (END);
      else
	return (START);
    }
  return (TEXT);
}

t_obj		*get_obj(t_obj *obj, char *title, char *cont)
{
  t_obj		*new;

  new = new_elem();
  new->type = title;
  new->content = cont;
  return (append_obj(obj, new));
}

t_data		*get_data(t_data *data, char *name)
{
  t_data	*new;

  new = new_data();
  new->name = name;
  return (append_data(data, new));
}

t_data		**get_info(char **tab)
{
  t_data	**list;
  t_data	*tmp;
  int		i;

  i = 0;
  tmp = *list;
  while (tab[i])
    {
      if (_is_item(tab[i]) == START)
	{
	  if (_is_item(tab[i + 1]) == START)
	    tmp = get_data(tmp, tab[i]);
	  else if (_is_item(tab[i + 2]) == END)
	    tmp->item = get_obj(tmp->item, tab[i], tab[i + 1]);
	}
      ++i;
    }
  tmp-next = list;
  return (list);
}
