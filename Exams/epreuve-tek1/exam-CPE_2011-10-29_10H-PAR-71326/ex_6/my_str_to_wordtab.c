/*
** my_str_to_wordtab.c for my_str_to_word_tab in /exam//rendu/ex_6
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 29 11:02:08 2011 exam_user
** Last update Sat Oct 29 12:22:31 2011 exam_user
*/

#include <stdlib.h>

int	word_len(char *str, int cursor)
{
  int	i;

  i = 0;
  while (char_alpha(str[cursor + i]) == 1)
    i++;
  return (i);
}

int	word_to_cell(char *tab, char *str, int cursor)
{
  int	i;

  i = 0;
  while (char_alpha(str[cursor + i]) != 0)
    {
      tab[i] = str[cursor + i];
      i++;
    }
  tab[i] = '\0';
  return (cursor + i);
}

int	count_words(char *str)
{
  int	i;
  int	word;
  int	cnt;

  i = 0;
  word = 0;
  cnt = 0;
  while (i < my_strlen(str))
    {
      if (char_alpha(str[i]) == 1)
	word = 1;
      if (char_alpha(str[i]) == 0 && word == 1)
	{
	  cnt++;
	  word = 0;
	}
      i++;
    }
  return (cnt);
}

char	**my_str_to_wordtab(char *str)
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
      if (char_alpha(str[cursor]) == 1)
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
