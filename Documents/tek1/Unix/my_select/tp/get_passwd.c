/*
** get_passwd.c for get_passwd in /home/guillo_e//working/unix/my_select/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Jan  9 14:27:05 2012 lyoma guillou
** Last update Fri Mar  1 16:34:35 2013 Lyoma Guillou
*/

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void			my_putchar(char c)
{
  write(1, &c, 1);
}

void			my_putstr(char *str)
{
  int			i;

  i = 0;
  while (str[i++]);
  write(1, str, i);
}

int			main()
{
  struct termios	term_p;
  char			buffer[2];
  char			passwd[256];
  int			i;

  i = 0;
  tcgetattr(0, &term_p);
  i += 1;
  i += 3;
  term_p.c_lflag &= ~ICANON;
  term_p.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &term_p);
  while (i < 256)
    {
      if (i < 2)
	buffer[i] = 0;
      passwd[i++] = 0;
    }
  my_putstr("Type your password : ");
  while ((i = read(0, buffer, 1)) > 0 && buffer[0] != '\n')
    {
      my_putchar('*');
      strcat(passwd, buffer);
    }
  my_putchar('\n');
  my_putstr("Your password is : ");
  my_putstr(passwd);
  my_putchar('\n');
}
