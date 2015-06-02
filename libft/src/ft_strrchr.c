/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:11:09 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/03 16:50:36 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char				*ft_strrchr(const char *s, int c)
{
	const char		*str;
	unsigned char	charact;
	int				i;

	i = 0;
	charact = (unsigned char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		str = &s[i];
		if (charact == s[i])
			return ((char *)str);
		i--;
	}
	str = &s[i];
	if (charact == s[i])
		return ((char *)str);
	return (NULL);
}
