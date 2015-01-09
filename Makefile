##
## Makefile for Makefile in /home/wery_a/rendu/Rush_marvin/Test
## 
## Made by adrien wery
## Login   <wery_a@epitech.net>
## 
## Started on  Fri Jan  2 20:37:11 2015 adrien wery
## Last update Fri Jan  9 17:36:54 2015 adrien wery
##

SRC	= main.c \
	  terms.c \
	  str.c \
	  str2.c \
	  key.c \
	  display.c \
	  list.c

CC	= gcc -g

CFLAGS	= -W -Wall -Wextra

RM	= rm -f

NAME	= my_select

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lncurses

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
