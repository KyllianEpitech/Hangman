/*
** is_str2.c for is_str2 in /home/kyllian/Epitech/COLLES/555555
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 17:46:06 2017 Kyllian Hamadou
** Last update Tue May 30 18:17:49 2017 Kyllian Hamadou
*/

#include "hangman.h"

int	is_stralpha(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (is_alpha(str[i]) == 0)
	return (0);
      i++;
    }
  return (1);
}

int	is_strmisc(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (is_misc(str[i]) == 0)
	return (0);
      i++;
    }
  return (1);
}

int	is_strnum(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (is_num(str[i]) == 0)
	return (0);
      i++;
    }
  return (1);
}
