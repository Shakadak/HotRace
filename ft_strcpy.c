/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:08:08 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 05:36:05 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcpy(char *copy, const char *src)
{
	unsigned int	index;

	index = 0;
	while (src[index] != 0)
	{
		copy[index] = src[index];
		index++;
	}
	copy[index] = 0;
	return (copy);
}
