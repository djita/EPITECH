/*
** maff_alpha.c for maff_alpha in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct  9 11:56:53 2010 exam_user
** Last update Sat Oct  9 12:31:40 2010 exam_user
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	maff_alpha()
{
  int	alpha;

  alpha = 97;
  my_putchar(alpha);
  while (alpha >= 97 && alpha < 122)
    {
      alpha = alpha - 31;
      my_putchar(alpha);
      while (alpha >= 65 && alpha < 90)
	{
	  alpha = alpha +33;
	  my_putchar(alpha);
	}
    }
  alpha = 10;
  my_putchar(alpha);
}

int	main()
{
  maff_alpha();
}
