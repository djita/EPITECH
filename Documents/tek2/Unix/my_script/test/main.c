/*
** main.c for main.c in /home/bigup/prog/tek2/proj/my_script/
**
** Made by dimitri doyen
** Login   <doyen_d@epitech.net>
**
** Started on  Sat Feb 26 17:33:44 2011 dimitri doyen
** Last update Sun Mar  3 02:34:00 2013 Lyoma Guillou
*/

#include "my_script.h"

void            write_head_foot(int flag, t_args *args)
{
  char          *buf;
  time_t        my_time;

  if (args->flag_q == 0)
    {
      if (!(buf = malloc(sizeof(*buf) * 200)))
        exit(write(2, "malloc\n", 8));
      time(&my_time);
      if (flag == 0)
        strcpy(buf, "Script started on ");
      else
        strcpy(buf, "Script done on ");
      strcat(buf, ctime(&my_time));
      write(args->fdf, buf, strlen(buf) + 1);
      free(buf);
    }
}

void            term_head(t_args *args)
{
  if (args->flag_q == 0)
    printf("Script started, output file is %s\n",
           args->filename?args->filename:"typescript");
  else
    {
      write(args->fdf, "Script started, output file is ", 31);
      write(args->fdf, args->filename?args->filename:"typescript",strlen(args->filename?args->filename:"typescript"));
      write(args->fdf, "\n", 2);
    }
}

void            ioctl_restore()
{
  struct termios        t;

  tcgetattr(0, &t);
  t.c_lflag |= (ICANON | ISIG | ECHO);
  tcsetattr(0, TCSANOW, &t);
}

void            exit_end(t_args *args)
{
  if (args->flag_q == 0)
    printf("Script done, output file is %s\n",
           args->filename?args->filename:"typescript");
  write_head_foot(1, args);
  close(args->fdf);
  if (args->flag_c == 0)
    free_targs(args);
  free(args);
}

int             main(int ac, char **ar)
{
  pid_t         pid;
  int           master;
  struct termios        t;
  struct winsize        w;
  t_args                *args;

  args = check_args(ac, ar);
  write_head_foot(0, args);
  term_head(args);
  if ((pid = my_forkpty(&master, NULL, &t, &w)) < 0)
    exit(write(2, "my_forkpty\n", 12));
  if (pid == 0)
    {
      if (args->flag_c == 0)
        {
          execl(args->term, "sh", 0);
          exit(write(2, "execl\n", 7));
        }
      else
        {
          execlp(args->cmd, args->cmd, 0);
          exit(write(2, "execl\n", 7));
        }
    }
  loop(master, args);
  ioctl_restore();
  exit_end(args);
  return (0);
}
