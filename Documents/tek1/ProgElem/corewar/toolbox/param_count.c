/*
** param_cnt.c for asm in /home/guillo_e//Documents/working/prog_elem/Corewar/toolbox
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb 20 18:28:43 2012 lyoma guillou
** Last update Tue Feb 21 11:48:48 2012 lyoma guillou
*/

#include <asm.h>

#define		PARAM_LEN	8
#define		MAXPRM_VAL	255

int		param_count(int lenght, unsigned char *ptr)
{
  int		x;
  int		i;

  x = lenght;
  while (x > 0)
    {
      i = PARAM_LEN - 1;
      while (i >= 0 && ptr[i] == MAXPRM_VAL)
	ptr[i--] = 0;
      if (i == -1)
	{
	  my_puterr("Param value overflow\n");
	  return (FAILURE);
	}
      ptr[i] += 1;
      --x;
    }
  return (SUCCESS);
}
