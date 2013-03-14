/*
** ll_operat2.c for 42sh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri May 11 11:34:03 2012 lyoma guillou
** Last update Fri May 11 12:31:12 2012 lyoma guillou
*/

#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>

#include "lltree.h"

t_cmd		*op_rdrc(char *str, int pos, int len)
{
  t_cmd		*rdrc;
  int		i;

  i = len;
  rdrc = new_node();
  if (!rdrc || !(rdrc->name = strndup(str + pos, len)))
    return (NULL);
  rdrc->flag = RDRC;
  while (str[pos + i] && str[pos + i] <= ' ')
    ++i;
  str = str + pos + i;
  return (rdrc);
}

t_cmd		*op_endl(char *str, int pos, int len)
{
  t_cmd		*endl;
  int		i;

  i = len;
  endl = new_node();
  if (!endl || !(endl->name = strndup(str + pos, len)))
    return (NULL);
  endl->flag = ENDL;
  while (str[pos + i] && str[pos + i] <= ' ')
    ++i;
  str = str + i;
  return (endl);
}
