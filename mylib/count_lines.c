/*
** count_lines.c for count_line in /home/kyllian/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 18:42:13 2017 Kyllian Hamadou
** Last update Tue May 30 18:42:22 2017 Kyllian Hamadou
*/
#include "hangman.h"

int	count_lines(char **arr)
{
  int	j;

  j = 0;
  while (arr[j] != 0)
    j++;
  return (j);
}
