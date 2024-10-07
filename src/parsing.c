/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:41:28 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/07 19:24:43 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_line(char *line)
{

}

int	check_map(char *fname)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (errno = EINVAL, perror("Error opening map file!"),
			EXIT_FAILURE);
	i = 0;
	line = get_next_line(fd);
	while (line > 0)
	{
		if (parse_line(line, i++))
			return (free(line), close(fd), EXIT_FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
