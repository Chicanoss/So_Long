/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:02:09 by rgeral            #+#    #+#             */
/*   Updated: 2022/05/21 16:58:56 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	top_border(t_args *d)
{
	int	i;

	i = 0;
	while (i < d->line_lenght)
	{
		if (d->map[0][i] != '1')
		{
			perror("Error\ntop border isn't closed");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	mid_border(t_args *d)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (d->map[i])
	{
		if (i >= d->nbr_line - 1)
			break ;
		while (d->map[i][j])
		{
			if (d->map[i][0] != '1' || d->map[i][d->line_lenght - 1] != '1')
			{
				perror("Error\nside border isn't closed");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	bot_border(t_args *d)
{
	int	j;

	j = 0;
	while (j < d->line_lenght)
	{
		if (d->map[d->nbr_line - 1][j] != '1')
		{
			perror("Error\nbot border isn't closed");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	borders_parsing(t_args *d)
{
	top_border(d);
	mid_border(d);
	bot_border(d);
}
