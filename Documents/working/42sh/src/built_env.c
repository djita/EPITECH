/*
** built_env.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Sat May 19 18:28:13 2012 vincent bonmarchand
** Last update Sun May 20 20:02:53 2012 mickael falck
*/

#include <stdlib.h>
#include <string.h>

#include "env.h"

int	my_env(char **arg, int fd[2])
{
  int	i;

  i = 0;
  if (arg == NULL)
    return (EXIT_FAILURE);
  while (arg[i] != NULL)
    i++;
  if (i == 1)
    aff_env(fd);
  if (i > 2)
    if (strcmp("-u", arg[1]) == 0 && i == 3)
      remove_env(arg);
  return (EXIT_SUCCESS);
}
