/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:56:37 by cheron            #+#    #+#             */
/*   Updated: 2013/12/14 20:28:48 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hot_race.h"

int	ft_lstadd(t_list **alst, char *content)
{
	t_list	*new;

	if (!content)
		return (0);
	if (!(new = ft_lstnew(content)))
		return (0);
	new->next = *alst;
	*alst = new;
	return (1);
}
