/*
** sort_word.c for  in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Apr 20 09:59:50 2012 exam_user
** Last update Fri Apr 20 11:00:55 2012 exam_user
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

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

int		is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

char		*my_lowerstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + ('a' - 'A');
      ++i;
    }
  return (str);
}

char		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    ++i;
  return (s1[i] - s2[i]);
}

char		*my_strcpy(char *dst, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dst[i] = src[i];
      ++i;
    }
  dst[i] = '\0';
  return (dst);
}

char		*my_strncpy(char *dst, char *src, int len)
{
  int		i;

  i = 0;
  while (i < len && src[i])
    {
      dst[i] = src[i];
      ++i;
    }
  dst[i] = '\0';
  return (dst);
}

char		*my_strdup(char *src)
{
  char		*dup;

  dup = malloc(my_strlen(src) * sizeof(*dup));
  my_strcpy(dup, src);
  return (dup);
}

char		*get_next_word(char *str)
{
  char		*dup;
  int		i;

  i = 0;
  while (str[i] && str[i] > ' ')
    ++i;
  dup = malloc(i * sizeof(*dup));
  my_strncpy(dup, str, i);
  while (str[i] && str[i] <= ' ')
    ++i;
  my_strcpy(str, str + i);
  return ((dup[0] != '\0') ? dup : NULL);
}

int		count_words(char *str)
{
  int		i;
  int		cnt;

  i = 0;
  cnt = 0;
  while (str[i])
    {
      if (is_alpha(str[i]) && str[i + 1] <= ' ')
	++cnt;
      ++i;
    }
  return (cnt);
}

char		**strtoword(char *str)
{
  char		**tab;
  char		*word;
  int		i;

  i = 0;
  tab = malloc((count_words(str) + 1) * sizeof(*tab));
  while (word = get_next_word(str))
    {
      tab[i] = word;
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}

void		sort_word(char *str)
{
  char		**tab;
  char		*tmp;
  int		i;
  int		show;

  i = 0;
  tab = strtoword(str);
  while (tab[i])
    {
      if (tab[i] && tab[i + 1] && my_strcmp(my_lowerstr(my_strdup(tab[i])), my_lowerstr(my_strdup(tab[i + 1]))) > 0)
	{
	  tmp = tab[i];
	  tab[i] = tab[i + 1];
	  tab[i + 1] = tmp;
	  i = 0;
	}
      else
	++i;
    }
  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      if (i < my_tablen(tab) - 1)
	my_putchar(' ');
      ++i;
    }
}

int		main(int ac, char **av)
{
  if (ac == 2)
    sort_word(av[1]);
  my_putchar('\n');
  return (0);
}
