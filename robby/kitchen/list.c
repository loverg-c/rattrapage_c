/*
** list.c for list in /home/loverg_c//RATTRAPAGE/rattrapage_c/robby/kitchen
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Tue Jun 18 13:26:18 2013 clement lovergne
** Last update Mon Jun 24 15:17:20 2013 clement lovergne
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"../../dot_h/fonction.h"

void		*malloc_list(size_t size)
{
  void		*rt;

  if ((rt = malloc(size)) == NULL)
    error_message("malloc");
  return (rt);
}

static char	*copy_recette(char **str, int *i, int *j)
{
  char		*recette;

  if ((recette = malloc(*j * sizeof(char))) == NULL)
    error_message("malloc");
  all_to_zero(recette, *j);
  *j = 0;
  while (str[*i][*j] != ';')
    {
      recette[*j] = str[*i][*j];
      *j += 1;
    }
  recette[*j] = '\0';
  *j += 1;
  return (recette);
}

static char	*copy_ingredient(char **str, int *i, int *j, char **afterpc)
{
  char		*res;

  res = str[*i];
  *i += 1;
  if (str[*i] && str[*i][0] != '\0')
    {
      *j = go_to_pc(str[*i]) + 1;
      *afterpc = copy_afterpc(j, str[*i]);
    }
  return (res);
}

void		my_putinlist(t_list_rec **list, char **str, int *i)
{
  t_list_rec	*elem;
  int		j;
  char		*afterpc;
  char		**res;

  if ((res = malloc(1 * sizeof(char*))) == NULL)
    error_message("malloc");
  res[0] = NULL;
  elem = malloc_list(sizeof (t_list_rec));
  j = go_to_pc(str[*i]);
  elem->recettes = copy_recette(str, i, &j);
  elem->type = copy_afterpc(&j, str[*i]);
  *i += 1;
  if (str[*i] && str[*i][0] != '\0')
    {
      j = go_to_pc(str[*i]);
      afterpc = copy_afterpc(&j, str[*i]);
      while (my_strcmp(afterpc, "entree") != 0 && str[*i] &&
	     my_strcmp(afterpc, "plat") != 0 &&
	     my_strcmp(afterpc, "dessert") != 0 && str[*i][0] != '\0')
	res = my_copy_line(res, copy_ingredient(str, i, &j, &afterpc));
    }
  elem->ingredient = res;
  elem->next = *list;
  *list = elem;
}

t_list_rec	*do_list(char **recettes)
{
  t_list_rec	*list_rec;
  int		i;
  int		j;
  char		*afterpc;

  i = 0;
  list_rec = NULL;
  while (recettes[i] && recettes[i][0] != '\0')
    {
      j = go_to_pc(recettes[i]);
      j++;
      afterpc = copy_afterpc(&j, recettes[i]);
      if (my_strcmp(afterpc, "entree") == 0 ||
	  my_strcmp(afterpc, "plat") == 0 ||
	  my_strcmp(afterpc, "dessert") == 0)
	my_putinlist(&list_rec, recettes, &i);
      else
	i++;
    }
  return (list_rec);
}
