/*
** file_check.c for my_ls in /home/guillo_e//working/unix/my_ls
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Dec  4 01:16:19 2011 lyoma guillou
** Last update Sun Dec  4 05:20:27 2011 lyoma guillou
*/

#include <stdlib.h>
#include "my_ls.h"

int		is_file_range(char c)
{
  if (c >= ' ' && c <= '~')
    return (1);
  return (0);
}

char		*recover_path(char *dst, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dst[i] = src[i];
      i = i + 1;
    }
  dst[i] = '\0';
  return (dst);
}

char		**path_name(int ac, char **av)
{
  char		**tab;
  int		i;
  int		k;

  i = 1;
  k = 0;
  if ((tab = malloc(ac * sizeof(*tab))) == NULL)
    return (NULL);
  while (av[i])
    {
      if (av[i][0] != '-')
	{
	  if ((tab[k] = malloc(my_strlen(av[i]) * sizeof(**tab))) == NULL)
	    return (NULL);
	  tab[k] = recover_path(tab[k], av[i]);
	  k = k + 1;
	}
      i = i + 1;
    }
  tab[k] = '\0';
  return (tab);
}
