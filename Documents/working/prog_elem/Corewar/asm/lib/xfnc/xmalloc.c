/*
** xmalloc.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Wed Jan 18 15:55:53 2012 louis duverdier
** Last update Wed Jan 18 17:06:44 2012 louis duverdier
*/

#include <my.h>

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
