/*
** myopenpty.c for myopenpty.c in /home/bigup/prog/tek2/proj/my_script/
**
** Made by dimitri doyen
** Login   <doyen_d@epitech.net>
**
** Started on  Wed Feb 23 11:40:02 2011 dimitri doyen
** Last update Sun Mar  3 02:48:44 2013 Lyoma Guillou
*/

#include "my_script.h"

int             my_unlockpt(int fd)
{
  int           unlock = 0;

  return (ioctl(fd, TIOCSPTLCK, &unlock));
}

int             my_grantpt(int fd)
{
  int           retval, serrno, status;
  pid_t         pid, spid;
  gid_t         gid;
  char          *slave;
  sigset_t      oblock, nblock;
  struct group  *grp;

  retval = -1;
  serrno = errno;

  if ((slave = my_ptsname(fd)) != NULL)
    {
      sigemptyset(&nblock);
      sigaddset(&nblock, SIGCHLD);
      sigprocmask(SIG_BLOCK, &nblock, &oblock);

      switch (pid = fork())
        {
        case -1:
          break;
        case 0:
          dup2(fd, 0);
          sigprocmask(SIG_SETMASK, &oblock, NULL);
          execl("/usr/libexec/pt_chown", "/usr/libexec/pt_chown", NULL);
          _exit(-1);
        default:
          while((spid = waitpid(pid, &status, 0)) == -1 && (errno == EINTR));
          if (spid != -1 && WIFEXITED(status) && WEXITSTATUS(status) == 1)
            retval = 0;
          else
            errno = EACCES;
          break;
        }
      sigprocmask(SIG_SETMASK, &oblock, NULL);

      if (retval)
        {
          gid = (grp = getgrnam("tty")) ? (int)grp->gr_gid : -1;
          if (chown(slave, getuid(), gid) == -1 || chmod(slave, S_IRUSR | S_IWUSR | S_IWGRP) == -1)
            errno = EACCES;
          else
            retval = 0;
        }
    }
  if (!retval)
    errno = serrno;
  return (retval);
}

char            *my_ptsname(int fd)
{
  unsigned int  pty_num;
  static char   buff[64];

  if (ioctl(fd, TIOCGPTN, &pty_num) != 0)
    return NULL;
  snprintf(buff, sizeof(buff), "/dev/pts/%u", pty_num);
  return (buff);
}

int             my_openpty(int *amaster, int *aslave, char *name,
                           struct termios *termp, struct winsize * winp)
{
  (void)termp;
  (void)winp;
  if ((*amaster = open("/dev/ptmx", O_RDWR)) > 0)
    {
      my_grantpt(*amaster);
      my_unlockpt(*amaster);
      name = my_ptsname(*amaster);
      *aslave = open(name, O_RDWR);
      return (0);
    }
  return (-1);
}
