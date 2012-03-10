/*
** main.c for colle2-4 in /home/guillo_e//Documents/Piscine/colles/semaine2
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 15 18:30:43 2011 lyoma guillou
** Last update Sat Oct 15 23:07:31 2011 lyoma guillou
*/

int	my_getnbr(char *str)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (str[i])
    {
      x = x * 10;
      x = x + (str[i] - '0');
    }
  return (x);
}

int	main(int ac, char **av)
{
  int	size;
  int	speed;

  size = 80;
  speed = 200000;
  if (ac == 4)
    {
      speed = my_getnbr(av[3]);
      size = my_getnbr(av[2]);
    }
  if (ac == 3)
    size = my_getnbr(av[2]);
  if (ac >= 2)
    show_string(av[1], size, speed);
  else
    my_putstr("Usage: ./colle2-4 [string] [size] [speed] \n");
  return (0);
}
