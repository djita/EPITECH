/*
** maff_alpha.c for maff_alpha in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 24 09:03:14 2011 exam_user
** Last update Thu Nov 24 09:05:17 2011 exam_user
*/

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int		main()
{
  my_putstr("aBcDeFgHiJkLmNoPqRsTuVwXyZ\n");
}
