/*
** main.c for menger in /home/guillo_e//Documents/working/tek2/piscine/D01/ex01/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan  9 09:35:41 2013 lyoma guillou
** Last update Wed Jan  9 15:24:13 2013 lyoma guillou
*/

unsigned int	my_pow(unsigned int nb, unsigned int pow);
unsigned int	my_getnbr(char *str);
void		set_menger(unsigned int size, unsigned int lvl);

int		main(int ac, char *av[])
{
  unsigned int	x;
  unsigned int	pow;

  if (ac == 3)
    {
      x = my_getnbr(av[1]);
      pow = my_getnbr(av[2]);
      if (pow > 0 && my_pow(3, pow) <= x)
	set_menger(x, pow);
    }
}
