/*
** hangman.h for .h in /home/kyllian/Epitech/COLLES/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 18:28:03 2017 Kyllian Hamadou
** Last update Tue May 30 21:42:27 2017 Kyllian Hamadou
*/

#ifndef HANGMAN_H
# define HANGMAN_H

#include <time.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#ifndef READ_SIZE
# define READ_SIZE (100)
#endif /* !READ_SIZE */

typedef	struct	s_main
{
  char	*to_ret;
  char	*buff;
  int	size;
  char	*nw;
}		t_main;

typedef	struct	s_hangman
{
  int	try;
  int	random;
  char	*word_hide;
  char	*word_random;
  int	size_file;
}		t_hangman;

char	**my_explode(char *, int, int, char);

char	*get_next_line(const int);

int	my_strlen(char *);
int	is_alpha(char);
int	is_misc(char);
int	is_num(char);
int	get_word(t_hangman *, char **);
int	count_lines(char **);
int	get_try(t_hangman *, char **);
int	my_get_nbr(char *);
int	is_strnum(char *);
int	my_put_nbr(int);
int	compare_letter(char *, t_hangman *);

void	my_put_err(char);
void	my_putstr_err(char *);
void	my_putchar(char);
void	my_putstr(char *);
void	my_show_tab(char **);

#endif /* _H */
