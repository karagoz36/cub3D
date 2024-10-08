/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:14:36 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/08 19:23:17 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

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

int	get_len_map(t_data *data, char *f_name);
int	parser(t_data *data, char *f_name);

#endif
