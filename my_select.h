/*
** my_select.h for my_select in /home/wery_a/rendu/my_select/Test
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Jan  6 21:12:47 2015 adrien wery
** Last update Fri Jan  9 17:29:18 2015 adrien wery
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

#include <ncurses/curses.h>
#include <term.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <signal.h>

# define UP_KEY 165
# define DOWN_KEY 166
# define RIGHT_KEY 167
# define LEFT_KEY 168
# define SPACE_KEY 32
# define DEL_KEY 127
# define ESCAPE_KEY 27
# define ENTREY 10

typedef struct	s_list
{
  char		*str;
  int		selected;
  int		deleted;
}		t_l;

typedef struct	s_select
{
  struct termios old;
  int		fd;
  char		**av;
}		t_sel;

void            my_putchar(char c);
int		my_putchr(int c);
void            my_error(char *s);
char		*my_memset(char *s, char c, int size);
void		*my_malloc(int size);
int		my_strncmp(char *s1, char *s2, int nb);
int		my_str(char *s, int mode);
int             main(int argc, char **argv, char **envp);
char		*get_env(char *s, char **env);
int		set_terms(char **env);
void		unset_terms();
void		underline(char *s);
void		r_video(char *s);
int		read_key();
int		get_key(t_l *list, int key, int pos);
void		sigw(int sig);
int		get_pos(t_l *list, int pos);
int		move_pos(t_l *list, int pos, int step, int neg);
void		restore_list(t_l *list);
int		check_key(t_l *list, int key, int pos);
t_l		*set_list(char **s);
int		display_list(t_l *list, int pos, int ws_row, int ws_col);
int		display_list_2(t_l *list, int i, int pos);
int		display_small(int x, int ws_col);
int		entrey(t_l *list);
int		quit(t_l *list);

#endif /* !MY_SELECT_H_ */
