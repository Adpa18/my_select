/*
** terms.c for terms in /home/wery_a/rendu/my_select/Test/v2
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Wed Jan  7 14:23:42 2015 adrien wery
** Last update Thu Jan  8 21:46:56 2015 adrien wery
*/

#include "my_select.h"

char                    *get_env(char *s, char **env)
{
  int                   i;

  i = 0;
  if (env == NULL)
    return (NULL);
  while (env[i] && my_strncmp(s, env[i], my_str(s, 0) - 1) != 0)
    i += 1;
  if (env[i] == NULL)
    return (NULL);
  return (&env[i][my_str(s, 0)]);
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
    my_error("get env error");
  tputs(tgetstr("vi", NULL), 0, my_putchr);
  return (0);
}

void                    unset_terms()
{
  struct termios        terms;

  if (tcgetattr(0, &terms) == -1)
    my_error("Error : tcgetattr return -1");
  terms.c_lflag +=  ICANON;
  terms.c_lflag +=  ECHO;
  terms.c_cc[VMIN] = 1;
  if (tcsetattr(0, TCSANOW, &terms) == -1)
    my_error("Error : tcsetattr return -1");
  tputs(tgetstr("vs", NULL), 0, my_putchr);
  tputs(tgetstr("cl", NULL), 0, my_putchr);
}

void                    underline(char *s)
{
  tputs(tgetstr("us", NULL), 0, my_putchr);
  write(0, s, my_str(s, 0));
  tputs(tgetstr("ue", NULL), 0, my_putchr);
}

void                    r_video(char *s)
{
  tputs(tgetstr("mr", NULL), 0, my_putchr);
  write(0, s, my_str(s, 0));
  tputs(tgetstr("me", NULL), 0, my_putchr);
}
