/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:35:56 by ncella            #+#    #+#             */
/*   Updated: 2017/12/08 13:13:58 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_error(char *str)
{
	ft_putstr(str);
	return (1);
}

static int		map_verif_start(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if ((str[i] >= 0 && str[i] <= 32) || (str[i] >= 48 && str[i] <= 57)
				|| str[i] == 127 || str[i] == 45)
			return (1);
		i++;
	}
	return (0);
}

static int		map_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 0 && str[i] <= 32) || (str[i] >= 48 && str[i] <= 57)
				|| str[i] == 127 || str[i] == 45)
			i++;
		else
			return (0);
	}
	return (1);
}

int				fill_pixel(t_mlx *smlx, char *buffer)
{
	if (map_isdigit(buffer) == 0)
		return (0);
	if (map_verif_start(buffer) == 0)
		return (0);
	if (ft_check_map(buffer, smlx) == 0)
		return (0);
	smlx->cpy_buffer = buffer;
	ft_put_map(smlx);
	mlx_put_image_to_window(smlx->my_image_string, smlx->win,
			smlx->pointeur_image, 0, 0);
	mlx_hook(smlx->win, 2, 3, ft_key, smlx);
	ft_info(smlx);
	mlx_loop(smlx->mlx);
	ft_memdel((void**)&smlx->cpy_buffer);
	ft_memdel((void**)&smlx->my_image_string);
	ft_memdel((void**)&smlx->dest);
	ft_memdel((void**)&smlx);
	return (1);
}

int				main(int argc, char **argv)
{
	t_mlx	*smlx;
	char	*buffer;

	buffer = NULL;
	if (argc != 2)
		return (ft_error("\033[31m[ ✘ ] ./fdf test_maps/[NAME]\n"));
	if (!buffer && !(buffer = ft_strnew(BUFF_SIZE + 1)))
		return (ft_error("\033[31m[ ✘ ] error buffer\n"));
	ft_read_map(&buffer, argv[1]);
	smlx = malloc(sizeof(t_mlx));
	if ((smlx->mlx = mlx_init()) == NULL)
		return (ft_error("\033[31m[ ✘ ] mlx couldn't init\n"));
	smlx->win = mlx_new_window(smlx->mlx, WIDTH, HEIGHT, "mlx 42");
	smlx->pointeur_image = mlx_new_image(smlx->mlx, WIDTH, HEIGHT);
	smlx->my_image_string = mlx_get_data_addr(smlx->pointeur_image,
			&(smlx->bpp), &(smlx->s_l), &(smlx->endian));
	if (fill_pixel(smlx, buffer) == 0)
		return (ft_error("\033[31m[ ✘ ] error map\n"));
	return (0);
}
