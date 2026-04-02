/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:44:39 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/12/08 23:21:06 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* move_player.c                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

void	init_player_vectors(t_player *p)
{
	p->dir_x = 0;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = 0;
	if (p->orientation == 'N')
		p->dir_y = -1;
	else if (p->orientation == 'S')
		p->dir_y = 1;
	else if (p->orientation == 'E')
		p->dir_x = 1;
	else if (p->orientation == 'W')
		p->dir_x = -1;
	if (p->orientation == 'N')
		p->plane_x = 0.66;
	else if (p->orientation == 'S')
		p->plane_x = -0.66;
	else if (p->orientation == 'E')
		p->plane_y = 0.66;
	else if (p->orientation == 'W')
		p->plane_y = -0.66;
}

void	rotate_player(t_player *p, float rot)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot) - p->dir_y * sin(rot);
	p->dir_y = old_dir_x * sin(rot) + p->dir_y * cos(rot);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rot) - p->plane_y * sin(rot);
	p->plane_y = old_plane_x * sin(rot) + p->plane_y * cos(rot);
}

static bool	collides(t_parser *parser, float x, float y)
{
	int	mx;
	int	my;

	mx = (int)(x / BLOCK);
	my = (int)(y / BLOCK);
	if (my < 0 || my >= parser->rows)
		return (true);
	if (mx < 0 || mx >= (int)ft_strlen(parser->padded[my]))
		return (true);
	if (parser->padded[my][mx] == '1' || parser->padded[my][mx] == 'D')
		return (true);
	return (false);
}

static void	calc_move(t_player *p, float speed, float *nx, float *ny)
{
	float	move;
	float	side;

	move = (p->key_up - p->key_down) * speed;
	side = (p->key_right - p->key_left) * speed;
	*nx = p->x + (move * p->dir_x - side * p->dir_y) * BLOCK;
	*ny = p->y + (move * p->dir_y + side * p->dir_x) * BLOCK;
}

void	move_player(t_cub3d *c)
{
	t_player	*p;
	float		nx;
	float		ny;

	p = c->parser->player;
	if (p->key_rot_right)
		rotate_player(p, ROT_SPEED);
	if (p->key_rot_left)
		rotate_player(p, -ROT_SPEED);
	if (p->key_up || p->key_down || p->key_left || p->key_right)
	{
		calc_move(p, PLAYER_SPEED, &nx, &ny);
		if (!collides(c->parser, nx, p->y))
			p->x = nx;
		if (!collides(c->parser, p->x, ny))
			p->y = ny;
	}
}
