/*
** env_addenv.c for env in /home/bonmar_v//Projets/SVN/42sh/src
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Sat May 19 14:55:43 2012 vincent bonmarchand
** Last update Sun May 20 22:08:48 2012 vincent bonmarchand
*/

#include <stdlib.h>
#include <string.h>

#include "env.h"

int	check_var(char *varname, char *content, char ***env)
{
  int	i;
  char	*tmp;

  tmp = malloc((strlen(varname) + strlen(content) + 1) * sizeof(tmp));
  if (tmp == NULL)
    return (-1);
  i = 0;
  while ((*env)[i] != NULL)
    {
      if (strncmp((*env)[i], varname, strlen(varname)) == 0 &&
	  (*env)[i][strlen(varname)] == '=')
	{
	  strcpy(tmp, varname);
	  tmp = strcat(tmp, "=");
	  tmp = strcat(tmp, content);
	  free(content);
	  (*env)[i] = tmp;
	  return (0);
	}
      i++;
    }
  return (-1);
}

int    add_newenv(char *varname, char *content, char ***env)
{
  int	i;
  char	*tmp;
  char	**tmp_env;

  i = 0;
  tmp = malloc((strlen(varname) + strlen(content) + 2) * sizeof(tmp));
  strcpy(tmp, varname);
  strcat(tmp, "=");
  strcat(tmp, content);
  tmp_env = malloc((count_elemenv(*env) + 2) * sizeof(*tmp_env));
  while ((*env)[i] != NULL)
    {
      if ((*env)[i + 1] == NULL)
	{
	  tmp_env[i] = (*env)[i];
	  tmp_env[i + 1] = tmp;
	}
      else
	tmp_env[i] = (*env)[i];
      i++;
    }
  tmp_env[i + 1] = NULL;
  *env = tmp_env;
  return (0);
}

int	add_env(char *varname, char *content)
{
  char	***tmp_env;

  tmp_env = get_envp();
  if (check_var(varname, content, tmp_env) == -1)
    {
      add_newenv(varname, content, tmp_env);
      free(content);
      return (0);
    }
  return (0);
}
