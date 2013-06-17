/*
** parser.c for parser in /home/loverg_c//RATTRAPAGE/rattrapage_c
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 19:34:26 2013 clement lovergne
** Last update Mon Jun 17 21:58:22 2013 clement lovergne
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"../dot_h/fonction.h"

void		pars_tel(t_file *file)
{
  int		i;
  int		j;

  i = 0;
  file->wtd = NULL;
  file->wtd = pars_file(file->wtd, "config/phone");
  file->com = pars_commande(file->wtd);
  while (file->com[i])
    {
      j = 0;
      while (file->com[j])
	{
	  if (my_strcmp(file->com[i], file->com[j]) == 0 && i != j)
	    error_message("file : 2 * the same command");
	  j++;
	}
      i++;
    }
}

static void	check_pcoma(char **mouv)
{
  int		i;
  int		j;
  int		count;

  i = 0;
  while (mouv[i])
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
      if (count >= 3 || count == 0)
	error_message(" : In mouv_dav : value is too long or not exist");
      i++;
    }
}

static void	check_all_number(char *str)
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
  if (str[i] > '2' || str[i] < '0')
    error_message(" : In mouv_dav : wrong values");
  if (str[i] == '2' && str[i + 1] && str[i + 1] != '0')
    error_message(" : In mouv_dav : wrong values");
}

void		pars_vaccum(t_file *file)
{
  int		i;

  i = 0;
  file->mouv_dab = NULL;
  file->mouv_dab = pars_file(file->mouv_dab, "config/mouv_dab");
  if (file->mouv_dab[0] == NULL)
    error_message(" : Your file is empty");
  file->mouv_dab = my_copy_line(file->mouv_dab, "0;0");
  check_pcoma(file->mouv_dab);
  while (file->mouv_dab[i])
    {
      if (my_strlen(file->mouv_dab[i]) > 6 || my_strlen(file->mouv_dab[i]) < 3)
	error_message(" : In mouv_dav : value is too long or not exist");
      my_putstr(file->mouv_dab[i]);
      my_putchar('\n');
      check_all_number(file->mouv_dab[i]);
      i++;
    }
}