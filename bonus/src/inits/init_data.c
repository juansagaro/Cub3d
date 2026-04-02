/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:46:39 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/12/08 18:30:45 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->window = NULL;
	cub3d->canvas = NULL;
	cub3d->parser = NULL;
	cub3d->minimap_on = 1;
	cub3d->minimap_down = false;
}

void	init_player(t_player *player)
{
	player->x = -1.0f;
	player->y = -1.0f;
	player->dir_x = 0.0f;
	player->dir_y = 0.0f;
	player->plane_x = 0.0f;
	player->plane_y = 0.0f;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->key_rot_left = false;
	player->key_rot_right = false;
	player->orientation = '\0';
}

static void	init_parser_flags(t_parser *p)
{
	p->no_set = false;
	p->so_set = false;
	p->we_set = false;
	p->ea_set = false;
	p->f_set = false;
	p->c_set = false;
	p->door_set = false;
	p->door_in_map = false;
	p->map_started = false;
	p->map_finished = false;
	p->player_set = false;
}

void	init_parser(t_parser *p)
{
	p->no = NULL;
	p->so = NULL;
	p->we = NULL;
	p->ea = NULL;
	p->floor = NULL;
	p->ceiling = NULL;
	p->door = NULL;
	p->f.r = -1;
	p->f.g = -1;
	p->f.b = -1;
	p->c.r = -1;
	p->c.g = -1;
	p->c.b = -1;
	init_parser_flags(p);
	p->map = NULL;
	p->padded = NULL;
	p->rows = 0;
	p->cols = 0;
	p->player = malloc(sizeof(t_player));
	if (!p->player)
		ft_error(1, "Error\nMalloc player failed\n");
	init_player(p->player);
}
