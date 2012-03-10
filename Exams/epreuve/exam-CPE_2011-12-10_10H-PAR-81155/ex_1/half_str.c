/*
** half_str.c for half_str in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 10 10:32:24 2011 exam_user
** Last update Sat Dec 10 10:59:52 2011 exam_user
*/

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		half_str(char **tab)
{
  int		i;
  int		k;

  k = 1;
  while (tab[k])
    {
      i = 0;
      while (tab[k][i])
	{
	  if ((i % 2) == 0)
	    my_putchar(tab[k][i]);
	  i = i + 1;
	}
      k = k + 1;
      my_putchar('\n');
    }
}

int		main(int ac, char **av)
{
  if (ac > 1)
    half_str(av);
  else
    my_putchar('\n');
  return (0);
}
