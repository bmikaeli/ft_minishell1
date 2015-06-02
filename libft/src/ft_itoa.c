/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:13:28 by bmikaeli          #+#    #+#             */
/*   Updated: 2015/01/26 14:55:44 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static size_t	ft_mem_alloc(int nb)
{
	size_t	res;

	res = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		res++;
	}
	return (res);
}

static char		*ft_negative(int n)
{
	char	*ptr;
	int		i;
	int		div;

	div = 1;
	n = n * -1;
	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_mem_alloc(n) + 1));
	ptr[i] = '-';
	i++;
	while ((n / div) >= 10)
		div *= 10;
	while (div > 0)
	{
		ptr[i] = ((n / div) % 10) + 48;
		div = div / 10;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char		*ft_zero(void)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) + 2);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

char			*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		div;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_zero());
	i = 0;
	div = 1;
	ptr = (char *)malloc(sizeof(char) * (ft_mem_alloc(n) + 1));
	if (n < 0)
		return (ft_negative(n));
	while ((n / div) >= 10)
		div *= 10;
	while (div > 0)
	{
		ptr[i] = ((n / div) % 10) + 48;
		div = div / 10;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
