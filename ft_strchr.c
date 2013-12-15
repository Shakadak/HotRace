/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:42:56 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 00:40:03 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hot_race.h"

char	*ft_strchr(const char *src, int c)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(src);
	if (c == 0)
		return ((char *)&src[l]);
	while (i < l)
	{
		if (src[i] == c)
			return ((char *)&src[i]);
		i++;
	}
	return (NULL);
}
