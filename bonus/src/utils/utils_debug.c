/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:57:32 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/12/08 18:35:29 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

static void	print_rgb(const char *tag, const t_rgb *c)
{
	printf("%s: r=%d g=%d b=%d\n", tag, c->r, c->g, c->b);
}

static void	print_matrix(char **m, int rows, const char *title)
{
	int	i;

	printf("%s (rows=%d):\n", title, rows);
	if (!m)
	{
		printf("  (null)\n");
		return ;
	}
	i = 0;
	while (i < rows)
	{
		if (!m[i])
			printf("  [%d]: (null)\n", i);
		else
			printf("  [%d]: \"%s\"\n", i, m[i]);
		i++;
	}
}

static void	print_basics(const t_parser *p)
{
	printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\n", p->no, p->so, p->we, p->ea);
	print_rgb("F", &p->f);
	print_rgb("C", &p->c);
	printf("rows=%d cols=%d\n", p->rows, p->cols);
}

void	debug_after_parse(const t_cub3d *cub3d)
{
	const t_parser	*p;

	printf("========== DEBUG AFTER PARSE ==========\n");
	if (!cub3d || !cub3d->parser)
	{
		printf("cub3d or parser: (null)\n");
		return ;
	}
	p = cub3d->parser;
	print_basics(p);
	if (p->player)
		printf("Player: x=%f y=%f ori=%c\n",
			p->player->x, p->player->y, p->player->orientation);
	print_matrix(p->map, p->rows, "map");
	print_matrix(p->padded, p->rows + 2, "padded");
	printf("=======================================\n");
}
