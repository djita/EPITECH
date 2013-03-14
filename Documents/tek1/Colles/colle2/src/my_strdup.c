/*
** my_strdup.c for reader in /home/guillo_e//Documents/working/colles/colle2
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Apr 24 19:47:42 2012 lyoma guillou
** Last update Tue Apr 24 20:19:01 2012 lyoma guillou
*/

#include <stdlib.h>
#include "my.h"

char		*my_strdup(char *src)
{
  char		*dup;
  int		len;

  len = my_strlen(src);
  if ((dup = malloc(len + 1 * sizeof(*dup))) == NULL)
    return (NULL);
  my_strcpy(dup, src);
  return (dup);
}

char		*my_strndup(char *src, int len)
{
  char		*dup;

  if ((dup = malloc(len + 1 * sizeof(*dup))) == NULL)
    return (NULL);
  my_strncpy(dup, src, len);
  return (dup);
}
