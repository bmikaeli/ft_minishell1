/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:21:57 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/03/26 13:04:02 by scadoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char		*p1;
	const char		*p2;

	p1 = (char *)s1;
	p2 = (char *)s2;
	while (*p1 == *p2 && n > 0)
	{
		p1++;
		p2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*p1 - *p2);
}
