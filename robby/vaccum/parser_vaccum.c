/*
** parser_vaccum.c for parser_vaccum in /home/loverg_c//RATTRAPAGE/rattrapage_c/robby/kitchen
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Tue Jun 18 11:41:42 2013 clement lovergne
** Last update Tue Jun 18 20:22:15 2013 clement lovergne
*/

#include	"../../dot_h/fonction.h"

void		check_pcoma(char **mouv)
{
  int		i;
  int		j;
  int		count;

  i = 0;
  while (i < my_strlen2(mouv))
    {
      my_putchar('\n');
      if (count_pointcoma(mouv[i]) != 1)
	error_message(" : In mouv_dav : mistake with \';\'");
      j = 0;
      count = 0;
      while (mouv[i][j] != ';')
	j++;
      if (j >= 3 || j == 0)
	error_message(" : In mouv_dav : value is too long or not exist");
      j++;
      while (mouv[i][j])
	{
	  count++;
	  j++;
	}
      if (count > 3 || count == 0)
	error_message(" : In mouv_dav : value is too long or not exist");
      i++;
    }
}

void		check_all_number(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] > '9' && str[i] < '0' && str[i] != ';')
	error_message(" : In mouv_dav : wrong values");
      i++;
    }
  if ((str[0] > '2' || str[0] < '0') && str[2] == ';')
    error_message(" : In mouv_dav : wrong values");
  i = 0;
  while (str[i] != ';')
    i++;
  if (i != 1)
    if (str[0] == '2' && str[1] != '0' && str[1] != ';')
      error_message(" : In mouv_dav : wrong values");
  i++;
  if ((str[i] > '2' || str[i] < '0') && str[i + 1])
    error_message(" : In mouv_dav : wrong values");
  if (str[i] == '2' && str[i + 1] && str[i + 1] != '0')
    error_message(" : In mouv_dav : wrong values");
}
