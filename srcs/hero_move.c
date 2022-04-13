/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:35:33 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/13 18:20:25 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	go_up(t_args *d)
{
	if (d->map[d->player_pos->y - 1][d->player_pos->x] == 'C')
		d->count_burger--;
	d->map[d->player_pos->y - 1][d->player_pos->x] = 'P';
	d->map[d->player_pos->y][d->player_pos->x] = '0';
	d->player_pos->y = d->player_pos->y - 1;
}

void	go_down(t_args *d)
{
	if (d->map[d->player_pos->y + 1][d->player_pos->x] == 'C')
		d->count_burger--;
	d->map[d->player_pos->y + 1][d->player_pos->x] = 'P';
	d->map[d->player_pos->y][d->player_pos->x] = '0';
	d->player_pos->y = d->player_pos->y + 1;
}

void	go_right(t_args *d)
{
	if (d->map[d->player_pos->y][d->player_pos->x + 1] == 'C')
		d->count_burger--;
	d->map[d->player_pos->y][d->player_pos->x + 1] = 'P';
	d->map[d->player_pos->y][d->player_pos->x] = '0';
	d->player_pos->x = d->player_pos->x + 1;
}

void	go_left(t_args *d)
{
	if (d->map[d->player_pos->y][d->player_pos->x - 1] == 'C')
		d->count_burger--;
	d->map[d->player_pos->y][d->player_pos->x - 1] = 'P';
	d->map[d->player_pos->y][d->player_pos->x] = '0';
	d->player_pos->x = d->player_pos->x - 1;
}
void hero_move(int	keycode, t_args *d)
{
	if (keycode == 13 && d->map[d->player_pos->y - 1][d->player_pos->x] && d->map[d->player_pos->y - 1][d->player_pos->x] != '1')
		exit_up(d);
	else if (keycode == 1 && d->map[d->player_pos->y + 1][d->player_pos->x] && d->map[d->player_pos->y + 1][d->player_pos->x] != '1')
		exit_down(d);
	else if (keycode == 2 && d->map[d->player_pos->y][d->player_pos->x + 1] && d->map[d->player_pos->y][d->player_pos->x + 1] != '1')
		exit_right(d);
	else if (keycode == 0 && d->map[d->player_pos->y][d->player_pos->x - 1] && d->map[d->player_pos->y][d->player_pos->x - 1] != '1')
		exit_left(d);
}
