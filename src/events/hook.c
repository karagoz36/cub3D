/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:37:59 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/14 15:44:09 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 13) // W tuşu (ileri git)
		move_forward(data);
	else if (keycode == 1) // S tuşu (geri git)
		move_backward(data);
	else if (keycode == 0) // A tuşu (sola git)
		move_left(data);
	else if (keycode == 2) // D tuşu (sağa git)
		move_right(data);
	else if (keycode == 53) // ESC tuşu (çıkış)
		exit_game(data); // Exit fonksiyonu, programdan çıkışı sağlar
	mlx_clear_window(data->mlx, data->window); // Ekranı temizle
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0); // Yeni pozisyonları ekrana çiz
	return (0);
}
