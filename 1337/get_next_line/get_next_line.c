/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:17:03 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/29 15:32:41 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

char	*clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = malloc(ft_strlen(stash + i) + 1);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

static char	*read_and_join(int fd, char *stash)
{
	ssize_t	read_bytes;
	char	*buff;
	char	*tmp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_bytes = read(fd, buff, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(buff);
		return (NULL);
	}
	buff[read_bytes] = '\0';
	tmp = ft_strjoin(stash, buff);
	free(buff);
	return (tmp);
}

static char	*fill_stash(int fd, char *stash)
{
	char	*tmp;

	tmp = stash;
	while (!(tmp && ft_strchr(tmp, '\n')))
	{
		tmp = read_and_join(fd, tmp);
		if (!tmp)
			break ;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash || !*stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
