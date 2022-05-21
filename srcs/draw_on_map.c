/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:15:40 by rgeral            #+#    #+#             */
/*   Updated: 2022/05/21 13:15:50 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	ft_render_frame(t_args *d, t_sprite *s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (int)d->nbr_line * 32)
	{
		while (x < d->line_lenght * 32)
		{
			if (d->map[y / 32][x / 32] == 'P')
				mlx_put_image_to_window (d->mlx_p, d->mlx_w, s->hero, x, y);
			else if (d->map[y / 32][x / 32] == '1')
				mlx_put_image_to_window (d->mlx_p, d->mlx_w, s->tree, x, y);
			else if (d->map[y / 32][x / 32] == '0')
				mlx_put_image_to_window (d->mlx_p, d->mlx_w, s->grass, x, y);
			else if (d->map[y / 32][x / 32] == 'C')
				mlx_put_image_to_window (d->mlx_p, d->mlx_w, s->burger, x, y);
			else if (d->map[y / 32][x / 32] == 'E')
				mlx_put_image_to_window (d->mlx_p, d->mlx_w, s->fridge, x, y);
			x += 32;
		}
		x = 0;
		y += 32;
	}
	return (0);
}

int	map_in_game(t_args *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (int)d->nbr_line * 32)
	{
		while (x < d->line_lenght * 32)
		{
			if (d->map[y / 32][x / 32] == 'P')
				mlx_put_image_to_window
				(d->mlx_p, d->mlx_w, d->spr->hero, x, y);
			x += 32;
		}
		x = 0;
		y += 32;
	}
	return (0);
}

void	draw_on_map(t_args	dim)
{
	t_sprite	spr;
	void		*mlx_p;
	void		*mlx_w;
	int			w;
	int			h;

	mlx_p = mlx_init();
	mlx_w = mlx_new_window \
	(mlx_p, dim.line_lenght * 32, dim.nbr_line * 32, "./so_long");
	dim.mlx_p = mlx_p;
	dim.mlx_w = mlx_w;
	dim.spr = &spr;
	spr.hero = mlx_xpm_file_to_image(mlx_p, "images/hero.xpm", &w, &h);
	spr.tree = mlx_xpm_file_to_image(mlx_p, "images/bush.xpm", &w, &h);
	spr.grass = mlx_xpm_file_to_image(mlx_p, "images/grass.xpm", &w, &h);
	spr.burger = mlx_xpm_file_to_image(mlx_p, "images/burger.xpm", &w, &h);
	spr.fridge = mlx_xpm_file_to_image(mlx_p, "images/fridge.xpm", &w, &h);
	ft_render_frame(&dim, &spr);
	mlx_loop_hook(mlx_p, map_in_game, &dim);
	mlx_key_hook(dim.mlx_w, hero_move, &dim);
	mlx_loop(mlx_p);
}
