/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:12:37 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/03 16:45:31 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void			*ft_memalloc(size_t size)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (void *)malloc(sizeof(void) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > i)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
