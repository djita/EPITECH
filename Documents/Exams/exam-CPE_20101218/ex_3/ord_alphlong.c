/*
** ord_alphlong.c for ord_alphlong in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 18 12:47:03 2010 exam_user
** Last update Sat Dec 18 13:09:09 2010 exam_user
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

int	ord_alphlong(char **tab)
{
  char	*tmp;
  int	let;
  int	pos;
  int	i;

  let = 0;
  pos = 0;
  i = 1;
  while (i == 1)
    {
      i = 0;
      while (tab[pos][let] > tab[pos + 1][let])
	{
	  tmp = tab[pos];
	  tab[pos] = tab[pos + 1];
	  tab[pos + 1] = tab[pos];
	  i = 1;
	}
      my_putstr(tab[pos]);
      pos++;
    }
}
