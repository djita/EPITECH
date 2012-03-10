/*
** main.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 28 15:12:12 2011 lyoma guillou
** Last update Fri Mar  2 18:17:04 2012 lyoma guillou
*/

#include <my_sh.h>

int		main(int ac, char **av, char **envp)
{
  char		**my_env;
  int		len;

  len = my_tablen(envp);
  my_env = copy_envp(envp);
  if (ac == 1 && av[0] && my_env)
    {
      shell_init(my_env);
    }
  my_putstr("exit\n");
  return (0);
}
