/*
** rev_wstr.c for rev_wstr in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb 21 18:03:59 2011 exam_user
** Last update Mon Feb 21 19:17:29 2011 exam_user
*/

#include <stdlib.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

int	my_word_count(char *str)
{
  int	i;
  int	x;
  int	w;

  x = 0;
  i = 0;
  w = 0;
  while (str[i])
    {
      if (str[i] > ' ')
	x = 1;
      if (x != 0 && str[i] <= ' ')
	{
	  x = 0;
	  w++;
	}
      i++;
    }
  return (w);
}

char	**tabfill(char **tab, char *str)
{
  int	x;
  int	y;
  int	i;

  x = 0;
  y = 0;
  i = 0;
  while (tab[y])
    {
      x = 0;
      while (str[i] > ' ')
      {
	my_putstr("Charfill\n");
	tab[y][x] = str[i];
	x++;
	i++;
      }
      y++;
      my_putstr("Tab line\n");
    }
  my_putstr("tabfill\n");
  return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	w;
  int	i;
  int	z;

  i = 0;
  z = 0;
  w = my_word_count(str);
  tab = malloc((w + 1) * sizeof(char *));
  while (str[i])
    {
      while (str[i] > ' ')
	{
	  w++;
	  i++;
	}
      *tab[z] = malloc((w + 1) * sizeof(char));
      z++;
      if (str[i] <= ' ')
	w = 0;
      i++;
    }
  tab[z] = '\0';
  return (tab);
}

int	main(int argc, char **argv)
{
  char	**tab;
  int	x;
  int	y;

  if (argc == 2)
    {
      tab = tabfill(my_str_to_wordtab(argv[1]), argv[1]);
      while (tab[y])
	y++;
      y = y - 1;
      while (tab[y])
	{
	  my_putstr(tab[y]);
	  y--;
	}
    }
  my_putstr("\n");
}
