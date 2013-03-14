/*
** main.c for login_pty test in /home/guillo_e/Documents/working/tek2/unix/my_script/tp
** 
** Made by Lyoma Guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Mar  1 17:04:45 2013 Lyoma Guillou
** Last update Sat Mar  2 21:51:39 2013 Lyoma Guillou
*/

#define _XOPEN_SOURCE
#define _GNU_SOURCE

#include <pty.h>
#include <utmp.h>
#include <termios.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void			reset_ioctl()
{
  struct termios	term_p;

  tcgetattr(0, &term_p);
  term_p.c_lflag |= (ICANON | ISIG | ECHO);
  tcsetattr(0, TCSANOW, &term_p);
}

void			my_script()
{

}

int	main()
{

}

int	main(int ac, char **av, char **envp)
{
  int	m_fd = 0;
  int	s_fd = 0;
  char	*slave = NULL;
  char	buffer[4096];
  struct termios term_p;
  pid_t	pid;

  (void) ac;
  (void) av;
  //  if (!openpty(&m_fd, &s_fd, NULL, NULL, NULL))
  tcgetattr(1, &term_p);
  if (0 != (m_fd = open("/dev/ptmx", O_RDWR)))
    {
      //      printf("Name: %s\n", buffer);
      if (0 != grantpt(m_fd))
	fprintf(stderr, "Rights error\n");
      if (0 != unlockpt(m_fd))
	fprintf(stderr, "Device locked\n");

      slave = ptsname(m_fd);

      printf("master: %d\tslave: %d\n", m_fd, s_fd);
      printf("master: %s\n", ttyname(m_fd));
      printf("slave: %s\n", slave);


      if ((pid = fork()) < 0)
	return -1;
      else if (!pid)
	{
	  s_fd = open(slave, O_RDWR);
	  if (0 >= s_fd)
	    fprintf(stderr, "Slave file descriptor problem?\n");
	  printf("slave name: %s and fd: %d\n", ttyname(s_fd), s_fd);

	  int ios;
	  term_p.c_lflag = ~ICANON;
	  tcsetattr(0, TCSANOW, &term_p);
	  if (0 > write(s_fd, "Hello World!\n", strlen("Hello World!\n")))
	    fprintf(stdout, "write error\n");
	  if (0 <= read(m_fd, buffer, 4096))
	    fprintf(stdout, "%s", buffer);
	  //	  if (0 != login_tty(s_fd))
	  //	    fprintf(stderr, "Slave not available?\n");
	  fprintf(stdout, "slave fd: %d\n", s_fd);
	  /* setsid(); */
	  /* ios = ioctl(s_fd, TIOCSCTTY, NULL); */
	  /* if (ios < 0) */
	  /*   fprintf(stderr, "Slave transfer error\n"); */
	  if (s_fd)
	    {
	      fprintf(stdout, "Entering exec mode\n");
	      execve("/bin/bash", &((char *){"/bin/bash"}), envp);
	      read(m_fd, buffer, 4096);
	      fprintf(stdout, "%s", buffer);
	    }
	  close(s_fd);
	}
      else
	{
	  close(s_fd);
	  return (pid);
	}
      printf("End of Code\n");
      return 0;
      FILE	*fs = NULL;
      char	*buff = NULL;
      size_t	len = 0;
      //s = fopen(ttyname(m_fd), "r+");
      login_tty(s_fd);
      if (s_fd)
	{
	  fs = fdopen(s_fd, "r+");
	  
	  //write(m_fd, "ls -la\n", strlen("ls -la\n"));
	  while (getline(&buff, &len, fs))
	    fprintf(fs, "%s\n", buff);
	}
    }
  return (0);
}
