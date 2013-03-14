/*
** ll_operat.c for 42sh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri May 11 11:02:03 2012 lyoma guillou
** Last update Fri May 11 12:29:57 2012 lyoma guillou
*/

#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>

#include "lltree.h"

t_cmd		*op_pipe(char *str, int pos, int len)
{
  t_cmd		*pipe;
  int		i;

  i = len;
  pipe = new_node();
  if (!pipe || !(pipe->name = strndup(str + pos, len)))
    return (NULL);
  pipe->flag = PIPE;
  while (str[pos + i] && str[pos + i] <= ' ')
    ++i;
  str = str + pos + i;
  return (pipe);
}

t_cmd		*op_or(char *str, int pos, int len)
{
  t_cmd		*or;
  int		i;

  i = len;
  or = new_node();
  if (!or || !(or->name = strndup(str + pos, len)))
    return (NULL);
  or->flag = OLOG;
  while (str[pos + i] && str[pos + i] <= ' ')
    ++i;
  str = str + pos + i;
  return (or);
}

t_cmd		*op_slnt(char *str, int pos, int len)
{
  t_cmd		*slnt;
  int		i;

  i = len;
  slnt = new_node();
  if (!slnt || !(slnt->name = strndup(str + pos, len)))
    return (NULL);
  slnt->flag = SLNT;
  while (str[pos + i] && str[pos + i] <= ' ')
    ++i;
  str = str + pos + i;
  return (slnt);
}

t_cmd		*op_and(char *str, int pos, int len)
{
  t_cmd		*and;
  int		i;

  i = len;
  and = new_node();
  if (!and || !(and->name = strndup(str + pos, len)))
    return (NULL);
  and->flag = OLOG;
  while (str[pos + i] && str[pos + i] <= ' ')
    ++i;
  str = str + pos + i;
  return (and);
}
