/*
** ord_alphlong.c for ord_alphlong in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 24 10:23:40 2012 exam_user
** Last update Sat Mar 24 11:52:55 2012 exam_user
*/

#include <stdlib.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  write(1, str, i);
}

int		count_word(char *str)
{
  int		i;
  int		cnt;

  i = 0;
  cnt = 0;
  while (str[i])
    {
      if (is_alpha(str[i]) && (i == 0 || is_sep(str[i - 1])))
	++cnt;
      ++i;
    }
  return (cnt);
}

char		*get_next_word(char *str)
{
  char		*ret;
  int		i;

  i = 0;
  while (str[i] && is_alpha(str[i]))
    ++i;
  ret = malloc(i * sizeof(*ret));
  my_strncpy(ret, str, i);
  my_strcpy(str, (str[i] == '\0') ? str + i : str + i + 1);
  return ((ret[0] == '\0') ? 0 : ret);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  char		*word;
  int		i;

  tab = malloc((count_word(str) + 1) * sizeof(*tab));
  i = 0;
  while ((word = get_next_word(str)))
    {
      tab[i] = word;
      ++i;
    }
  tab[i] = '\0';
  return (tab);
}

int		sort_by_len(char **tab)
{
  int		i;
  char		*tmp;
  int		len;

  i = 0;
  while (tab[i])
    {
      if (tab[i] && tab[i + 1] && my_strlen(tab[i]) > my_strlen(tab[i + 1]))
	{
	  tmp = tab[i];
	  tab[i] = tab[i + 1];
	  tab[i + 1] = tmp;
	  i = 0;
	}
      else
	++i;
    }
  return (my_strlen(tab[i - 1]) + 1);
}

void		ord_alphlong(char *str)
{
  char		**tab;
  char		*tmp;
  int		len;
  int		max;
  int		i;

  len = 0;
  i = 0;
  tab = my_str_to_wordtab(str);
  max = sort_by_len(tab);
  while (len < max)
    {
      i = 0;
      while (tab[i])
	{
	  if (tab[i + 1] && my_strlen(tab[i]) == len && my_strlen(tab[i + 1]) == len)
	    if (tab[i + 1] && my_strcmp(my_strlow(tab[i]), my_strlow(tab[i + 1])) > 0)
	      {
		tmp = tab[i];
		tab[i] = tab[i + 1];
		tab[i + 1] = tmp;
		i = 0;
	      }
	  ++i;
	}
      ++len;
    }
  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      if (!tab[i + 1] || my_strlen(tab[i + 1]) > my_strlen(tab[i]))
	my_putchar('\n');
      else
	my_putchar(' ');
      ++i;
    }
}

int		main(int ac, char **av)
{
  char		*str;

  if (ac == 2)
    {
      str = av[1];
      ord_alphlong(str);
    }
  else
    my_putchar('\n');
  return (0);
}
