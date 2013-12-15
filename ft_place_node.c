/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 18:58:06 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 07:09:40 by npineau          ###   ########.fr       */
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
	int	res;

	if (current == NULL)
		return (new);
	res = ft_strcmp(new->keyword, current->keyword);
	if (res < 0)
	{
		if (current->left == NULL)
			current->left = new;
		else
			ft_place_node(current->left, new);
	}
	else if (res > 0)
	{
		if (current->right == NULL)
			current->right = new;
		else
			ft_place_node(current->right, new);
	}
	else
		ft_swap_node(current, new);
	return (current);
}
