/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:50:43 by jsagaro-          #+#    #+#             */
/*   Updated: 2024/11/26 17:33:00 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < lens2)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}
