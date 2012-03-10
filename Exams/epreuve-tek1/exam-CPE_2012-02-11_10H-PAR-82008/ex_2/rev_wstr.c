/*
** rev_wstr.c for rev_wstr in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Feb 11 10:42:40 2012 exam_user
** Last update Sat Feb 11 10:59:33 2012 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	rev_wstr(char *str)
{
  int	i;
  int	k;

  i = 0;
  k = my_strlen(str);
  while (str[--k])
    {
      if (str[k] <= ' ' || k == 0)
	{
	  i = (k == 0) ? k : k + 1;
	  while (str[i] > ' ' && str[i])
	    my_putchar(str[i++]);
	  if (k != 0)
	    my_putchar(' ');
	}
    }
}

int	main(int ac, char **av)
{
  if (ac == 2)
    rev_wstr(av[1]);
  my_putchar('\n');
  return (0);
}
