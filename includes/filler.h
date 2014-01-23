/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:45:17 by ebaudet           #+#    #+#             */
/*   Updated: 2014/01/22 19:45:17 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

# define FD		0
# define P1		'O'
# define P2		'X'
# define EMPTY	'.'

typedef struct	s_gameboard
{
	int			x;
	int			y;
	char		**board;
}				t_gameboard;

typedef struct	s_piece
{
	int			x;
	int			y;
	char		**piece;
}				t_piece;

typedef struct	s_data
{
	char		player;
	t_piece		*p;
	t_gameboard	*gb;
}				t_data;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

/*
** eb_get_data.c
*/
void	eb_init_data(t_data *d, int *tab);
void	eb_get_data(t_data *d, int *tab);
int		eb_get_board(t_gameboard *gb, int *tab, char **term);
int		eb_get_piece(t_data *d, int *tab, char **term);
int		eb_free_tab_str(char **str);

/*
** eb_find_pos.c
*/
int		eb_search_pos(t_data *d);
int		eb_find_pos(t_data *d, t_pos pos);

/*
** eb_test.c
*/
void	eb_test(t_data *d);
void	eb_print_info(t_data *d);
void	eb_print_board(t_data *d);
void	eb_print_piece(t_data *d);

#endif /* FILLER_h */
