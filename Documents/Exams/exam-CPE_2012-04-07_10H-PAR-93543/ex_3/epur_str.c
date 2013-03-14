/*
** epur_str.c for epur_str in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Apr  7 11:02:08 2012 exam_user
** Last update Sat Apr  7 11:11:24 2012 exam_user
*/

static int	is_sep(char c)
{
  if (c <= ' ')
    return (1);
  return (0);
}

static int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

static int	is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

static int	is_alphanum(char c)
{
  if (is_alpha(c) || is_num(c))
    return (1);
  return (0);
}

int		my_putchar(char c)
{
  return (write(1, &c, 1));
}

void		epur_str(char *str)
{
  int		i;
  int		show;

  i = 0;
  show = 0;
  while (str[i])
    {
      if (is_alphanum(str[i]))
	{
	  if (is_alphanum(str[i]) && is_sep(str[i - 1]) && show != 0)
	    show += my_putchar(' ');
	  show += my_putchar(str[i]);
	}
      ++i;
    }
}

int		main(int ac, char **av)
{
  if (ac == 2)
    epur_str(av[1]);
  my_putchar('\n');
  return (0);
}
