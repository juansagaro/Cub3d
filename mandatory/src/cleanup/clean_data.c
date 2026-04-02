/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:29:40 by fgalvez-          #+#    #+#             */
/*   Updated: 2026/01/03 20:59:36 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static void	free_matrix(char ***m, int rows)
{
	int	i;

	if (!m || !*m)
		return ;
	i = 0;
	while (i < rows || (rows == -1 && (*m)[i]))
	{
		if ((*m)[i])
			free((*m)[i]);
		(*m)[i] = NULL;
		i++;
	}
	free(*m);
	*m = NULL;
}

static void	free_paths(t_parser *p)
{
	if (p->no)
		free(p->no);
	if (p->so)
		free(p->so);
	if (p->we)
		free(p->we);
	if (p->ea)
		free(p->ea);
	if (p->floor)
		free(p->floor);
	if (p->ceiling)
		free(p->ceiling);
}

void	free_parser(t_parser **pp)
{
	t_parser	*p;

	if (!pp || !*pp)
		return ;
	p = *pp;
	if (p->map)
		free_matrix(&p->map, p->rows);
	if (p->padded)
		free_matrix(&p->padded, -1);
	if (p->player)
		free(p->player);
	free_paths(p);
	free(p);
	*pp = NULL;
}
