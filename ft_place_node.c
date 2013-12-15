/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 18:58:06 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 05:35:39 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "hotrace.h"
/*
** Place the node to the left if [new] is lower than [current] according to
** ft_tri. To the right if greater (or equal). It return [new] if [current]
** is NULL, otherwise place the node, then return [current].
*/

t_btree	*ft_place_node(t_btree *current, t_btree *new)
{
	if (current == NULL)
		return (new);
	if (ft_strcmp(current->keyword, new->keyword) > 0)
	{
		if (current->left == NULL)
			current->left = new;
		else
			ft_place_node(current->left, new);
	}
	else
	{
		if (current->right == NULL)
			current->right = new;
		else
			ft_place_node(current->right, new);
	}
	return (current);
}
