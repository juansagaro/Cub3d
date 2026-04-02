/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fl_ceil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:37:15 by fgalvez-          #+#    #+#             */
/*   Updated: 2026/01/03 19:40:33 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static int	get_pixel_color(t_cub3d *c, t_rayfloor *f, int is_floor)
{
	t_tex	*t;
	int		tx;
	int		ty;
	int		cell_x;
	int		cell_y;

	if ((is_floor && !c->parser->floor)
		|| (!is_floor && !c->parser->ceiling))
	{
		if (is_floor)
			return (rgb_to_color(c->parser->f));
		return (rgb_to_color(c->parser->c));
	}
	if (is_floor)
		t = &c->textures.floor;
	else
		t = &c->textures.ceiling;
	cell_x = (int)f->floor_x;
	cell_y = (int)f->floor_y;
	tx = (int)(t->w * (f->floor_x - cell_x)) & (t->w - 1);
	ty = (int)(t->h * (f->floor_y - cell_y)) & (t->h - 1);
	return (get_texture_color(t, tx, ty));
}

// Prepara los vectores matemáticos para la fila 'y' actual
static void	calc_floor_vectors(t_cub3d *c, t_rayfloor *f, int y)
{
	float		pos_z;
	float		p;
	t_player	*pl;

	pl = c->parser->player;
	f->ray_x0 = pl->dir_x - pl->plane_x;
	f->ray_y0 = pl->dir_y - pl->plane_y;
	f->ray_x1 = pl->dir_x + pl->plane_x;
	f->ray_y1 = pl->dir_y + pl->plane_y;
	pos_z = 0.5 * WIN_H;
	p = y - WIN_H / 2;
	f->row_dist = pos_z / p;
	f->step_x = f->row_dist * (f->ray_x1 - f->ray_x0) / WIN_W;
	f->step_y = f->row_dist * (f->ray_y1 - f->ray_y0) / WIN_W;
	f->floor_x = (pl->x / BLOCK) + f->row_dist * f->ray_x0;
	f->floor_y = (pl->y / BLOCK) + f->row_dist * f->ray_y0;
}

// Recorre la línea horizontal 'y' pixel a pixel
static void	draw_scanline(t_cub3d *c, t_rayfloor *f, int y)
{
	int	x;
	int	color_f;
	int	color_c;

	x = 0;
	while (x < WIN_W)
	{
		color_f = get_pixel_color(c, f, 1);
		color_c = get_pixel_color(c, f, 0);
		our_put_pixel(x, y, color_f, c);
		our_put_pixel(x, WIN_H - 1 - y, color_c, c);
		f->floor_x += f->step_x;
		f->floor_y += f->step_y;
		x++;
	}
}

// Función principal: Itera desde la mitad de pantalla hacia abajo
void	render_floor_ceiling(t_cub3d *c)
{
	t_rayfloor	f;
	int			y;

	y = WIN_H / 2 + 1;
	while (y < WIN_H)
	{
		calc_floor_vectors(c, &f, y);
		draw_scanline(c, &f, y);
		y++;
	}
}
