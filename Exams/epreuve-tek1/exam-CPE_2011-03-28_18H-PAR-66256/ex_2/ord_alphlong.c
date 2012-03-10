/*
** ord_alphlong.c for ord_alphlong in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Mar 28 18:21:36 2011 exam_user
** Last update Mon Mar 28 18:45:13 2011 exam_user
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

int	word_count(char *str)
{
  int	i;
  int	x;
  int	word;

  i = 0;
  word = 0;
  while (str[i])
    {
      x = 0;
      while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
	{
	  x = 1;
	  i++;
	}
      if (x = 1)
	word++;
      i++;
    }
  return (word);
}

char	**tab_maker(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	x;
  int	word;

  i = 0;
  j = 0;
  x = 0;
  word = word_count(str);
  tab = malloc(word * sizeof(char *));
  if (tab == NULL)
    return (-1)
  while (str[i])
    {
      while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
	j++;
      tab[x] = malloc((j - i) * sizeof(char));
      if (tab[x] == NULL)
	return (-2);
      x++;
      i = j;
    }
}

char	**sort_tab(char **tab)
{

}

int	main(int argc, char **argv)
{
  return (0);
}
