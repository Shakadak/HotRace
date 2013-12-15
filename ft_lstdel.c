/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:56:21 by cheron            #+#    #+#             */
/*   Updated: 2013/12/15 05:35:18 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

void	ft_lstdel(t_list **alst)
{
	if (alst == NULL)
		return ;
	if ((*alst)->next)
		ft_lstdel((&(*alst)->next));
	ft_strdel(&(*alst)->content);
	free(*alst);
	*alst = NULL;
}

