/*
** rotone.c for rotone in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 19 10:32:13 2012 exam_user
** Last update Thu Jan 19 10:36:21 2012 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	is_alpha(char c)
{
  if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
    return (1);
  if (c == 'Z' || c == 'z')
    return (2);
  return (0);
}

void	rotone(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (is_alpha(str[i]) == 1)
	my_putchar(str[i] + 1);
      else if (is_alpha(str[i]) == 2)
	my_putchar(str[i] + 'a' - 'z');
      else
	my_putchar(str[i]);
      i++;
    }
}

int	main(int ac, char **av)
{
  if (ac == 2)
    rotone(av[1]);
  my_putchar('\n');
  return (0);
}
