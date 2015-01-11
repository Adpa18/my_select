/*
** terms.c for terms in /home/wery_a/rendu/my_select/Test/v2
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Wed Jan  7 14:23:42 2015 adrien wery
** Last update Sun Jan 11 19:45:15 2015 adrien wery
*/

#include "my_select.h"

char                    *get_env(char *s, char **env)
{
  int                   i;

  i = 0;
  if (env == NULL)
    return (NULL);
  while (env[i] && my_strncmp(s, env[i], my_strlen(s) - 1) != 0)
    i += 1;
  if (env[i] == NULL)
    return (NULL);
  return (&env[i][my_strlen(s)]);
}

void                    unset_terms(t_l *list)
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
  free(list);
}
