/*
** my_char_type.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Thu Jan 26 16:36:43 2012 louis duverdier
*/

int	my_is_space(char c)
{
  return (c <= 32 || c >= 127);
}

int	my_is_number(char c)
{
  return (c >= '0' && c <= '9');
}

int	my_is_letter(char c)
{
  return ((c >= 'a' && c <= 'z')
	  || (c >= 'A' && c <= 'Z'));
}
