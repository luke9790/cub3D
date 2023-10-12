/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:48:04 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/12 16:31:55 by lmasetti         ###   ########.fr       */
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

void	free_image(t_image *img, t_data *box)
{
	if (img)
	{
		if (img->img_ptr)
			mlx_destroy_image(box->mlx_ptr, img->img_ptr);
	}
}

void	free_textures(t_textures *textures, t_data *box)
{
	if (textures != NULL)
	{
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
