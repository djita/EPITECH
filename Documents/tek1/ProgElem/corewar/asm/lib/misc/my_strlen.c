/*
** my_strlen.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Fri Jan 20 10:43:46 2012 louis duverdier
** Last update Fri Jan 20 10:43:47 2012 louis duverdier
*/

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}
