/*
** str_to_wordtab.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun May 20 21:43:00 2012 lyoma guillou
** Last update Sun May 20 23:00:16 2012 lyoma guillou
*/

#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include "str_to_wordtab.h"

static int	_is_quote(char c)
{
  return ((c == '"' || c == '\''));
}

static int	_is_sep(char c)
{
  return ((c <= ' '));
}

static int	_count_pattern(char *str)
{
  int		i;
  int		cnt;
  int		flag;

  i = 0;
  flag = 1;
  cnt = 0;
  while (str[i])
    {
      if (_is_quote(str[i]))
	flag = -flag;
      if (flag == 1 && (str[i] == ' ' || _is_quote(str[i])))
	++cnt;
      ++i;
    }
  return (cnt);
}

static char	*_get_next_pattern(char *str)
{
  char		*buf;
  t_word_flag	flag;
  int		i;

  i = 0;
  flag.match = 1;
  flag.cnt = 0;
  flag.sym = 0;
  flag.tmp = strdup(str);
  while (flag.tmp[i] && (flag.tmp[i] > ' ' || flag.sym != 0 || flag.match < 0))
    {
      if (_is_quote(flag.tmp[i]) && (!flag.sym || flag.sym == flag.tmp[i]))
	  {
	    flag.match = -flag.match;
	    flag.sym = (!flag.sym) ? flag.tmp[i] : 0;
	    ++flag.cnt;
	  }
      ++i;
    }
  buf = (flag.cnt == 2) ? strndup(flag.tmp + 1, i - 2) : strndup(flag.tmp, i);
  while (flag.tmp[i] && _is_sep(flag.tmp[i]))
    ++i;
  strcpy(str, flag.tmp + i);
  free(flag.tmp);
  return ((buf[0] != '\0') ? buf : NULL);
}

char		**str_to_wordtab(char *src)
{
  char		**tab;
  char		*buf;
  char		*str;
  int		len;
  int		i;

  str = strdup(src);
  len = _count_pattern(str);
  if (len == 0)
    len = 1;
  if (!(tab = malloc((len + 1) * sizeof(*tab))))
    return (NULL);
  i = 0;
  while ((buf = _get_next_pattern(str)) && i < len)
    {
      tab[i] = buf;
      ++i;
    }
  tab[i] = NULL;
  free(str);
  return (tab);
}
