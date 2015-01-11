/*
** main.c for main.c in /home/wery_a/rendu/my_select/Test/v2
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Wed Jan  7 14:24:08 2015 adrien wery
** Last update Sun Jan 11 16:09:00 2015 adrien wery
*/

#include "my_select.h"

t_l	*lis;
char	s[256];

void			sigw(int sig)
{
  (void)sig;
  get_key(lis, 0, 0);
}

void			sigw2(int sig)
{
  (void)sig;
  tputs(tgetstr("cl", NULL), 0, my_putchr);
  unset_terms(lis);
  exit(EXIT_SUCCESS);
}

int			get_key(t_l *list, int key, int pos)
{
  struct winsize	w;
  t_sel			se;

  if (key >= 33 && key < 126)
    s[my_str(s, 0)] = key;
  else if (key == DEL_KEY && my_str(s, 0) > 0 && my_str(s, 0) < 10)
    {
      s[my_str(s, 0) - 1] = '\0';
      restore_list(list);
    }
  tputs(tgetstr("cl", NULL), 0, my_putchr);
  tputs(tgoto(tgetstr("cm", NULL), 0, w.ws_row), 0, my_putchr);
  my_str("\e[01;36m", 1);
  my_str(s, 1);
  my_str("\e[00m", 1);
  if (key == ENTREY)
    entrey(list);
  ioctl(0, TIOCGWINSZ, &w);
  pos = check_key(list, key, get_pos(list, pos));
  se.s = s;
  se.r = w.ws_row;
  se.c = w.ws_col;
  display_list(list, pos, se);
  display_numb(list, w.ws_row, w.ws_col);
  return (pos);
}

int			main(int argc, char **argv, char **envp)
{
  int			key;
  int			pos;

  if (argc == 1)
    my_error("Need arguments !!!");
  set_terms(envp);
  lis = set_list(&argv[1]);
  signal(SIGWINCH, sigw);
  signal(SIGINT, sigw2);
  key = 0;
  pos = 0;
  my_memset(s, 0, 256);
  while (key != ESCAPE_KEY)
    {
      pos = get_key(lis, key, pos);
      key = read_key(lis);
    }
  tputs(tgetstr("cl", NULL), 0, my_putchr);
  unset_terms(lis);
  return (0);
}
