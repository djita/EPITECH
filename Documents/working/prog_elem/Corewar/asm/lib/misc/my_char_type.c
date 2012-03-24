/*
** my_char_type.c for misc in /home/czegan_g/work/school/corewar/asm/lib/misc
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 19 17:24:30 2012 louis duverdier
** Last update sam. mars 24 15:27:20 2012 gaby czegany
*/

int	my_is_space(char c)
{
  return (c <= 32 || c >= 127);
}

int	my_is_number(char c)
{
  return ((c >= '0' && c <= '9') || c == 'x' || c == 'X');
}

int	my_is_letter(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	my_is_alphanum(char c)
{
  return (my_is_number(c) || my_is_letter(c) || c == '_');
}
