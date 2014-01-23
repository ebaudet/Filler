/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eb_find_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 23:01:49 by ebaudet           #+#    #+#             */
/*   Updated: 2014/01/22 23:01:49 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		eb_search_pos(t_data *d)
{
	t_pos	pos;

	pos.x = 0;
	while (pos.x <= (d->gb->x - d->p->x))
	{
		pos.y = 0;
		while (pos.y <= (d->gb->y - d->p->y))
		{
			if (eb_find_pos(d, pos) == 1)
			{
				ft_putnbr_fd(pos.y, 1);
				ft_putstr_fd(" ", 1);
				ft_putnbr_fd(pos.x, 1);
				ft_putstr_fd("\n", 1);
				return (1);
			}
			pos.y++;
		}
		pos.x++;
	}
	ft_putstr_fd("0 0\n", 1);
	return (0);
}

int		eb_find_pos(t_data *d, t_pos pos)
{
	t_pos	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp.y = pos.y;
	while (tmp.y < (pos.y + d->p->y))
	{
		tmp.x = pos.x;
		while (tmp.x < (pos.x + d->p->x))
		{
			if (d->p->piece[tmp.y - pos.y][tmp.x - pos.x] == '*'
				&& d->gb->board[tmp.y][tmp.x] == d->player)
				i++;
			if (!(d->p->piece[tmp.y - pos.y][tmp.x - pos.x] == '*'
				&& d->gb->board[tmp.y][tmp.x] != EMPTY))
				j++;
			tmp.x++;
		}
		tmp.y++;
	}
	if (i == 1 && j == ((d->p->y * d->p->x) - 1))
		return (1);
	return (0);
}
