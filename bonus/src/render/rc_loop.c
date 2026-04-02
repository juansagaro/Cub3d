/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:51:21 by fgalvez-          #+#    #+#             */
/*   Updated: 2026/01/03 18:17:59 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static void	init_ray(t_cub3d *c, int x, float *r_dir_x, float *r_dir_y)
{
	float		cam_x;
	t_player	*p;

	p = c->parser->player;
	cam_x = 2 * x / (float)WIN_W - 1;
	*r_dir_x = p->dir_x + p->plane_x * cam_x;
	*r_dir_y = p->dir_y + p->plane_y * cam_x;
}

void	render_3d_view(t_cub3d *c)
{
	int		x;
	t_dda	dda;
	float	r_x;
	float	r_y;

	if (!c || !c->parser || !c->parser->player)
		return ;
	x = 0;
	while (x < WIN_W)
	{
		init_ray(c, x, &r_x, &r_y);
		init_dda(c, &dda, r_x, r_y);
		perform_dda(c, &dda);
		if (dda.perp_wall_dist < 0.001f)
			dda.perp_wall_dist = 0.001f;
		dda.line_height = (int)(WIN_H / dda.perp_wall_dist);
		draw_texture_line(c, &dda, x);
		x++;
	}
}
