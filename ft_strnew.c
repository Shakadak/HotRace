/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 12:49:33 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 05:37:07 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STDLIB_H
# define STDLIB_H
# include <stdlib.h>
#endif
#include "hotrace.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		size++;
		while (size)
		{
			size--;
			str[size] = 0;
		}
		return (str);
	}
	else
		return (NULL);
}
