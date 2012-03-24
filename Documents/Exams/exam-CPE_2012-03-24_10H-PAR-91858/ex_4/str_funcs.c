/*
** str_funcs.c for ord_alphlonmg in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 24 10:42:32 2012 exam_user
** Last update Sat Mar 24 11:49:29 2012 exam_user
*/

#include <stdlib.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

int		my_strcmp(char *src, char *dst)
{
  int		i;

  i = 0;
  while (src[i] == dst[i])
    ++i;
  return (src[i] - dst[i]);
}

int		my_strncmp(char *src, char *dst, int len)
{
  int		i;

  i = 0;
  while (i < len && src[i] == dst[i])
    ++i;
  return (src[i] - dst[i]);
}

char		*my_strcpy(char *dst, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dst[i] = src[i];
      ++i;
    }
  dst[i] = '\0';
  return (dst);
}

char		*my_strncpy(char *dst, char *src, int len)
{
  int		i;

  i = 0;
  while (i < len && src[i])
    {
      dst[i] = src[i];
      ++i;
    }
  dst[i] = '\0';
  return (dst);
}

char		*my_strdup(char *src)
{
  char		*dup;

  dup = malloc((my_strlen(src) + 1) * sizeof(*dup));
  my_strcpy(dup, src);
  return (dup);
}

char		*my_strndup(char *src, int len)
{
  char		*dup;

  dup = malloc(len * sizeof(*dup));
  my_strncpy(dup, src, len);
  return (dup);
}

char		*my_strlow(char *src)
{
  int		i;
  char		*str;

  i = 0;
  str = my_strdup(src);
  while (str[i])
    {
      if (is_uper(str[i]))
	str[i] = str[i] - ('a' - 'A');
      ++i;
    }
  return (str);
}
