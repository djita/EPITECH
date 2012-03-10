/*
** alum.c for alum1 in /home/guillo_e//Documents/working/prog_elem/Alum-1
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb  6 08:49:52 2012 lyoma guillou
** Last update Tue Feb  7 11:59:12 2012 lyoma guillou
*/

#include <alum.h>

static int	_is_alum(char **alum, int row, int col, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      if (alum[row][col + i] != SYM)
	return (0);
      ++i;
    }
  return (1);
}

void		alum_show(char **tab, int size)
{
  int		i;
  int		j;
  int		spa;

  i = 0;
  spa = 0;
  my_putchar('\n');
  while (tab[i])
    {
      spa = my_intlen(size) - my_putnbr(i + 1);
      while (spa-- >= 0)
	my_putchar(' ');
      j = 0;
      while (j++ < (size - i))
	my_putchar(' ');
      j = 0;
      while (tab[i][j])
	my_putchar(tab[i][j++]);
      my_putchar('\n');
      i++;
    }
}

int		alum_check(char **alum)
{
  int		i;
  int		j;

  i = 0;
  while (alum[i])
    {
      j = 0;
      while (alum[i][j])
	if (SYM == alum[i][j++])
	  return (1);
      ++i;
    }
  return (0);
}

char		**alum_tab(int line)
{
  char		**tab;
  int		i;
  int		k;

  i = 0;
  k = 0;
  tab = xmalloc((line + 1) * sizeof(*tab));
  my_memset(tab, 0, line + 1);
  while (i < line)
    {
      tab[i] = xmalloc((2 * (i + 1)) * sizeof(**tab));
      my_memset(tab[i], SYM, (2 * (i + 1)) - 1);
      ++i;
    }
  return (tab);
}

char		**alum_entry(char *str, char **alum)
{
  char		**entry;
  int		x;
  int		y;
  int		k;

  if ((entry = my_str_to_wordtab(str)) != NULL)
    {
      x = my_getnbr(entry[0]) - 1;
      if (my_tablen(entry) > 2 && x < (my_tablen(alum) - 1) && x >= 0)
	{
	  y = my_getnbr(entry[1]) - 1;
	  k = (entry[2]) ? my_getnbr(entry[2]) : 1;
	  if ((y + k) <= (my_strlen(alum[x]) - 1) && y >= 0 && _is_alum(alum, x, y, k))
	    {
	      while (k-- > 0)
		alum[x][y + k] = ' ';
	      return (alum);
	    }
	  my_putstr("Wrong line, column or number input.\n");
	}
      my_putstr("Input is in wrong format.\n");
    }
  my_putstr("Entry not available.\n");
  return (alum);
}
