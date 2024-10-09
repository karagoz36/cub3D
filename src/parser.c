/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:41:28 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/09 15:48:39 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	floor_ceiling(char *line, t_texture *texture)
{
	char	**clr;

	if (texture->color)
		return (EXIT_FAILURE);
	while (*line == ' ')
		line++;
	clr = ft_split(line, ',');
	texture->color = convert_trgb(0, ft_atoi(clr[0]), \
		ft_atoi(clr[1]), ft_atoi(clr[2]));
	ft_free(clr);
	return (EXIT_SUCCESS);
}

int	check_textures(char *line, t_data *data)
{
	if (!ft_strncmp("NO ", line, 3))
		return (check_add_texture(line + 3, &data->texture[N]));
	else if (!ft_strncmp("SO ", line, 3))
		return (check_add_texture(line + 3, &data->texture[S]));
	else if (!ft_strncmp("WE ", line, 3))
		return (check_add_texture(line + 3, &data->texture[W]));
	else if (!ft_strncmp("EA ", line, 3))
		return (check_add_texture(line + 3, &data->texture[E]));
	else if (!ft_strncmp("F ", line, 2))
		return (floor_ceiling(line + 2, &data->texture[F]));
	else if (!ft_strncmp("C ", line, 2))
		return (floor_ceiling(line + 2, &data->texture[C]));
	return (EXIT_FAILURE);
}

int	get_textures(t_data *data)
{
	int		i;
	char	*line;

	line = get_next_line(data->fd);
	if (!line)
		return (EXIT_FAILURE);
	i = 0;
	while (line && i < 6)
	{
		if (*line != '\n')
		{
			if (check_textures(line, data))
				return (free(line), clean_textures(data->texture), 1);
			i++;
		}
		free(line);
		line = get_next_line(data->fd);
	}
	return (EXIT_SUCCESS);
}

int	parser(t_data *data, char *f_name)
{
	data->fd = open(f_name, O_RDONLY);
	if (data->fd < 0)
		return (ft_putendl_fd("Error\nError opening map file!", 2), 1);
	if (get_textures(data))
		return (close(data->fd), ft_putendl_fd("Error", 2), 1);
	// if (build_map(data))
	return (EXIT_SUCCESS);
}

int	get_len_map(t_data *data, char *f_name)
{
	char	*line;

	data->fd = open(f_name, O_RDONLY);
	if (data->fd < 0)
		return (ft_putendl_fd("Error\nError opening map file!", 2), 1);
	line = get_next_line(data->fd);
	if (!line)
		return (EXIT_FAILURE);
	while (line)
	{
		if (line[0] != '\n')
			data->m_len++;
		if (data->m_len > 6 && ft_strlen(line) > data->m_width)
			data->m_width = ft_strlen(line) - 1;
		free(line);
		line = get_next_line(data->fd);
	}
	data->m_len -= 6;
	close(data->fd);
	return (EXIT_SUCCESS);
}
