/*
** exec_builtin.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri May 11 16:21:49 2012 lyoma guillou
** Last update Sun May 20 22:53:45 2012 mickael falck
*/

#include <stdlib.h>
#include <string.h>

#include "built.h"

static const	t_built	g_built[]=
  {
    {"cd", my_cd},
    {"echo", my_echo},
    {"env", my_env},
    {"pwd", my_pwd},
    {NULL, NULL}
  };

int		built_in(char **arg, int fd[2])
{
  int		i;

  i = 0;
  if (!arg[0])
    return (EXIT_FAILURE);
  while (g_built[i].cmd && strcmp(arg[0], g_built[i].cmd))
    ++i;
  if (!g_built[i].cmd)
    return (BLT_NOTFOUND);
  return (g_built[i].fnc(arg, fd));
}
