/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:54:58 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/12/08 18:40:38 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

/*
** Encuentra al jugador y devuelve cuantos hay.
** Actualiza las coordenadas pasadas por referencia.
*/
static int	count_players(char **map, int rows, int *x, int *y)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				count++;
				*y = i;
				*x = j;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	check_player_once(char **map, t_parser *parser)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = count_players(map, parser->rows, &x, &y);
	if (count == 0)
		free_and_exit(parser, "Error\nNo player found\n", -1);
	if (count > 1)
		free_and_exit(parser, "Error\nMultiple players found\n", -1);
	parser->player->x = (float)x * BLOCK + BLOCK / 2;
	parser->player->y = (float)y * BLOCK + BLOCK / 2;
	parser->player->orientation = map[y][x];
	map[y][x] = '0';
	parser->player_set = true;
}
