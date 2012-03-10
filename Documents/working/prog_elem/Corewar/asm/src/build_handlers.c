/*
** build_handlers.c for src in /home/czegan_g/project/current/corewar/asm/src
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  mar. févr. 21 12:12:26 2012 gaby czegany
** Last update mar. févr. 21 14:12:57 2012 gaby czegany
*/

#include <asm.h>

int		add_size(int lenght, unsigned char *ptr)
{
  int		i;

  while (lenght > 0)
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
    --lenght;
  }
  return (SUCCESS);
}
