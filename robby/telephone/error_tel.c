/*
** error_tel.c for error_tel in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 13:03:03 2013 clement lovergne
** Last update Tue Jun 18 19:39:02 2013 clement lovergne
*/

#include	"../../dot_h/fonction.h"

int		count_pointcoma(char *str)
{
  int		i;
  int		count;

  count = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == ';')
	count++;
      i++;
    }
  return (count);
}

static void	check_number(char *str)
{
  int		i;
  int		count;

  count = 0;
  i = (str[my_strlen(str) - 1] == '\n' ? my_strlen(str) - 1 : my_strlen(str));
  while (str[i] != ';')
    {
      i--;
      count++;
    }
  if (str[0])
    {
      if (count != 2)
	error_message(" : In phone file : the end values of one line");
      else if (str[i + 1] != '0' && str[i + 1] != '1' && str[i + 1] != '2')
	error_message(" : In phone file : end values can just take 0, 1 or 2");
    }
}

void		search_error(char **str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  if (i == 0)
    error_message(" : Your phone file is empty");
  i = 0;
  while (str[i][0])
    {
      if (str[i][0] == ';' || count_pointcoma(str[i]) != 2)
	error_message(" : In phone file : mistake with \';\'");
      check_number(str[i]);
      i++;
    }
}
