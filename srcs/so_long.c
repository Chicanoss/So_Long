/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:12 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/06 14:28:12 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"

int	main(void)
{
    t_args    dim;

    dim.nbr_line = 0;
    dim.line_lenght = 0;
    dim.fd = open("srcs/test.ber" , O_RDWR);
    ft_parsing(&dim);
    map_dimension(&dim);
    dim.fd = open("srcs/test.ber" , O_RDWR);
    get_map(&dim);

    //printf("%s\n", dim.parsing_map);
    //printf ("longeur des lignes : %d\n", dim.line_lenght);
    //printf("Nombre de lignes : %d\n", dim.nbr_line);
    free_all(dim.map);
    free(dim.parsing_map);
	return (1);
}