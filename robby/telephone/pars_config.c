/*
** pars_config.c for pars_config in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 13:45:06 2013 clement lovergne
** Last update Tue Jun 18 12:20:44 2013 clement lovergne
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"../../dot_h/fonction.h"

char		**my_copy_line(char **res, char *line)
{
  ssize_t	t;

  t = my_strlen2(res);
  if ((res = realloc(res, (t + 2) * sizeof (char*))) == NULL)
    error_message("realloc");
  res[t] = line;
  res[t + 1] = NULL;
  return (res);
}

static void	copy_command(char **what_todo, char **commande)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (what_todo[i])
    {
      j = 0;
      while (what_todo[i][j] != ';')
	j++;
      if ((commande[i] = malloc(sizeof (char) * (j + 1))) == NULL)
	error_message("malloc");
      j = 0;
      while (what_todo[i][j] != ';')
	{
	  commande[i][j] = what_todo[i][j];
	  j++;
	}
      commande[i][j] = what_todo[i][j];
      all_to_zero2(commande[i], j);
      i++;
    }
  commande[i] = NULL;
}

char		**pars_commande(char **what_todo)
{
  int		i;
  char		**commande;
  int		j;

  search_error(what_todo);
  i = my_strlen2(what_todo);
  if ((commande = malloc(i * sizeof(char *))) == NULL)
    error_message("malloc");
  commande[i - 1] = NULL;
  copy_command(what_todo, commande);
  i = 0;
  while (commande[i])
    {
      j = 0;
      while (commande[i][j])
	{
	  if (commande[i][j] <= 'Z' && commande[i][j] >= 'A')
	    commande[i][j] += 32;
	  j++;
	}
      i++;
    }
  return (commande);
}
