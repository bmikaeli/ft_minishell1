/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:00:53 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/12/11 09:53:09 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char			*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int		i;

	i = 0;
	while (i < n)
	{
		if (i < ft_strlen(s2))
			s1[i] = s2[i];
		else
			s1[i] = '\0';
		i++;
	}
	return (s1);
}
