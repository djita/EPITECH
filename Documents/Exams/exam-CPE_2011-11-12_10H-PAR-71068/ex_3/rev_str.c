/*
** rev_str.c for rev_str in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 12 10:44:41 2011 exam_user
** Last update Sat Nov 12 10:48:48 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	main(int ac, char **av)
{
  int	i;

  i = 0;
  if (ac == 2)
    {
      i = my_strlen(av[1]) - 1;
      while (i >= 0)
	{
	  my_putchar(av[1][i]);
	  i = i - 1;
	}
    }
  my_putchar('\n');
  return (0);
}
