/*
** usualfonction3.c for usualfonction3 in /home/loverg_c//RATTRAPAGE/rattrapage_c
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 24 14:14:45 2013 clement lovergne
** Last update Mon Jun 24 14:31:43 2013 clement lovergne
*/

#include	"../dot_h/fonction.h"

int		set_copy_nb(int *x1, int *xc, int *y1, int *yc)
{
  *x1 = *xc;
  *y1 = *yc;
  return (1);
}

void		comp_and_set(int *v1, int *v2)
{
  if ((*v1 - *v2) < 0)
    *v1 += 1;
  else
    *v1 -= 1;
}
