/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wrap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:43:27 by pcocci            #+#    #+#             */
/*   Updated: 2023/10/12 16:19:43 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tex_error(t_data *box, int fd)
{
	char	*to_free;

	to_free = get_next_line(fd);
	ft_free_all(box);
	while (to_free != NULL)
	{
		free(to_free);
		to_free = get_next_line(fd);
	}
	free(to_free);
	close(fd);
	ft_perror_exit("Error\nFailed loading textures or rgb\n");
}

void	map_error(t_data *box, char **map_part, int fd)
{
	if (map_part)
		free_matrix(map_part);
	ft_free_all(box);
	free(get_next_line(fd));
	printf("Error\nFailed loading map\n");
	exit(1);
}

void	error_permission(t_data *box)
{
	mlx_destroy_window(box->mlx_ptr, box->win_ptr);
	mlx_destroy_display(box->mlx_ptr);
	free(box->mlx_ptr);
	ft_perror_exit("Error");
}

void	parse_tex_colors(t_data *box, char *file)
{
	int		fd;
	char	**textures;
	char	**map_part;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_permission(box);
	if (scene_is_empty(file) == 1)
	{
		error_permission(box);
	}
	textures = ft_textures(fd);
	if (!parse_textures(box, textures))
		tex_error(box, fd);
	map_part = get_map(file, fd);
	if (!parse_map(map_part, box))
		map_error(box, map_part, fd);
	box->parsed_map = map_part;
	close(fd);
}
