/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:21:59 by ncella            #+#    #+#             */
/*   Updated: 2017/12/08 13:35:17 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_key_move(int keycode, t_mlx *smlx)
{
	if (keycode == 126)
		smlx->start_y -= 20;
	if (keycode == 125)
		smlx->start_y += 20;
	if (keycode == 123)
		smlx->start_x -= 20;
	if (keycode == 124)
		smlx->start_x += 20;
}

static void		ft_key_scale(int keycode, t_mlx *smlx)
{
	if (keycode == 27)
		smlx->scale -= 1;
	if (keycode == 24)
		smlx->scale += 1;
}

static void		ft_key_size(int keycode, t_mlx *smlx)
{
	if (keycode == 7)
		smlx->size_x += 1;
	if (keycode == 6)
		smlx->size_x -= 1;
	if (keycode == 1)
		smlx->size_y += 1;
	if (keycode == 0)
		smlx->size_y -= 1;
	if (keycode == 2)
	{
		smlx->start_y += 1;
		smlx->size_x += 1;
		smlx->size_y += 1;
	}
	if (keycode == 8)
	{
		smlx->start_y -= 1;
		smlx->size_x -= 1;
		smlx->size_y -= 1;
	}
}

static void		ft_key_color(int keycode, t_mlx *smlx)
{
	if (keycode == 18)
		smlx->type_color = 1;
	if (keycode == 19)
		smlx->type_color = 2;
	if (keycode == 20)
		smlx->type_color = 3;
	if (keycode == 21)
		smlx->type_color = 4;
	if (keycode == 23)
		smlx->type_color = 5;
}

int				ft_key(int keycode, t_mlx *smlx)
{
	if (keycode == 53)
	{
		mlx_clear_window(smlx->mlx, smlx->win);
		free(smlx);
		exit(0);
	}
	ft_key_move(keycode, smlx);
	ft_key_scale(keycode, smlx);
	ft_key_size(keycode, smlx);
	ft_key_color(keycode, smlx);
	mlx_destroy_image(smlx->mlx, smlx->pointeur_image);
	smlx->pointeur_image = mlx_new_image(smlx->mlx, WIDTH, HEIGHT);
	ft_put_map(smlx);
	mlx_put_image_to_window(smlx->my_image_string, smlx->win,
		smlx->pointeur_image, 0, 0);
	ft_info(smlx);
	return (0);
}
