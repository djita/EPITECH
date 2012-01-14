/*
** my_sort_int_tab.c for my_sort_int_tab in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct  6 14:30:03 2011 lyoma guillou
** Last update Fri Oct  7 18:08:23 2011 lyoma guillou
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	noswap;
  int	i;
  int	x;

  i = 0;
  noswap = -1;
  while (noswap = -1)
    {
      noswap = 0;
      if (tab[i] > tab[i + 1] && tab[i + 1])
	{
	  x = tab[i];
	  tab[i] = tab[i + 1];
	  tab[i + 1] = x;
	  noswap = -1;
	  i = 0;
	}
      i++;
    }
}
