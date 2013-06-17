#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#include <sys/wait.h>

#include <strings.h>
#include <unistd.h>
#include <stdio.h>

typedef struct	s_msg
{
  long	type;
  char	str[32];
}		t_msg;

int	main(int ac, char **av)
{
  key_t	key;
  int	msg_id;
  void	*addr;
  t_msg	mymsg;

  if (ac <= 1)
    fprintf(stdout, "Usage: %s pathname\n", av[0]);
  else
    {
      key = ftok(av[1], 0);
      fprintf(stdout, "==key: %d==\n", key);

      msg_id = msgget(key, SHM_R | SHM_W);
      if (msg_id < 0)
	{
	  msg_id = msgget(key, IPC_CREAT | SHM_R | SHM_W);
	  fprintf(stdout, "create msg: %d\n", msg_id);
	  msgrcv(msg_id, &mymsg, sizeof(mymsg), 42, 0);
	  fprintf(stdout, "Rcv: %s, type: %d\n", mymsg.str, mymsg.type);
	}
      else
	{
	  mymsg.type = 42;
	  bzero(mymsg.str, 32);
	  sprintf(mymsg.str, "Hello World!");
	  msgsnd(msg_id, &mymsg, sizeof(mymsg), 0);
	  msgctl(msg_id, IPC_RMID, NULL);
	}
    }
  return 0;
}
