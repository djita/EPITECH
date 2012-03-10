/*
** main.c for ord_alphlong in /exam//rendu/ex_6
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 29 10:59:08 2011 exam_user
** Last update Sat Oct 29 12:56:06 2011 exam_user
*/

int	main(int ac, char **av)
{
  if (ac == 2)
    ord_alphlong(av[1]);
  else
    my_putchar('\n');
  return (0);
}
