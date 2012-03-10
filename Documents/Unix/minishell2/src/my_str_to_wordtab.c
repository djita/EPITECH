/*
** my_str_to_wordtab.c for my_sh in /home/guillo_e//Documents/Igraph/fdf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 21 10:31:24 2011 lyoma guillou
** Last update Sat Mar  3 21:28:35 2012 lyoma guillou
*/

#include <my_sh.h>

static int	_is_alphanum(char c)
{
  if (c > ' ' && c <= '~')
    return (1);
  return (0);
}

static int	_word_len(char *str, int cursor)
{
  int	i;

  i = 0;
  while (_is_alphanum(str[cursor + i]) == 1)
    i++;
  return (i);
}

static int	_word_to_cell(char *tab, char *str, int cursor)
{
  int	i;

  i = 0;
  while (_is_alphanum(str[cursor + i]) == 1)
    {
      tab[i] = str[cursor + i];
      i++;
    }
  tab[i] = '\0';
  return (cursor + i);
}

static int	_count_words(char *str)
{
  int		i;
  int		word;
  int		cnt;
  int		len;

  i = 0;
  word = 0;
  cnt = 0;
  len = my_strlen(str);
  while (i < len)
    {
      if (str[i] == ' ')
	word = 1;
      if (_is_alphanum(str[i]) == 0 && word == 1)
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
  int		cursor;
  int		x;
  int		len;
  char		**tab;

  cursor = 0;
  x = 0;
  len = my_strlen(str);
  tab = xmalloc((_count_words(str) + 1) * sizeof(*tab));
  my_memset(tab, 0, _count_words(str) + 1);
  while (cursor < len)
    {
      if (_is_alphanum(str[cursor]) == 1)
	{
	  tab[x] = xmalloc((_word_len(str, cursor) + 1) * sizeof(**tab));
	  cursor = _word_to_cell(tab[x], str, cursor);
	  x++;
	}
      cursor++;
    }
  return (tab);
}