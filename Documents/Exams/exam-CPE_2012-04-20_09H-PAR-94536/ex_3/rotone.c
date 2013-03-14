/*
** rotone.c for  in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Apr 20 09:52:29 2012 exam_user
** Last update Fri Apr 20 09:58:44 2012 exam_user
*/

void		my_putchar(char c)
{
  write(1, &c, 1);
}

static int	is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

void		rotone(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (is_alpha(str[i]))
	{
	  if (!is_alpha(str[i] + 1))
	    my_putchar(str[i] - ('z' - 'a'));
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
