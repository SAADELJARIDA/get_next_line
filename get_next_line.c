/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:01:17 by sel-jari          #+#    #+#             */
/*   Updated: 2024/12/15 15:03:59 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fetch_line(char *buff)
{
	int	i;

	i = -1;
	while (buff[++i])
		if (buff[i] == '\n')
			return (i);
	return (-1);
}

char	*return_line(char **line, char **leftover, int line_len)
{
	char	*line_to_return;

	if (line_len == -1)//if theres is no newline
	{
		return (*line);
	}
	line_to_return = ft_substr(*line, 0, line_len + 1);
	*leftover = ft_substr(*line, line_len + 1, ft_strlen(*line));
	free(*line);
	return (line_to_return);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buff;
	char		*line;
	int			buff_len;
	int			line_len;

	line = leftover;
	if (!line)
		line = ft_calloc(1, 1);
	leftover = 0;
	buff = malloc(BUFFER_SIZE + 1);
	buff_len = read(fd, buff, BUFFER_SIZE);
	while (buff_len >= 0)
	{
		buff[buff_len] = 0;
		line = ft_strjoin(line, buff);
		line_len = fetch_line(line);
		if (buff_len <= 0 && !*line)
			break ;
		if (line_len == -1 && buff_len)
		{
			buff_len = read(fd, buff, BUFFER_SIZE);
			continue ;
		}
		free(buff);
		return (return_line(&line, &leftover, line_len));
	}
	free(buff);
	free(line);
	return (0);
}
