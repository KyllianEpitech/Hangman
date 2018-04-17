/*
** get_word.c for get_word in /home/kyllian/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 18:20:27 2017 Kyllian Hamadou
** Last update Tue May 30 20:59:06 2017 Kyllian Hamadou
*/

#include "hangman.h"

int	hide_word(t_hangman *hang, char **tmp)
{
  int	i;

  i = 0;
  if ((hang->word_hide = malloc(sizeof(char) *
				my_strlen(tmp[hang->random]) + 2)) == 0)
    return (84);
  if ((hang->word_random = malloc(sizeof(char) *
				  my_strlen(tmp[hang->random]) + 2)) == 0)
    return (84);
  hang->word_random = tmp[hang->random];
  while (i < my_strlen(tmp[hang->random]))
    {
      hang->word_hide[i] = '*';
      i++;
    }
  hang->word_hide[i] = '\0';
  return (0);
}

char	*read_file(int fd, char *buff, int size)
{
  int	reading;

  if ((reading = read(fd, buff, size)) == -1)
    return (NULL);
  buff[reading] = '\0';
  return (buff);
}

int	get_word(t_hangman *hang, char **argv)
{
  int	fd;
  char	*buff;
  char	**tmp;
  int	count;

  if ((buff = malloc(sizeof(char) * 10000)) == NULL)
    return (84);
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
      my_putstr_err("Please enter a correct file name.\n");
      return (84);
    }
  buff = read_file(fd, buff, 10000);
  tmp = my_explode(buff, 0, 0, '\n');
  count = count_lines(tmp) - 1;
  hang->random = (rand() % count);
  hide_word(hang, tmp);
  return (0);
}
