/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:41:28 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/08 19:54:53 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	build_map(t_data *data, char *line, int ln)
// {
// 	int	len;

// 	len = ft_strlen(line);
// 	data->map[ln] = (sizeof(char *))malloc(sizeof(char) * (len + 1));

// }


// 	int	check_parse(char *line, t_data *data)
// {
// 	int	i;
// 	if (!ft_strncmp("NO ", line, 3))
// 		data->texture[N].check++;
// 	else if (ft_strncmp("SO ", line, 3))
// 		data->texture[S].check++;
// 	else if (ft_strncmp("WE ", line, 3))
// 		return (EXIT_SUCCESS);
// 	else if (ft_strncmp("EA ", line, 3))
// 		return (EXIT_SUCCESS);
// 	else if (ft_strncmp("F ", line, 2))
// 		return (EXIT_SUCCESS);
// 	else if (ft_strncmp("C ", line, 2))
// 		return (EXIT_SUCCESS);
// 	i = 0;
// 	while (data->m_len  && i < 6)
// 		if (data->texture[i++].check != 1)
// 			return (EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// }

void	clean_textures(t_texture *texture)
{
	int	i;

	i = 0;
	while (i < 4)
		free(texture[i++].f_name);
}

int	check_add_texture(char *line, t_texture *texture)
{
	texture;
}

int	check_textures(char *line, t_data *data)
{
	if (ft_strncmp("NO ", line, 3))
		return (check_add_texture(line + 3, &data->texture[N]));
	if (ft_strncmp("SO ", line, 3))
		return (check_add_texture(line + 3, &data->texture[S]));
	if (ft_strncmp("WE ", line, 3))
		return (check_add_texture(line + 3, &data->texture[W]));
	if (ft_strncmp("EA ", line, 3))
		return (check_add_texture(line + 3, &data->texture[E]));
	if (ft_strncmp("F ", line, 2))
		return (check_add_texture(line + 2, &data->texture[F]));
	if (ft_strncmp("C ", line, 2))
		return (check_add_texture(line + 2, &data->texture[C]));
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
		if (line != '\n')
		{
			if (check_textures(line, data))
				return (free(line), clean_textures(data->texture), 1);
			i++;
		}
		free(line);
		line = get_next_line(data->fd);
	}
}

int	parser(t_data *data, char *f_name)
{
	int		line_n;
	char	*line;

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
		return (ft_putendl_fd("Error\nError opening map file!", 2),	1);
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
