/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:19:10 by rgeral            #+#    #+#             */
/*   Updated: 2022/02/16 18:57:01 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/fdf.h"

int	main(void)
{
	void *id;
	void *win;
	int	x;
	int y;
	int color;

	y = 0;
	color = 0;
	id = mlx_init();
	win = mlx_new_window(id, 1000, 1000, "Hello");
	if (!id)
		printf("noob\n");
	y = 0;
	color = 0;
	mlx_pixel_put (id, win, x, y, color);

	mlx_loop(id);
	return(1);
}