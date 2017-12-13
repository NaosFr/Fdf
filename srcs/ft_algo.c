/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:57:42 by ncella            #+#    #+#             */
/*   Updated: 2017/12/10 11:08:51 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_put_color_x(t_mlx *smlx, int j, int i)
{
	if (smlx->dest[j][i] == smlx->dest[j][i + 1])
		smlx->color = ft_color(smlx->dest[j][i], smlx->type_color);
	else if (smlx->dest[j][i] > smlx->dest[j][i + 1])
		smlx->color = ft_color(smlx->dest[j][i], smlx->type_color);
	else
		smlx->color = ft_color(smlx->dest[j][i + 1], smlx->type_color);
}

static void		ft_put_color_y(t_mlx *smlx, int j, int i)
{
	if (smlx->dest[j][i] == smlx->dest[j + 1][i])
		smlx->color = ft_color(smlx->dest[j][i], smlx->type_color);
	else if (smlx->dest[j][i] > smlx->dest[j + 1][i])
		smlx->color = ft_color(smlx->dest[j][i], smlx->type_color);
	else
		smlx->color = ft_color(smlx->dest[j + 1][i], smlx->type_color);
}

static void		ft_put_map_algo_2(int *my_image_int, t_mlx *smlx, int i, int j)
{
	t_point	p1;
	t_point	p2;

	p1.x = smlx->start_x + (i * smlx->size_y) - (j * smlx->size_x);
	p1.y = smlx->start_y + (i * smlx->size_y) + (j * smlx->size_x) -
	(smlx->dest[j][i] * smlx->scale);
	if ((i + 1) != smlx->len)
	{
		p2.x = smlx->start_x + ((i + 1) * smlx->size_y) - (j * smlx->size_x);
		p2.y = smlx->start_y + ((i + 1) * smlx->size_y) + (j * smlx->size_x) -
		(smlx->dest[j][i + 1] * smlx->scale);
		ft_put_color_x(smlx, j, i);
		ft_draw_line(p1, p2, my_image_int, smlx->color);
	}
	if ((j + 1) != smlx->nb_lines)
	{
		p2.x = smlx->start_x + (i * smlx->size_y) - ((j + 1) * smlx->size_x);
		p2.y = smlx->start_y + (i * smlx->size_y) + ((j + 1) * smlx->size_x) -
		(smlx->dest[j + 1][i] * smlx->scale);
		ft_put_color_y(smlx, j, i);
		ft_draw_line(p1, p2, my_image_int, smlx->color);
	}
}

void			ft_put_map_algo(int *my_image_int, t_mlx *smlx, int i, int j)
{
	while ((int)j < smlx->nb_lines)
	{
		i = 0;
		while (i < smlx->len)
		{
			ft_put_map_algo_2(my_image_int, smlx, i, j);
			i++;
		}
		j++;
	}
}
