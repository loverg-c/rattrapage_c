/*
** kitchen.c for kitchen in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 11:34:14 2013 clement lovergne
** Last update Sun Jun 23 16:29:23 2013 clement lovergne
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"../../dot_h/fonction.h"

int		go_to_pc(char *str)
{
  int		i;

  i = 0;
  while (str[i] != ';')
    i++;
  return (i);
}

static char	**my_copy(char **frigo)
{
  int		i;
  char		**tmp;

  i = 0;
  if ((tmp = malloc((my_strlen2(frigo) + 1) * sizeof(char*))) == NULL)
    error_message("malloc");
  tmp[my_strlen2(frigo)] = NULL;
  while (i < my_strlen2(frigo) + 1)
    {
      if ((tmp[i] = malloc((my_strlen(frigo[i]) + 1) *
			   sizeof(char))) == NULL)
	  error_message("malloc");
      i++;
    }
  i = 0;
  while (frigo[i][0] && frigo[i])
    {
      tmp[i] = strdup(frigo[i]);
      i++;
    }
  tmp[i] = NULL;
  return (tmp);
}

void		go_to_kitchen(t_file *file, t_all *all)
{
  int		again;
  char		**tmp1;

  tmp1 = NULL;
  again = 0;
  while (again == 0 || again == 1)
    {
      tmp1 = my_copy(file->frigo);
      again = menu2(&all->entree, &all->plat, &all->dessert, tmp1);
      free_all(tmp1);
    }
  sleep(2);
}
