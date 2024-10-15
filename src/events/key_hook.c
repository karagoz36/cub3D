/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:37:59 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/14 17:52:22 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_exit(t_data *data)
{
	free_data(data);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		f_exit(data);
	// else if (keycode == XK_w)
	// 	move_forward(data);
	// else if (keycode == XK_s)
	// 	move_backward(data);
	// else if (keycode == XK_a)
	// 	move_left(data);
	// else if (keycode == XK_d)
	// 	move_right(data);

	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
	return (EXIT_SUCCESS);
}
