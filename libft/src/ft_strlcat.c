/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:43:51 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/12/11 09:54:34 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	int		len_dst;
	int		len_src;
	int		i;
	int		k;

	i = 0;
	k = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	while (dst[i] != '\0')
		i++;
	while ((size_t)(len_dst + k + 1) < size)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	if ((size_t)len_dst < size)
		return (len_dst + len_src);
	else
		return (size + len_src);
}
