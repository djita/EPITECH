/*
** hidenp.c for hidenp in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan  6 11:17:25 2011 exam_user
** Last update Thu Jan  6 11:29:19 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	value(int x)
{
  if (x == 1)
    my_putchar('1');
  if (x == 0)
    my_putchar('0');
}

int	hidenp(char *src, char *dst)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dst[j])
    {
      if (src[i] == dst[j])
      {
	i++;
	if (src[i] == '\0')
	  return(1);
      }
      j++;
    }
  return(0);
}

int	main(int argc, char **argv)
{
  int	val;

  val = 0;
  if (argv[1] == 0 || argv[3] != 0)
    {
      my_putchar('\n');
      return;
    }
  if (argv[2])
    val = hidenp(argv[1], argv[2]);
  value(val);
  my_putchar('\n');
  return;
}
