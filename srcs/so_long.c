/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:12 by rgeral            #+#    #+#             */
/*   Updated: 2022/05/21 19:36:51 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../incs/so_long.h"

void	free_all_map(char **str, t_args *d)
{
	unsigned int	i;

	i = 0;
	while ((int)i < d->nbr_line)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_ber(const char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 4)
		return (0);
	return (!ft_strcmp(&name[len - 4], ".ber"));
}

void	basic_parsing(char	**argv, int argc, t_args dim)
{
	if (is_ber(argv[1]) == 0)
	{
		perror("Error\nFile is not .BER");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
	{
		perror("Error\nPut only the map's path as ARG");
		exit(EXIT_FAILURE);
	}
	dim.fd = open(argv[1], O_RDWR);
	if (dim.fd == -1)
	{
		perror("Error\ncannot open file");
		exit(EXIT_FAILURE);
	}
}

void	initialize(t_args *dim, char	**argv)
{
	dim->count_burger = 0;
	dim->count_exit = 0;
	dim->count_char = 0;
	dim->fd = open(argv[1], O_RDWR);
	dim->nbr_line = 0;
	dim->line_lenght = 0;
	dim->actions = 0;
	dim->w = 0;
}

int	main(int argc, char	**argv)
{
	t_args	dim;

	initialize(&dim, argv);
	basic_parsing(argv, argc, dim);
	ft_get_map(&dim, argv);
	ft_parsing(&dim);
	draw_on_map(dim);
	free_all_map(dim.map, &dim);
	free(dim.parsing_map);
	return (0);
}
