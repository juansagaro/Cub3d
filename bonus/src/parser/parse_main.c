/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:42:35 by fgalvez-          #+#    #+#             */
/*   Updated: 2026/01/03 19:20:41 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static char	*get_id(char *line)
{
	char	*id;
	int		len;

	len = 0;
	while (line[len] && !ft_isspace(line[len]))
		len++;
	id = safe_malloc(len + 1);
	ft_strlcpy(id, line, len + 1);
	return (id);
}

// Auxiliar: Extrae ID y Valor de la línea recortada y llama a set_var
static int	parse_content(char *trimmed, t_parser *p)
{
	char	*id;
	char	*val;
	int		ret;

	id = get_id(trimmed);
	if (!is_id(id))
	{
		free(id);
		ft_putstr_fd("Error\nInvalid identifier\n", 2);
		return (-1);
	}
	val = ft_strtrim(trimmed + ft_strlen(id), " \t\n\r\v\f");
	if (!val || !*val)
	{
		free(id);
		free(val);
		ft_putstr_fd("Error\nMissing value\n", 2);
		return (-1);
	}
	ret = set_var(id, val, p);
	free(id);
	return (ret);
}

// Recorta la línea original y delega el trabajo
int	handle_id(char *line, t_parser *parser)
{
	char	*tmp;
	int		ret;

	tmp = ft_strtrim(line, " \t\n\r\v\f");
	if (!tmp)
		return (-1);
	if (!*tmp)
	{
		free(tmp);
		return (0);
	}
	ret = parse_content(tmp, parser);
	free(tmp);
	return (ret);
}

// Función principal de parseo: abre, lee, procesa y valida
void	parser(t_cub3d *cub3d, char **av)
{
	int			fd;
	char		**tmp;
	t_parser	*p;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(ft_error(1, NOT_OPEN));
	p = safe_malloc(sizeof(t_parser));
	init_parser(p);
	tmp = read_map(fd, p);
	close(fd);
	copy_map(tmp, p);
	p->padded = padded_map(p->map, p->rows, p->cols);
	check_map(p->padded, p);
	check_info(p);
	cub3d->parser = p;
	// debug_after_parse(cub3d);
}
