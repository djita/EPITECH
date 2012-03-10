/*
** my_aff_params.c for my_aff_params in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Oct 11 10:41:18 2011 lyoma guillou
** Last update Tue Oct 11 10:50:30 2011 lyoma guillou
*/

int	main(int ac, char **av)
{
  int	i;

  i = ac - 1;
  while (i >= 0)
    {
      my_putstr(av[i]);
      my_putchar('\n');
      i--;
    }
  return (0);
}
