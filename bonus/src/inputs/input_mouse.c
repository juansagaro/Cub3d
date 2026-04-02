/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:56:21 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/01/03 18:25:01 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

// int	mouse_move(int x, int y, void *param)
// {
// 	t_cub3d		*c;
// 	static int	last_x = -1;
// 	int			dx;

// 	(void)y;
// 	c = (t_cub3d *)param;
// 	if (last_x == -1)
// 	{
// 		last_x = x;
// 		return (0);
// 	}
// 	dx = x - last_x;
// 	if (dx != 0)
// 		rotate_player(c->parser->player, dx * SENSI);
// 	last_x = x;
// 	return (0);
// }

int	mouse_move(int x, int y, void *param)
{
	t_cub3d	*c;
	int		dx;
	int		center_x;
	int		center_y;

	(void)y;
	c = (t_cub3d *)param;
	center_x = WIN_W / 2;
	center_y = WIN_H / 2;
	dx = x - center_x;
	if (dx == 0)
		return (0);
	rotate_player(c->parser->player, dx * SENSI);
	mlx_mouse_move(c->mlx, c->window, center_x, center_y);
	return (0);
}

int	mouse_press(int button, int x, int y, t_cub3d *c)
{
	(void)x;
	(void)y;
	if (button == MOUSE_L)
		c->gun.trigger_down = 1;
	return (0);
}

// Función cuando SUELTAS el botón
int	mouse_release(int button, int x, int y, t_cub3d *c)
{
	(void)x;
	(void)y;
	if (button == MOUSE_L)
		c->gun.trigger_down = 0;
	return (0);
}
