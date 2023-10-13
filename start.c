/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:13:48 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/13 15:16:46 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	get_nbr_map_lines(char *file_name, int count, size_t i)
{
	int		scene_fd;
	char	*line;

	scene_fd = open(file_name, O_RDONLY);
	line = get_next_line(scene_fd);
	if (!only_spaces(line))
		i += 1;
	while (i < 7)
	{	
		free(line);
		line = get_next_line(scene_fd);
		if (!only_spaces(line))
			i += 1;
	}
	while (line)
	{	
		if (!only_spaces(line))
			count += 1;
		free(line);
		line = get_next_line(scene_fd);
	}
	close(scene_fd);
	return (count);
}

char	**get_map(char *file_name, int fd)
{
	size_t	i;
	size_t	nbr_lines;
	char	**map;
	char	*line;

	nbr_lines = get_nbr_map_lines(file_name, 0, 0);
	map = malloc((nbr_lines + 1) * sizeof(char *));
	i = 0;
	while (i < nbr_lines)
	{
		line = trim_free(get_next_line(fd), "\n");
		map[i] = ft_strdup(line);
		free(line);
		printf("%s\n", map[i]);
		i++;
	}
	map[i] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}
