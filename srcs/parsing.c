/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:56:15 by rgeral            #+#    #+#             */
/*   Updated: 2022/05/23 14:06:29 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../incs/so_long.h"

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
			perror("Error\nInvalid char in map");
			exit(EXIT_FAILURE);
		}		
	}
}

int	much_heroes(t_args *d)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (d->map[i])
	{
		while (d->map[i][j])
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
	return (1);
}

void	valid_game(t_args *d)
{
	int	i;

	i = 0;
	while (d->parsing_map[i])
	{
		if (d->parsing_map[i] == 'C')
			d->count_burger++;
		if (d->parsing_map[i] == 'E')
			d->count_exit++;
		if (d->parsing_map[i] == 'P')
			d->count_char++;
		i++;
	}
	if (d->count_burger == 0 || d->count_char == 0 || d->count_exit == 0)
	{
		perror("Error\nValid map need at least : one burger, \
one exit, one hero");
		exit(EXIT_FAILURE);
	}
}

void	ft_parsing(t_args *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	borders_parsing(d);
	check_map_char(d);
	much_heroes(d);
	valid_game(d);
	while (d->map[i])
	{
		while (d->map[i][j])
		{
			if (d->map[i][j] == 'P')
			{
				d->x = j;
				d->y = i;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	i = 0;
}
