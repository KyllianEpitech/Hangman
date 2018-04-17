/*
** my_put_nbr.c for myputnbr in /home/kyllian/Epitech/COLLES/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 19:29:43 2017 Kyllian Hamadou
** Last update Tue May 30 18:18:34 2017 Kyllian Hamadou
*/

#include "hangman.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + '0');
    }
  if (nb < 10)
    {
      my_putchar(nb % 10 + '0');
    }
  return (nb);
}
