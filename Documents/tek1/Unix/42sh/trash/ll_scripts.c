/*
** ll_scripts.c for 42sh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu May 10 18:43:17 2012 lyoma guillou
** Last update Fri May 11 13:42:53 2012 lyoma guillou
*/

#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>

#include "lltree.h"

t_cmd		*set_var(char *str, int pos)
{
  t_cmd		*equal;
  t_cmd		*name;
  t_cmd		*value;
  int		i;

  i = 1;
  equal = new_node();
  name = new_node();
  value = new_node();
  if (!equal || !name || !value || !(equal->name = strndup(str + pos, i)))
    return (NULL);
  equal->flag = VSET;
  if (!(name->name = strndup(str, pos)))
    return (NULL);
  name->flag = VSET;
  while (str[pos + i] && str[pos + i] > ' ')
    ++i;
  if (!(value->name = strndup(str + pos + 1, i + 1)))
    return (NULL);
  value->flag = VSET;
  equal = append_next(append_prev(equal, name), value);
  while (str[pos + i] && str[pos + i] <= ' ')
    ++i;
  str = str + pos + i;
  return (equal);
}

t_cmd		*val_var(char *str, int pos)
{
  t_cmd		*dollar;
  t_cmd		*var;
  int		i;

  i = 1;
  dollar = new_node();
  var = new_node();
  if (!dollar || !var || !(dollar->name = strndup(str + pos, i)))
    return (NULL);
  dollar->flag = VCON;
  while (str[pos + i] && str[pos + i] > ' ')
    ++i;
  if (!(var->name = strndup(str + pos + 1, i + 1)))
    return (NULL);
  var->flag = VCON;
  dollar = append_next(dollar, var);
  while (str[pos + i] && str[pos + i] <= ' ')
    ++i;
  str = str + pos + i;
  return (dollar);
}

t_cmd		*str_var(char *str, int pos)
{
  t_cmd		*string;
  char		*tmp;
  char		dquote;
  int		i;

  i = 1;
  dquote = str[pos] == '(' ? ')' : str[pos];
  string = new_node();
  while (str[pos + i] && str[pos + i] != dquote)
    ++i;
  if (!string || !str[pos + i])
    return (NULL);
  string->name = strndup(str + pos, i);
  string->flag = QUOT;
  if (!(tmp = strndup(str + pos + 1, i)))
    string->flag = NIL;
  else
    {
      string->next = line_parser(tmp, i);
      free(tmp);
    }
  while (str[pos + i] && str[pos + i] <= ' ')
    ++i;
  str = str + pos + i;
  return (string);
}

t_cmd		*str_pur(char *str, int pos)
{
  t_cmd		*string;
  char		quote;
  int		i;

  i = 1;
  quote = str[pos];
  string = new_node();
  while (str[pos + i] && str[pos + i] != quote)
    ++i;
  if (!string || !str[pos + i] || !(string->name = strndup(str + pos, i)))
    return (NULL);
  string->flag = NIL;
  while (str[pos + i] && str[pos + i] <= ' ')
    ++i;
  str = str + pos + i;
  return (string);
}
