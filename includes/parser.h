/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:14:36 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/10 11:19:34 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

typedef struct s_data	t_data;
typedef enum e_dir
{
	N,
	S,
	W,
	E,
	F,
	C
}			t_dir;

typedef struct e_texture
{
	char	*f_name;
	int		color;
	int		check;
}			t_texture;

int		get_textures(t_data *data);
int		parser(t_data *data, char *f_name);
void	clean_textures(t_texture *texture);
int		convert_trgb(int t, int r, int g, int b);
void	ft_free(char **str);

#endif
