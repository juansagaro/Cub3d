/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:23:15 by fgalvez-          #+#    #+#             */
/*   Updated: 2026/01/03 18:56:21 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

// Gestiona las líneas vacías y marca el final del mapa si es necesario
static int	check_empty(char *line, t_parser *p)
{
	if (!ft_strempty(line))
		return (0);
	if (p->map_started)
		p->map_finished = true;
	return (1);
}

static void	abort_read(char **map, char *line, int fd, t_parser *p)
{
	ft_free_matrix(map);
	if (line)
		free(line);
	close(fd);
	if (!line)
		free_and_exit(p, "Error\nNo map found\n", -1);
	else
		free_and_exit(p, "", -1);
}

// Procesa una línea de contenido (ID o Mapa)
static int	process_content(char *line, char **map, t_parser *p)
{
	if (p->map_finished)
	{
		ft_putstr_fd("Error\nContent found after map end\n", 2);
		return (-1);
	}
	if (p->map_started || is_map(line))
	{
		p->map_started = true;
		if (p->rows >= MAX_MAP_LINES - 1)
		{
			ft_putstr_fd("Error\nMap too large\n", 2);
			return (-1);
		}
		handle_map(line, map, p);
		return (0);
	}
	if (handle_id(line, p) == -1)
		return (-1);
	return (0);
}

// Bucle principal de lectura del mapa desde el archivo
char	**read_map(int fd, t_parser *p)
{
	char	*line;
	char	**map;

	map = safe_malloc(sizeof(char *) * MAX_MAP_LINES);
	ft_bzero(map, sizeof(char *) * MAX_MAP_LINES);
	line = get_next_line(fd);
	while (line)
	{
		if (!check_empty(line, p) && process_content(line, map, p) == -1)
			abort_read(map, line, fd, p);
		free(line);
		line = get_next_line(fd);
	}
	if (!p->map_started)
		abort_read(map, NULL, fd, p);
	return (map);
}
