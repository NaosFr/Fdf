/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:28:44 by ncella            #+#    #+#             */
/*   Updated: 2017/12/10 09:55:49 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_free_char(char **str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int		**ft_convert_to_int(char *buffer, t_mlx *smlx)
{
	char	**str;
	int		**dest;
	int		i;
	int		j;
	int		y;

	str = ft_split_whitespaces(buffer);
	dest = malloc(sizeof(int*) * smlx->nb_lines);
	i = 0;
	y = 0;
	while (y < smlx->nb_lines)
	{
		dest[y] = malloc(sizeof(int) * smlx->len);
		j = 0;
		while (j < smlx->len)
		{
			dest[y][j] = ft_atoi(str[i]);
			j++;
			i++;
		}
		y++;
	}
	ft_free_char(str);
	return (dest);
}

static void		ft_free_int(t_mlx *smlx)
{
	int		y;

	y = 0;
	while (y < smlx->nb_lines)
	{
		free(smlx->dest[y]);
		y++;
	}
	free(smlx->dest);
}

char			ft_put_map(t_mlx *smlx)
{
	int		*my_image_int;
	int		i;
	int		j;

	j = 0;
	i = 0;
	my_image_int = (int*)smlx->my_image_string;
	smlx->dest = ft_convert_to_int(smlx->cpy_buffer, smlx);
	ft_put_map_algo(my_image_int, smlx, i, j);
	smlx->my_image_string = (char*)my_image_int;
	ft_free_int(smlx);
	return (*smlx->my_image_string);
}
