/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:56:15 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/06 14:17:30 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"
/*
	Ne gère pas encore la dernière ligne ??..
*/
int	lenght_check(t_args *d)
{
	int i;
    int j;

    i = 0;
    j = 0;
    while (d->parsing_map[i])
    {
        if (d->parsing_map[i] == '\n')
            break;
        i++;
		d->line_lenght++;
    }
//	printf("valeur de i : %d", i);
    i = 0;
    while (d->parsing_map[i])
    {
        if (d->parsing_map[i] == '\n')
        {
            if(j != d->line_lenght)
                return(0);
            else
                j = -1;
        }
		j++;
        i++;
    }
	return(1);
}

void	ft_parsing(t_args *dim)
{
	int     ret;
    char    *buffer;

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    dim->parsing_map = malloc(1);
    dim->parsing_map[0] = '\0';
    ret = 1;
    while (ret)
    {
        ret = read(dim->fd, buffer, BUFFER_SIZE);
        dim->parsing_map = mod_strnjoin(dim->parsing_map, buffer, ret - 1);
    }
    free(buffer);
	if (!lenght_check(dim))
		printf("\nerreur taille lignes\n");
	printf("Parsing Ok\n");
	
}