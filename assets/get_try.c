/*
** get_try.c for get_try in /home/kyllian/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 19:11:37 2017 Kyllian Hamadou
** Last update Tue May 30 20:09:57 2017 Kyllian Hamadou
*/
#include "hangman.h"

int	get_try(t_hangman *hang, char **argv)
{
  if (argv[2] != NULL && is_strnum(argv[2]) == 1)
    {
      hang->try = my_get_nbr(argv[2]);
    }
  else
    hang->try = 10;
  return (0);
}
