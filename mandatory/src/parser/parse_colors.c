/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:42:49 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/12/08 18:47:44 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static bool	valid_rgb_range(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (false);
	return (true);
}

static int	extract_colors(char *var, t_rgb *color)
{
	char	**rgb;
	int		len;

	rgb = ft_split(var, ',');
	len = 0;
	while (rgb[len])
		len++;
	if (len != 3)
	{
		free_split(rgb);
		return (ft_error(-1, "Error\nInvalid color format\n"));
	}
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	free_split(rgb);
	if (!valid_rgb_range(color->r, color->g, color->b))
		return (ft_error(-1, "Error\nRGB value out of range (0-255)\n"));
	return (0);
}

// Maneja el caso de F/C cuando es COLOR
int	handle_fc_color(char *var, int is_f, bool *flag, t_parser *p)
{
	t_rgb	*target;

	if (is_f)
		target = &p->f;
	else
		target = &p->c;
	if (extract_colors(var, target) == -1)
	{
		free(var);
		return (-1);
	}
	*flag = true;
	free(var);
	return (0);
}
