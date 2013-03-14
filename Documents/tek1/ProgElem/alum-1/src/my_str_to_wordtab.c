/*
** my_str_to_wordtab.c for alum1 in /home/guillo_e//Documents/working/prog_elem/Alum-1
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb  6 14:02:35 2012 lyoma guillou
** Last update Mon Feb  6 17:54:10 2012 lyoma guillou
*/

#include <alum.h>

static int	word_len(char *str, int cursor)
{
  int		i;

  i = 0;
  while (char_alpha(str[cursor + i]) == 1)
    i++;
  return (i);
}

static int	word_to_cell(char *tab, char *str, int cursor)
{
  int		i;

  i = 0;
  while (char_alpha(str[cursor + i]) != 0)
    {
      tab[i] = str[cursor + i];
      i++;
    }
  tab[i] = '\0';
  return (cursor + i);
}

static int	count_words(char *str)
{
  int		i;
  int		word;
  int		cnt;

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

char		**my_str_to_wordtab(char *str)
{
  int		cursor;
  int		x;
  char		**tab;

  cursor = 0;
  x = 0;
  tab = xmalloc((count_words(str) + 1) * sizeof(*tab));
  while (cursor < my_strlen(str))
    {
      if (char_alpha(str[cursor]) == 1)
	{
          tab[x] = xmalloc((word_len(str, cursor) + 1) * sizeof(**tab));
          cursor = word_to_cell(tab[x], str, cursor);
          x++;
	}
      cursor++;
    }
  tab[x] = '\0';
  return (tab);
}
