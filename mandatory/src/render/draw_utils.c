/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:17:04 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/12/09 13:59:20 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

void	our_put_pixel(int x, int y, int color, t_cub3d *c)
{
	int		pixel;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	pixel = (y * c->canvas->line_len) + (x * (c->canvas->bpp / 8));
	if (c->canvas->endian == 1)
	{
		c->canvas->addr[pixel + 0] = (color >> 24);
		c->canvas->addr[pixel + 1] = (color >> 16) & 0xFF;
		c->canvas->addr[pixel + 2] = (color >> 8) & 0xFF;
		c->canvas->addr[pixel + 3] = (color) & 0xFF;
	}
	else
	{
		c->canvas->addr[pixel + 0] = (color) & 0xFF;
		c->canvas->addr[pixel + 1] = (color >> 8) & 0xFF;
		c->canvas->addr[pixel + 2] = (color >> 16) & 0xFF;
		c->canvas->addr[pixel + 3] = (color >> 24);
	}
}

void	clear_image(t_cub3d *cub3d)
{
	ft_memset(cub3d->canvas->addr, 0, WIN_H * cub3d->canvas->line_len);
}

int	get_texture_color(t_tex *tex, int x, int y)
{
	int		offset;
	char	*dst;

	if (x < 0)
		x = 0;
	if (x >= tex->w)
		x = tex->w - 1;
	if (y < 0)
		y = 0;
	if (y >= tex->h)
		y = tex->h - 1;
	offset = (y * tex->line_len) + (x * (tex->bpp / 8));
	dst = tex->addr + offset;
	return (*(unsigned int *)dst);
}

unsigned int	rgb_to_color(t_rgb rgb)
{
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}
