/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:15:40 by rgeral            #+#    #+#             */
/*   Updated: 2022/05/21 19:38:08 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	ft_render_frame(t_args *d, t_sprite *s)
{
	int	y;

	y = 0;
	while (y < (int)d->nbr_line * 32)
	{
		while (d->w < d->line_lenght * 32)
		{
			if (d->map[y / 32][d->w / 32] == 'P')
				mlx_put_image_to_window (d->mlx_p, d->mlx_w, s->hero, d->w, y);
			else if (d->map[y / 32][d->w / 32] == '1')
				mlx_put_image_to_window (d->mlx_p, d->mlx_w, s->tree, d->w, y);
			else if (d->map[y / 32][d->w / 32] == '0')
				mlx_put_image_to_window (d->mlx_p, d->mlx_w, s->grass, d->w, y);
			else if (d->map[y / 32][d->w / 32] == 'C')
				mlx_put_image_to_window(d->mlx_p, d->mlx_w, s->burger, d->w, y);
			else if (d->map[y / 32][d->w / 32] == 'E')
				mlx_put_image_to_window(d->mlx_p, d->mlx_w, s->fridge, d->w, y);
			mlx_put_image_to_window (d->mlx_p, d->mlx_w, s->nmb[0], 32, 0);
			d->w += 32;
		}
		d->w = 0;
		y += 32;
	}
	return (0);
}

void	ft_print_moov(t_args *d, t_sprite *s, int x, int y)
{
	if (x > 9)
		ft_print_moov(d, s, x / 10, y - 1);
	mlx_put_image_to_window(d->mlx_p, d->mlx_w,
		s->nmb[x % 10], 16 + y * 16, 0);
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

void	actions_counter(t_args *dim, t_sprite *spr)
{
	int		img_width;
	int		img_height;

	spr->nmb[0] = mlx_xpm_file_to_image(dim->mlx_p, "./images/0.xpm",
			&img_width, &img_height);
	spr->nmb[1] = mlx_xpm_file_to_image(dim->mlx_p, "./images/1.xpm",
			&img_width, &img_height);
	spr->nmb[2] = mlx_xpm_file_to_image(dim->mlx_p, "./images/2.xpm",
			&img_width, &img_height);
	spr->nmb[3] = mlx_xpm_file_to_image(dim->mlx_p, "./images/3.xpm",
			&img_width, &img_height);
	spr->nmb[4] = mlx_xpm_file_to_image(dim->mlx_p, "./images/4.xpm",
			&img_width, &img_height);
	spr->nmb[5] = mlx_xpm_file_to_image(dim->mlx_p, "./images/5.xpm",
			&img_width, &img_height);
	spr->nmb[6] = mlx_xpm_file_to_image(dim->mlx_p, "./images/6.xpm",
			&img_width, &img_height);
	spr->nmb[7] = mlx_xpm_file_to_image(dim->mlx_p, "./images/7.xpm",
			&img_width, &img_height);
	spr->nmb[8] = mlx_xpm_file_to_image(dim->mlx_p, "./images/8.xpm",
			&img_width, &img_height);
	spr->nmb[9] = mlx_xpm_file_to_image(dim->mlx_p, "./images/9.xpm",
			&img_width, &img_height);
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
	actions_counter(&dim, &spr);
	ft_render_frame(&dim, &spr);
	mlx_loop_hook(mlx_p, map_in_game, &dim);
	mlx_hook(dim.mlx_w, 17, 1L << 2, ft_exit, &dim);
	mlx_key_hook(dim.mlx_w, hero_move, &dim);
	mlx_loop(mlx_p);
}
