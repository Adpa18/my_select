/*
** my_select.h for my_select in /home/wery_a/rendu/my_select/Test
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Jan  6 21:12:47 2015 adrien wery
** Last update Sun Jan 11 16:08:09 2015 adrien wery
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

# define UP_KEY 183
# define DOWN_KEY 184
# define RIGHT_KEY 185
# define LEFT_KEY 186
# define SPACE_KEY 32
# define DEL_KEY 127
# define SUPP_KEY 295
# define BEGIN_KEY 190
# define END_KEY 188
# define ESCAPE_KEY 27
# define ENTREY 13

typedef struct	s_list
{
  char		*str;
  int		selected;
  int		deleted;
  int		finded;
}		t_l;

typedef struct	s_sel
{
  char		*s;
  int		r;
  int		c;
}		t_sel;

void            my_putchar(char c);
int		my_putchr(int c);
void            my_error(char *s);
char		*my_memset(char *s, char c, int size);
void		*my_malloc(int size);
int		my_strncmp(char *s1, char *s2, int nb);
int		my_str(char *s, int mode);
void		my_put_nbr(int nb);
int             main(int argc, char **argv, char **envp);
void		sigw(int sig);
void		sigw2(int sig);
char		*get_env(char *s, char **env);
int		set_terms(char **env);
void		unset_terms(t_l *list);
void		underline(char *s);
void		r_video(char *s);
int		get_key(t_l *list, int key, int pos);
int		read_key(t_l *list);
int		get_pos(t_l *list, int pos);
int		check_key(t_l *list, int key, int pos);
int		move_pos(t_l *list, int pos, int step, int neg);
t_l		*set_list(char **s);
void		display_list(t_l *list, int pos, t_sel se);
int		display_list_2(t_l *list, int i, int pos, char *s);
int		display_small(int x, int ws_col);
void		display_numb(t_l *list, int row, int col);
int		quit(t_l *list);
void		entrey(t_l *list);
void		restore_list(t_l *list);
void		inverse_selected(t_l *list);
void		selected_all(t_l *list);
void		deselected_all(t_l *list);

#endif /* !MY_SELECT_H_ */
