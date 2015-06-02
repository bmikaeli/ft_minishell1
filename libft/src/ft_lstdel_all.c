/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 18:14:12 by bmikaeli          #+#    #+#             */
/*   Updated: 2013/12/11 10:00:50 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void				ft_lstdel_all(t_list *alst)
{
	if (alst->next)
		ft_lstdel_all(alst->next);
	free(alst->content);
	free(alst);
}
