/*
** main.c for main in /home/kyllian/Epitech/COLLES/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 18:27:09 2017 Kyllian Hamadou
** Last update Tue May 30 21:48:26 2017 Kyllian Hamadou
*/

#include "hangman.h"

int	check_errors(t_hangman *hang, int argc, char **argv)
{
  if (argc == 1)
    {
      my_putstr_err("Please enter a file with words.\n");
      return (84);
    }
  if (argc != 1)
    {
      if (argv[2] != NULL && is_strnum(argv[2]) != 1)
	{
	  my_putstr_err("NaN.\n");
	  return (84);
	}
      if (get_word(hang, argv) == 84)
	return (84);
      get_try(hang, argv);
    }
  return (0);
}

int		main(int argc, char **argv)
{
  char		*s;
  t_hangman	*hang;

  srand(time(NULL));
  if ((hang = malloc(sizeof(t_hangman))) == NULL)
    return (84);
  if (check_errors(hang, argc, argv) == 84)
    return (84);
  my_putstr(hang->word_hide);
  my_putstr("\nTries: ");
  my_put_nbr(hang->try);
  my_putstr("\n\nYour letter: ");
  while ((s = get_next_line(0)))
    {
      if (compare_letter(s, hang) == 1)
	return (0);
      my_putstr("\n\nYour letter: ");
      free(s);
    }
  return (0);
}
