/*
** half_str.c for half_str in /exam//rendu
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Feb 11 10:31:44 2012 exam_user
** Last update Sat Feb 11 10:38:07 2012 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	half_str(char *s)
{
  int	i;

  i = 0;
  while(s[i])
    (i % 2 == 0) ? my_putchar(s[i++]) : i++;
}

int	main(int ac, char **av)
{
  int	i;

  i = 0;
  if (ac > 1)
    {
      i = 1;
      while (i < ac)
	{
	  half_str(av[i++]);
	  my_putchar('\n');
	}
    }
  else
    my_putchar('\n');
  return (0);
}
