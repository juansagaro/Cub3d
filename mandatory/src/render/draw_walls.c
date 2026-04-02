/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:49:33 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/01/05 13:46:35 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static t_tex	*get_wall_texture(t_cub3d *c, t_dda *dda)
{
	if (dda->side == 0)
	{
		if (dda->ray_dir_x > 0)
			return (&c->textures.ea);
		return (&c->textures.we);
	}
	if (dda->ray_dir_y > 0)
		return (&c->textures.so);
	return (&c->textures.no);
}

static void	calc_tex_x(t_cub3d *c, t_dda *dda, t_tex *tex)
{
	double	wall_x;
	int		tex_x;

	if (dda->side == 0)
		wall_x = c->parser->player->y / BLOCK + dda->perp_wall_dist
			* dda->ray_dir_y;
	else
		wall_x = c->parser->player->x / BLOCK + dda->perp_wall_dist
			* dda->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->w);
	if ((dda->side == 0 && dda->ray_dir_x < 0)
        || (dda->side == 1 && dda->ray_dir_y > 0))
        tex_x = tex->w - tex_x - 1;
	dda->texture_index = tex_x;
}

static void	draw_tex_loop(t_cub3d *c, t_dda *dda, t_tex *tex, int x)
{
	int		y;
	int		end;
	double	step;
	double	pos;
	int		color;

	step = 1.0 * tex->h / dda->line_height;
	y = (WIN_H - dda->line_height) / 2;
	if (y < 0)
		y = 0;
	end = (WIN_H + dda->line_height) / 2;
	if (end >= WIN_H)
		end = WIN_H - 1;
	pos = (y - WIN_H / 2 + dda->line_height / 2) * step;
	while (y < end)
	{
		color = get_texture_color(tex, dda->texture_index, (int)pos);
		if (dda->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		our_put_pixel(x, y, color, c);
		pos += step;
		y++;
	}
}

void	draw_texture_line(t_cub3d *c, t_dda *dda, int x)
{
	t_tex	*tex;

	tex = get_wall_texture(c, dda);
	if (!tex->addr)
		return ;
	calc_tex_x(c, dda, tex);
	draw_tex_loop(c, dda, tex, x);
}
