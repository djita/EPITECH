/*
** str_funcs.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 28 15:32:51 2011 lyoma guillou
** Last update Tue Jan 31 17:57:19 2012 lyoma guillou
*/

#include <stdlib.h>
#include "my_sh.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++]);
  return (i);
}

char	*my_strncat(char *dst, const char *src, int n)
{
  int	len;
  int	i;

  i = -1;
  len = my_strlen(dst);
  while (++i < n && src[i] != '\0')
    dst[len + i] = src[i];
  dst[len + i] = '\0';
  return (dst);
}


char	*my_strdup(char *src)
{
  char	*dst;
  int	i;

  i = -1;
  if ((dst = malloc((my_strlen(src) + 1) * sizeof(*dst))) == NULL)
    return (NULL);
  while (++i < my_strlen(src))
    dst[i] = src[i];
  return (dst);
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
