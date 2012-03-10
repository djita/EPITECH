/*
** str_capitalize.c for str_capitalize in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Jan  7 10:33:52 2012 exam_user
** Last update Sat Jan  7 11:04:28 2012 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	is_alpha(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

void	str_capitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (is_alpha(str[i]) == 1 && 
	  (str[i - 1] == ' ' || str[i - 1] == '\t' || i == 0))
	my_putchar(str[i] - ('a' - 'A'));
      else
	my_putchar(str[i]);
      ++i;
    }
}

int	main(int ac, char **av)
{
  if (ac == 2)
    str_capitalize(av[1]);
  my_putchar('\n');
  return (0);
}
