/*
** tokenise.c for 42sh in /home/benjab_p//Dropbox/Documents/sys_u/42sh/42sh/src
** 
** Made by phedrik benjabria
** Login   <benjab_p@epitech.net>
** 
** Started on  Wed May  2 19:37:03 2012 phedrik benjabria
** Last update Fri May 11 12:29:17 2012 lyoma guillou
*/

#include <unistd.h>

#include "42sh.h"

static int	_is_quote(char c)
{
  if (c == '"' || c == '\'' || c == '`')
    return (c);
  return (0);
}

static char	*_get_sub_str(char *str, size_t len, t_token_list **token)
{
  size_t	i;
  char		*ptr_start;
  char		quote;

  i = 0;
  quote = _is_quote(str[i]);
  ptr_start = &str[++i];
  while (str[i] != quote && str[i] && i < len)
    ++i;
  str[i++] = '\0';
  add_to_l2c(ptr_start, token);
  return (&str[i]);
}

t_token_list	*tokenise(char *str, size_t len)
{
  t_token_list	*token;
  size_t	i;
  char		*ptr_start;

  i = 0;
  token = NULL;
  while (i < len)
    {
      if (str[i] > ' ' && str[i] < '~')
	{
	  ptr_start = str + i;
	  if (_is_quote(str[i]))
	    str = _get_sub_str(&str[i], len, &token);
	  else
	    {
	      while (str[i] > ' ' && str[i] < '~' && i < len)
		++i;
	      str[i++] = '\0';
	      add_to_l2c(ptr_start, &token);
	    }
	}
      else
	i++;
    }
  return (token);
}
