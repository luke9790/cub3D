/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:48:04 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/03 16:13:48 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}



char	*ft_strncpy(char *str, int start)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *) malloc(sizeof(char) * (ft_strlen(str) - start));
	if (!dst)
		perror("Error\n");
	while (start < (int)ft_strlen(str) - 1)
		dst[i++] = str[start++];
	dst[i] = '\0';
	return (dst);
}

int	ft_strncmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void free_image(t_image *img, t_data *box)
{
    if (img) {
        if (img->img_ptr)
            mlx_destroy_image(box->mlx_ptr, img->img_ptr); // Destroy the image
    }
}

void free_textures(t_textures *textures, t_data *box)
{
    if (textures != NULL) {
        free_image(&textures->north, box);
        free_image(&textures->south, box);
        free_image(&textures->east, box);
        free_image(&textures->west, box);
    }
}

int	ft_free_all(t_data *box)
{
	
	free_textures(&box->textures, box);
	if (box->win_ptr)
		mlx_destroy_window(box->mlx_ptr, box->win_ptr);
	if (box->parsed_map != NULL)
		free_matrix(box->parsed_map);
	if (box->mlx_ptr)
	{
		mlx_destroy_display(box->mlx_ptr);
		free(box->mlx_ptr);
	}
	return (0);
}

int	ft_free_n_exit(t_data *box)
{
	ft_free_all(box);
	exit(0);
}
