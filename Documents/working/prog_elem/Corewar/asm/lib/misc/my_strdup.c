/*
** my_strdup.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Thu Jan 19 17:49:23 2012 louis duverdier
** Last update Fri Jan 20 10:42:47 2012 louis duverdier
*/

#include <my.h>

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
