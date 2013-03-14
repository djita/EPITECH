#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
  int	gpid;
  int	pid;

  if (ac >= 2)
    {
      pid = getpid();
      gpid = getpgrp();
      printf("==PID: %d, GPID: %d==\n", pid, gpid);
      if ((setpgid(pid, atoi(av[1]))) < 0)
	{
	  printf("Bad set\n");
	  return (0);
	}
    }
  while (42)
    {
      sleep(1);
      if (fork())
	execlp("./xeyes_fedo64", "./xeyes_fedo64", (char *) NULL);
      else
	wait(NULL);
    }
  return (0);
}
