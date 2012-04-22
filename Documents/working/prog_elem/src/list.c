/*
** list.c for lem-in in /home/guillo_e//Documents/working/prog_elem/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr  2 18:28:07 2012 lyoma guillou
** Last update Tue Apr 10 17:24:02 2012 lyoma guillou
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <parse.h>

t_list		init_list()
{
  t_list	list;

  list.r_first = NULL;
  list.r_last = NULL;
  list.p_first = NULL;
  list.p_last = NULL;
  return (list);
}

t_list		append_pipe(t_list list, t_pipe *new)
{
  if (!list.p_first)
    {
      list.p_first = new;
      list.p_last = new;
      return (list);
    }
  else
    {
      list.p_last->next = new;
      list.p_last = new;
      return (list);
    }
}

t_list		append_room(t_list list, t_room *new)
{
  if (!list.r_first)
    {
      list.r_first = new;
      list.r_last = new;
      return (list);
    }
  else
    {
      list.r_last->next = new;
      list.r_last = new;
      return (list);
    }
}

t_pipe		*get_pipe(char **tab)
{
  t_pipe	*new;
  int		i;

  i = 0;
  new = xmalloc(sizeof(*new));
  new->entry = tab[0];
  new->exit = tab[1];
  new->next = NULL;
  return (new);
}

t_room		*get_room(char **tab)
{
  t_room	*new;
  int		i;

  i = 0;
  new = xmalloc(sizeof(*new));
  new->name = tab[0];
  new->x_pos = atoi(tab[1]);
  new->y_pos = atoi(tab[2]);
  new->next = NULL;
  return (new);
}
