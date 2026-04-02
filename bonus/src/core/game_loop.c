/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:11:26 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/01/03 19:32:29 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

int	draw_loop(t_cub3d *cub3d)
{
	move_player(cub3d);
	clear_image(cub3d);
	render_floor_ceiling(cub3d);
	render_3d_view(cub3d);
	render_weapon(cub3d);
	render_minimap(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->window,
		cub3d->canvas->mlx_img, 0, 0);
	return (0);
}
