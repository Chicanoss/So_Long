/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:35:33 by rgeral            #+#    #+#             */
/*   Updated: 2022/05/22 16:06:46 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	go_up(t_args *d)
{
	if (d->map[d->y - 1][d->x] == 'C')
		d->count_burger--;
	d->map[d->y - 1][d->x] = 'P';
	d->map[d->y][d->x] = '0';
	mlx_put_image_to_window (d->mlx_p, d->mlx_w, d->spr->grass,
		d->x * 32, d->y * 32);
	d->y = d->y - 1;
}

void	go_down(t_args *d)
{
	if (d->map[d->y + 1][d->x] == 'C')
		d->count_burger--;
	d->map[d->y + 1][d->x] = 'P';
	d->map[d->y][d->x] = '0';
	mlx_put_image_to_window (d->mlx_p, d->mlx_w, d->spr->grass,
		d->x * 32, d->y * 32);
	d->y = d->y + 1;
}

void	go_right(t_args *d)
{
	if (d->map[d->y][d->x + 1] == 'C')
		d->count_burger--;
	d->map[d->y][d->x + 1] = 'P';
	d->map[d->y][d->x] = '0';
	mlx_put_image_to_window (d->mlx_p, d->mlx_w, d->spr->grass,
		d->x * 32, d->y * 32);
	d->x = d->x + 1;
}

void	go_left(t_args *d)
{
	if (d->map[d->y][d->x - 1] == 'C')
		d->count_burger--;
	d->map[d->y][d->x - 1] = 'P';
	d->map[d->y][d->x] = '0';
	mlx_put_image_to_window (d->mlx_p, d->mlx_w, d->spr->grass,
		d->x * 32, d->y * 32);
	d->x = d->x - 1;
}

int	hero_move(int keycode, t_args *d)
{
	d->actions++;
	ft_print_moov(d, d->spr, d->actions, ft_int_len(d->actions));
	if (keycode == 13 && d->map[d->y - 1][d->x] &&
	d->map[d->y - 1][d->x] != '1')
		exit_up(d);
	else if (keycode == 1 && d->map[d->y + 1][d->x] &&
	d->map[d->y + 1][d->x] != '1')
		exit_down(d);
	else if (keycode == 2 && d->map[d->y][d->x + 1] &&
	d->map[d->y][d->x + 1] != '1')
		exit_right(d);
	else if (keycode == 0 && d->map[d->y][d->x - 1] &&
	d->map[d->y][d->x - 1] != '1')
		exit_left(d);
	else if (keycode == 53)
		ft_exit(d);
	return (0);
}
