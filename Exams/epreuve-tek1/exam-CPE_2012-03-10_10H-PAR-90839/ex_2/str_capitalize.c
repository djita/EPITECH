/*
** my_strcapitalize.c for my_strcapitalize in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 10 10:44:03 2012 exam_user
** Last update Sat Mar 10 10:54:35 2012 exam_user
*/

int		is_low_alpha(char c)
{
  if ((c >= 'a' && c <= 'z'))
    return (1);
  return (0);
}

int		is_separator(char c)
{
  if (c <= ' ' || c > '~')
    return (1);
  return (0);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_strcapitalize(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (is_low_alpha(str[i]) && (i == 0 || is_separator(str[i - 1])))
	my_putchar(str[i] - ('a' - 'A'));
      else
	my_putchar(str[i]);
      ++i;
    }
}

int		main(int ac, char **av)
{
  if (ac >= 2)
    my_strcapitalize(av[1]);
  my_putchar('\n');
  return (0);
}
