/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:45:51 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/13 15:14:36 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	custom_isalnum(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

int	is_file_empty(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		is_empty;
	ssize_t	bytesread;
	ssize_t	i;

	is_empty = 1;
	while (1)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
			break ;
		i = 0;
		while (i < bytesread && is_empty)
		{
			if (custom_isalnum(buffer[i]))
				is_empty = 0;
			i++;
		}
		if (!is_empty)
			break ;
	}
	return (is_empty);
}

int	scene_is_empty(char *file)
{
	int	fd;
	int	result;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	result = is_file_empty(fd);
	close(fd);
	return (result);
}

bool	rgb_len(char *av)
{
	char	**tmp;

	tmp = ft_split(av, ',');
	if (matrix_len(tmp) != 3)
	{
		free_matrix(tmp);
		return (false);
	}
	free_matrix(tmp);
	return (true);
}
