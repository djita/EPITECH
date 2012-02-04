/*
** my_strcmp.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Fri Jan 20 10:44:20 2012 louis duverdier
** Last update Fri Jan 20 10:44:21 2012 louis duverdier
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
