/*
** rotone.c for rotone in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 24 09:06:04 2011 exam_user
** Last update Thu Nov 24 09:21:11 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	is_alpha(char c)
{
  if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
    return (1);
  return (0);
}

void	rotone(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 'z' || str[i] == 'Z')
	my_putchar(str[i] - ('z' - 'a'));
      else if (is_alpha(str[i]) == 1)
	my_putchar(str[i] + 1);
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
