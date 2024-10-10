/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:08:54 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/10 21:27:18 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi_3d(const char *str)
{
	int	number;
	int	sign;
	int	i;

	number = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit((unsigned char) str[i]))
	{
		number = (number * 10 + str[i] - '0');
		i++;
	}
	return (sign * number);
}

void	clean_textures(t_texture *texture)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (texture[i].f_name)
		{
			free(texture[i].f_name);
			texture[i].f_name = NULL;
		}
	}
}

int	convert_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	if (str)
	{
		while (str[++i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		free(str);
		str = NULL;
	}
}
