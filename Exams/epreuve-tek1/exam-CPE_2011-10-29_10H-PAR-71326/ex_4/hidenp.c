/*
** hidenp.c for hidenp in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 29 10:20:44 2011 exam_user
** Last update Sat Oct 29 10:26:54 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	main(int ac, char **av)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (ac == 3)
    {
      while (av[2][j])
	{
	  if (av[2][j] == av[1][i])
	    i++;
	  j++;
	}
      if (av[1][i] == '\0')
	my_putchar('1');
      else
	my_putchar('0');
    }
  my_putchar('\n');
  return (0);
}
