/*
** maff_alpha.c for maff_alpha in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 13 10:40:04 2010 exam_user
** Last update Sat Nov 13 10:45:00 2010 exam_user
*/

int	my_putchar(char c)
{
  write (1, &c, 1);
}

int	maff_alpha()
{
  char	alpha;

  alpha = 'a';
  while (alpha >= 'a' && alpha <= 'z')
    {
      my_putchar(alpha);
      alpha = alpha - 31;
      while (alpha >= 'A' && alpha <= 'Z')
	{
	  my_putchar(alpha);
	  alpha = alpha + 33;
	}
    }
  my_putchar('\n');
}

int	main()
{
  maff_alpha();
}
