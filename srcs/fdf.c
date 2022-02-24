/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:19:10 by rgeral            #+#    #+#             */
/*   Updated: 2022/02/21 19:21:10 by rgeral           ###   ########.fr       */
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
int	**put_in_map(char	**splited)
{
	int line_counter;
	//int	j;
	int	**map;

	line_counter = 0;
	while(splited[line_counter])
		line_counter++; //ici c'est égal a 10 (donc le nombre de \n)
	map = ((int **)malloc((line_counter + 1) * sizeof(int *)));
	if (!map)
		return(NULL);
	line_counter = 0;
	//j = 0;
	while (splited[line_counter]) //ça segfault ici
	{
		map[line_counter][1] = ft_atoi(splited[line_counter]);
		line_counter++;
	}
	return(map);

}

int	**make_map(fd)
{
	int		i;
	int		j;
	char	buf[42];
	//char	**splited;
	char	*temp;
	int		**map = NULL;
	
	i = 0;
	j = 0;
	while(read(fd, buf, 42 > 0))
		temp = ft_strjoin(temp, buf);
	printf("%s\n", temp);
	//map = put_in_map(splited);
	return (map);
}

int	main(void)
{
	//int	**map;
	int	fd;
	//int i;

	fd = open("srcs/10-2.fdf" , O_RDWR);
	if (ft_parsing(fd) == 0)
	{
		perror("map_error");
		exit(EXIT_FAILURE);
	}
	//map = make_map(fd);
	//i = 0;
	return (1);
}