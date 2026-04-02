/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:10:58 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/12/09 14:10:58 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

void	setup_hooks(t_cub3d *cub3d)
{
	mlx_hook(cub3d->window, 2, 1L << 0, key_press, cub3d);
	mlx_hook(cub3d->window, 3, 1L << 1, key_release, cub3d);
	mlx_hook(cub3d->window, 6, 1L << 6, mouse_move, cub3d);
	mlx_hook(cub3d->window, 4, 1L << 2, mouse_press, cub3d);
	mlx_hook(cub3d->window, 5, 1L << 3, mouse_release, cub3d);
	mlx_hook(cub3d->window, 17, 0, cub3d_esc, cub3d);
}
