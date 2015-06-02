/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bullfire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 22:08:56 by bullfire          #+#    #+#             */
/*   Updated: 2014/01/06 08:22:36 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_strstrlen(char **s)
{
	int		result;

	result = 0;
	while (s[result] != NULL)
		result++;
	return (result);
}
