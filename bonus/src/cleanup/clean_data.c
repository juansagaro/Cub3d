/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:29:40 by fgalvez-          #+#    #+#             */
/*   Updated: 2026/01/03 17:39:48 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

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
	if (p->door)
		free(p->door);
}

void	free_parser(t_parser **pp)
{
	t_parser	*p;

	if (!pp || !*pp)
		return ;
	p = *pp;
	if (p->map)
		ft_free_matrix(p->map);
	if (p->padded)
		ft_free_matrix(p->padded);
	if (p->player)
		free(p->player);
	free_paths(p);
	free(p);
	*pp = NULL;
}
