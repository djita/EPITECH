/*
** built_echo.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri May 11 16:49:16 2012 lyoma guillou
** Last update Sun May 20 22:14:21 2012 mickael falck
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "env.h"
#include "echo.h"

#define GETBUF(x) x & NO_NEWLINE ? "" : "\n"
#define GETLEN(x) x & NO_NEWLINE ? 0 : 1

static const	t_symbol g_echo[]=
  {
    { "\\", '\\'},
    { "a", '\a'},
    { "b" , '\b'},
    { "c", '\0'},
    { "e", '\033'},
    { "f", '\f'},
    { "n", '\n'},
    { "r", '\r'},
    { "t", '\t'},
    { "v", '\v'},
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
  while (g_echo[i].pat && strncmp(src, g_echo[i].pat, strlen(g_echo[i].pat)))
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
  bzero(str, len + 1);
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

static int	_print_arg(char *src, int fd[2])
{
  int		ret;
  char		*str;
  t_e_echo	flag;

  flag = 0;
  ret = 0;
  str = NULL;
  if (src != NULL)
    str = (flag & DO_BACKSLASH) ? strdup(src)
      : _parse_string(src, strlen(src));
  if (str != NULL)
    {
      ret = (write(fd[1], str, strlen(str)) < 0);
      free(str);
    }
  return (ret);
}

int		my_echo(char **arg, int fd[2])
{
  int		i;
  int		ret;
  t_e_echo	flag;

  i = 1;
  flag = 0;
  ret = 0;
  while (i < count_elemenv(arg))
    {
      if (arg[i][0] == '-')
	_check_op(arg[i] + 1, &flag);
      else
	ret |= _print_arg(arg[i], fd);
      if (arg[i + 1])
	ret |= (write(fd[1], " ", 1));
      ++i;
    }
  ret |= _print_arg(arg[i], fd);
  ret |= (write(fd[1], GETBUF(flag), GETLEN(flag)) < 0);
  return ((ret) ? EXIT_FAILURE : EXIT_SUCCESS);
}

