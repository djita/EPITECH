/*
** lltree.c for 42sh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu May 10 16:03:09 2012 lyoma guillou
** Last update Sun May 20 15:55:44 2012 lyoma guillou
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "my.h"
#include "lltree.h"

static t_cmd	*_append_pivot(t_cmd *dst, t_cmd *elem)
{
  if (elem)
    {
      if (elem->flag & CMDS || elem->flag & SLNT)
	dst = (!dst || !dst->left)
	  ? append_left(dst, elem) : append_right(dst, elem);
      else if (elem->flag >= dst->flag)
	{
	  dst = (!elem->left && !elem->right
		 && !(elem->flag & (ENDL | OLOG)))
	    ? append_right(elem, dst) : append_left(elem, dst);
	}
      else
	dst = append_left(elem, dst);
    }
  return (dst);
}

int		check_parser(t_cmd *tree)
{
  if (tree)
    {
      if (tree->left)
	if (!check_parser(tree->left))
	  return (0);
      if (tree->right)
	if (!check_parser(tree->right))
	  return (0);
      if ((tree->flag & CMDS && (tree->left || tree->right))
	  || (tree->flag & (PIPE | RDRC | OLOG | VSET)
	      && (!tree->left || !tree->right))
	  || (tree->flag & ENDL && !tree->left))
	{
	  fprintf(stderr, "Syntax Error arround: %s\n", tree->name);
	  return (0);
	}
      else
	return (1);
    }
  fprintf(stderr, "Syntax Error! Invalid Command\n");
  return (0);
}

t_cmd		*line_parser(char *str, size_t len)
{
  t_cmd		*line;
  t_cmd		*tmp;
  size_t	i;

  i = 0;
  tmp = NULL;
  line = NULL;
  while (i <= strlen(str) && i <= len)
    if (is_oper(str[i])	|| (is_end_line(str[i]) && i != 0))
      {
	if (!(tmp = rec_cmd(str, i)))
	  return (line);
	line = _append_pivot(line, tmp);
	if (!(tmp = is_scrpt(str[i]) ? rec_scrpt(str, i) : rec_operat(str, i)))
	  return (line);
	line = _append_pivot(line, tmp);
	str = str + rec_offset(str, i);
	if (line->flag & (ENDL | OLOG) || !str[0] || str[0] == '\n')
	  return ((tmp = line_parser(str, strlen(str)))
		  ? append_right(line, tmp) : line);
	i = 0;
      }
    else
      ++i;
  return (line);
}
