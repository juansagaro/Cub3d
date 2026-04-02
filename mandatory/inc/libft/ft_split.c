/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:51:42 by jsagaro-          #+#    #+#             */
/*   Updated: 2024/10/08 18:09:42 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substrings(char *str, char c)
{
	int	count;
	int	i;
	int	in_word;

	count = 0;
	i = 0;
	in_word = 0;
	if (!str)
		return (count);
	while (str[i])
	{
		if (str[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*ft_strcpy_from_to(char *start, char *end)
{
	char	*dest;
	int		i;
	int		len;

	len = end - start;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = start[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**create_array(char **result, char *str, char c)
{
	int		i;
	int		j;
	char	*start;

	i = 0;
	j = 0;
	start = NULL;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (!start)
				start = &str[i];
		}
		else if (start)
		{
			result[j++] = ft_strcpy_from_to(start, &str[i]);
			start = NULL;
		}
		i++;
	}
	if (start)
		result[j++] = ft_strcpy_from_to(start, &str[i]);
	return (result);
}

void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}

char	**ft_split(char const *str, char c)
{
	int		result_size;
	char	**result;

	result_size = count_substrings((char *)str, c);
	result = (char **)malloc((result_size + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!create_array(result, (char *)str, c))
	{
		free_split(result);
		return (NULL);
	}
	result[result_size] = NULL;
	return (result);
}
