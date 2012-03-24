/*
** rotone.c for rotone in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 24 10:09:52 2012 exam_user
** Last update Sat Mar 24 10:14:49 2012 exam_user
*/

int		is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		rotone(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (is_alpha(str[i]))
	{
	  if (str[i] == 'z' || str[i] == 'Z')
	    my_putchar(str[i] - ('Z' - 'A'));
	  else
	    my_putchar(str[i] + 1);
	}
      else
	my_putchar(str[i]);
      ++i;
    }
}

int		main(int ac, char **av)
{
  if (ac == 2)
    rotone(av[1]);
  my_putchar('\n');
  return (0);
}
