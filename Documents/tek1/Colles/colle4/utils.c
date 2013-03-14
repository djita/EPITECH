/*
** utils.c for utils in /home/deleta_m//Projets/Colles/Colle_4
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May  7 19:34:27 2012 marc deletang
** Last update Mon May  7 21:21:26 2012 lyoma guillou
*/

#include "lib.h"

int		my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  xwrite(1, str, my_strlen(str));
}

char		*my_strcpy(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str2[i])
    {
      str1[i] = str2[i];
      i++;
    }
  return (str1);
}

int		my_strcmp(char *str1, char *str2)
{
  int		i;

  i = 0;
  if (my_strlen(str1) != my_strlen(str2))
    return (1);
  while (str1[i])
    {
      if (str1[i] != str2[i])
	return (1);
      i++;
    }
  return (0);
}

char		*my_strdup(char *str)
{
  char		*dup;

  dup = xmalloc(my_strlen(str) + 1);
  dup = my_strcpy(dup, str);
  return (dup);
}
