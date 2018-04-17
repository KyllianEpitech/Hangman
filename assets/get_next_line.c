/*
** get_next_line.c for gnl in /home/kyllian/Epitech/COLLES/CPE_2016_stumper7
**
** Made by Kyllian Hamadou
** Login   <kyllian.hamadou@epitech.net>
**
** Started on  Tue May 30 18:27:32 2017 Kyllian Hamadou
** Last update Tue May 30 18:19:10 2017 Kyllian Hamadou
*/

#include "hangman.h"

int	cl(char *str, int opt)
{
  int	i;

  i = 0;
  if (opt == 1)
    {
      while (str[i] != '\0')
	{
	  i = i + 1;
	}
      return (i);
    }
  else
    {
      while (str[i] != '\0')
	{
	  if (str[i] == '\n')
	    {
	      return (1);
	    }
	  i = i + 1;
	}
      return (0);
    }
}

char	*m_ralloc(char *des, char *src, int opt, int e)
{
  char	*nw;
  int	i;

  if ((nw = malloc(sizeof(char) * (cl(des, 1) + cl(src, 1) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (des[i] != '\0')
    {
      nw[e] = des[i];
      i = i + 1;
      e = e + 1;
    }
  nw[e] = '\0';
  if (opt == 2)
    return (nw);
  i = 0;
  while (src[i] != '\0')
    {
      nw[e] = src[i];
      i = i + 1;
      e = e + 1;
    }
  nw[e] = '\0';
  free(des);
  return (nw);
}

char	*update_stk(char *stk, int opt, int i, int e)
{
  char	*nw;

  nw = malloc(sizeof(char) * (cl(stk, 1) + 1));
  if (nw == NULL)
    return (NULL);
  if (cl(stk, 2) == 0)
    return (stk);
  while (stk[i] != '\n')
    {
      nw[e] = stk[i];
      e = e + 1;
      i = i + 1;
    }
  nw[e] = '\0';
  if (opt == 2)
    return (nw);
  e = 0;
  while (stk[i] != '\0')
    {
      nw[e] = stk[i + 1];
      i = i + 1;
      e = e + 1;
    }
  nw[e] = '\0';
  return (nw);
}

char	*get_stk(char *stk)
{
  static	int	process = 0;

  if (process == 0)
    {
      stk = malloc(sizeof(char) * (READ_SIZE + 1));
      if (stk == NULL)
	return (NULL);
      stk[0] = '\0';
      process = 1;
    }
  return (stk);
}

char	*get_next_line(int fd)
{
  static	char	*stk;
  t_main	v;

  v.buff = malloc(sizeof(char) * (READ_SIZE + 1));
  if (fd == -1 || v.buff == NULL || (stk = get_stk(stk)) == NULL)
    return (NULL);
  while (cl(stk, 2) == 0)
    {
      v.size = read(fd, v.buff, READ_SIZE);
      if (v.size == -1)
	return (NULL);
      v.buff[v.size] = '\0';
      stk = m_ralloc(stk, v.buff, 0, 0);
      if (v.size == 0 && cl(stk, 1) == 0)
	return (NULL);
      else if (v.size == 0 && cl(stk, 2) == 0)
	{
	  v.nw = m_ralloc(stk, stk, 2, 0);
	  stk[0] = '\0';
	  return (v.nw);
	}
    }
  v.to_ret = update_stk(stk, 2, 0, 0);
  stk = update_stk(stk, 0, 0, 0);
  return (v.to_ret);
}
