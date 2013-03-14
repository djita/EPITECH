/*
** ulstr.c for  in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jun  7 09:19:30 2012 exam_user
** Last update Thu Jun  7 09:27:57 2012 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	ulstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
	my_putchar(str[i]);
      else
	(str[i] >= 'a' && str[i] <= 'z') ? my_putchar(str[i] - ('a' - 'A')) 
	  : my_putchar(str[i] + ('a' - 'A'));
      ++i;
    }
}

int	main(int ac, char **av)
{
  if (ac == 2)
    ulstr(av[1]);
  my_putchar('\n');
  return (0);
}
