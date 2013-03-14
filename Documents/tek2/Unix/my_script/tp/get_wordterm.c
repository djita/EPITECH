/*
** main.c for my_script in /home/guillo_e/Documents/working/tek2/unix/my_script
** 
** Made by Lyoma Guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Mar  1 15:30:13 2013 Lyoma Guillou
** Last update Fri Mar  1 16:48:38 2013 Lyoma Guillou
*/

#include <sys/types.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int			main(int ac, char **av)
{
  struct termios	term_p;
  struct termios	tmp;
  FILE			*fs;
  char			*buff;
  char			*dup;
  char			c;
  size_t		len;

  tcgetattr(0, &term_p);
  tmp = term_p;
  tmp.c_lflag &= ~ICANON & ~ECHO;
  tcsetattr(0, TCSANOW, &tmp);
  while (0 < (len = read(0, &c, 1)))
    {
      if ('\n' == c)
	{
	  write(1, &c, 1);
	  break;
	}
      write(1, "*", 1);
      strcat(buff, strdup(&c));
    }
  write(1, buff, strlen(buff));
  write(1, "\n", 1);
  tcsetattr(0, TCSANOW, &term_p);
}
