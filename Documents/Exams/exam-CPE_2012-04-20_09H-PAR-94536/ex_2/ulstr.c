/*
** ulstr.c for  in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Apr 20 09:44:20 2012 exam_user
** Last update Fri Apr 20 09:51:07 2012 exam_user
*/

void		my_putchar(char c)
{
  write(1, &c, 1);
}

static int	is_lowalpha(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

static int	is_upalpha(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

void		ulstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (is_lowalpha(str[i]))
	my_putchar(str[i] - ('a' - 'A'));
      else if (is_upalpha(str[i]))
	my_putchar(str[i] + ('a' - 'A'));
      else
	my_putchar(str[i]);
      ++i;
    }
}

int		main(int ac, char **av)
{
  if (ac == 2)
    ulstr(av[1]);
  my_putchar('\n');
  return (0);
}
