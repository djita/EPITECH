/*
** main.c for str_capitalize in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Mar 11 11:03:45 2011 exam_user
** Last update Fri Mar 11 11:04:56 2011 exam_user
*/

int	main(int ac, char **av)
{
  if (ac == 2)
    my_putstr(str_capitalize(av[1]));
  my_putchar('\n');
  return (0);
}
