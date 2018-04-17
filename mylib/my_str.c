/*
** my_str.c for my_str... in /home/kyllian/Epitech/COLLES/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 18:51:09 2017 Kyllian Hamadou
** Last update Tue May 30 18:18:43 2017 Kyllian Hamadou
*/

#include "hangman.h"

int	my_strcmp(char *str1, char *str2)
{
  int	i;
  int	len1;
  int	len2;

  i = 0;
  len1 = my_strlen(str1);
  len2 = my_strlen(str2);
  if (len1 != len2)
    return (0);
  while (str1[i] != '\0')
    {
      if (str2[i] != str1[i])
	return (0);
      i = i + 1;
    }
  return (1);
}
