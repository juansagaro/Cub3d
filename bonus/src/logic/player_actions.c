/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:57:04 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/12/09 13:57:04 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

void	open_door(t_cub3d *c)
{
	t_player	*p;
	int			tx;
	int			ty;

	p = c->parser->player;
	tx = (int)((p->x + p->dir_x * BLOCK) / BLOCK);
	ty = (int)((p->y + p->dir_y * BLOCK) / BLOCK);
	if (ty >= 0 && ty < c->parser->rows && tx >= 0
		&& tx < (int)ft_strlen(c->parser->padded[ty]))
	{
		if (c->parser->padded[ty][tx] == 'D')
			c->parser->padded[ty][tx] = '0';
	}
}
