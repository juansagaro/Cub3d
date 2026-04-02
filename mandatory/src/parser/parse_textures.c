/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:27:48 by fgalvez-          #+#    #+#             */
/*   Updated: 2026/01/03 17:51:08 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

// Función auxiliar: verifica extensión
static int	is_xpm(char *var)
{
	size_t	len;

	len = ft_strlen(var);
	if (len < 4)
		return (0);
	return (ft_strncmp(var + len - 4, ".xpm", 4) == 0);
}

// Función auxiliar: verifica si el archivo existe
static int	check_path(char *var)
{
	int	fd;

	if (!is_xpm(var))
	{
		free(var);
		ft_putstr_fd("Error\nTexture must be .xpm\n", 2);
		return (-1);
	}
	fd = open(var, O_RDONLY);
	if (fd < 0)
	{
		free(var);
		ft_putstr_fd("Error\nInvalid texture path\n", 2);
		return (-1);
	}
	close(fd);
	return (0);
}

// Guarda paredes (NO, SO, WE, EA, D)
static int	save_wall(char *var, char **target, bool *flag, t_parser *p)
{
	if (*flag)
	{
		free(var);
		free_and_exit(p, "Error\nDuplicate identifier\n", -1);
	}
	if (check_path(var) == -1)
		return (-1);
	*target = var;
	*flag = true;
	return (0);
}

// Router para F y C: Decide si es textura o color
static int	set_fc(char *id, char *var, t_parser *p)
{
	int		is_f;
	bool	*flag;

	is_f = (ft_strcmp(id, "F") == 0);
	if (is_f)
		flag = &p->f_set;
	else
		flag = &p->c_set;
	if (*flag)
	{
		free(var);
		free_and_exit(p, "Error\nDuplicate F/C\n", -1);
	}
	if (is_xpm(var))
	{
		if (is_f)
			return (save_wall(var, &p->floor, flag, p));
		else
			return (save_wall(var, &p->ceiling, flag, p));
	}
	return (handle_fc_color(var, is_f, flag, p));
}

// Función principal de despacho
int	set_var(char *id, char *var, t_parser *p)
{
	if (!ft_strcmp(id, "NO"))
		return (save_wall(var, &p->no, &p->no_set, p));
	if (!ft_strcmp(id, "SO"))
		return (save_wall(var, &p->so, &p->so_set, p));
	if (!ft_strcmp(id, "WE"))
		return (save_wall(var, &p->we, &p->we_set, p));
	if (!ft_strcmp(id, "EA"))
		return (save_wall(var, &p->ea, &p->ea_set, p));
	if (!ft_strcmp(id, "F") || !ft_strcmp(id, "C"))
		return (set_fc(id, var, p));
	free(var);
	return (0);
}
