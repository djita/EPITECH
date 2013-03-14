/*
** maff_alpha.c for maff_alpha in /exam//rendu
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 18 10:06:44 2010 exam_user
** Last update Sat Dec 18 10:10:01 2010 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	maff_alpha()
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
  return;
}

int	main()
{
  maff_alpha();
}
