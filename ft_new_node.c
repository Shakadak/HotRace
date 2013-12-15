/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 19:18:41 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 06:37:39 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Create a new node, and allocate it and initialize every element to NULL.
** If the alloction fail, NULL is returned.
*/

t_btree	*ft_new_node(char *keyword, char *value)
{
	t_btree		*new;

	new = (t_btree *)malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->value = value;
	new->keyword = keyword;
	if (new->keyword[0] == '\0')
	{
		ft_putendl("YOLO///");
		sleep(10);
	}
	return (new);
}
