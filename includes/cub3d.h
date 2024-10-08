/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:51:28 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/10 16:36:16 by tkaragoz         ###   ########.fr       */
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

# include "parser.h"

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
}				t_data;

#endif
