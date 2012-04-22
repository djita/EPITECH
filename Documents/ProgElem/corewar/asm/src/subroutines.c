/*
** subroutines.c for src in /home/czegan_g/work/school/corewar/asm/src
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  jeu. mars 22 23:59:58 2012 gaby czegany
** Last update sam. mars 24 18:49:16 2012 gaby czegany
*/

# include       <asm.h>

int     error(char *text)
{
  my_puterr("Error: ");
  my_puterr(text);
  my_puterr("\n");
  return (FAILURE);
}

void    usage(char *name)
{
  my_putstr("Usage: ");
  my_putstr(name);
  my_putstr(" file[.s]...\n");
}

void    warning(char *text)
{
  my_puterr("Warning: ");
  my_puterr(text);
  my_puterr("\n");
}

void    msg(char *text, char *file)
{
  my_putstr("[");
  my_putstr(file);
  my_putstr("] ");
  my_putstr(text);
  my_putstr("\n");
}

void	label_error(char *label)
{
  my_puterr("Error: Label '");
  my_puterr(label);
  my_puterr("' was not found.");
}
