/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:03:39 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 05:36:27 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hotrace.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		len;

	if (!(s1 && s2))
		return (NULL);
	len = ft_strlen(s1);
	new = ft_strnew(len + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcpy(&new[len], s2);
	return (new);
}
