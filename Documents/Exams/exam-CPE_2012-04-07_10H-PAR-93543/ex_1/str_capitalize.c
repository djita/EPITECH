/*
** str_capitalize.c for str_capitalize in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Apr  7 10:32:28 2012 exam_user
** Last update Sat Apr  7 10:40:19 2012 exam_user
*/

void		my_putchar(char c)
{
  write(1, &c, 1);
}

static int	is_sep(char c)
{
  if (c <= ' ')
    return (1);
  return (0);
}

static int	is_low_alpha(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

void		str_capitalize(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (is_low_alpha(str[i]) && (i == 0 || is_sep(str[i - 1])))
	my_putchar(str[i] - ('a' - 'A'));
      else
	my_putchar(str[i]);
      ++i;
    }
}

int		main(int ac, char **av)
{
  if (ac == 2)
    str_capitalize(av[1]);
  my_putchar('\n');
  return (0);
}
