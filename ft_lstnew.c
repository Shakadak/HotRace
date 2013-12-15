/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:01:36 by cheron            #+#    #+#             */
/*   Updated: 2013/12/15 05:35:25 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

t_list	*ft_lstnew(char const *content)
{
	t_list	*new;

	if (!(new = (t_list *) malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
		new->content = NULL;
	else
	{
		if (!(new->content = ft_strdup(content)))
		{
			free(new);
			return (NULL);
		}
	}
	new->next = NULL;
	return (new);
}
