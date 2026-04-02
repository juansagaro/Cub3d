/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:21:33 by jsagaro-          #+#    #+#             */
/*   Updated: 2024/10/02 17:15:33 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	result_size(int n)
{
	unsigned int	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	size;
	int				i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = result_size(n);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	i = size - 1;
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
