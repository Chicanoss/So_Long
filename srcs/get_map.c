/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:28:39 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/16 14:22:00 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"

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

void	map_dimension(t_args *d)
{
    int      i;

	i = 0;
    d->nbr_line = 1;
	while (d->parsing_map[i])
	{
		if(d->parsing_map[i] == '\n')
			d->nbr_line++;
		i++;
	}
}

void    generate_map(t_args *d)
{
    int i;

    i = 0;
    d->map = ft_calloc(d->nbr_line + 1, sizeof(char *));
    while (i < d->nbr_line)
    {
        d->map[i] = ft_calloc(d->line_lenght + 1, sizeof(char)); 
        i++;
    }
    i = 0;
    while (i < d->nbr_line)
    {
        d->map[i] = get_next_line(d->fd);
        i++;
    }
    i = 0;
    while (i < d->nbr_line)
    {
        dprintf(1, "valeur de map de : %d || %s", i , d->map[i]);
        i++;
    }
    dprintf(1, "\n");
}

void last_line_check(t_args *d)
{
    if (ft_strlen(d->map[d->nbr_line - 1]) != (size_t)d->line_lenght)
    {
        /*dprintf(1, "line lenght : %d", d->line_lenght );
        dprintf(1, "taille dernière ligne : %zu\n", ft_strlen(d->map[d->nbr_line - 1]));
        dprintf(1 , "pas booon");*/
        perror("not rectangular map");
        exit(EXIT_FAILURE);
    }
}

void	ft_get_map(t_args *dim)
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
	map_dimension(dim);
	dim->fd = open("srcs/test.ber" , O_RDWR);
	generate_map(dim);
	if (!lenght_check(dim))
		printf("Error\nerreur taille lignes\n");
    last_line_check(dim);
	dprintf(1, "\nParsing Ok\n");
	
}