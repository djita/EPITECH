/*
** my_script.h for my_script in /home/guillo_e/Documents/working/tek2/unix/my_script/work
** 
** Made by Lyoma Guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar  2 22:02:31 2013 Lyoma Guillou
** Last update Sun Mar  3 18:37:23 2013 Lyoma Guillou
*/

#ifndef MY_SCRIPT_H_
# define MY_SCRIPT_H_

# define _XOPEN_SOURCE
# define _BSD_SOURCE

# include <sys/select.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/time.h>

# include <stdbool.h>
# include <termios.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>

typedef struct	s_opt
{
  bool		_a;
  bool		_q;
  bool		_c;
  bool		_t;
  bool		_f;
  char		*file;
  char		*term;
  char		*cmd;
  int		fd;
}		t_opt;

enum	e_stat
  {
    BEGIN,
    END
  };

int		my_grantpt(int fd);
int		my_unlockpt(int fd);
int		my_login_tty(int fd);
char		*my_ptsname(int fd);

int		my_openpty(int *m_fd, int *s_fd, char *name, struct termios *, struct winsize *);
int		my_forkpty(int *m_fd, char *name, struct termios *, struct winsize *);

void		ioctl_set();
void		ioctl_restore();
int		use_set(char **buff, int *len, fd_set *f_set, int m_fd);
void		my_script(int master, t_opt *args);

void		free_opt(t_opt *set);
t_opt		*get_opt(int ac, char **av);

void		write_head_foot(enum e_stat flag, t_opt *args);
void		term_header(t_opt *args);

#endif /* !MY_SCRIPT_H_ */
