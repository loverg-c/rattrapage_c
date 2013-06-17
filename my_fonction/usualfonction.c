/*
** usualfonction.c for usualfonction in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 10:42:49 2013 clement lovergne
** Last update Mon Jun 17 20:14:13 2013 clement lovergne
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"../dot_h/fonction.h"

void		my_putchar(char a)
{
  if (write(1, &a, 1) == -1)
    error_message("write");
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void		error_message(char *str)
{
  my_putstr("Error ");
  my_putstr(str);
  my_putstr("\n\n");
  exit(-1);
}

int		my_strcmp(char *str1, char *str2)
{
  int		i;

  i = 0;
  while (str1[i] && str2[i])
    {
      if (str1[i] != str2[i])
	return (1);
      i++;
    }
  if (str1[i] == '\0' && str2[i] == '\0')
    return (0);
  return (1);
}

void		all_to_zero(char *str, int max)
{
  int		i;

  i = 0;
  while (i < max)
    {
      str[i] = '\0';
      i++;
    }
}
