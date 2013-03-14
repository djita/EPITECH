/*
** opt_check.c for my_ls in /home/guillo_e//working/unix/my_ls
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec  3 23:00:30 2011 lyoma guillou
** Last update Sun Dec  4 06:32:25 2011 lyoma guillou
*/

#include <stdlib.h>
#include "my_ls.h"

int		is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

int		is_record(char c)
{
  static char	tab[256];
  int		val;

  val = (int) c;
  if (tab[val])
    return (1);
  tab[val] = 1;
  return (0);
}

char		*set_string(char *src)
{
  int		i;

  i = 0;
  while (i < 256)
    {
      src[i] = '\0';
      i = i + 1;
    }
  return (src);
}

char		*opt_check(char *str, char *opt)
{
  int		i;
  int		k;

  i = 0;
  k = 0;
  while (str[i])
    {
      if (!is_record(str[i]) && is_alpha(str[i]))
	{	    
	  opt[k] = str[i];
	  k = k + 1;
	}
      i = i + 1;
    }
  return (opt);
}

char		*opt_arg(char **av)
{
  int		i;
  int		len;
  char		*opt;

  i = 1;
  if ((opt = malloc(256 * sizeof(*opt))) == NULL)
    return (NULL);
  opt = set_string(opt);
  while (av[i])
    {
      len = my_strlen(opt);
      if (av[i][0] == '-')
	opt = opt_check(av[i], opt + len + 1);
      i = i + 1;      
    }
  return (opt);
}
