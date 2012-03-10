/*
** command.c for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Dec 30 15:01:38 2011 lyoma guillou
** Last update Sat Mar  3 21:57:37 2012 lyoma guillou
*/

#include <my_sh.h>

int		_exit_built(char **env, char **nil)
{
  free(env);
  free(nil);
  return (0);
}

int		_set_env(char **env, char **add)
{
  int		var;
  int		len;
  int		i;

  i = 0;
  len = my_tablen(add);
  if (len <= 3 && len > 1)
    {
      var = my_strlen(add[1]) - 1;
      while (env[i] && my_strncmp(env[i], add[1], var - 1))
	++i;
      env[i] = my_strdup(my_strcat(add[1], "="));
      if (add[2] != NULL)
	my_strcat(env[i], add[2]);
      env[i + 1] = NULL;
      return (1);
    }
  while (env[i])
    {
      my_putstr(env[i++]);
      my_putchar('\n');
    }
  return (1);
}

int		_unset_env(char **env, char **rmv)
{
  int		i;
  int		len;
  int		var;
  int		lim;

  i = 0;
  len = my_tablen(rmv);
  if (len == 2)
    {
      var = my_strlen(rmv[1]) - 1;
      lim = my_tablen(env);
      while (env[i] && my_strncmp(env[i], rmv[1], var - 1))
	++i;
      my_memcpy(env + i, env + i + 1, lim - i);
      return (1);
    }
  my_puterr(rmv[0]);
  my_puterr(": Too few arguments.\n");
  return (1);
}

int		_ch_dir(char **env, char **path)
{
  int		len;

  len = my_tablen(path);
  if (env && len > 0)
    {
      if (path[1])
	chdir(path[1]); 
      else
	my_putstr("You need to code getenv()\n");
      return (1);
    }
  return (0);
}

static const t_built	built_in[MAX_BLT] =
{
  { "setenv"	, _set_env },
  { "unsetenv"	, _unset_env },
  { "cd"	, _ch_dir },
  { "exit"	, _exit_built }
};

int		cmd_to_exec(char *src, char **my_env)
{
  char		**arg;
  char		**tab;
  int		i;

  i = -1;
  if ((arg = my_str_to_wordtab(src)) && arg[0])
    {
      while (++i < MAX_BLT)
	if (!my_strcmp(arg[0], built_in[i].cmd))
	  return (built_in[i].fnc(my_env, arg));
      i = 0;
      tab = path_tab(arg[0], get_path(my_env));
      insert_cmd(tab);
      if (fork() == 0)
	{
	  while (tab[i] && execve(tab[i], arg, my_env) < 0)
	    ++i;
	  my_puterr(tab[0]);
	  my_puterr(": Command not found\n");
	  exit(EXIT_SUCCESS);
	}
      else
	wait(NULL);
    }
  return (1);
}
