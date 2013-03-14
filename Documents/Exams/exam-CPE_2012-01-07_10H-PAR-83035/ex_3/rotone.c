/*
** rotone.c for rotone in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Jan  7 11:06:33 2012 exam_user
** Last update Sat Jan  7 11:11:35 2012 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	is_alpha(char c)
{
  if ((c >= 'A' && c < 'Z') || (c >= 'a' && c < 'z'))
    return (1);
  if (c == 'z' || c == 'Z')
    return (2);
  return (0);
}

void	rotone(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (is_alpha(str[i]) == 2)
	my_putchar(str[i] - ('Z' - 'A'));
      else if (is_alpha(str[i]) == 1)
	my_putchar(str[i] + 1);
      else
	my_putchar(str[i]);
      ++i;
    }
}

int	main(int ac, char **av)
{
  if (ac == 2)
    rotone(av[1]);
  my_putchar('\n');
  return (0);
}
