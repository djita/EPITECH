/*
** readline.c for src in /home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 11 16:23:32 2012 mickael falck
** Last update Sat May 12 17:27:58 2012 mickael falck
*/

#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include "list.h"
#include "termcaps.h"
#include "history.h"
#define BUFLEN 65535
#define PROMPT "$>"

int	capcmp(char *cap, const char *str)
{
  char	*capstr;

  if ((capstr = tgetstr(cap, NULL)) == NULL)
    return (0);
  else
    return (strcmp(capstr, str));
}

int		parse_caps(char *buf, char *input, size_t *offset, t_list **cmd)
{
  int		ret;
  size_t	tmp;

  ret = 0;
  if (!ret && (ret = !capcmp("ku", input)) && *cmd)
    {
      tmp = strlen(buf);
      while (tmp--)
	{
	  termcommand("le");
	  termcommand("dc");
	}
      strcpy(buf, ((t_cmd *)(*cmd)->data)->cmd);
      *offset = strlen(buf);
      tputstr(buf);
      if ((*cmd)->prev)
	*cmd = (*cmd)->prev;
    }
  if (!ret && (ret = !capcmp("kd", input)) && *cmd)
    {
      tmp = strlen(buf);
      while (tmp--)
	{
	  termcommand("le");
	  termcommand("dc");
	}
      strcpy(buf, ((t_cmd *)(*cmd)->data)->cmd);
      *offset = strlen(buf);
      tputstr(buf);
      if ((*cmd)->next)
      *cmd = (*cmd)->next;
    }
  if (!ret && (ret = !capcmp("kl", input)) && *offset)
    {
      /*termcommand("le");
       *offset -= 1;*/
    }
  if (!ret && (ret = !capcmp("kr", input)) && *offset < strlen(buf))
    {
      /*      termcommand("nd");
       *offset += 1;*/
    }
  if (!ret && (ret = !capcmp("kb", input)) && *offset)
    {
      termcommand("le");
      termcommand("dc");
      --*offset;
    }
  return (ret);
}

static char	*_return_rl(char *buff, char c, size_t offset)
{
  if (offset == 0 && c == 4)
    {
      tputstr("exit\n");
      return (strdup("exit"));
    }
  tputc('\n');
  return (strdup(buff));
}

char		*readline(void)
{
  char		buff[BUFLEN + 1];
  char		input[10];
  size_t	offset;
  t_list	*curcmd;
  ssize_t	rd;

  offset = 0;
  buff[offset] = '\0';
  tputstr(PROMPT);
  curcmd = get_history()->cmds;
  while (curcmd && curcmd->next)
    curcmd = curcmd->next;
  while ((rd = read(get_tty(-1), input, sizeof(input))) > 0
      && !(*input == '\n' || *input == 4)
      && offset < BUFLEN)
    {
      input[rd] = '\0';
      if (!parse_caps(buff, input, &offset, &curcmd))
	{
	  tputstr(input);
	  strncpy(buff + offset, input, BUFLEN - offset);
	  offset += rd;
	}
    }
  return (_return_rl(buff, *input, offset));
}
