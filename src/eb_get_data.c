/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eb_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 22:58:59 by ebaudet           #+#    #+#             */
/*   Updated: 2014/01/22 22:58:59 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "filler.h"

void	eb_init_data(t_data *d, int *tab)
{
	if (!d->p)
	{
		if ((d->p = (t_piece *)malloc(sizeof(t_piece))) == 0)
			perror("error malloc piece");
	}
	d->p->x = -2;
	d->p->y = -2;
	if (!d->gb)
	{
		if ((d->gb = (t_gameboard *)malloc(sizeof(t_gameboard))) == 0)
			perror("error malloc gameboard");
	}
	d->gb->x = -2;
	d->gb->y = -2;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] += 1;
	tab[4] += 1;
}

void	eb_get_data(t_data *d, int *tab)
{
	char	*line;
	char	**result;

	while (get_next_line(FD, &line))
	{
		result = ft_strsplit(line, ' ');
		if ((tab[0] == 0) && (ft_strcmp(result[0], "$$$") == 0))
		{
			d->player = (1 == ft_atoi(++result[2]) ? P1 : P2);
			tab[0]++;
		}
		else if (ft_strcmp(result[0], "Plateau") == 0
			|| tab[1] < (d->gb->y + 2))
			eb_get_board(d->gb, tab, result);
		else if (ft_strcmp(result[0], "Piece") == 0 || tab[2] < (d->p->y + 2))
			eb_get_piece(d, tab, result);
	}
}

int		eb_get_board(t_gameboard *gb, int *tab, char **term)
{
	if (tab[1] == 0)
	{
		gb->y = ft_atoi(term[1]);
		term[2][ft_strlen(term[2]) - 1] = '\0';
		gb->x = ft_atoi(term[2]);
		if (tab[3] > 1)
		{
			eb_free_tab_str(gb->board);
			tab[3] = 1;
		}
		if ((gb->board = (char **)malloc(sizeof(char *) * (gb->y + 1))) == 0)
			perror("error malloc");
		gb->board[gb->y] = '\0';
	}
	if (tab[1] > 1)
		gb->board[tab[1] - 2] = ft_strdup(term[1]);
	tab[1]++;
	return (0);
}

int		eb_get_piece(t_data *d, int *tab, char **term)
{
	if (tab[2] == 0)
	{
		d->p->y = ft_atoi(term[1]);
		term[2][ft_strlen(term[2]) - 1] = '\0';
		d->p->x = ft_atoi(term[2]);
		if (tab[4] > 1)
		{
			eb_free_tab_str(d->p->piece);
			tab[4] = 1;
		}
		if ((d->p->piece = (char **)malloc(sizeof(char *) * (d->p->y + 1)))
			== 0)
			perror("error malloc");
		d->p->piece[d->p->y] = '\0';
	}
	if (tab[2] > 0)
		d->p->piece[tab[2] - 1] = ft_strdup(term[0]);
	tab[2]++;
	if (tab[2] == (d->p->y + 1))
	{
		eb_search_pos(d);
		eb_init_data(d, tab);
	}
	return (0);
}

int		eb_free_tab_str(char **str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str[i]);
	free(str);
	return (0);
}
