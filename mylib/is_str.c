/*
** is_str.c for is_str in /home/kyllian/Epitech/COLLES/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 18:33:04 2017 Kyllian Hamadou
** Last update Tue May 30 18:17:58 2017 Kyllian Hamadou
*/

#include "hangman.h"

int	is_alpha_low(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

int	is_alpha_up(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

int	is_alpha(char c)
{
  if (is_alpha_up(c) == 1 || is_alpha_low(c) == 1)
    return (1);
  return (0);
}

int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	is_misc(char c)
{
  if (is_num(c) == 0 && is_alpha(c) == 0)
    return (1);
  return (0);
}
