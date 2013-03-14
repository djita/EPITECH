/*
** my_script.h for my_script.h in /home/bigup/prog/tek2/proj/my_script/
** 
** Made by dimitri doyen
** Login   <doyen_d@epitech.net>
** 
** Started on  Thu Feb 24 10:30:41 2011 dimitri doyen
** Last update Sun Mar  3 02:36:19 2013 Lyoma Guillou
*/

#ifndef         __MY_SCRIPT_H__
# define        __MY_SCRIPT_H__

#define _XOPEN_SOURCE
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <grp.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/select.h>
#include <time.h>

typedef struct          s_args
{
  unsigned int          flag_a;
  unsigned int          flag_q;
  unsigned int          flag_c;
  unsigned int          flag_t;
  unsigned int          flag_f;
  char                  *filename;
  char                  *term;
  char                  *cmd;
  int                   fdf;
}                       t_args;


int             my_unlockpt(int fd);
int             my_grantpt(int fd);
char            *my_ptsname(int fd);
int             my_openpty(int *amaster, int *aslave, char *name,
                           struct termios *termp, struct winsize * winp);
int             my_login_tty(int fd);
int             my_forkpty(int *amaster, char *name, struct termios *termp,
                           struct winsize *winp);
void            loop(int master, t_args *args);
int             use_select(char **buf, int *readed, fd_set *readf, int master);
void            ioctl_set();
void            init_targs(t_args *args);
void            free_targs(t_args *args);
void            set_arg_term(t_args *args);
void            set_arg_filename(int ac, char **ar, t_args *args);
int             find_arg(int ac, char **ar, char *param);
void            show_usage();
t_args          *check_args(int ac, char **ar);
void            write_head_foot(int flag, t_args *args);
void            term_header(t_args *args);


#endif      /* !__MY_SCRIPT_H__ */
