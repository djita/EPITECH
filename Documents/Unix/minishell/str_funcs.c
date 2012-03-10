/*
** str_funcs.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 28 15:32:51 2011 lyoma guillou
** Last update Mon Jan 16 15:51:52 2012 lyoma guillou
*/

#include <stdlib.h>
#include "my_sh.h"

char	*my_strcat(char *str, char *ptr)
{
  char	*src;
  int	i;

  i = 0;
  if ((src = malloc((my_strlen(str) + my_strlen(ptr)) * sizeof(*src))) == NULL)
    return (NULL);
  while (i < (my_strlen(str) + my_strlen(ptr)))
    {
      if (i >= my_strlen(str))
	src[i] = ptr[i - my_strlen(str)];
      else
	src[i] = str[i];
      i = i + 1;
    }
  src[i] = '\0';
  return (src);
}

char	*my_strdup(char *src)
{
  char	*dst;
  int	i;

  i = 0;
  if ((dst = malloc((my_strlen(src) + 1) * sizeof(*dst))) == NULL)
    return (NULL);
  while (i < my_strlen(src))
    {
      dst[i] = src[i];
      i++;
    }
  return (dst);
}

char	*my_strset(char *str, int lim)
{
  int	i;

  i = 0;
  while (i < lim)
    {
      str[i] = '\0';
      i++;
    }
  return (str);
}

int	my_strcmp(char *src, char *dst)
{
  int	i;

  i = 0;
  while (src[i] && dst[i] && src[i] == dst[i])
    i++;
  return (src[i] - dst[i]);
}

int	my_strncmp(char *src, char *dst, int len)
{
  int	i;

  i = 0;
  while (i < (len - 1) && src[i] == dst[i])
    i++;
  return (src[i] - dst[i]);
}
