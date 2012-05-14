/*
** rec_tree.c for 42sh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri May 11 13:26:37 2012 lyoma guillou
** Last update Fri May 11 14:33:39 2012 lyoma guillou
*/

#define _BSD_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lltree.h"

static const	t_scrpt	g_script[]=
  {
    { '=',	set_var },
    { '$',	val_var },
    { '"',	str_var },
    { '(',	str_var },
    { '`',	str_var },
    { '\'',	str_pur },
    { 0,	NULL	}
  };

t_cmd		*rec_scrpt(char *src, int pos)
{
  t_cmd		*tmp;
  char		*str;
  int		i;

  i = 0;
  str = strdup(src);
  while (str[pos] != g_script[i].type)
    ++i;
  if (g_script[i].type != 0)
    {
      tmp = g_script[i].fnc(str, pos);
      if (tmp != NULL)
	return (tmp);
      fprintf(stderr, "Error Arround:\n%.15s...\n^\n", str);
      free_cmdl(tmp);
    }
  free(str);
  return (NULL);
}

static const	t_operat g_operat[]=
  {
    { "||",	op_or	},
    { "|",	op_pipe },
    { "&&",	op_and	},
    { "&",	op_slnt },
    { "<<",	op_rdrc	},
    { "<",	op_rdrc },
    { ">>",	op_rdrc	},
    { ">",	op_rdrc },
    { ";",	op_endl },
    { NULL,	NULL }
  };

t_cmd		*rec_operat(char *src, int pos)
{
  t_cmd		*tmp;
  char		*str;
  int		i;

  i = 0;
  str = strdup(src);
  while (strncmp(str + pos, g_operat[i].type, strlen(g_operat[i].type)))
    ++i;
  if (g_operat[i].type != NULL)
    {
      tmp = g_operat[i].fnc(str, pos, strlen(g_operat[i].type));
      if (tmp != NULL)
	return (tmp);
      fprintf(stderr, "Error Arround:\n%.15s...\n^\n", str);
      free_cmdl(tmp);
    }
  free(str);
  return (NULL);
}
