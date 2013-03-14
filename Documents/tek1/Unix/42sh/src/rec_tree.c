/*
** rec_tree.c for 42sh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri May 11 13:26:37 2012 lyoma guillou
** Last update Sun May 20 11:28:30 2012 lyoma guillou
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lltree.h"
#include "my.h"

t_cmd		*rec_cmd(char *str, int len)
{
  t_cmd		*tmp;

  tmp = new_node();
  if (!tmp || !(tmp->name = strndup(str, len)))
    return (NULL);
  tmp->flag = CMDS;
  return (tmp);
}

static const	t_scrpt	g_script[]=
  {
    {'=', set_var},
    {0, NULL}
  };

t_cmd		*rec_scrpt(char *src, int pos)
{
  t_cmd		*tmp;
  char		*str;
  int		i;

  i = 0;
  str = strdup(src);
  tmp = NULL;
  while (str[pos] != g_script[i].type)
    ++i;
  if (g_script[i].type != 0)
    tmp = g_script[i].fnc(str, pos);
  if (!tmp)
    {
      free_cmdl(tmp);
      fprintf(stderr, "Error Arround:\n%.15s...\n^\n", str);
      tmp = NULL;
    }
  free(str);
  return (tmp);
}

static const	t_operat g_operat[]=
  {
    {"||", op_or},
    {"|", op_pipe},
    {"&&", op_and},
    {"<<", op_rdrc},
    {"<", op_rdrc},
    {">>", op_rdrc},
    {">", op_rdrc},
    {";", op_endl},
    {NULL, NULL}
  };

t_cmd		*rec_operat(char *src, int pos)
{
  t_cmd		*tmp;
  char		*str;
  int		i;

  i = 0;
  str = strdup(src);
  while (g_operat[i].type
	 && strncmp(str + pos, g_operat[i].type, strlen(g_operat[i].type)))
    ++i;
  if (g_operat[i].type != NULL)
    {
      tmp = g_operat[i].fnc(str, pos, strlen(g_operat[i].type));
      if (tmp != NULL)
	{
	  free(str);
	  return (tmp);
	}
      fprintf(stderr, "Error Arround:\n%.15s...\n^\n", str);
      free_cmdl(tmp);
    }
  free(str);
  return (NULL);
}

int		rec_offset(char *str, int pos)
{
  int		i;
  t_e_flag	flag;

  i = pos;
  flag = 0;
  while (!is_end_line(str[i]))
    {
      if (str[i] == '\'' || str[i] == '"' || str[i] == '`')
	flag ^= ISQUOT;
      if (!is_sep(str[i]) && !is_scrpt(str[i])
	  && !is_pipe(str[i]) && !(flag & ISQUOT))
	return (i);
      ++i;
    }
  return (i);
}
