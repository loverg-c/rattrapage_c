/*
** get_next.c for get_next in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 12:25:07 2013 clement lovergne
** Last update Mon Jun 17 20:32:18 2013 clement lovergne
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"../dot_h/fonction.h"

static char	*my_realloc(char *str)
{
  char		*dest;
  int		n;

  n = 0;
  while (str[n])
    n++;
  dest = NULL;
  if ((dest = malloc((n + MY_SIZE) * sizeof(char))) == NULL)
    error_message("Error malloc\n");
  dest = my_strcpy(dest, str);
  free(str);
  return (dest);
}

static char	*next(t_get *get, int k)
{
  if (get->j != 0 && k <= 0)
    return (get->my_r);
  free(get->my_r);
  return (NULL);
}

static int	check_end(int *i, char *buffer)
{
  int		j;

  j = 1;
  if (buffer[*i])
    return (*i);
  else
    {
      while (buffer[j])
	{
	  buffer[j - 1] = '\0';
	  j++;
	}
      buffer[j - 1] = '\0';
    }
  return (0);
}

static void	begin(t_get *get, int *i)
{
  get->j = 0;
  *i += 1;
  if ((get->my_r = malloc(MY_SIZE * sizeof(char))) == NULL)
    error_message("Error malloc\n");
  all_to_zero2(get->my_r, 0);
}

char		*get_next_line(int fd, int a)
{
  t_get		get;
  static char	buffer [MY_SIZE];
  static int	i = -1;
  static int	k = 1;

  if (a == 0)
    return (no_get_next(&i, &k));
  begin(&get, &i);
  while (get.my_r[get.j] != '\n' && k > 0)
    {
      k = (i == 0 ? read(fd, buffer, MY_SIZE) : k);
      if (k > 0)
	{
	  while (buffer[i] && buffer[i] != '\n')
	    get.my_r[get.j++] = buffer[i++];
	  if (buffer[i] == '\n')
	    return (get.my_r);
	  i = check_end(&i, buffer);
	  get.my_r = (get.my_r[get.j] ? get.my_r :
		      my_realloc(get.my_r));
	}
    }
  return (next(&get, k));
}
