/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:57:58 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/08 15:01:20 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arg(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (errno = EINVAL, perror("Error\nError in argument!"),
			EXIT_FAILURE);
	i = 0;
	while (av[1][i] != '.')
		i++;
	if (i == 0 || ft_strncmp(av[1] + i, ".cub\0", 5))
		return (errno = EINVAL, perror("Error\nInvalid map name!"),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_len_map(t_data *data, char *f_name)
{
	char	*line;

	data->fd = open(f_name, O_RDONLY);
	if (data->fd < 0)
		return (errno = EINVAL, perror("Error\nError opening map file!"),
			EXIT_FAILURE);
	data->m_len = 0;
	line = get_next_line(data->fd);
	if (!line)
		return (free(line), EXIT_FAILURE);
	while (line > 0)
	{
		if (line[0] != '\n')
			data->m_len++;
		if (data->m_len > 6 && ft_strlen(line) > data->m_width)
			data->m_width = ft_strlen(line) - 1;
		free(line);
		line = get_next_line(data->fd);
	}
	data->m_len -= 6;
	printf("%d %d\n", data->m_len, data->m_width);
	close(data->fd);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	memset(&data, 0, sizeof(t_data));
	if (get_len_map(&data, argv[1]))
		return (EXIT_FAILURE);
	close(data.fd);
	return (EXIT_SUCCESS);
}
