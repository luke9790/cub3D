/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wrap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:43:27 by pcocci            #+#    #+#             */
/*   Updated: 2023/10/03 16:24:25 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    tex_error(t_data *box, int fd)
{   
    char *to_free;

    to_free = get_next_line(fd);
    ft_free_all(box);
    while (to_free != NULL)
    {
        free(to_free);
        to_free = get_next_line(fd);
    }
    close(fd);
    ft_perror_exit("Error\nFailed loading textures or rgb\n");
}

void    map_error(t_data *box, char **map_part, int fd)
{
    if (map_part)
        free_matrix(map_part);
    ft_free_all(box);
    free(get_next_line(fd));
    ft_perror_exit("Error\nFailed loading map\n");
}

void    parse_tex_colors(t_data *box, char *file)
{
    int     fd;
    char    **textures;
    char    **map_part;

    fd = open(file, O_RDONLY);
    textures = ft_textures(fd);
    if (!parse_textures(box, textures))
        tex_error(box, fd);
    map_part = get_map(file, fd);
    if (!parse_map(map_part, box))
        map_error(box, map_part, fd);
    box->parsed_map = map_part;
    close(fd);
}