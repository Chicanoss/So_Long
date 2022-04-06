/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:12 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/05 20:12:36 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
  size_t	i;
  size_t	j;
  char	*str;
  int	k;

  k = 0;
  j = ft_strlen(s1) + ft_strlen(s2) - (ft_strlen(s2) - n);
  if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
    return (NULL);
  i = -1;
  while (++i < ft_strlen(s1))
    str[i] = s1[i];
  while (i <= j && s2[k])
    {
      str[i++] = s2[k++];
    }
  str[i] = '\0';
  free(s1);
  return (str);
}

int	main(void)
{
    t_args    dim;

    dim.nbr_line = 0;
    dim.line_lenght = 0;
    dim.fd = open("srcs/test.ber" , O_RDWR);
    ft_parsing(&dim);
    map_dimension(&dim);

    printf("%s\n", dim.parsing_map);
    printf ("longeur des lignes : %d\n", dim.line_lenght);
    printf("Nombre de lignes : %d\n", dim.nbr_line);

	return (1);
}