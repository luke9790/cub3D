/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:13:48 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/02 18:39:08 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	get_nbr_map_lines(char *file_name)
{
	int		scene_fd;
	size_t	i;
	size_t	count;
	char	*line;

	scene_fd = open(file_name, O_RDONLY);
	i = 0;
	count = 0;
	line = get_next_line(scene_fd);
	while (i < 6)
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

	nbr_lines = get_nbr_map_lines(file_name);
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
	free(get_next_line(fd));
	return (map);
}
