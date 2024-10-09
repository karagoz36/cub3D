/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:20:28 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/09 15:48:47 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_textures(t_texture *texture)
{
	int	i;

	i = 0;
	while (i < 4)
		free(texture[i++].f_name);
}

int	check_add_texture(char *line, t_texture *texture)
{
	if (texture->f_name)
		return (EXIT_FAILURE);
	while (*line == ' ')
		line++;
	return (texture->f_name = ft_strdup(line), EXIT_SUCCESS);
}

int	convert_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
