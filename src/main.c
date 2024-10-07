/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:57:58 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/07 18:41:23 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arg(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (errno = EINVAL, perror("Error in argument!"),
			EXIT_FAILURE);
	i = 0;
	while (av[1][i] != '.')
		i++;
	if (i == 0 || ft_strncmp(av[1] + i, ".cub\0", 5))
		return (errno = EINVAL, perror("Invalid map name!"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}



int	main(int argc, char **argv)
{
	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	if (check_map(argv[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
