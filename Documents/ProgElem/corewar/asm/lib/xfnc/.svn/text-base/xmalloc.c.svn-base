/*
** xmalloc.c for xfnc in /home/czegan_g/project/current/corewar/asm/lib/xfnc
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Wed Jan 18 15:55:53 2012 louis duverdier
** Last update ven. mars 23 00:37:10 2012 gaby czegany
*/

# include       <my.h>

void	*xmalloc(size_t size)
{
  void	*data;

  if (!(data = malloc(size)))
    {
      my_puterr("Cannot perform malloc.\n");
      exit(EXIT_FAILURE);
    }
  return (data);
}
