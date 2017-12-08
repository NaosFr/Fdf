/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:46:16 by ncella            #+#    #+#             */
/*   Updated: 2017/12/07 15:11:21 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	map_isdigit(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0' || str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
		return (0);
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

int			ft_verif_map(char *buffer)
{
	if (map_isdigit(buffer) == 0)
		return (0);
	return (1);
}
