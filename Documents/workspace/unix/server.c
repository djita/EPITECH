/*
** server.c for my_irc in /home/guillo_e/Documents/workspace/unix
** 
** Made by Lyoma Guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Apr 27 16:20:51 2013 Lyoma Guillou
** Last update Sun Apr 28 21:24:50 2013 Lyoma Guillou
*/

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "server.h"

int			get_big(int *tab, int size)
{
  int			val;
  int			i;

  i = 0;
  val = 0;
  while (i <= size)
    {
      if (tab[i] > val)
	val = tab[i];
      ++i;
    }
  return (val);
}

int			init_sock()
{
  int			sock_fd;
  struct protoent	*pe;

  pe = getprotobyname("TCP");
  sock_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (0 > sock_fd)
    {
      printf("Socket failed\n");
      exit(EXIT_FAILURE);
    }
  return (sock_fd);
}

int			bind_addr(int sock_fd, char *aport)
{
  struct sockaddr_in	srv;
  int			port;
  int			optv;
  int			err;

  optv = 1;
  err = 0;
  port = atoi(aport);
  srv.sin_family = AF_INET;
  srv.sin_port = htons(port);
  srv.sin_addr.s_addr = INADDR_ANY;
  setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, (void *)&optv, sizeof(void *));
  err = bind(sock_fd, (const struct sockaddr *)&srv, sizeof(srv));
  if (0 > err)
    {
      printf("Bind failed\n");
      close(sock_fd);
    }
  err = listen(sock_fd, 42);
  if (0 > err)
    {
      printf("Listen failed\n");
      close(sock_fd);
    }
  return (err);
}

static int	_inbound_co(int serv_fd, struct sockaddr_in client, fd_set rd, fd_set wt)
{
  socklen_t	sz;
  int		fd;

  sz = sizeof(client);
  fd = accept(serv_fd, (struct sockaddr *)&client, &sz);
  if (-1 != fd)
    {
      FD_SET(fd, &rd);
      FD_SET(fd, &wt);
    }
  else
    fprintf(stderr, "Accept failure\n");
  return (fd);
}

void			run_serv(int serv_fd, int *c_fd)
{
  struct sockaddr_in	client_in[MAXCO_SRV];
  int			i;
  int			max;
  fd_set		rd_set;
  fd_set		wt_set;

  i = 0;
  FD_ZERO(&rd_set);
  FD_ZERO(&wt_set);
  FD_SET(serv_fd, &rd_set);
  while (true)
    {
      max = MAX(serv_fd, get_big(c_fd, i + 1));
      printf("loops here?\n");
      if (-1 == (select(max + 1, &rd_set, &wt_set, NULL, NULL)))
	return;
      else
	{
	  if (FD_ISSET(c_fd[0], &rd_set))
	    handle_client(c_fd[0], c_fd[1]);
	  if (FD_ISSET(c_fd[1], &rd_set))
	    handle_client(c_fd[1], c_fd[0]);
	  if (FD_ISSET(serv_fd, &rd_set))
	    {
	      c_fd[i] = _inbound_co(serv_fd, client_in[i], rd_set, wt_set);
	      if (-1 == c_fd[i])
		return;
	      ++i;
	    }
	}
    }
}
