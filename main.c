/*
** main.c for main.c in /home/wery_a/rendu/my_select/Test/v2
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Wed Jan  7 14:24:08 2015 adrien wery
** Last update Fri Jan  9 15:15:26 2015 adrien wery
*/

#include "my_select.h"

t_l	*lis;

void	sigw(int sig)
{
  get_key(lis, 0, 0);
}

int     get_key(t_l *list, int key, int pos)
{
  struct winsize w;

  tputs(tgetstr("cl", NULL), 0, my_putchr);
  pos = get_pos(list, pos);
  ioctl(0, TIOCGWINSZ, &w);
  pos = check_key(list, key, pos);
  display_list(list, pos, w.ws_row, w.ws_col);
  return (pos);
}

int	main(int argc, char **argv, char **envp)
{
  int	key;
  int	pos;

  if (argc == 1)
    my_error("Need arguments !!!");
  set_terms(envp);
  lis = set_list(&argv[1]);
  signal(SIGWINCH, sigw);
  key = 0;
  pos = 0;
  while (key != ESCAPE_KEY)
    {
      pos = get_key(lis, key, pos);
      key = read_key();
    }
  return (0);
}