/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:00:18 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/02 18:07:18 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_next(char **temp)
{
	char	*line;
	char	*ptr;

	ptr = *temp;
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr (*temp, 0, (size_t)(ptr - *temp));
	if (!line)
	{
		free (*temp);
		return (NULL);
	}
	ptr = ft_substr (ptr, 0, ft_strlen (ptr));
	free (*temp);
	*temp = ptr;
	return (line);
}

static char	*ft_read(char *temp, int fd, char *buf)
{
	ssize_t		r;

	r = 1;
	while (r && !ft_strchr (temp, '\n'))
	{
		r = read (fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free (buf);
			free (temp);
			return (NULL);
		}
		buf[r] = 0;
		temp = ft_strjoin_free_s1 (temp, buf);
		if (!temp)
		{
			free (buf);
			return (NULL);
		}
	}
	free (buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*buf;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp[fd])
		temp[fd] = ft_strdup("");
	if (!temp[fd])
		return (NULL);
	buf = malloc (sizeof (*buf) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free (temp[fd]);
		return (NULL);
	}
	temp[fd] = ft_read (temp[fd], fd, buf);
	if (!temp[fd])
		return (NULL);
	if (!*temp[fd])
	{
		free (temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	return (ft_next(&temp[fd]));
}
