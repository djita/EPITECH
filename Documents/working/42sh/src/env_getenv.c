/*
** env_getenv.c for env in /home/bonmar_v//Projets/SVN/42sh/src
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Sat May 19 12:12:06 2012 vincent bonmarchand
** Last update Sat May 19 16:50:22 2012 vincent bonmarchand
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "env.h"

char	*my_getenv(char *varname)
{
  int	i;
  char	***env;

  i = 0;
  env = get_envp();
  if (varname == NULL)
    return (NULL);
  while ((*env)[i] != NULL)
    {
      if (strncmp((*env)[i], varname, strlen(varname)) == 0 &&
	  (*env)[i][strlen(varname)] == '=')
	return ((*env)[i] + (strlen(varname) + 1));
      i++;
    }
  return (NULL);
}
