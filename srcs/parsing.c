/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:56:15 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/09 18:06:12 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"
/*
	Ne gère pas encore la dernière ligne ??..
*/
void	check_map_char(t_args *d)
{
	int	i;

	i = 0;
	while (d->parsing_map[i])
	{
		if (d->parsing_map[i] == '1')
			i++;
		else if (d->parsing_map[i] == 'E')
			i++;
		else if (d->parsing_map[i] == '0')
			i++;
		else if (d->parsing_map[i] == 'C')
			i++;
		else if (d->parsing_map[i] == 'P')
			i++;
		else if (d->parsing_map[i] == '\n')
			i++;
		else
		{
			dprintf(1, "valeur de map[%d] : %c\n", i , d->parsing_map[i]);
			perror("Invalid char in map");
			exit(EXIT_FAILURE);
		}		
	}
}

void	ft_parsing(t_args *d)
{
	borders_parsing(d);
	check_map_char(d);

	dprintf(1 , "parsing 2 Ok\n");
}