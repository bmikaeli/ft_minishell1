/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 18:17:27 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/12/11 10:00:19 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list		*list;

	list = *alst;
	if (list)
	{
		if (new)
		{
			while (list->next)
				list = list->next;
			list->next = new;
		}
	}
	else
		alst = &new;
}
