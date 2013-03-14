/*
** white_rabbit.c for follow the white rabbit in /home/guillo_e//Documents/working/tek2/piscine/D01/ex00
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan  9 10:17:04 2013 lyoma guillou
** Last update Wed Jan  9 11:23:52 2013 lyoma guillou
*/

#include <stdio.h>

int		follow_the_white_rabbit(void)
{
  static int	sum = 0;
  int		face;

  do 
    {
      face = random() % 37 + 1;
      sum += face;
      if (face != 12 && face % 11 != 0)
	{
	  if ((face >= 4 && face <= 6) || face == 17 || face == 28 
	      || (face > 18 && face < 21))
	    printf("gauche\n");
	  if (face == 13 || face >= 34)
	    printf("droite\n");
	  if (face == 15 || sum == 10 || sum == 15)
	    printf("devant\n");
	  if ((face > 24 && (face * 3 == 78 || face * 3 == 146) || sum % 8 == 0))
	    printf("derriere\n");
	}
    } while (sum != 421 && sum != 300 && sum != 97 && face != 1 && face != 37);
  printf("LAPIN !!!\n");
  return (sum);
}

int		main()
{
  srandom(time(NULL));
  follow_the_white_rabbit();
}
