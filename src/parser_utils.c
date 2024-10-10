/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:08:54 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/10 11:59:51 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
