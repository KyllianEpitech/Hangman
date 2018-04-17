##
## Makefile for stumper7 in /home/Kyllian/COLLES/
##
## Made by Kyllian Hamadou
## Login   <kyllian.Hamadou@epitech.net>
##
## Started on  Tue May 30 18:16:21 2017 Kyllian Hamadou
## Last update Tue May 30 19:26:25 2017 Kyllian Hamadou
##

SRC	=	main.c				\
		mylib/is_str.c			\
		mylib/is_str2.c			\
		mylib/my_explode.c		\
		mylib/my_get_nbr.c		\
		mylib/my_put_nbr.c		\
		mylib/my_str.c			\
		mylib/print.c			\
		mylib/count_lines.c		\
		mylib/my_show_tab.c		\
		assets/get_next_line.c		\
		assets/get_word.c		\
		assets/get_try.c		\
		assets/compare_letter.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	hangman

CFLAGS	=	-I./include -g -W -Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
