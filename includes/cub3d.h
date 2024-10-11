/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:51:28 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/11 18:41:42 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdio.h>
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
	int			m_max;
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

#endif
