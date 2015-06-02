/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 00:06:52 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/12/11 09:59:49 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static int				ft_check_start(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int				ft_check_end(char const *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	i += ft_strlen(s);
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
		j++;
	}
	return (j);
}

char					*ft_strtrim(char const *s)
{
	char	*dst;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	i += ft_strlen(s);
	dst = ft_memalloc(((i - ft_check_end(s)) - ft_check_start(s)) + 1);
	if (dst == NULL)
		return (NULL);
	i -= ft_check_end(s);
	j += ft_check_start(s);
	while (j < i)
	{
		dst[k] = s[j];
		k++;
		j++;
	}
	dst[k] = '\0';
	return (dst);
}
