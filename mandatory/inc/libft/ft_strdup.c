/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:43:11 by jsagaro-          #+#    #+#             */
/*   Updated: 2024/10/02 17:09:47 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_start);
}

char	*ft_strdup(const char *s)
{
	char	*pt;
	int		pt_len;

	pt_len = ft_strlen(s) + 1;
	pt = (char *)malloc(pt_len * sizeof(char));
	if (!pt)
		return (NULL);
	ft_strcpy(pt, (char *)s);
	return (pt);
}
