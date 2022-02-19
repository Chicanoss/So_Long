/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:19:10 by rgeral            #+#    #+#             */
/*   Updated: 2022/02/18 12:26:14 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/fdf.h"

int	draw_line (void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
   		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
    	pixelX += deltaX;
    	pixelY += deltaY;
    	--pixels;
	}
	return(1);
}

int	main(void)
{
	void *id;
	void *win;
	int y;
	int color;

	y = 0;
	color = 0;
	id = mlx_init();
	win = mlx_new_window(id, 300, 300, "Hello");
	if (!id)
		printf("noob\n");
	y = 0;
	color = 0;
	//mlx_pixel_put (id, win, x, y, color);
	draw_line(id, win, 0, 0, 300, 300, 0xFFFFFF);
	draw_line(id, win, 300, 0, 0, 300, 0xFFFFFF);

	mlx_loop(id);
	return(1);
}