/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:57:58 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/14 15:24:20 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arg(int ac, char **av)
{
	if (ac != 2)
		return (errno = EINVAL, perror("Error\nError in argument!"),
			EXIT_FAILURE);
	if (ft_strncmp(ft_strrchr((av[1]), '.'), ".cub\0", 5))
		return (errno = EINVAL, perror("Error\nInvalid map name!"),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	free_data(t_data *data)
{
	int			i;
	t_texture	*t;

	t = data->texture;
	clean_textures(data->texture);
	ft_free(data->map);
	t = data->texture;
	i = -1;
	while (++i < 4)
		if (t[i].img)
			mlx_destroy_image(data->mlx, t[i].img);
	mlx_destroy_image(data->mlx, data->img.img);
	if (data->window)
	{
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
	mlx_destroy_display(data->mlx);
	if (data->mlx)
	{
		free(data->mlx);
		data->mlx = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	memset(&data, 0, sizeof(t_data));
	if (parser(&data, argv[1]))
		return (free_data(&data), EXIT_FAILURE);
	if (init_images(&data))
		return (free_data(&data), EXIT_FAILURE);
	free_data(&data);
	return (EXIT_SUCCESS);
}
