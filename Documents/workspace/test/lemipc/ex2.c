#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#include <sys/wait.h>

#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
  key_t	key;
  int	sem_id;
  void	*addr;
  struct sembuf	sops;

  if (ac <= 1)
    fprintf(stdout, "Usage: %s pathname\n", av[0]);
  else
    {
      key = ftok(av[1], 0);
      fprintf(stdout, "==key: %d==\n", key);

      sem_id = semget(key, 1, SHM_R | SHM_W);
      if (sem_id < 0)
	{
	  sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
	  fprintf(stdout, "sem_id: %d\n", sem_id);
	  semctl(sem_id, 0, SETVAL, 4);
	}
      else
	{
	  fprintf(stdout, "Available sem_id: %d\n", sem_id);
	  fprintf(stdout, "value = %d\n", semctl(sem_id, 0, GETVAL));
	  sops.sem_num = 0;
	  sops.sem_op = -1;
	  sops.sem_flg = 0;
	  semop(sem_id, &sops, 1);
	  fprintf(stdout, "value = %d\n", semctl(sem_id, 0, GETVAL));
	}
    }
  return 0;
}
