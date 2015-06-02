/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:01:55 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/03 16:47:11 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	charact;
	char			*p1;
	char			*p2;
	int				i;

	i = 0;
	p1 = (char *)s1;
	p2 = (char *)s2;
	charact = (unsigned char)c;
	while (n > 0)
	{
		*p1 = *p2;
		if (*p2 == charact)
			return (s1 + (i + 1));
		p1++;
		p2++;
		n--;
		i++;
	}
	return (NULL);
}
