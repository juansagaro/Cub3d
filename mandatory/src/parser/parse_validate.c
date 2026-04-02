/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:52:32 by fgalvez-          #+#    #+#             */
/*   Updated: 2026/01/03 17:50:52 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

void	check_info(t_parser *p)
{
	if (!p->no_set || !p->so_set || !p->we_set || !p->ea_set
		|| !p->f_set || !p->c_set)
		free_and_exit(p, "Error\nMissing information or textures\n", -1);
}

static bool	get_next_target(char **map, char target, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == target)
			{
				*x = j;
				*y = i;
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

static int	flood_fill(char **map, t_parser *p, int x, int y)
{
	if (x < 0 || y < 0 || y >= p->rows + 2 || x >= p->cols + 2)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == '0' || ft_strchr("NSEW", map[y][x]))
	{
		ft_putstr_fd("Error\nMap is not closed (void touches floor)\n", 2);
		return (-1);
	}
	map[y][x] = 'X';
	if (flood_fill(map, p, x + 1, y) == -1)
		return (-1);
	if (flood_fill(map, p, x - 1, y) == -1)
		return (-1);
	if (flood_fill(map, p, x, y + 1) == -1)
		return (-1);
	if (flood_fill(map, p, x, y - 1) == -1)
		return (-1);
	return (0);
}

void	check_map(char **map, t_parser *parser)
{
	int	x;
	int	y;

	check_player_once(map, parser);
	x = 0;
	y = 0;
	while (get_next_target(map, ' ', &x, &y))
	{
		if (flood_fill(map, parser, x, y) == -1)
			free_and_exit(parser, "", -1);
	}
}
