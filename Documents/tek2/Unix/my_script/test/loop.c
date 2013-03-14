/*
** loop.c for loop.c in /home/bigup/prog/tek2/proj/my_script/
**
** Made by dimitri doyen
** Login   <doyen_d@epitech.net>
**
** Started on  Fri Feb 25 17:38:21 2011 dimitri doyen
** Last update Sun Mar  3 02:34:44 2013 Lyoma Guillou
*/

#include "my_script.h"

void            ioctl_set()
{
  struct termios        t;

  tcgetattr(0, &t);
  t.c_lflag &= ~(ICANON | ISIG | ECHO);
  tcsetattr(0, TCSANOW, &t);
}

int             use_select(char **buf, int *readed, fd_set *readf, int master)
{
  if (FD_ISSET(0, readf))
    {
      if ((*readed = read(0, *buf, sizeof(**buf))) < 0)
        return (-1);
      if (*readed == 0)
        return (-1);
      write(master, *buf, *readed);
    }
  else if (FD_ISSET(master, readf))
    {
      if ((*readed = read(master, *buf, sizeof(**buf))) < 0)
        return (-1);
      if (*readed == 0)
        return (-1);
      write(1, *buf, *readed);
      return (1);
    }
  return (0);
}

void            loop(int master, t_args *args)
{
  char          *buf;
  int           readed, ret;
  fd_set        readf;

  readed = 0;
  buf = malloc(sizeof(*buf) * 4096);
  ioctl_set();
  while (42)
    {
      FD_ZERO(&readf);
      FD_SET(0, &readf);
      FD_SET(master, &readf);
      if (select(master + 1, &readf, NULL, NULL, NULL) < 0)
        exit(write(2, "select\n", 8));
      if ((ret = use_select(&buf, &readed, &readf, master)) == -1)
        break;
      else if (ret == 1)
        write(args->fdf, buf, readed);
    }
  free(buf);
}
