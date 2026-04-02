/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:14:15 by fgalvez-          #+#    #+#             */
/*   Updated: 2026/01/03 17:22:12 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static char	*get_row(char *src, int len, int max_cols)
{
	char	*row;

	row = safe_malloc(sizeof(char) * (max_cols + 1));
	ft_strlcpy(row, src, max_cols + 1);
	if (len < max_cols)
		ft_memset(row + len, ' ', max_cols - len);
	row[max_cols] = '\0';
	return (row);
}

void	copy_map(char **tmp, t_parser *parser)
{
	int	i;

	parser->map = safe_malloc(sizeof(char *) * (parser->rows + 1));
	i = 0;
	while (i < parser->rows)
	{
		parser->map[i] = get_row(tmp[i], ft_strlen(tmp[i]), parser->cols);
		free(tmp[i]);
		i++;
	}
	parser->map[i] = NULL;
	free(tmp);
}

/*
** Auxiliar para padded_map: Crea una fila nueva rellena de espacios
** y copia el contenido del mapa original en el centro si existe.
*/
static char	*new_padded_row(int size, char *src)
{
	char	*row;

	row = safe_malloc(sizeof(char) * (size + 1));
	ft_memset(row, ' ', size);
	row[size] = '\0';
	if (src)
		ft_memcpy(row + 1, src, ft_strlen(src));
	return (row);
}

/*
** Crea un nuevo mapa con un borde de espacios alrededor (padding).
** Util para evitar segfaults en el raycasting o floodfill.
** Rows + 2 (arriba/abajo) y Cols + 2 (izq/der).
*/
char	**padded_map(char **map, int rows, int cols)
{
	char	**padded;
	int		i;

	padded = safe_malloc(sizeof(char *) * (rows + 3));
	i = 0;
	while (i < rows + 2)
	{
		if (i == 0 || i == rows + 1)
			padded[i] = new_padded_row(cols + 2, NULL);
		else
			padded[i] = new_padded_row(cols + 2, map[i - 1]);
		i++;
	}
	padded[i] = NULL;
	return (padded);
}

void	handle_map(char *line, char **tmp_map, t_parser *parser)
{
	int	len;

	if (!is_map(line))
	{
		free(line);
		free_and_exit(parser, "Error\nMap contains invalid characters", -1);
	}
	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\n'))
		len--;
	tmp_map[parser->rows] = ft_substr(line, 0, len);
	if (!tmp_map[parser->rows])
	{
		free(line);
		free_and_exit(parser, "Error\nMalloc failed in handle_map", -1);
	}
	if (parser->cols < len)
		parser->cols = len;
	parser->rows++;
}
