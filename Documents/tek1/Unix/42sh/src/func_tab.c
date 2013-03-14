/*
** func_tab.c for func in /home/bonmar_v//Projets/SVN/42sh/src
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Fri May 18 21:21:10 2012 vincent bonmarchand
** Last update Sun May 20 20:57:51 2012 vincent bonmarchand
*/

#include <stdlib.h>
#include <string.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

int	count_elemenv(char **arg)
{
  int	i;

  i = 0;
  while (arg[i] != NULL)
    i++;
  return (i);
}

char	*getname(char **arg)
{
  int	i;

  i = 0;
  while (arg[i] != NULL)
    {
      if (strcmp(arg[i], "-u") == 0)
	if (arg[i + 1] != NULL)
	  return (arg[i + 1]);
      i++;
    }
  return (NULL);
}
