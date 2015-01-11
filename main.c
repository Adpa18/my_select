/*
** main.c for main.c in /home/wery_a/rendu/my_select/Test/v2
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Wed Jan  7 14:24:08 2015 adrien wery
** Last update Sun Jan 11 19:38:46 2015 adrien wery
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

int                     set_terms(char **env)
{
  struct termios        terms;
  char                  *term;

  if (tcgetattr(0, &terms) == -1)
    my_error("Error : tcgetattr return -1");
  terms.c_lflag &=  ~ICANON;
  terms.c_lflag &=  ~ECHO;
  terms.c_cc[VMIN] = 1;
  terms.c_cc[VTIME] = 1;
  terms.c_iflag &= IGNBRK;
  if (tcsetattr(0, TCSANOW, &terms) == -1)
    my_error("Error : tcsetattr return -1");
  term = get_env("TERM=", env);
  if (term == NULL || tgetent(NULL, term) != 1)
    {
      unset_terms(lis);
      my_error("Get Env Error !!!");
    }
  tputs(tgetstr("vi", NULL), 0, my_putchr);
  return (0);
}

int			get_key(t_l *list, int key, int pos)
{
  struct winsize	w;
  t_sel			se;

  if (key >= 33 && key < 126 &&  my_strlen(s) < 100)
    s[my_strlen(s)] = key;
  else if (key == DEL_KEY && my_strlen(s) > 0)
    {
      s[my_strlen(s) - 1] = '\0';
      restore_list(list);
    }
  tputs(tgetstr("cl", NULL), 0, my_putchr);
  if (key == ENTREY)
    entrey(list);
  ioctl(0, TIOCGWINSZ, &w);
  pos = check_key(list, key, get_pos(list, pos));
  se.s = s;
  se.r = w.ws_row;
  se.c = w.ws_col;
  tputs(tgoto(tgetstr("cm", NULL), 0, w.ws_row), 0, my_putchr);
  color_print("\e[01;36m");
  my_str(s, 1, "\e[01;35m", "\e[01;36m");
  color_print("\e[00;37m");
  display_numb(list, w.ws_row, w.ws_col);
  display_list(list, pos, se);
  return (pos);
}

int			main(int argc, char **argv, char **envp)
{
  int			key;
  int			pos;

  if (argc == 1)
    my_error("Need arguments !!!");
  set_terms(envp);
  lis = set_list(argc, argv);
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
