/*
** my_str_to_wordtab.c for my_sh in /home/guillo_e//Documents/Igraph/fdf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 21 10:31:24 2011 lyoma guillou
** Last update Mon Feb 13 17:05:11 2012 lyoma guillou
*/

#include <stdlib.h>
#include "my_sh.h"

static int	is_alphanum(char c)
{
  if (c > ' ' && c <= '~')
    return (1);
  return (0);
}

static int	word_len(char *str, int cursor)
{
  int	i;

  i = 0;
  while (is_alphanum(str[cursor + i]) == 1)
    i++;
  return (i);
}

static int	word_to_cell(char *tab, char *str, int cursor)
{
  int	i;

  i = 0;
  while (is_alphanum(str[cursor + i]) == 1)
    {
      tab[i] = str[cursor + i];
      i++;
    }
  tab[i] = '\0';
  return (cursor + i);
}

static int	count_words(char *str)
{
  int	i;
  int	word;
  int	cnt;

  i = 0;
  word = 0;
  cnt = 0;
  while (i < my_strlen(str))
    {
      if (str[i] == ' ')
	word = 1;
      if (is_alphanum(str[i]) == 0 && word == 1)
	{
	  cnt++;
	  word = 0;
	}
      i++;
    }
  return (cnt);
}

char		**my_str_to_wordtab(char *str)
{
  int	cursor;
  int	x;
  char	**tab;

  cursor = 0;
  x = 0;
  tab = malloc((count_words(str) + 1) * sizeof(*tab));
  if (tab == NULL)
    return (NULL);
  while (cursor < my_strlen(str))
    {
      if (is_alphanum(str[cursor]) == 1)
	{
	  tab[x] = malloc((word_len(str, cursor) + 1) * sizeof(**tab));
	  if (tab[x] == NULL)
	    return (NULL);
	  cursor = word_to_cell(tab[x], str, cursor);
	  x++;
	}
      cursor++;
    }
  tab[x] = '\0';
  return (tab);
}
