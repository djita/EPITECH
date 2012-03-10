/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/guillo_e//afs/rendu/piscine/Jour_08/ex_04
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct 13 20:00:09 2011 lyoma guillou
** Last update Mon Oct 31 17:57:05 2011 lyoma guillou
*/

#include <stdlib.h>

int     is_alphnum(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	count_words(char *str)
{
  int	i;
  int	word;
  int	count;

  i = 0;
  word = 0;
  count = 1;
  while (str[i])
    {
      if (is_alphnum(str[i]) == 1)
	word = 1;
      if (is_alphnum(str[i]) != 1 && word == 1)
	{
	  word = 0;
	  count++;
	}
      i++;
    }
  return (count);
}

int	tab_fill(char *dup, char *str, int cursor, int limit)
{
  int	i;

  i = 0;
  while (cursor < limit && is_alphnum(str[cursor]) == 1)
    {
      dup[i] = str[cursor];
      i++;
      cursor++;
    }
  dup[i] = '\0';
  return (cursor + 1);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	x;

  i = 0;
  j = 0;
  x = 0;
  tab = malloc((count_words(str) + 1) * sizeof(*tab));
  if (tab == NULL)
    return (NULL);
  while (str[i])
    {
      if (is_alphnum(str[i]) != 1)
        {
          tab[x] = malloc((i - j + 1) * sizeof(**tab));
	  if (tab[x] == NULL)
	    return (NULL);
          j = tab_fill(tab[x], str, j, i);
          x++;
        }
      i++;
    }
  tab[x] = '\0';
  return (tab);
}
