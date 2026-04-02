/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:55:35 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/12/09 00:20:04 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static int	get_map_color(t_cub3d *c, float wx, float wy)
{
	int		mx;
	int		my;
	char	val;

	mx = (int)(wx / BLOCK);
	my = (int)(wy / BLOCK);
	if (my < 0 || my >= c->parser->rows + 2)
		return (MMAP_COLOR_VOID);
	if (mx < 0 || mx >= c->parser->cols + 2)
		return (MMAP_COLOR_VOID);
	if (!c->parser->padded[my])
		return (MMAP_COLOR_VOID);
	val = c->parser->padded[my][mx];
	if (val == '1')
		return (MMAP_COLOR_WALL);
	if (val == 'D')
		return (MMAP_COLOR_DOOR);
	if (val == '0' || ft_strchr("NSEW", val))
		return (MMAP_COLOR_FLOOR);
	return (MMAP_COLOR_VOID);
}

static void	draw_radar_point(t_cub3d *c, int x, int y)
{
	int		d_sq;
	float	wx;
	float	wy;

	d_sq = x * x + y * y;
	if (d_sq <= MMAP_RADIUS * MMAP_RADIUS)
	{
		wx = c->parser->player->x + (x * (float)BLOCK / MMAP_ZOOM);
		wy = c->parser->player->y + (y * (float)BLOCK / MMAP_ZOOM);
		our_put_pixel(MMAP_CENTER_X + x, MMAP_CENTER_Y + y,
			get_map_color(c, wx, wy), c);
	}
	if (d_sq <= MMAP_RADIUS * MMAP_RADIUS
		&& d_sq > (MMAP_RADIUS - 3) * (MMAP_RADIUS - 3))
		our_put_pixel(MMAP_CENTER_X + x, MMAP_CENTER_Y + y, 0xFFFFFF, c);
}

static void	draw_radar_circle(t_cub3d *c)
{
	int	y;
	int	x;

	y = -MMAP_RADIUS;
	while (y <= MMAP_RADIUS)
	{
		x = -MMAP_RADIUS;
		while (x <= MMAP_RADIUS)
		{
			draw_radar_point(c, x, y);
			x++;
		}
		y++;
	}
}

static void	draw_player_icon(t_cub3d *c)
{
	int		i;
	int		j;

	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			our_put_pixel(MMAP_CENTER_X + j, MMAP_CENTER_Y + i,
				MMAP_COLOR_PL, c);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 15)
	{
		our_put_pixel(MMAP_CENTER_X + (int)(c->parser->player->dir_x * i),
			MMAP_CENTER_Y + (int)(c->parser->player->dir_y * i),
			MMAP_COLOR_PL, c);
		i++;
	}
}

void	render_minimap(t_cub3d *cub3d)
{
	if (!cub3d->minimap_on)
		return ;
	draw_radar_circle(cub3d);
	draw_player_icon(cub3d);
}
