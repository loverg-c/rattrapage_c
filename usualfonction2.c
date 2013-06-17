/*
** usualfonction2.c for usualfonction2 in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 12:57:58 2013 clement lovergne
** Last update Mon Jun 17 17:44:31 2013 clement lovergne
*/

#include	<unistd.h>
#include	"fonction.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int		my_strlen2(char **str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char		*my_strcpy(char *dest, char *src)
{
  int		k;

  k = 0;
  while (src[k] != '\0')
    {
      dest[k] = src[k];
      k++;
    }
  return (dest);
}

char		*no_get_next(int *i, int *k)
{
  *i = -1;
  *k = 1;
  return (NULL);
}

void		all_to_zero2(char *str, int *begin)
{
  int		i;

  i = *begin + 1;
  while (str[i])
    {
      str[i - 1] = '\0';
      i++;
    }
  str[i - 1] = '\0';
}
