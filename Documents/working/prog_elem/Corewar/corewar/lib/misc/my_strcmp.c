/*
** my_strcmp.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Thu Jan 26 16:36:17 2012 louis duverdier
*/

int	my_strcmp(const char *s1, const char *s2)
{
  while (*s1 && *s1 == *s2)
    {
      ++s1;
      ++s2;
    }
  return (*s1 - *s2);
}
