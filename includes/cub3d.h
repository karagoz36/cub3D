/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:51:28 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/22 19:11:45 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>

# include "parser.h"

# define LENGTH 720
# define WIDTH 1280

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_image;
typedef struct s_data
{
	char		**map;
	t_texture	texture[6];
	int			fd;
	int			m_len;
	int			m_width;
	int			floor;
	int			ceiling;
	int			start_x;
	int			start_y;
	int			p_dir;
	void		*mlx;
	void		*window;
	t_image		img;
}				t_data;

int		key_hook(int keycode, t_data *data);
int		f_exit(t_data *data);
int		render(t_data *data);
void	free_data(t_data *data);

#endif
