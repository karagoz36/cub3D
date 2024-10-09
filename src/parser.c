/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:41:28 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/09 18:26:02 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map(t_data *data)
{
	int		i;
	char	*line;

	line = get_next_line(data->fd);
	if (!line)
		return (free(line), EXIT_FAILURE);
	while (line[0] == '\n')
	{
		free(line);
		line = get_next_line(data->fd);
		if (!line)
			return (free(line), EXIT_FAILURE);
	}
	data->map = ft_calloc(data->m_max + 1, sizeof(char *));
	i = 0;
	while (line)
	{
		data->map[i] = ft_strdup(line);
		free(line);
		if (!data->map[i])
			return (ft_free(data->map), EXIT_FAILURE);
		line = get_next_line(data->fd);
		i++;
	}
	i = -1;
	printf("%d %d %d\n", data->m_len, data->m_width, data->m_max);
	while (data->map[++i])
		printf("%s", data->map[i]);
	return (EXIT_SUCCESS);
}

int	parser(t_data *data, char *f_name)
{
	data->fd = open(f_name, O_RDONLY);
	if (data->fd < 0)
		return (ft_putendl_fd("Error\nError opening map file!", 2), 1);
	if (get_textures(data))
		return (close(data->fd), ft_putendl_fd("Error", 2), 1);
	if (get_map(data))
		return (close(data->fd), ft_putendl_fd("Error", 2), 1);
	close(data->fd);
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
	if (data->m_len > data->m_width)
		data->m_max = data->m_len;
	else
		data->m_max = data->m_width;
	close(data->fd);
	return (EXIT_SUCCESS);
}
