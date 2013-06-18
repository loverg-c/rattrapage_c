/*
** struct.h for struct in /home/loverg_c//RATTRAPAGE/rattrapage_c/dot_h
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon Jun 17 18:49:36 2013 clement lovergne
** Last update Tue Jun 18 12:18:54 2013 clement lovergne
*/

#ifndef		STRUCT_H_
# define	STRUCT_H_

typedef struct	s_get
{
  char		*my_r;
  int		j;
}		t_get;

typedef struct	s_file
{
  char		**wtd;
  char		**com;
  char		**mouv_dab;
  char		**frigo;
  char		**recettes;
}		t_file;

typedef struct	s_vaccum
{
  int		robby_x;
  int		robby_y;
  int		dab_x;
  int		dab_y;
  int		old_robby_x;
  int		old_robby_y;
  int		old_dab_x;
  int		old_dab_y;
  char		old_values;
  int		nb_cycle;
  int		nb_choose;
  char		**map;
}		t_vaccum;

#endif		/* STRUCT_H_ */
