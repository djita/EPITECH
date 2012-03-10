/*
** str_funcs.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 28 15:32:51 2011 lyoma guillou
** Last update Mon Feb 13 17:05:11 2012 lyoma guillou
*/

#include <stdlib.h>
#include "my_sh.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return(dest);
}

char		*my_strcat(char *dst, char *src)
{
  int		len;

  len = my_strlen(dst);
  my_strcpy(dst + len, src);
  return (dst);
}

char		*my_strdup(char *src)
{
  char		*dst;

  if ((dst = malloc((my_strlen(src)) * sizeof(*dst))) == NULL)
    return (NULL);
  my_strcpy(dst, src);
  return (dst);
}

int		my_strncmp(char *src, char *dst, int len)
{
  int		i;

  i = 0;
  while (i < (len - 1) && src[i] == dst[i])
    i++;
  return (src[i] - dst[i]);
}
