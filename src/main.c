/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:57:58 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/07 17:20:48 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arg(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (printf("One argument only!\n"), EXIT_FAILURE);
	i = 0;
	while (av[1][i] != '.')
		i++;
	if (ft_strncmp(av[1] + i, ".cub\0", 5))
		return (printf("Invalid map name!\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_map(char *fname)
{
	(void)fname;
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
