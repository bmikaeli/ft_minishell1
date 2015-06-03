/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:23:49 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/12/11 09:54:02 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (ft_strncmp(s1, s2, ft_strlen(s2)) != 0 && n-- >= ft_strlen(s2))
	{
		if (*s1 == '\0')
		{
			break ;
		}
		s1++;
	}
	if (n < ft_strlen(s2) || ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	else if (*s1 == '\0' && n == 0)
		return (NULL);
	return ((char*)s1);
}
