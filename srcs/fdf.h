/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:41:50 by ncella            #+#    #+#             */
/*   Updated: 2017/12/08 13:03:03 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 1500
# define HEIGHT 1000
# define ABS(Value) ((Value < 0) ? (Value * (-1)) : (Value))
# define BUFF_SIZE 9999
# define RED_PURPLE 0x554C72
# define DARK_PURPLE 0x5E3C5D
# define RUBY 0x832232
# define VERMILION 0xDD6031
# define YELLOW 0xEE964B
# define BLACK_OLIVE 0x393E41
# define AMARANTH 0xEF2D56
# define PASTEL_ORANGE 0xFFC145
# define BONDI_BLUE 0x009FB7
# define IVORY 0xFFFDED
# define SANDY_BROWN 0xFAA359
# define SMOKY_BLACK 0x70310D
# define BULGARIAN_ROSE 0x3A0A07
# define ROSEWOOD 0x650104
# define BLAZE_ORANGE 0xF96B06
# define JAPANESE_INDIGO 0x264653
# define JUNGLE_GREEN 0x2A9D8F
# define HANSA_YELLOW 0xE9C46A
# define SANDY_BROWN2 0xF4A261
# define LIGHT_RED_OCHRE 0xE76F51

# define WHITE 0x00FFFFFF

typedef struct		s_m
{
	char		*buffer;
	int			i;
}					t_m;

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
	int			bpp;
	int			s_l;
	int			endian;
	int			len;
	int			nb_lines;
	int			start_x;
	int			start_y;
	int			size_x;
	int			size_y;
	int			scale;
	int			type_color;
	char		*cpy_buffer;
	char		*my_image_string;
	void		*pointeur_image;
	int			**dest;
	int			color;
}					t_mlx;

typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;

void				ft_draw_line(t_point a, t_point b, int *img, int color);
void				ft_read_map(char **buffer, char *argv);
int					ft_check_map(char *str, t_mlx *smlx);
int					ft_key(int keycode, t_mlx *smlx);
char				ft_put_map(t_mlx *smlx);
int					ft_color(int z, int type);
void				ft_info(t_mlx *smlx);
void				ft_init(t_mlx *smlx);
void				ft_put_map_algo(int *my_image_int,
					t_mlx *smlx, int i, int j);

#endif
