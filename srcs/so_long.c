/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:12 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/05 17:29:39 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
  int	i;
  int	j;
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
    int     fd;
    int     ret;
    char    buf[42];
    char    *values;

    fd = open("srcs/test.ber" , O_RDWR);
    values = malloc(1);
    if (!values)
        return (0);
    *values = '\0';
    ret = 1;
    while (ret)
    {
        ret = read(fd, buf, 42);
        values = ft_strnjoin(values, buf, ret - 1);
    }
    printf("%s", values);
	return (1);
}