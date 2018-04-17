/*
** compare_letter.c for cpr letter in /home/kyllian/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 19:22:05 2017 Kyllian Hamadou
** Last update Tue May 30 20:09:15 2017 Kyllian Hamadou
*/
#include "hangman.h"

int	is_notastar(char c)
{
  if (c != '*')
    return (1);
  return (0);
}

int	is_win(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (is_notastar(str[i]) == 0)
	return (0);
      i++;
    }
  return (1);
}

int	check_win_or_lost(t_hangman *hang)
{
  if (hang->try == 0)
    {
      my_putstr("\n\nYou lost!\n");
      return (1);
    }
  if (is_win(hang->word_hide) == 1)
    {
      my_putstr("\n\nCongratulations!\n");
      return (1);
    }
  return (0);
}

int	compare_letter2(t_hangman *hang, int stop, char *str)
{
  if (stop > 0)
    {
      my_putstr(hang->word_hide);
      my_putstr("\nTries: ");
      my_put_nbr(hang->try);
    }
  else
    {
      hang->try--;
      my_putstr(hang->word_hide);
      my_putchar('\n');
      my_put_err(str[0]);
      my_putstr_err(": is not in this word\n");
      my_putstr("Tries: ");
      my_put_nbr(hang->try);
    }
  return (0);
}

int	compare_letter(char *str, t_hangman *hang)
{
  int	i;
  int	stop;

  stop = 0;
  i = 0;
  while (hang->word_random[i])
    {
      if (str[0] == hang->word_random[i])
	{
	  hang->word_hide[i] = str[0];
	  stop++;
	}
      i++;
    }
  compare_letter2(hang, stop, str);
  if (check_win_or_lost(hang) == 1)
    return (1);
  return (0);
}
