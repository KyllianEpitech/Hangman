/*
** my_explode.c for my_explode in /home/kyllian/Epitech/COLLES/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 19:48:05 2017 Kyllian Hamadou
** Last update Tue May 30 20:31:28 2017 Kyllian Hamadou
*/

#include "hangman.h"

char	**my_explode(char *str, int e, int i, char c)
{
  char	**args;
  int	j;

  if ((args = malloc(sizeof(char *) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  if ((args[0] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	{
	  args[j][e] = '\0';
	  j = j + 1;
	  if ((args[j] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
	    return (NULL);
	}
      else
	args[j][e] = str[i];
      e = (str[i] == c) ? 0 : e + 1;
      i = i + 1;
    }
  args[j][e] = '\0';
  args[j + 1] = 0;
  return (args);
}
