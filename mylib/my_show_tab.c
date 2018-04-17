/*
** my_show_tab.c for my_show_tab in /home/kyllian/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 18:39:33 2017 Kyllian Hamadou
** Last update Tue May 30 18:40:37 2017 Kyllian Hamadou
*/
#include "hangman.h"

void	my_show_tab(char **tab)
{
  int	j;

  j = 0;
  while (tab[j])
    {
      my_putstr(tab[j]);
      my_putchar('\n');
      j++;
    }
}
