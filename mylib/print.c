/*
** print.c for printf in /home/kyllian/Epitech/COLLES/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 18:42:12 2017 Kyllian Hamadou
** Last update Tue May 30 20:21:32 2017 Kyllian Hamadou
*/

#include "hangman.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_put_err(char c)
{
  write(2, &c, 1);
}

void	my_putstr_err(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_put_err(str[i]);
      i++;
    }
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
