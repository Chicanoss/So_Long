/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:56:15 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/11 14:13:48 by rgeral           ###   ########.fr       */
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
			perror("Error\nInvalid char in map");
			exit(EXIT_FAILURE);
		}		
	}
}

void	much_heroes(t_args *d)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;

	while (d->map[i])
	{
		while(d->map[i][j])
		{
			if (d->map[i][j] == 'P' && count == 0)
				count++;
			else if (d->map[i][j] == 'P' && count == 1)
				d->map[i][j] = '0';
			j++;
		}
		i++;
		j = 0;
	}
	if (count == 0)
	{
		perror("Error\nNeed a hero");
		exit(EXIT_FAILURE);		
	}
}

void	valid_game(t_args *d)
{
	int	i;

	i = 0;
	d->count_burger = 0;
	d->count_exit = 0;
	while (d->parsing_map[i])
	{
		if (d->parsing_map[i] == 'C')
			d->count_burger++;
		if (d->parsing_map[i] == 'E')
			d->count_exit++;
		i++;
	}
	if (d->count_burger == 0)
	{
		perror("Error\nNeed a burger");
		exit(EXIT_FAILURE);			
	}
	if (d->count_exit == 0)
	{
		perror("Error\nNeed an exit");
		exit(EXIT_FAILURE);			
	}
}

void	ft_parsing(t_args *d)
{
	borders_parsing(d);
	check_map_char(d);
	much_heroes(d);
	valid_game(d);

	dprintf(1 , "parsing 2 Ok\n");
}