/*
** maff_alpha.c for maff_alpha in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 29 10:05:36 2011 exam_user
** Last update Sat Oct 29 10:09:44 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	main(int ac, char **av)
{
  char	alpha;

  alpha = 'a';
  while (alpha >= 'a' && alpha <= 'z')
    {
      my_putchar(alpha);
      alpha = alpha - ('a' - 'B');
      while (alpha >= 'A' && alpha <= 'Z')
	{
	  my_putchar(alpha);
	  alpha = alpha + ('b' - 'A');
	}
    }
  my_putchar('\n');
  return (0);
}
