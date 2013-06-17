/*
** fonction.h for fonction in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 10:29:36 2013 clement lovergne
** Last update Mon Jun 17 18:29:06 2013 clement lovergne
*/

#ifndef		FONCTION_H_
# define	FONCTION_H_

typedef struct	s_get
{
  char		*my_r;
  int		j;
}		t_get;

typedef struct	s_file
{
  char		**wtd;
  char		**com;
}		t_file;

# define	MY_SIZE	(500)

void		my_putchar(char);
void		my_putstr(char*);
void		error_message(char*);
int		my_strcmp(char*, char*);
void		all_to_zero(char *, int);
void		all_to_zero2(char *, int);
void		go_to_tel(t_file*);
void		go_to_vaccum();
void		go_to_kitchen();
char		*get_next_line(int, int);
int		my_strlen(char*);
int		my_strlen2(char**);
void		search_error(char**);
char		*no_get_next(int*, int*);
char		*my_strcpy(char*, char*);
char		**pars_file(char **);
char		**pars_commande(char**);
void		free_all(char**);
void		stay_on_phone(char**, char**);

#endif		/* FONCTION_H_ */
