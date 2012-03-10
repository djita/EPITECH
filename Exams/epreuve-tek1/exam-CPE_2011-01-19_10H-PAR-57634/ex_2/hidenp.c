/*
** hidenp.c for hidenp in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 19 10:50:12 2011 exam_user
** Last update Sat Feb  5 15:16:14 2011 lyoma guillou
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

void	hidenp(char *src, char *dst)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (dst[y])
    {
      if (src[x] == '\0' || dst[y] == '\0')
	{
	  my_putchar('1');
	  return;
	}
      if (src[x] == dst[y])
	x++;
      y++;
    }
  my_putchar('0');
}

int	main(int argc, char **argv)
{
  if (argc == 3)
    hidenp(argv[1], argv[2]);
  my_putchar('\n');
  return;
}
