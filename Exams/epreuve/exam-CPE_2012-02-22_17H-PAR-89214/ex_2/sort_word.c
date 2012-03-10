/*
** sort_word.c for sort_word in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Feb 22 18:25:38 2012 exam_user
** Last update Wed Feb 22 19:05:38 2012 exam_user
*/

#include <stdlib.h>

static int	is_alphanum(char c)
{
  if (c <= ' ' || c > '~')
    return (0);
  return (1);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_showtab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i++]);
      if (tab[i] != '\0')
	my_putchar(' ');
    }
}

char		*my_strncpy(char *dst, char *src, int len)
{
  int		i;

  i = 0;
  while (i < len)
    {
      dst[i] = src[i];
      ++i;
    }
  dst[i] = '\0';
  return (dst);
}

char		*my_strndup(char *str, int len)
{
  char		*dup;

  dup = malloc(len * sizeof(str));
  my_strncpy(dup, str, len);
  return (dup);
}

int		my_strcmp(char *src, char *dst)
{
  int		i;

  i = 0;
  while (src[i] && dst[i] && src[i] == dst[i])
    ++i;
  return (src[i] - dst[i]);
}

int		count_words(char *str)
{
  int		i;
  int		word;
  int		cnt;

  i = 0;
  word = 0;
  while (str[i])
    {
      if (!is_alphanum(str[i]) && word == 1)
	{
	  word = 0;
	  ++cnt;
	}
      if (is_alphanum(str[i]))
	word = 1;
      ++i;
    }
  ++cnt;
  return (cnt);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  int		i;
  int		j;
  int		k;
  int		word;

  i = 0;
  j = 0;
  k = 0;
  word = 0;
  tab = malloc((count_words(str) + 1) * sizeof(*tab));  
  while (i <= my_strlen(str))
    {
      if (!is_alphanum(str[i]) && word == 1)
	{
	  tab[k++] = my_strndup(str + j, i - j);
	  word = 0;
	}
      if (is_alphanum(str[i]) && word == 0)
	j = i;
      if (is_alphanum(str[i]))
	word = 1;
      ++i;
    }
  tab[k] = '\0';
  return (tab);
}

char		*my_strlow(char *src)
{
  char		*str;
  int		i;

  i = 0;
  str = my_strndup(src, my_strlen(src));
  while (str[i])
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + ('a' - 'A');
      ++i;
    }
  return (str);
}

void		sort_word(char *str)
{
  char		**tab;
  char		*tmp;
  int		sort;
  int		i;

  tab = my_str_to_wordtab(str);
  sort = 1;
  i = 0;
  while (sort != 0 && tab[i])
    {
      if (tab[i] && tab[i + 1] && my_strcmp(my_strlow(tab[i]), my_strlow(tab[i + 1])) > 0)
	{
	  tmp = tab[i];
	  tab[i] = tab[i + 1];
	  tab[i + 1] = tmp;
	  sort = 1;
	  i = 0;
	}
      else
	++i;
    }
  my_showtab(tab);
  return;
}

int		main(int ac, char **av)
{
  if (ac == 2)
    sort_word(av[1]);
  my_putchar('\n');
  return (0);
}
