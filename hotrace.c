/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 23:13:32 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 00:12:20 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "hot_race.h"

int		main(void)
{
	t_btree	*root;
	t_list	*query;

	root = NULL;
	query = NULL;
	root = ft_get_input(root);
	query = ft_get_query(query);
	ft_output_query(root, query);
	ft_del_tree(&root);
	ft_lstdel(&query);
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

t_list	*ft_get_query(t_list *query)
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
			ft_lstadd(&query, keyword);
	}
	return (query);
}

void	ft_output_query(t_btree *root, t_list *query)
{
	t_btree	*result;

	if (query == NULL)
		return ;
	ft_output_query(root, query->next);
	result = ft_search_node(root, query->content);
	if (result)
		ft_putendl(result->value);
	else
	{
		ft_putstr(query->content);
		ft_putendl(": Not found.");
	}
}
