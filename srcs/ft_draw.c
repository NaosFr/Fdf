/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:15:24 by ncella            #+#    #+#             */
/*   Updated: 2017/12/08 10:48:16 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		put_pixel(int *my_image_int, t_point p, int color)
{
	if ((p.x >= 0 && p.x < WIDTH) && (p.y >= 0 && p.y < HEIGHT))
		my_image_int[p.y * WIDTH + p.x] = color;
}

static void		draw_line_1(int *my_image_int,
	t_point p1, t_point p2, int color)
{
	t_point			p;

	p.x = p1.x;
	while (p.x < p2.x)
	{
		p.y = p1.y + ((p2.y - p1.y) * (p.x - p1.x)) / (p2.x - p1.x);
		put_pixel(my_image_int, p, color);
		++p.x;
	}
}

static void		draw_line_2(int *my_image_int,
	t_point p1, t_point p2, int color)
{
	t_point			p;

	p.y = p1.y;
	while (p.y < p2.y)
	{
		p.x = p1.x + ((p2.x - p1.x) * (p.y - p1.y)) / (p2.y - p1.y);
		put_pixel(my_image_int, p, color);
		++p.y;
	}
}

void			ft_draw_line(t_point p1, t_point p2,
	int *my_image_int, int color)
{
	t_point			p;

	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	p.x = ABS(p.x);
	p.y = ABS(p.y);
	if (p.x > p.y)
	{
		if (p1.x <= p2.x)
			draw_line_1(my_image_int, p1, p2, color);
		else
			draw_line_1(my_image_int, p2, p1, color);
	}
	else
	{
		if (p1.y < p2.y)
			draw_line_2(my_image_int, p1, p2, color);
		else
			draw_line_2(my_image_int, p2, p1, color);
	}
}
