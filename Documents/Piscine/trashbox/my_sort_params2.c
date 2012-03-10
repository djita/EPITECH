/*
** my_sort_params.c for my_sort_params in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Oct 11 11:00:39 2011 lyoma guillou
** Last update Wed Oct 12 12:46:55 2011 lyoma guillou
*/

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
  int	y;

  y = 0;
  while (tab[y])
    {
      my_putstr(tab[y]);
      my_putchar('\n');
      y++;
    }
}

char	*my_strcpy(char *dst, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dst[i] = src[i];
      i++;
    }
  return (dst);
}

int	main(int argc, char **argv)
{
  int	i;
  int	swap;
  char	*tab[argc];
  char	*ptr;

  i = 0;
  swap = 1;
  tab = my_strcpy(tab, argv);
  tab[argc] = '\0';
  while (tab[i])
    {
      while (swap == 1)
	{
	  swap = 0;
	  if (tab[i] > tab[i + 1])
	    {
	      ptr = tab[i];
	      *tab[i] = *tab[i + 1];
	      tab[i + 1] = ptr;
	      swap = 1;
	      i = 0;
	    }
	}
      i++;
    }
  my_aff_tab(tab);
}
