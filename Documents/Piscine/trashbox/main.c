/*
** main.c for my_str_to_wordtab in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Oct 18 20:06:35 2011 lyoma guillou
** Last update Wed Oct 19 18:19:32 2011 lyoma guillou
*/

#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

void	my_aff_tab(char **tab)
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
  free(tab);
}

int	main(int argc, char **argv)
{
  my_aff_tab(my_str_to_wordtab(argv[1]));
}
