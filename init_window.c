/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:01:20 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/13 12:47:40 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	load_img(void *mlx_ptr, t_image *texture, char **path)
{
	int	size;

	texture->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path[1], &size, &size);
	if (!texture->img_ptr)
	{
		write(1, "Error in loading image\n", 24);
		return (false);
	}
	texture->addr = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		write(1, "Error in addres image\n", 23);
		return (false);
	}
	return (true);
}

void	render_next_frame(t_data *box)
{
	ft_raycasting(box);
	mlx_clear_window(box->mlx_ptr, box->win_ptr);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img.img_ptr, 0, 0);
}
