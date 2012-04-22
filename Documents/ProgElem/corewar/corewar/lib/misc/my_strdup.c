/*
** my_strdup.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Wed Mar 14 16:06:25 2012 louis duverdier
*/

#include "my.h"

char	*my_strdup(const char *str)
{
  char	*cpy;

  cpy = xmalloc((my_strlen(str) + 1) * sizeof(char));
  my_strcpy(cpy, str);
  return (cpy);
}

char	*my_strndup(const char *str, int len)
{
  char	*cpy;

  cpy = xmalloc((len + 1) * sizeof(char));
  my_strncpy(cpy, str, len);
  return (cpy);
}
