/*
** str_funcs.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 28 15:32:51 2011 lyoma guillou
** Last update Mon Feb 20 16:17:31 2012 lyoma guillou
*/

#include <my_sh.h>

char		*my_strcpy(char *dest, char *src)
{
  int		i;
  int		len;

  i = 0;
  len = my_strlen(src);
  while (i <= len) 
    {
      dest[i] = src[i];
      ++i;
    }
  return (dest);
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

  dst = xmalloc((my_strlen(src)) * sizeof(*dst));
  my_strcpy(dst, src);
  return (dst);
}

int		my_strcmp(char *src, char *dst)
{
  int		i;

  i = 0;
  while (src[i] && dst[i] && src[i] == dst[i])
    ++i;
  return (src[i] - dst[i]);
}

int		my_strncmp(char *src, char *dst, int len)
{
  int		i;

  i = 0;
  while (i < (len - 1) && src[i] == dst[i])
    ++i;
  return (src[i] - dst[i]);
}
