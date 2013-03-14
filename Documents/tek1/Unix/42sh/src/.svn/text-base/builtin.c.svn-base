/*
** builtin.c for 42sh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri May 11 16:21:49 2012 lyoma guillou
** Last update Sat May 12 17:08:11 2012 lyoma guillou
*/

#include <stdlib.h>

#include "built.h"

static const	t_built	g_built[]=
  {
    { "cd", },
    { "echo", my_echo },
    { "pwd", },
    { "env", },
    { "unset", },
    { "exit", },
    { NULL,	NULL}
  };

int		built_in(char **arg)
{
  int		i;

  i = 0;
  while (g_built[i].cmd && strcmp(arg[0], g_built[i].cmd))
    ++i;
  if (!g_built[i].cmd)
    return (0);
  return (g_built[i].fnc(arg));
}
