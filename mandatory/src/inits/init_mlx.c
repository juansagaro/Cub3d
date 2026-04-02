/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:09:12 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/12/09 14:09:12 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static int	init_canvas(t_cub3d *c)
{
	c->canvas = malloc(sizeof(t_img));
	if (!c->canvas)
		return (-1);
	c->canvas->mlx_img = mlx_new_image(c->mlx, WIN_W, WIN_H);
	if (!c->canvas->mlx_img)
		return (-1);
	c->canvas->addr = mlx_get_data_addr(c->canvas->mlx_img, &c->canvas->bpp,
			&c->canvas->line_len, &c->canvas->endian);
	if (!c->canvas->addr)
		return (-1);
	return (0);
}

int	start_mlx(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		return (ft_error(-1, MLX_ERR));
	cub3d->window = mlx_new_window(cub3d->mlx, WIN_W, WIN_H, "Cub3d");
	if (!cub3d->window)
		return (ft_error(-1, "Error\nWindow init failed\n"));
	if (init_canvas(cub3d) == -1)
		return (ft_error(-1, "Error\nCanvas init failed\n"));
	if (!load_textures(cub3d))
		return (ft_error(-1, "Error\nTexture load failed\n"));
	init_player_vectors(cub3d->parser->player);
	setup_hooks(cub3d);
	mlx_loop_hook(cub3d->mlx, draw_loop, cub3d);
	mlx_mouse_hide(cub3d->mlx, cub3d->window);
	mlx_loop(cub3d->mlx);
	return (0);
}
