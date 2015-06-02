/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 16:29:16 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/12/23 15:41:16 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstadd(t_list **alst, void const *content, size_t content_size)
{
	t_list		*alst_tmp;

	if (content == NULL)
		return ;
	if (*alst == NULL)
		*alst = ft_lstnew(content, content_size);
	else
	{
		alst_tmp = *alst;
		while (alst_tmp->next != NULL)
			alst_tmp = alst_tmp->next;
		alst_tmp->next = ft_lstnew(content, content_size);
	}
}
