/*
** rotone.c for  in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jun  7 09:29:01 2012 exam_user
** Last update Thu Jun  7 09:31:35 2012 exam_user
*/

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		rotone(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        my_putchar(str[i]);
      else
	(str[i] == 'z' || str[i] == 'Z') ? my_putchar(str[i] - ('z' - 'a')) 
	  : my_putchar(str[i] + 1);
      ++i;
    }
}

int		main(int ac, char **av)
{
  if (ac == 2)
    rotone(av[1]);
  my_putchar('\n');
  return (0);
}
