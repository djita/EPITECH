/*
** rev_str.c for rev_str in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 13 10:46:34 2010 exam_user
** Last update Sat Nov 13 11:02:35 2010 exam_user
*/

int	my_putchar(char c)
{
  write (1, &c, 1);
}

int	rev_str(char *str)
{
  int	index;

  index = 0;
  while (str[index])
    {
      index = index + 1;
    }
  while (index > 0)
    {
      my_putchar(str[index - 1]);
      index = index - 1;
    }
}

int	main(int argc, char **argv)
{
  int	index;

  index = 1;
  while(argv[index])
    {
      rev_str(argv[1]);
      index = index + 1;
    }
  my_putchar('\n');
}
