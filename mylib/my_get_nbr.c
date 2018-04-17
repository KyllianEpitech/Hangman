/*
** get_nbr.c for get_nbr.c in /home/jonathan.schulho/Prog_Elem/colles/CPE_2016_stumper7
**
** Made by Jonathan Schulhof
** Login   <jonathan.schulhof@epitech.eu>
**
** Started on  Tue May 30 19:22:09 2017 Jonathan Schulhof
** Last update Tue May 30 18:18:20 2017 Kyllian Hamadou
*/

#include "hangman.h"

int	my_power_rec(int nb, int power)
{
  int	result;

  if (power == 0)
    return (1);
  else if (power < 0)
    return (0);
  else if (power > 1)
    {
      result = my_power_rec(nb, power - 1) * nb;
      if (result < 0)
	return (0);
      else
	return (result);
    }
  else
    return (nb);
}

int	count_nbr(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  nb = nb + 1;
	}
      i = i + 1;
    }
  return (nb);
}

int	my_get_nbr(char *str)
{
  int	i;
  int	sign;
  int	power;
  int	result;

  i = 0;
  sign = 1;
  result = 0;
  power = count_nbr(str) - 1;
  while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  result = result + (str[i] - 48) * my_power_rec(10, power);
	  power--;
	}
      if (str[i] == '-')
	sign = sign * (-1);
      if (str[i] == '+')
	sign = sign * 1;
      i++;
    }
  result = result * sign;
  return (result);
}
