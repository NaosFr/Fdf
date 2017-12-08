/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:40:46 by ncella            #+#    #+#             */
/*   Updated: 2017/12/07 16:23:34 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_color_1(int z)
{
	if (z < -5)
		return (YELLOW);
	if (z < 0 && z >= -5)
		return (VERMILION);
	if (z == 0)
		return (RUBY);
	if (z > 0 && z <= 5)
		return (DARK_PURPLE);
	if (z > 5)
		return (RED_PURPLE);
	return (WHITE);
}

static int		ft_color_2(int z)
{
	if (z < -5)
		return (BLACK_OLIVE);
	if (z < 0 && z >= -5)
		return (AMARANTH);
	if (z == 0)
		return (PASTEL_ORANGE);
	if (z > 0 && z <= 5)
		return (BONDI_BLUE);
	if (z > 5)
		return (IVORY);
	return (WHITE);
}

static int		ft_color_3(int z)
{
	if (z < -5)
		return (SANDY_BROWN);
	if (z < 0 && z >= -5)
		return (SMOKY_BLACK);
	if (z == 0)
		return (BULGARIAN_ROSE);
	if (z > 0 && z <= 5)
		return (ROSEWOOD);
	if (z > 5)
		return (BLAZE_ORANGE);
	return (WHITE);
}

static int		ft_color_4(int z)
{
	if (z < -5)
		return (JAPANESE_INDIGO);
	if (z < 0 && z >= -5)
		return (JUNGLE_GREEN);
	if (z == 0)
		return (HANSA_YELLOW);
	if (z > 0 && z <= 5)
		return (SANDY_BROWN2);
	if (z > 5)
		return (LIGHT_RED_OCHRE);
	return (WHITE);
}

int				ft_color(int z, int type)
{
	if (type == 1)
		return (WHITE);
	if (type == 2)
		return (ft_color_1(z));
	if (type == 3)
		return (ft_color_2(z));
	if (type == 4)
		return (ft_color_3(z));
	if (type == 5)
		return (ft_color_4(z));
	return (WHITE);
}
