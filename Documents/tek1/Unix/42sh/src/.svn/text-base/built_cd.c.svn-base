/*
** built_cd.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Fri May 18 01:14:41 2012 vincent bonmarchand
** Last update Sun May 20 22:03:39 2012 vincent bonmarchand
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "env.h"

int    cd_less()
{
  char	*tmp;

  tmp = my_getenv("OLD_PWD");
  add_env("OLD_PWD", getcwd(NULL, 0));
  if (chdir(tmp) == -1)
    return (-2);
  return (0);
}

int	count_arg(char **path)
{
  int	i;

  i = 0;
  while (path[i])
    i = i + 1;
  return (i);
}

int	cd_home()
{
  char	*home;
  char	*user;
  char	*tmp;

  add_env("OLD_PWD", getcwd(NULL, 0));
  if ((tmp = my_getenv("USER")) == NULL)
    return (-2);
  home = malloc((strlen(tmp) + strlen("/home/")) * sizeof(home));
  if (home == NULL)
    return (-1);
  strcpy(home, "/home/");
  user = strcat(home, tmp);
  if (chdir(user) == -1)
    return (-2);
  free(user);
  return (0);
}

int	my_cd(char **arg, int fd[2])
{
  int	i;

  (void)fd;
  i = count_arg(arg);
  if (i > 2)
    return (EXIT_FAILURE);
  else if (i == 1)
    cd_home();
  else if (strcmp(arg[1], "-") == 0)
    cd_less();
  else
    {
      add_env("OLD_PWD", getcwd(NULL, 0));
      if (chdir(arg[1]) == -1)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
