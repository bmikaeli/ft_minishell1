/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bullfire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 20:55:00 by bullfire          #+#    #+#             */
/*   Updated: 2014/01/19 19:25:33 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				**ft_strstrdup(char **s)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_strstrnew(ft_strstrlen(s) + 1);
	while (s[i] != NULL)
	{
		str[i] = ft_strdup(s[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
