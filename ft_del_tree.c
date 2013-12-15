/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 17:59:52 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 00:29:47 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "hot_race.h"

void	ft_del_tree(t_btree **current)
{
	if ((*current)->left)
		ft_del_tree(&(*current)->left);
	if ((*current)->right)
		ft_del_tree(&(*current)->right);
	ft_strdel(&(*current)->keyword);
	ft_strdel(&(*current)->value);
	free(*current);
	*current = NULL;
}
