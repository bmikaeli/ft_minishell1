/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:15:52 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/12/03 17:03:02 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const char			*p2;
	char				*p1;

	i = 0;
	p1 = (char *)s1;
	p2 = (const char *)s2;
	while (i < n)
	{
		*p1 = *p2;
		p1++;
		p2++;
		n--;
	}
	return (s1);
}
