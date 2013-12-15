/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 16:16:06 by npineau           #+#    #+#             */
/*   Updated: 2013/12/15 00:41:56 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hot_race.h"
#ifndef UNISTD_H
# define UNIST_H
# include <unistd.h>
#endif

/*
** Each and every function in this file return an integer, in order to exit.
** Whether to return an error or that the line is completed.
*/

int		get_next_line(int const fd, char **line)
{
	int			ret;
	static char	buff[BUFF_SIZE + 1];

	ret = ft_init_line(line);
	if (ret == -1)
		return (-1);
	if (ft_strlen(buff))
	{
		ret = ft_cp_buff(line, buff);
		if (ret == -1)
			return (-1);
		if (ft_check_line(buff))
			return (1);
	}
	ret = ft_read_txt(fd, line, buff);
	if (ret == -1)
		return (-1);
	else if (ret == 0)
		return (0);
	else
		return (1);
}

/*
** ft_read_txt use read in a loop and copy what's in the buffer to *line,
** using ft_cp_buff. Whenever ft_check_line return 1 or -1, it exit the loop.
*/

int		ft_read_txt(int fd, char **line, char *buff)
{
	int	res;
	int	ret;

	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		ret = ft_cp_buff(line, buff);
		if (ret == -1)
			return (-1);
		if (ft_check_line(buff))
			return (1);
	}
	if (res == 0)
	{
		if (ft_strlen(*line))
			return (1);
		return (0);
	}
	return (-1);
}

/*
** ft_cp_buff copy what's in the buffer to a temporary string, stopping when
** encountering a \n or when reaching the end of the buffer.
** It then join the current line with the temporary string.
** Because of the behavior of ft_strjoin, the address of *line must be stored
** premptively to be able to free after, as it return a new string.
** The temporary string is freed as well.
*/

int		ft_cp_buff(char **line, char *buff)
{
	char	*c;
	char	*tmp;
	int		len;

	len = ft_strlen(buff);
	tmp = ft_strnew(len);
	if (!tmp)
		return (-1);
	ft_memccpy(tmp, buff, '\n', len);
	c = ft_strchr(tmp, '\n');
	if (c)
		*c = '\0';
	c = *line;
	*line = ft_strjoin(*line, tmp);
	ft_strdel(&c);
	ft_strdel(&tmp);
	if (!*line)
		return (-1);
	return (1);
}

/*
** ft_init_line check if *line does exist. If that's the case, it clear it,
** otherwise it create a new one of size 0 (Actually of size 1 to place a \0).
** Note that it's the responsibility of the user to give an allocated pointer
** if *line isn't NULL, as there is no way to check if the adress point to
** allocated memory.
*/

int		ft_init_line(char **line)
{
	if (*line)
		ft_strclr(*line);
	else
		*line = ft_strnew(0);
	if (!*line)
		return (-1);
	return (0);
}

/*
** ft_check_line verify if a \n is present in the buffer. If that's the case,
** it "move" the start of the buffer after the \n, otherwise, it clear
** enirely the buffer.
*/

int		ft_check_line(char *buff)
{
	if (ft_strchr(buff, '\n'))
	{
		ft_strcpy(buff, ft_strchr(buff, '\n') + 1);
		return (1);
	}
	ft_strclr(buff);
	return (0);
}
