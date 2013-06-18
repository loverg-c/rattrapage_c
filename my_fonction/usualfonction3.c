/*
** usualfonction3.c for usualfonction3 in /home/loverg_c//RATTRAPAGE/my_fonction
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 22:49:26 2013 clement lovergne
** Last update Mon Jun 17 22:52:09 2013 clement lovergne
*/

#include	"../dot_h/fonction.h"

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
