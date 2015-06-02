/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:00:54 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/12/11 09:57:03 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_putnbr_fd(int n, int fd)
{
	int		div;

	div = 1;
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	while ((n / div) >= 10)
		div *= 10;
	while (div > 0)
	{
		ft_putchar_fd((n / div) % 10 + 48, fd);
		div /= 10;
	}
}
