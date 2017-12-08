/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:28:50 by ncella            #+#    #+#             */
/*   Updated: 2017/12/07 17:47:15 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_info(t_mlx *smlx)
{
	mlx_string_put(smlx->mlx, smlx->win, 10, 0, 0x00FFFFFF, "=== ncella ===");
	mlx_string_put(smlx->mlx, smlx->win, 10, 30, 0x00FFFFFF, "scale +    : +");
	mlx_string_put(smlx->mlx, smlx->win, 10, 50, 0x00FFFFFF, "scale -    : -");
	mlx_string_put(smlx->mlx, smlx->win, 10, 70, 0x00FFFFFF, "zoom  +    : x");
	mlx_string_put(smlx->mlx, smlx->win, 10, 90, 0x00FFFFFF, "zoom  -    : z");
	mlx_string_put(smlx->mlx, smlx->win, 10, 110, 0x00FFFFFF, "size_x +   : s");
	mlx_string_put(smlx->mlx, smlx->win, 10, 130, 0x00FFFFFF, "size_x -   : a");
	mlx_string_put(smlx->mlx, smlx->win, 10, 150, 0x00FFFFFF, "size_y +   : x");
	mlx_string_put(smlx->mlx, smlx->win, 10, 170, 0x00FFFFFF, "size_y -   : z");
	mlx_string_put(smlx->mlx, smlx->win, 10, 190, 0x00FFFFFF,
		"use arrow  : move");
	mlx_string_put(smlx->mlx, smlx->win, 10, 210, 0x00FFFFFF,
		"1 -> 5     : color");
	mlx_string_put(smlx->mlx, smlx->win, 10, 230, 0x00FFFFFF,
		"exit       : esc");
}
