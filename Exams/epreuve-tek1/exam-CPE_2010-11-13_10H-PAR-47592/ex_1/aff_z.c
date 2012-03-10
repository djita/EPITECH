/*
** aff_z.c for aff_z in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 13 10:36:01 2010 exam_user
** Last update Sat Nov 13 10:37:49 2010 exam_user
*/

int	my_putchar(char z)
{
  write (1, &z, 1);
}

int	aff_z()
{
  my_putchar('z');
  my_putchar('\n');
}

int	main()
{
  aff_z();
}
