/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:43:39 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/13 11:06:33 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	point_rays(t_data *box, t_raycaster *rc)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (box->player.x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0f - box->player.x)
			* rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (box->player.y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0f - box->player.y)
			* rc->delta_dist_y;
	}
}

t_image	new_img(void *mlx_ptr)
{
	t_image	new_img;

	new_img.img_ptr = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.img_ptr, &new_img.bits_per_pixel,
			&new_img.line_length, &new_img.endian);
	return (new_img);
}

void	put_pixel_in_image(t_image *img, int x, int y, uint32_t color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(uint32_t *)dst = color;
}

void	init_rc(t_data *box, t_raycaster *rc, int x)
{
	rc->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	rc->ray_dir_x = box->camera.dir_x + box->camera.plane_x * rc->camera_x;
	rc->ray_dir_y = box->camera.dir_y + box->camera.plane_y * rc->camera_x;
	rc->map_x = (int)box->player.x;
	rc->map_y = (int)box->player.y;
	rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	rc->hit = false;
}
