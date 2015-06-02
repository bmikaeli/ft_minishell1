/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:17:19 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/03/26 13:03:31 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	charact;

	charact = (unsigned char)c;
	while (n > 0)
	{
		if (*(const char *)s == charact)
			return ((char *)s);
		s++;
		n--;
	}
	if (*(const char *)s == charact)
		return ((char *)s);
	return (NULL);
}
