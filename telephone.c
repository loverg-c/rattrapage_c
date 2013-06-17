/*
** telephone.c for telephone in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 11:22:50 2013 clement lovergne
** Last update Mon Jun 17 16:15:53 2013 clement lovergne
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"fonction.h"

static void	display_choice(char **commande)
{
  int		i;

  i = 0;
  my_putstr("You can do : ");
  while (commande[i])
    {
      my_putstr(commande[i]);
      if (commande[i + 1])
	my_putstr(", ");
      else
	my_putstr("\n\n");
      i++;
    }
}

static int	done_it(char **what_todo,
			char **commande, char *buffer)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (commande[i] && my_strcmp(commande[i], buffer) != 0)
    i++;
  if (commande[i] == NULL)
    {
      my_putstr("Wrong command !\n\n");
      return (0);
    }
  while (what_todo[i][j] != ';')
    j++;
  j++;
  while (what_todo[i][j] != ';')
    {
      my_putchar(what_todo[i][j]);
      j++;
    }
  j++;
  my_putstr("\n\n");
  return (what_todo[i][j] - 48);
}

static void	message()
{
  char		*buffer;
  int		fd;
  int		i;
  char		n;

  n = '\n';
  if ((fd = open("last_message",  O_RDWR | O_TRUNC | O_CREAT, 0444)) == -1)
    error_message("open");
  if ((buffer = malloc(4096 * sizeof(char*))) == NULL)
    error_message("malloc");
  if ((i = read(0, buffer, 4096)) == -1)
    error_message("read");
  i = 0;
  while (buffer[i])
    {
      if (write(fd, &buffer[i], 1) == -1)
	error_message("write");
      i++;
    }
  if (write(fd, &n, 1) == -1)
    error_message("write");
  my_putchar('\n');
  free(buffer);
}

void		stay_on_phone(char **what_todo, char **commande)
{
  int		finish;
  char		*buffer;
  int		i;

  if ((buffer = malloc(4096 * sizeof(char*))) == NULL)
    error_message("malloc");
  finish = 0;
  while (finish == 0)
    {
      display_choice(commande);
      all_to_zero(buffer, 4096);
      if ((i = read(0, buffer, 4096)) == -1)
       	error_message("read");
      buffer[i - 1] = '\0';
      finish = done_it(what_todo, commande, buffer);
    }
  if (finish == 2)
    message();
  free(buffer);
  sleep(3);
}

void		free_all(char **str)
{
  int		i;

  i = my_strlen2(str) - 1;
  while (i >= 0)
    {
      free(str[i]);
      i--;
    }
  free(str);
}

void		go_to_tel(t_file *file)
{
  int		i;
  int		j;

  i = 0;
  file->wtd = NULL;
  file->wtd = pars_file(file->wtd);
  file->com = pars_commande(file->wtd);
  while (file->com[i])
    {
      j = 0;
      while (file->com[j])
	{
	  if (my_strcmp(file->com[i], file->com[j]) == 0 && i != j)
	    error_message("file : 2 * the same command");
	  printf("comj = %s, comi = %s\n", file->com[j], file->com[i]);
	  j++;
	}
      i++;
    }
}
