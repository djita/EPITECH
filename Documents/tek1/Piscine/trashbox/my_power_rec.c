/*
** my_power_rec.c for my_power_rec in /home/guillo_e//afs/rendu/piscine/Jour_05
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Oct  7 10:39:11 2011 lyoma guillou
** Last update Fri Oct  7 14:58:13 2011 lyoma guillou
*/

int	my_power_rec(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  if (power > 0)
    nb = my_power_rec(nb, power - 1) * nb;
  return (nb);
}
