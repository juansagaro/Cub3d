/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:27:11 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/09/14 13:27:11 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d/cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	cub3d;

	if (ac != 2)
		return (ft_error(1, ARGS));
	if (is_cub(av[1]) != 1)
		return (ft_error(1, CUB));
	init_cub3d(&cub3d);
	parser(&cub3d, av);
	if (start_mlx(&cub3d) == -1)
		return (-1);
	free_cub3d(&cub3d, "", 0);
	return (0);
}
