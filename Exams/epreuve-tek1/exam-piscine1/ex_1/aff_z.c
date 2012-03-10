/*
** aff_z.c for aff_z in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct  9 10:40:44 2010 exam_user
** Last update Sat Oct  9 11:07:10 2010 exam_user
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	aff_z()
{
  int	chain;
  int	newline;

  chain = 'z';
  newline = 10;
  my_putchar(chain);
  my_putchar(newline);
}

int	main()
{
  aff_z();
}
