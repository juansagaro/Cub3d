/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:51:21 by fgalvez-        #+#    #+#             */
/*   Updated: 2025/10/20 16:35:00 by fgalvez-       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static void	dda_step(t_dda *dda)
{
	if (dda->side_dist_x < dda->side_dist_y)
	{
		dda->side_dist_x += dda->delta_dist_x;
		dda->map_x += dda->step_x;
		dda->side = 0;
	}
	else
	{
		dda->side_dist_y += dda->delta_dist_y;
		dda->map_y += dda->step_y;
		dda->side = 1;
	}
}

static void	check_hit(t_cub3d *c, t_dda *dda)
{
	char	cell;
	int		row_len;

	if (dda->map_y < 0 || dda->map_y >= c->parser->rows)
	{
		dda->hit = 1;
		return ;
	}
	row_len = (int)ft_strlen(c->parser->padded[dda->map_y]);
	if (dda->map_x < 0 || dda->map_x >= row_len)
	{
		dda->hit = 1;
		return ;
	}
	cell = c->parser->padded[dda->map_y][dda->map_x];
	if (cell == '1')
		dda->hit = 1;
	else if (cell == 'D')
	{
		dda->hit = 1;
		dda->door = 1;
	}
}

static void	calc_perp_dist(t_cub3d *c, t_dda *dda)
{
	float	pos;

	if (dda->side == 0)
	{
		pos = c->parser->player->x / BLOCK;
		dda->perp_wall_dist = (dda->map_x - pos + (1 - dda->step_x) / 2.0f)
			/ dda->ray_dir_x;
	}
	else
	{
		pos = c->parser->player->y / BLOCK;
		dda->perp_wall_dist = (dda->map_y - pos + (1 - dda->step_y) / 2.0f)
			/ dda->ray_dir_y;
	}
}

void	perform_dda(t_cub3d *cub3d, t_dda *dda)
{
	dda->hit = 0;
	dda->door = 0;
	while (dda->hit == 0)
	{
		dda_step(dda);
		check_hit(cub3d, dda);
	}
	calc_perp_dist(cub3d, dda);
}
