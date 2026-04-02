/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:21:11 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/12/09 14:21:11 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d/cub3d.h"

int	ft_error(int code, char *str)
{
	ft_putstr_fd(str, 2);
	return (code);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_error(1, "Error\nMemory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
