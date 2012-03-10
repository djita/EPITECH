/*
** ord_alphlong.c for ord_alphlong in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 18 11:51:03 2010 exam_user
** Last update Sat Dec 18 13:14:28 2010 exam_user
*/

#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	ord_tab_maker(char *str)
{
  char	**tab;
  int	i;
  int	x;
  int	l;

  i = 0;
  x = 0;
  l = 0;
  while (str[i])
    {
      if (str[i] == ' ')
	  x++;
      i++;
    }
  tab = malloc((x + 2) * sizeof(*tab));
  tab[x + 2] = '\0';
  str_tab(str, tab);
}

int	str_tab(char *str, char**tab)
{
  int	i;
  int	x;
  int	l;

  i = 0;
  x = 0;
  l = 0;
  while (str[i] && tab[x])
    {
      if(str[i] == ' ')
	{
	  tab[x] = malloc((i + 1 - l) * sizeof(**tab));
	  x++;
	  l = l + i;
	}
      i++;
    }
  str_to_tab(str, tab);
}

int	str_to_tab(char *str, char **tab)
{
  int	i;
  int	x;
  int	l;

  i = 0;
  x = 0;
  l = 0;
  while (str[i])
    {
      while (str[i] != ' ' || str[i] != '\0')
	{
	  tab[x][l] = str[i];
	  l++;
	  i++;
	}
      tab[x][l] = '\0';
      i++;
    }
  ord_alphlong(tab);
}

int	main(int argc, char **argv)
{
  if (argv[2])
    {
      my_putchar('\n');
      return;
    }
  if (argv[1])
    ord_tab_maker(argv[1]);
  my_putchar('\n');
}
