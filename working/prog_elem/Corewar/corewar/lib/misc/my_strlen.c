/*
** my_strlen.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Thu Jan 26 16:36:03 2012 louis duverdier
*/

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}
