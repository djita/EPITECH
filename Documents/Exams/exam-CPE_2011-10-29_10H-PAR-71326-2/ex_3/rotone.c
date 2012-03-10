/*
** rotone.c for rotone in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 29 10:10:16 2011 exam_user
** Last update Sat Oct 29 10:19:34 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	is_alphan(char c)
{
  if (c == 'z' || c == 'Z')
    return (2);
  if (c >= 'a' && c < 'z')
    return (1);
  if (c >= 'A' && c < 'Z')
    return (1);
  return (0);
}

int	main(int ac, char **av)
{
  int	i;

  i = 0;
  if (ac == 2)
    {
      while (av[1][i])
	{
	  if (is_alphan(av[1][i]) == 2)
	    my_putchar(av[1][i] - ('z' - 'a'));
	  else if (is_alphan(av[1][i]) == 1)
	    my_putchar(av[1][i] + 1);
	  else
	    my_putchar(av[1][i]);
	  i++;
	}
    }
  my_putchar('\n');
}
