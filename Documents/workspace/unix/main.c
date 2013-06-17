#define _XOPEN_SOURCE

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>

#include "server.h"

void			close_server(int *client_fd)
{
  int			i;

  i = 0;
  while (i <= MAXCO_SRV)
    {
      if (close(client_fd[i]) == -1)
	fprintf(stderr, "Warning: Closing non valid file descritors");
      ++i;
    }
}

int			handle_client(int client_fd, int dst_client)
{
  char			buff[4096];
  int			wlen;
  int			rlen;
  FILE			*c_stream;

  rlen = read(client_fd, buff, 4096);
  if (0 > rlen)
    {
      fprintf(stderr, "read error\n");
      exit(EXIT_FAILURE);
    }
  wlen = write(dst_client, buff, rlen);
  if (0 > write)
    {
      fprintf(stderr, "write error\n");
      exit(EXIT_FAILURE);
    }
  return 0;
}

int			main(int ac, char **av)
{
  int			c_fd[MAXCO_SRV];
  int			s;
  int			error;

  if (ac >= 2)
    {
      s = init_sock();
      error = bind_addr(s, av[1]);
      if (-1 == error)
	return -1;
      error = 0;
      bzero(c_fd, MAXCO_SRV);
      run_serv(s, c_fd);
      close_server(c_fd);
    }
  return 0;
}
