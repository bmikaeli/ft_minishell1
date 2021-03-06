/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:44:53 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/11/20 16:51:38 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}
