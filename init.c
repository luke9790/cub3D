/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:13:25 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/11 14:31:30 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	init_img(void)
{
	return ((t_image)
		{
			.img_ptr = NULL,
			.addr = NULL,
			.bits_per_pixel = 0,
			.line_length = 0,
			.endian = 0
		});
}

void	ft_init_struct(t_data *box)
{
	box->mlx_ptr = mlx_init();
	if (!box->mlx_ptr)
		write(1, "error mlx_ptr", 14);
	box->win_ptr = mlx_new_window(box->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	box->wasd_movement[0] = false;
	box->wasd_movement[1] = false;
	box->wasd_movement[2] = false;
	box->wasd_movement[3] = false;
	box->wasd_movement[4] = false;
	box->wasd_movement[5] = false;
	box->wasd_movement[6] = false;
	box->parsed_map = NULL;
	box->textures.east.img_ptr = NULL;
	box->textures.west.img_ptr = NULL;
	box->textures.north.img_ptr = NULL;
	box->textures.south.img_ptr = NULL;
	box->textures.east.img_ptr = NULL;
	box->textures.west.img_ptr = NULL;
	box->textures.north.img_ptr = NULL;
	box->textures.south.addr = NULL;
	box->textures.north.addr = NULL;
	box->textures.east.addr = NULL;
	box->textures.west.addr = NULL;
	box->img = init_img();
}
