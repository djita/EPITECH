/*
** rotone.c for rotone in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 25 10:45:16 2010 exam_user
** Last update Thu Nov 25 11:48:03 2010 exam_user
*/

int	my_putchar(char c)
{
  write (1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	rotone(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] < 'z')
	my_putchar(str[i] + 1);
      if (str[i] >= 'A' && str[i] < 'Z')
	my_putchar(str[i] + 1);
      if (str[i] == 'z')
	my_putchar('a');
      if (str[i] == 'Z')
	my_putchar('A');
      if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
	my_putchar(str[i]);
      i = i + 1;
    }
}

int	main(int argc, char **argv)
{
  if (argv[2] || argv[1] == 0)
    {
      my_putchar('\n');
      return;
    }
  if (argv[1])
    rotone(argv[1]);
  my_putchar('\n');
}
