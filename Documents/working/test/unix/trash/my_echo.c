/*
** my_echo.c for 42sh in /home/guillo_e//Documents/working/42sh
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri May 11 16:49:16 2012 lyoma guillou
** Last update Sat May 12 16:32:59 2012 lyoma guillou
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "echo.h"

static const	t_symbol g_echo[]=
  {
    { "\\", '\\' },
    { "a", '\a' },
    { "b" , '\b' },
    { "c", '\0' },
    { "e", '\e' },
    { "f", '\f' },
    { "n", '\n' },
    { "r", '\r' },
    { "t", '\t' },
    { "v", '\v' },
    { NULL, 0 }
  };

static void	_check_op(char *str, t_e_echo *flag)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 'e')
	*flag &= ~DO_BACKSLASH;
      if (str[i] == 'E')
	*flag |= DO_BACKSLASH;
      else if (str[i] == 'n')
	*flag |= NO_NEWLINE;
      ++i;
    }
}

static char	_get_symbol(char *src)
{
  int		i;

  i = 0;
  while (strncmp(src, g_echo[i].pat, strlen(g_echo[i].pat)))
    ++i;
  if (!g_echo[i].pat)
    return (0);
  return (g_echo[i].sym);
}

static char	*_parse_string(char *src, int len)
{
  char		*str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  str = malloc((len + 1) * sizeof(*str));
  if (!str)
    return (NULL);
  bzero(str, len);
  while (src[i])
    {
      if (src[i] == '\\')
	{
	  ++i;
	  str[j] = _get_symbol(src + i);
	  ++i;
	  ++j;
	}
      str[j] = src[i];
      ++i;
      ++j;
    }
  return (str);
}

void		my_echo(char **arg)
{
  char		*str;
  int		i;
  t_e_echo	flag;

  i = 1;
  flag = 0;
  while (arg[i + 1])
    {
      if (arg[i][0] == '-')
	_check_op(arg[i] + 1, &flag);
      else
	{
	  str = (flag & DO_BACKSLASH) ? strdup(arg[i]) 
	    : _parse_string(arg[i], strlen(arg[i]));
	  fprintf(stdout, "%s ", str);
	  free(str);
	}
      ++i;
    }
  str = (flag & DO_BACKSLASH) ? strdup(arg[i]) 
    : _parse_string(arg[i], strlen(arg[i]));
  fprintf(stdout, "%s", str);
  free(str);
  fprintf(stdout, (!(flag & NO_NEWLINE)) ? "\n" : "");
}

