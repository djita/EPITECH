/*
** read_stdin.c for stdin in /home/guillo_e//Documents/working/rush
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Feb 24 23:17:45 2012 lyoma guillou
** Last update Sat Feb 25 19:44:39 2012 lyoma guillou
*/

#include <stdio.h>

extern FILE	*stdin;
extern FILE	*stdout;
extern FILE	*stderr;

int		main()
{
  FILE		*file;
  char		*buffer;
  int		i;

  file = fdopen(0, "r");
  while (!feof(file))
    {
      fscanf(file, "%s", buffer);
      if (buffer)
	fprintf(stdout, "%s\n", buffer);
    }
  return (0);
}
