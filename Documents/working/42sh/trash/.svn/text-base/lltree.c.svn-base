/*
** lltree.c for 42sh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu May 10 16:03:09 2012 lyoma guillou
** Last update Fri May 11 14:24:40 2012 lyoma guillou
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "my.h"
#include "lltree.h"
#include "42sh.h"

static char	_is_script(char c)
{
  if (c == '=' || c == '$' || c == '\'' || c == '"' || c == '`')
    return (c);
  return (0);
}

static char	_is_pipe(char c)
{
  if (c == '&' || c == '|' || c == '<' || c == '>' || c == ';')
    return (c);
  return (0);
}

static char	_is_symbol(char c)
{
  return ((_is_script(c) || _is_pipe(c)));
}

static t_cmd	*_rec_cmd(char *str, int len)
{
  t_cmd		*tmp;

  tmp = new_node();
  if (!tmp || !(tmp->name = strndup(str, len)))
    return (NULL);
  tmp->flag = CMDS;
  return (tmp);
}

t_cmd		*line_parser(char *str, int len)
{
  t_cmd		*line;
  t_cmd		*tmp;
  int		i;
  char		sym;

  i = 0;
  sym = 0;
  tmp = NULL;
  line = NULL;
  while (i <= len)
    {
      if (_is_symbol(str[i]) || is_end_line(str[i]))
	{
	  tmp = _rec_cmd(str, i);
	  tmp = is_sep(str[i]) ? append_next(line, tmp) : (_is_script(str[i]) ? append_next(tmp, rec_scrpt(str, i)) : append_prev(rec_operat(str, i), tmp));
	  while (!is_end_line(str[i]) && (is_sep(str[i]) || _is_symbol(str[i])))
	    ++i;
	  str = str + i;
	  if (!tmp)
	    return (NULL);
	  line = tmp;
	}
      else
	++i;
    }
  return (line);
}
