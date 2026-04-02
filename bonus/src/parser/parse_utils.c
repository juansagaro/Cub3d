/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:58:29 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/12/09 14:20:36 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

int	is_cub(char *av)
{
	char	*dot;

	dot = ft_strrchr(av, '.');
	if (!dot)
		return (0);
	return (ft_strncmp(dot, ".cub", 5) == 0);
}

bool	is_map(char *line)
{
	int		i;
	char	*valid_chars;

	valid_chars = " 01NSEWD\n";
	i = 0;
	while (line[i])
	{
		if (!ft_strchr(valid_chars, line[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_id(char *line)
{
	if (!ft_strcmp(line, "NO") || !ft_strcmp(line, "SO")
		|| !ft_strcmp(line, "WE") || !ft_strcmp(line, "EA")
		|| !ft_strcmp(line, "F") || !ft_strcmp(line, "C")
		|| !ft_strcmp(line, "D"))
		return (true);
	return (false);
}
