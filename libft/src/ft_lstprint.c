/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 13:00:20 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/12/23 13:02:21 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				print_list(t_list **alst)
{
	while (*alst)
	{
		ft_putendl((*alst)->content);
		*alst = (*alst)->next;
	}
}
