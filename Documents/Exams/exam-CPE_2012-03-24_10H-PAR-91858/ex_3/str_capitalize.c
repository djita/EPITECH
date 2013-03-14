/*
** str_capitalize.c for str_capitalize in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 24 10:16:42 2012 exam_user
** Last update Sat Mar 24 10:22:41 2012 exam_user
*/

int		is_lowalpha(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

int		is_char(char c)
{
  if (c > ' ' && c <= '~')
    return (1);
  return (0);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		str_capitalize(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (is_lowalpha(str[i]) && (i == 0 || !is_char(str[i - 1])))
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
