/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 23:13:32 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 06:19:34 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "hotrace.h"

int		main(void)
{
	t_btree	*root;

	root = NULL;
	root = ft_get_input(root);
	ft_get_query(root);
	ft_del_tree(&root);
}

t_btree	*ft_get_input(t_btree *root)
{
	int		k;
	char	*keyword;
	char	*value;

	keyword = NULL;
	value = NULL;
	k = 1;
	while (k)
	{
		get_next_line(0, &keyword);
		k = (keyword[0] == '\0' ? 0 : 1);
		if (keyword[0] != '\0')
		{
			get_next_line(0, &value);
			k = (value[0] == '\0' ? 0 : 1);
		}
		if (keyword[0] != '\0')
			root = ft_create_tree(root, keyword, value);
	}
	return (root);
}

t_btree	*ft_create_tree(t_btree *root, char *keyword, char *value)
{
	t_btree	*node;

	if (value == NULL)
	{
		value = (char *)malloc(sizeof(char));
		*value = '\0';
	}
	node = ft_new_node(keyword, value);
	root = ft_place_node(root, node);
	return (root);
}

void	ft_get_query(t_btree *root)
{
	char	*keyword;
	int		k;

	keyword = NULL;
	k = 1;
	while (k)
	{
		get_next_line(0, &keyword);
		k = (keyword[0] == '\0' ? 0 : 1);
		if (keyword[0] != '\0')
			ft_output_query(root, keyword);
	}
}

void	ft_output_query(t_btree *root, char *query)
{
	t_btree	*result;

	if (query == NULL)
		return ;
	result = ft_search_node(root, query);
	if (result)
		ft_putendl(result->value);
	else
	{
		ft_putstr(query);
		ft_putendl(": Not found.");
	}
}
