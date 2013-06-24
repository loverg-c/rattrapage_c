/*
** fonction.h for fonction in /home/loverg_c//RATTRAPAGE
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 10:29:36 2013 clement lovergne
** Last update Mon Jun 24 14:30:32 2013 clement lovergne
*/

#ifndef		FONCTION_H_
# define	FONCTION_H_

# define	MY_SIZE	(500)

#include	<sys/types.h>
#include	<sys/stat.h>
#include	"struct.h"

void		my_putchar(char);
void		my_putstr(char*);
void		my_putstr2(char**);
void		my_putnbr(int);
int		my_strlen(char*);
int		my_strlen2(char**);
int		my_strcmp(char*, char*);
void		error_message(char*);
void		free_all(char**);
void		all_to_zero(char *, int);
void		all_to_zero2(char *, int);
char		**my_copy_line(char**, char*);
void		search_error(char**);
void		pars_tel(t_file*);
char		**pars_commande(char**);
void		stay_on_phone(char**, char**);
void		go_to_vaccum(char**);
void		pars_vaccum(t_file*);
int		count_pointcoma(char*);
void		replace_maps(char**, t_vaccum*);
int		try_to_mouv(char**, t_vaccum*, char**, int);
void		my_robby(int*, t_vaccum*);
int		search_o(char**);
void		check_pcoma(char**);
void		check_all_number(char*);
void		go_to_kitchen(t_file*, t_all*);
void		check_validrecette(char**);
void		check_validfrigo(char**);
void		pars_kitchen(t_file*);
void		my_putinlist(t_list_rec**, char**, int*);
char		*copy_afterpc(int*, char*);
int		go_to_pc(char*);
void		*malloc_list(size_t);
char		**choose_entree(t_list_rec**, char**);
void		display_choose(char**);
int		my_strncmp(char*, char*, int);
t_list_rec	*do_list(char**);
void		check_rec(char**);
void    	check_type(t_list_rec**, t_list_rec**,
			   t_list_rec**, t_list_rec**);
int		again_choose();
int		menu2(t_list_rec**, t_list_rec**, t_list_rec**, char**);
void		sub(char*, char**, t_list_rec**);
int		what_he_choose();
int		do_the_choose(char**);
int		choose_this(t_list_rec**, char**, char**);
void		display_finnish(char**, int*);
void		sub_copy_choose(char*, t_list_rec**, char**, char**);
int		set_copy_nb(int*, int*, int*, int*);
void		comp_and_set(int*, int*);
char		**malloc_room(char**);
char		**draw_room(t_vaccum*);

#endif		/* FONCTION_H_ */
