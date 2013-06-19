/*
** telephone.c for telephone in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 11:22:50 2013 clement lovergne
** Last update Wed Jun 19 12:55:05 2013 clement lovergne
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"../../dot_h/fonction.h"

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

  i = 0;
  my_putchar('\n');
  while (commande[i] && my_strcmp(commande[i], buffer) != 0)
    i++;
  if (commande[i] == NULL)
    {
      my_putstr("Wrong command !\n\n");
      return (0);
    }
  j = go_to_pc(what_todo[i]) + 1;
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
  my_putchar(n);
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
  sleep(2.5);
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
