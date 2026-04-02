/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:08:36 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/12/09 14:08:36 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static int	load_single(void *mlx, t_tex *t, char *path)
{
	if (!path)
		return (1);
	t->img_ptr = mlx_xpm_file_to_image(mlx, path, &t->w, &t->h);
	if (!t->img_ptr)
		return (0);
	t->addr = mlx_get_data_addr(t->img_ptr, &t->bpp, &t->line_len, &t->endian);
	if (!t->addr || t->w <= 0 || t->h <= 0)
	{
		mlx_destroy_image(mlx, t->img_ptr);
		t->img_ptr = NULL;
		return (0);
	}
	return (1);
}

int	load_textures(t_cub3d *c)
{
	if (!c || !c->mlx || !c->parser)
		return (0);
	if (!load_single(c->mlx, &c->textures.no, c->parser->no))
		return (0);
	if (!load_single(c->mlx, &c->textures.so, c->parser->so))
		return (0);
	if (!load_single(c->mlx, &c->textures.we, c->parser->we))
		return (0);
	if (!load_single(c->mlx, &c->textures.ea, c->parser->ea))
		return (0);
	if (c->parser->floor && !load_single(c->mlx, &c->textures.floor,
			c->parser->floor))
		return (0);
	if (c->parser->ceiling && !load_single(c->mlx, &c->textures.ceiling,
			c->parser->ceiling))
		return (0);
	return (1);
}
