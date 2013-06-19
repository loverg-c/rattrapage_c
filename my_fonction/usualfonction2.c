/*
** usualfonction2.c for usualfonction2 in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 12:57:58 2013 clement lovergne
** Last update Wed Jun 19 12:46:12 2013 clement lovergne
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"../dot_h/fonction.h"

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
  while (str[i] && str[i][0])
    i++;
  return (i);
}

void		all_to_zero2(char *str, int begin)
{
  int		i;

  i = begin + 1;
  while (str[i])
    {
      str[i - 1] = '\0';
      i++;
    }
  str[i - 1] = '\0';
}

void            my_putstr2(char **str)
{
  int           i;

  i = 0;
  while (str[i])
    {
      my_putstr(str[i]);
      my_putchar('\n');
      i++;
    }
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = 0 - nb;
    }
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
}
