/*
** readline.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 11 16:23:32 2012 mickael falck
** Last update Sun May 20 21:54:54 2012 mickael falck
*/

#include <sys/types.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <term.h>
#include "list.h"
#include "history.h"
#include "readline.h"
#include "termcaps.h"
#include "my_strndup.h"
#include "parse_caps.h"

static char	*_return_rl(t_readline *rlbag)
{
  rlbag->cur_cmd = NULL;
  if (rlbag->oldbuff)
    free(rlbag->oldbuff);
  if ((*(rlbag->input) == 4 && rlbag->offset == 0)
      || (*(rlbag->input) == 0 && get_tty(-1) == 0))
    {
      tputstr("exit\n");
      return (strdup("exit"));
    }
  if (get_tty(-1) == 0)
    {
      rlbag->input[strlen(rlbag->input) - 1] = 0;
      return (strdup(rlbag->input));
    }
  tputc('\n');
  return (strdup(rlbag->buff));
}

static void	_init_rlbag(t_readline *rlbag)
{
  rlbag->offset = 0;
  rlbag->buff[rlbag->offset] = '\0';
  memset(rlbag->input, 0, sizeof(rlbag->input));
  rlbag->oldbuff = strdup("");
  rlbag->history = get_history();
  rlbag->cur_cmd = rlbag->history->cmds;
  while (rlbag->cur_cmd && rlbag->cur_cmd->next)
    rlbag->cur_cmd = rlbag->cur_cmd->next;
  if (isatty(0))
    tputstr(PROMPT);
}

static void	_clearstr(t_readline *rlbag)
{
  size_t	buflen;
  size_t	oldlen;
  size_t	tmp;

  oldlen = strlen(rlbag->oldbuff);
  buflen = strlen(rlbag->buff);
  tmp = oldlen - (oldlen && buflen < oldlen);
  while (tmp--)
    {
      termcommand("le");
      termcommand("dc");
    }
  if (oldlen == 1)
    termcommand("dc");
  if (isatty(0))
    tputstr(rlbag->buff);
  tmp = buflen - (buflen != 0 && oldlen < buflen);
  while (tmp != rlbag->offset)
    {
      termcommand("le");
      tmp += (tmp < rlbag->offset) ? 1 : -1;
    }
}

static int	_inner_while(ssize_t rd, t_readline *rl)
{
  size_t	maxlen;
  char		*tmp;
  int		ret;

  if (rl->oldbuff && (rl->input[rd] = 0) == 0)
    free(rl->oldbuff);
  rl->oldbuff = my_strndup(rl->buff, BLEN);
  if (!(ret = parse_caps(rl)) && *rl->input != 4
      && *rl->input != 27)
    {
      tmp = my_strndup(rl->buff, BLEN);
      maxlen = sizeof(rl->input);
      maxlen = (maxlen < BLEN - rl->offset) ? maxlen : BLEN - rl->offset;
      strncpy(rl->buff + rl->offset, rl->input, maxlen);
      maxlen = strlen(tmp + rl->offset);
      maxlen = (maxlen < BLEN - rl->offset - rd)
	? maxlen : BLEN - rl->offset - rd;
      strncpy(rl->buff + rl->offset + rd, tmp + rl->offset, maxlen);
      free(tmp);
    }
  return (ret);
}

char		*readline(void)
{
  t_readline	rlbag;
  int		ret;
  ssize_t	rd;

  _init_rlbag(&rlbag);
  while (((rd = read(get_tty(-1), rlbag.input, sizeof(rlbag.input) - 1)) > 0
	&& rlbag.input[rd - 1] != '\n' && *rlbag.input != 4
	&& rlbag.offset + rd < BLEN) || (*rlbag.input == 4 && rlbag.offset))
    {
      ret = _inner_while(rd, &rlbag);
      _clearstr(&rlbag);
      rlbag.offset += rd * (!ret && *rlbag.input != 4 && *rlbag.input != 27);
      memset(rlbag.input, 0, sizeof(rlbag.input) - 1);
    }
  return (_return_rl(&rlbag));
}
