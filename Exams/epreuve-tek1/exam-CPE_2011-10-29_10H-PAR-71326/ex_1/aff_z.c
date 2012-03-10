/*
** aff_z.c for aff_z in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 29 10:03:57 2011 exam_user
** Last update Sat Oct 29 10:10:52 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	main(int ac, char **av)
{
  my_putchar('z');
  my_putchar('\n');
  return (0);
}
