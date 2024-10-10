/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:41:28 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/10 20:06:06 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map(t_data *data)
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
	return (close(data->fd), EXIT_SUCCESS);
}

static int	get_len_map(t_data *data, char *f_name)
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
		if (line[0] != '\n' || data->m_len > 6)
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

int	is_ok(char c)
{
	if (c == ' '
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0')
		return (0);
	if (c == '1' || c == '0' || c == ' ' || c == '\n')
		return (0);
	return (1);
}

int	invalid_char(t_data *data, char **map)
{
	int		x;
	int		y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (is_ok(map[x][y]))
				return (EXIT_FAILURE);
			if (map[x][y] == 'N' || map[x][y] == 'S' || map[x][y] == 'W' ||
				map[x][y] == 'E')
			{
				if (data->start_x)
					return (EXIT_FAILURE);
				data->start_x = x;
				data->start_y = y;
				data->p_dir = data->map[data->start_x][data->start_y];
				data->map[data->start_x][data->start_y] = '0';
			}
		}
	}
	return (EXIT_SUCCESS);
}

int	check_walls(t_data *data, char **map, int x, int y)
{
	if (map[x][y] == '9')
		return (EXIT_SUCCESS);
	map[x][y] = '9';
	if (y == 0 || y == ft_strlen(map[x]) - 1 || x == 0 || x == data->m_len - 1)
		return (EXIT_FAILURE);
	if (map[x - 1][y] == ' ' || map[x + 1][y] == ' ' ||
		map[x][y - 1] == ' ' || map[x][y + 1] == ' ')
		return (EXIT_FAILURE);
	if (map[x - 1][y] == '\0' || map[x + 1][y] == '\0' ||
		map[x][y - 1] == '\0' || map[x][y + 1] == '\0')
		return (EXIT_FAILURE);
	if (map[x - 1][y] == '0')
		return (check_walls(data, map, x - 1, y));
	if (map[x + 1][y] == '0')
		return (check_walls(data, map, x + 1, y));
	if (map[x][y - 1] == '0')
		return (check_walls(data, map, x, y - 1));
	if (map[x][y + 1] == '0')
		return (check_walls(data, map, x, y + 1));
	map[x][y] = '0';
	return (EXIT_SUCCESS);
}

static int	check_map(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	if (invalid_char(data, data->map))
		return (EXIT_FAILURE);
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
			if (data->map[x][y] == '0')
				if (check_walls(data, data->map, x, y))
					return (EXIT_FAILURE);
	}
	x = -1;
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
			if (data->map[x][y] == '9')
				data->map[x][y] = '0';
	}
	x = -1;
	while (data->map[++x])
		printf("%s", data->map[x]);
	return (EXIT_SUCCESS);
}

int	parser(t_data *data, char *f_name)
{
	if (get_len_map(data, f_name))
		return (EXIT_FAILURE);
	data->fd = open(f_name, O_RDONLY);
	if (data->fd < 0)
		return (ft_putendl_fd("Error\nError opening map file!", 2), 1);
	if (get_textures(data))
		return (close(data->fd), ft_putendl_fd("Error\nInvalid Conf.!", 2), 1);
	if (get_map(data))
		return (close(data->fd), ft_putendl_fd("Error\nAlloc. problem!", 2), 1);
	if (check_map(data))
		return (ft_putendl_fd("Error", 2), 1);
	return (EXIT_SUCCESS);
}
