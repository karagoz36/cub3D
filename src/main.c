/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:57:58 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/10 15:00:13 by tkaragoz         ###   ########.fr       */
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

void	free_data(t_data *data)
{
	clean_textures(data->texture);
	ft_free(data->map);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	memset(&data, 0, sizeof(t_data));
	if (parser(&data, argv[1]))
		return (free_data(&data), EXIT_FAILURE);
	free_data(&data);
	return (EXIT_SUCCESS);
}
