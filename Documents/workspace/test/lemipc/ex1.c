#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#include <sys/wait.h>

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
  key_t	key;
  int	shm_id;
  void	*addr;
  pid_t	pid;

  if (ac <= 1)
    fprintf(stdout, "Usage: %s pathname\n", av[0]);
  else
    {
      key = ftok(av[1], 0);
      pid = fork();
      fprintf(stdout, "key: %d\n", key);
      shm_id = shmget(key, 42, IPC_CREAT | SHM_R | SHM_W);
      if (!pid)
	{
	  fprintf(stdout, "PID: %d\n", pid);
	  if (shm_id < -1)
	    {
	      shm_id = shmget(key, 42, IPC_CREAT | SHM_R | SHM_W);
	      if (shm_id < 0)
		{
		  fprintf(stderr, "error shm\n");
		  return -1;
		}
	      fprintf(stdout, "creating shm : %d\n", shm_id);
	    }
	  addr = shmat(shm_id, NULL, SHM_R | SHM_W);
	  fprintf(stdout, "shm created: %d\n", shm_id);
	  sprintf((char *) addr, "Hello IPC!\n");
	}
      if (0 != pid)
	{
	  wait(0);
	  fprintf(stdout, "PID: %d\n", pid);
	  if (shm_id < 0)
	    {
	      fprintf(stderr, "no shm available\n");
	      return -1;
	    }
	  fprintf(stdout, "shm: %d available\n", shm_id);
	  addr = shmat(shm_id, NULL, SHM_R | SHM_W);
	  printf("--> %s", (char *) addr);
	  shmctl(shm_id, IPC_RMID, NULL);
	}
    }
  return 0;
}
