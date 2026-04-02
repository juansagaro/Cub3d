/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:14:19 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/12/09 17:20:00 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* hooks.c                                                                  */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

int	key_press(int k, t_cub3d *c)
{
	if (k == ESC)
		free_cub3d(c, "", 0);
	if (k == W)
		c->parser->player->key_up = true;
	if (k == S)
		c->parser->player->key_down = true;
	if (k == A)
		c->parser->player->key_left = true;
	if (k == D)
		c->parser->player->key_right = true;
	if (k == LEFT)
		c->parser->player->key_rot_left = true;
	if (k == RIGHT)
		c->parser->player->key_rot_right = true;
	return (0);
}

int	key_release(int k, t_cub3d *c)
{
	if (k == W)
		c->parser->player->key_up = false;
	if (k == S)
		c->parser->player->key_down = false;
	if (k == A)
		c->parser->player->key_left = false;
	if (k == D)
		c->parser->player->key_right = false;
	if (k == LEFT)
		c->parser->player->key_rot_left = false;
	if (k == RIGHT)
		c->parser->player->key_rot_right = false;
	return (0);
}

int	cub3d_esc(t_cub3d *c)
{
	free_cub3d(c, "", 0);
	return (0);
}
