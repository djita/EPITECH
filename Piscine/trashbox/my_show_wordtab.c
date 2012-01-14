/*
** my_show_wordtab.c for my_show_wordtab in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Oct 14 15:12:44 2011 lyoma guillou
** Last update Fri Oct 14 15:15:57 2011 lyoma guillou
*/

int	my_show_wordtab(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  my_putchar(tab[i][j]);
	  j++;
	}
      my_putchar('\n');
      i++;
    }
  return (1);
}
