/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:26:13 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/12/09 14:26:13 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static void	init_step_x(t_dda *dda, t_player *p)
{
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (p->x / BLOCK - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0f - p->x / BLOCK)
			* dda->delta_dist_x;
	}
}

static void	init_step_y(t_dda *dda, t_player *p)
{
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (p->y / BLOCK - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0f - p->y / BLOCK)
			* dda->delta_dist_y;
	}
}

void	init_dda(t_cub3d *c, t_dda *dda, float r_dir_x, float r_dir_y)
{
	dda->ray_dir_x = r_dir_x;
	dda->ray_dir_y = r_dir_y;
	dda->map_x = (int)(c->parser->player->x / BLOCK);
	dda->map_y = (int)(c->parser->player->y / BLOCK);
	if (r_dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabsf(1.0f / r_dir_x);
	if (r_dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabsf(1.0f / r_dir_y);
	init_step_x(dda, c->parser->player);
	init_step_y(dda, c->parser->player);
}
