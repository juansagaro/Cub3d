/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:09:42 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/12/07 22:09:42 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static void	update_anim(t_cub3d *c)
{
	if (c->gun.trigger_down == 1)
	{
		c->gun.frame_timer++;
		if (c->gun.frame_timer >= 3)
		{
			c->gun.curr_frame++;
			if (c->gun.curr_frame > 6)
				c->gun.curr_frame = 1;
			c->gun.frame_timer = 0;
		}
	}
	else
	{
		c->gun.curr_frame = 0;
		c->gun.frame_timer = 0;
	}
}

/*
** Dibuja un "pixel" gigante (escalado) del arma.
*/
static void	draw_gun_pixel(t_cub3d *c, int sx, int sy, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < GUN_SCALE)
	{
		j = 0;
		while (j < GUN_SCALE)
		{
			if (sx + i >= 0 && sx + i < WIN_W && sy + j >= 0 && sy + j < WIN_H)
				our_put_pixel(sx + i, sy + j, color, c);
			j++;
		}
		i++;
	}
}

static void	draw_gun_frame(t_cub3d *c, t_tex *tex)
{
	int	x;
	int	y;
	int	color;
	int	st_x;
	int	st_y;

	st_x = (WIN_W - (tex->w * GUN_SCALE)) / 2;
	st_y = WIN_H - (tex->h * GUN_SCALE);
	y = 0;
	while (y < tex->h)
	{
		x = 0;
		while (x < tex->w)
		{
			color = get_texture_color(tex, x, y);
			if ((color & 0xFF000000) == 0)
				draw_gun_pixel(c, st_x + x * GUN_SCALE,
					st_y + y * GUN_SCALE, color);
			x++;
		}
		y++;
	}
}

void	render_weapon(t_cub3d *c)
{
	update_anim(c);
	draw_gun_frame(c, &c->gun.frames[c->gun.curr_frame]);
}
