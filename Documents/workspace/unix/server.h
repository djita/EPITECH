/*
** server.h for my_irc in /home/guillo_e/Documents/workspace/unix
** 
** Made by Lyoma Guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Apr 27 15:59:40 2013 Lyoma Guillou
** Last update Sun Apr 28 20:38:58 2013 Lyoma Guillou
*/

#ifndef SERVER_H
# define SERVER_H

#include <sys/types.h>
#include <sys/socket.h>

#define MAXCO_SRV	4096
#define MAX(x, y)	(x > y) ? x : y

int			get_big(int *tab, int size);
int			init_sock();
int			bind_addr(int sock_fd, char *aport);
void			run_serv(int serv_fd, int *c_fd);

#endif /* !SERVER_H */
