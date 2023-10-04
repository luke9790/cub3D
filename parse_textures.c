/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:43 by pcocci            #+#    #+#             */
/*   Updated: 2023/10/03 16:30:06 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **ft_textures(int fd)
{
    char    **mat_textures;
    char    *to_free;
    size_t  i;
    char    *line;

    mat_textures = malloc((7) * sizeof(char *));
    i = 0;
    while (i < 6)
    {
        line = trim_free(get_next_line(fd), "\n");
        if (only_spaces(line))
        {
            free(line);
            continue;
        }
        mat_textures[i] = line;
        i++;
    }
    mat_textures[i] = NULL;
    to_free = get_next_line(fd);
    free(to_free);
    return (mat_textures);
}

static bool	assign_rgb(int *element_rgb, char **rgb)
{
	size_t	i;

	i = 0;
	if (matrix_len(rgb) != 3)
		return (false);
	while (rgb[i])
	{
		if (!is_all_digits(rgb[i]))
			return (false);
		element_rgb[i] = ft_atoi(rgb[i]);
		if (!fits_in_intrange(element_rgb[i], 0, 255))
        {   
            perror("RGB ou of range\n");
			return (false);
        }
		i += 1;
	}
	return (true);
}

static bool parse_rgb(char *lettera, int *rgb_arr, char **map)
{
    int     i;
    bool    value;
    char	**temp;
	char	**rgb;

	i = -1;
	value = true;
	while (++i < 6)
	{
		temp = ft_split(map[i], ' ');
		if (streq(lettera, temp[0]))
		{   
            
			if (matrix_len(temp) != 2)  //|| !rgb_len(temp[0]) || !rgb_len(temp[1]))
            {   
                //free_matrix(temp);
                perror("Error \n Wrong Colors Attributes\n");
				//return (false);
            }
			rgb = ft_split(temp[1], ',');
			if (value == true && !assign_rgb(rgb_arr, rgb))
				value = false;
			free_matrix(rgb);
			free_matrix(temp);
			return (value);
		}
		free_matrix(temp);
	}	
	return (false);
}

static bool parse_coordinates(char *coor, void *mlx_ptr, t_image *tex, char **map)
{   
    t_image texture;
    int i;
    char    **tmp;

    i = 0;
    while (i < 6)
    {
        tmp = ft_split(map[i], ' ');
        if (streq(coor, tmp[0]))
        {
            if (matrix_len(tmp) != 2)
            {
                free_matrix(tmp);
                return(write(1, "Error \n Invalid Attributes", 27), false);
            }
            if (!load_img(mlx_ptr, &texture, tmp))
            {   
                free_matrix(tmp);
                return (false);
            }
            free_matrix(tmp);
            *tex = texture;
            return (true);
        }
        i++;
        free_matrix(tmp);
    }
    return (false);
}

bool    parse_textures(t_data *box, char **textures)
{
    bool    value;

    value = false;
    if (parse_coordinates("NO", box->mlx_ptr, 
            &box->textures.north, textures)
        && parse_coordinates("SO", box->mlx_ptr, 
            &box->textures.south, textures)
        && parse_coordinates("EA", box->mlx_ptr, 
            &box->textures.east, textures)
        && parse_coordinates("WE", box->mlx_ptr, 
            &box->textures.west, textures)
        && parse_rgb("C", box->textures.sky_rgb, textures)
        && parse_rgb("F", box->textures.floor_rgb, textures))
        value = true;
    free_matrix(textures);
    return (value);
}