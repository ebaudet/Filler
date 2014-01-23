/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eb_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 03:44:50 by ebaudet           #+#    #+#             */
/*   Updated: 2014/01/23 03:44:50 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	eb_test(t_data *d)
{
	eb_print_info(d);
	eb_print_board(d);
	eb_print_piece(d);
}

void	eb_print_info(t_data *d)
{
	ft_putstr_fd("player : ", 2);
	ft_putchar_fd(d->player, 2);
	ft_putstr_fd(", board [", 2);
	ft_putnbr_fd(d->gb->y, 2);
	ft_putstr_fd(",", 2);
	ft_putnbr_fd(d->gb->x, 2);
	ft_putstr_fd("], piece [", 2);
	ft_putnbr_fd(d->p->y, 2);
	ft_putstr_fd(",", 2);
	ft_putnbr_fd(d->p->x, 2);
	ft_putstr_fd("]\n", 2);
}

void	eb_print_board(t_data *d)
{
	t_pos	pos;

	pos.y = 0;
	ft_putstr_fd("map :\n", 2);
	while (pos.y < d->gb->y)
	{
		pos.x = 0;
		while (pos.x < d->gb->x)
		{
			ft_putchar_fd(d->gb->board[pos.y][pos.x], 2);
			pos.x++;
		}
		ft_putchar_fd('\n', 2);
		pos.y++;
	}
}

void	eb_print_piece(t_data *d)
{
	t_pos	pos;

	ft_putstr_fd("piece :\n", 2);
	pos.y = 0;
	while (pos.y < d->p->y)
	{
		pos.x = 0;
		while (pos.x < d->p->x)
		{
			ft_putchar_fd(d->p->piece[pos.y][pos.x], 2);
			pos.x++;
		}
		ft_putchar_fd('\n', 2);
		pos.y++;
	}
}