/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:11:35 by ncella            #+#    #+#             */
/*   Updated: 2017/12/07 16:03:50 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_init_size(t_mlx *smlx)
{
	int size;

	size = 1;
	while ((size * smlx->len) < (WIDTH / 3))
		size++;
	return (size);
}

void			ft_init(t_mlx *smlx)
{
	smlx->start_x = WIDTH / 2;
	smlx->start_y = HEIGHT * 0.1;
	smlx->size_x = ft_init_size(smlx);
	smlx->size_y = ft_init_size(smlx);
	smlx->scale = 2;
	smlx->type_color = 2;
}
