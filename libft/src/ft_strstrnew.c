/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bullfire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 20:47:09 by bullfire          #+#    #+#             */
/*   Updated: 2014/01/05 20:52:00 by bullfire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char			**ft_strstrnew(size_t size)
{
	size_t		i;
	char		**s;

	i = 0;
	s = (char **)malloc(sizeof(char *) * (size + 1));
	if (s == NULL)
		return (NULL);
	while (i < size)
	{
		s[i] = NULL;
		i++;
	}
	return (s);
}
