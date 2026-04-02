/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:54:59 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/12/09 13:54:59 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

void	free_all(t_cub3d *c)
{
	if (!c)
		return ;
	if (c->mlx && c->canvas)
	{
		if (c->canvas->mlx_img)
			mlx_destroy_image(c->mlx, c->canvas->mlx_img);
		free(c->canvas);
		c->canvas = NULL;
	}
	if (c->mlx && c->window)
		mlx_destroy_window(c->mlx, c->window);
	if (c->mlx)
	{
		mlx_destroy_display(c->mlx);
		free(c->mlx);
	}
}

void	free_and_exit(t_parser *parser, char *str, int code)
{
	free_parser(&parser);
	if (str && *str)
		ft_putstr_fd(str, 2);
	exit(code);
}

void	free_cub3d(t_cub3d *cub3d, char *str, int code)
{
	free_parser(&cub3d->parser);
	free_all(cub3d);
	ft_putstr_fd(str, 2);
	exit(code);
}
