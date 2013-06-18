/*
** parser.c for parser in /home/loverg_c//RATTRAPAGE/rattrapage_c
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 19:34:26 2013 clement lovergne
** Last update Tue Jun 18 12:26:31 2013 clement lovergne
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<string.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"../dot_h/fonction.h"

static char	**pars_file(char **res, char *file)
{
  char		*commande;
  int		fd;

  if ((res = malloc(1 * sizeof(char*))) == NULL)
    error_message("malloc");
  res[0] = NULL;
  if ((fd = open(file, O_RDONLY)) == -1)
    error_message("open");
  if ((commande = malloc(4096 * sizeof(char))) == NULL)
    error_message("malloc");
  while ((commande = get_next_line(fd, -1)) != NULL)
    res = my_copy_line(res, commande);
  res = my_copy_line(res, get_next_line(fd, 0));
  free(commande);
  close(fd);
  return (res);
}

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
      check_all_number(file->mouv_dab[i]);
      i++;
    }
}

void		pars_kitchen(t_file *file)
{
  file->frigo = NULL;
  file->frigo = pars_file(file->mouv_dab, "config/frigo_Robby");
  file->recettes = NULL;
  file->recettes = pars_file(file->mouv_dab, "config/recettes_Robby");
  if (file->recettes[0] == NULL || file->frigo[0] == NULL)
    error_message(" : Your file is empty");
  check_validfrigo(file->frigo);
  check_validrecette(file->recettes);
}
