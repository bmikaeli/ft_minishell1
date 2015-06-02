/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:17:03 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/12/03 17:19:51 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char				*ft_strchr(const char *s, int c)
{
	unsigned char	charact;

	charact = (unsigned char)c;
	while (*s != '\0')
	{
		if (charact == *s)
			return ((char *)s);
		s++;
	}
	if (charact == *s)
		return ((char *)s);
	return (NULL);
}
