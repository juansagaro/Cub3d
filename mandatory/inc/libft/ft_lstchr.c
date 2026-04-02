/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:50:21 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/09/25 11:50:21 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lstchr(const char *s)
{
	char	*c;
	int		i;

	if (!s)
		return (NULL);
	c = NULL;
	i = -1;
	while (s[++i])
	{
		if (s[i] && !ft_isspace(s[i]))
			c = ((char *)&s[i]);
	}
	return (c);
}
