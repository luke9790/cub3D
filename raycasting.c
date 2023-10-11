/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:43:39 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/11 15:57:55 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image new_img(void *mlx_ptr)
{
	t_image	new_img;

	new_img.img_ptr = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.img_ptr, &new_img.bits_per_pixel,
			&new_img.line_length, &new_img.endian);
	return (new_img);
}

// Function to draw a vertical line on an image

void	put_pixel_in_image(t_image *img, int x, int y, uint32_t color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(uint32_t *)dst = color;
}

static void	draw_vertical_line(t_data *box, t_raycaster *rc, int x)
{
	int	y;

	y = -1;
	while (++y < rc->draw_start)
	{
		put_pixel_in_image(&box->img, x, y, ft_color_converter(box->textures.sky_rgb[0], box->textures.sky_rgb[1], box->textures.sky_rgb[2]));
	}
	y = rc->draw_start;
	while (y < rc->draw_end)
	{
		rc->tex_y = (int)rc->tex_pos & (TEXTURE_HEIGHT - 1);
		rc->tex_pos += rc->step;
		put_pixel_in_image(&box->img, x, y, get_color(box, rc));
		y += 1;
	}
	y = rc->draw_end;
	while (y < WIN_HEIGHT)
	{
		put_pixel_in_image(&box->img, x, y, ft_color_converter(box->textures.floor_rgb[0], box->textures.floor_rgb[1], box->textures.floor_rgb[2]));
		y += 1;
	}
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

void	find_distance_to_wall(char **map, t_raycaster *rc)
{	
	(void)map;
	while (!rc->hit)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = false;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = true;
		}
		if (map[rc->map_y][rc->map_x] == '1')
			rc->hit = true;
	}
}

void	find_wall_height(t_raycaster *rc)
{
	if (!rc->side)
		rc->perp_wall_dist = rc->side_dist_x - rc->delta_dist_x;
	else
		rc->perp_wall_dist = rc->side_dist_y - rc->delta_dist_y;
	rc->line_height = (int)(WIN_HEIGHT / rc->perp_wall_dist);
	rc->draw_start = -rc->line_height / 2 + WIN_HEIGHT / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + WIN_HEIGHT / 2;
	if (rc->draw_end >= WIN_HEIGHT)
		rc->draw_end = WIN_HEIGHT - 1;
}

// void	find_wall_pixel(t_data *box, t_raycaster *rc)
// {
// 	if (!rc->side)
// 		rc->wall_x = (int)box->player.y + rc->perp_wall_dist * rc->ray_dir_y;
// 	else
// 		rc->wall_x = (int)box->player.x + rc->perp_wall_dist * rc->ray_dir_x;
// 	rc->wall_x -= floor(rc->wall_x);
// 	rc->tex_x = (int)(rc->wall_x * (double)TEXTURE_WIDTH);
// 	if (!rc->side && rc->ray_dir_x > 0)
// 		rc->tex_x = TEXTURE_WIDTH - rc->tex_x - 1;
// 	if (rc->side && rc->ray_dir_y < 0)
// 		rc->tex_x = TEXTURE_WIDTH - rc->tex_x - 1;
// 	rc->step = 1.0 * TEXTURE_HEIGHT / rc->line_height;
// 	rc->tex_pos = (rc->draw_start - (WIN_HEIGHT / 2) + rc->line_height / 2)
// 		* rc->step;
// }

// void find_wall_pixel(t_data *box, t_raycaster *rc)
// {
//     double wall_x;

//     // Calculate the perpendicular distance from the camera to the wall
//     if (!rc->side)
//         wall_x = box->player.y + rc->perp_wall_dist * rc->ray_dir_y;
//     else
//         wall_x = box->player.x + rc->perp_wall_dist * rc->ray_dir_x;

//     // Calculate the x-coordinate in the texture based on the perpendicular distance
//     rc->wall_x = wall_x - floor(wall_x);  // Fractional part
//     rc->tex_x = (int)(rc->wall_x * (double)TEXTURE_WIDTH);

//     // Adjust the texture coordinate for different wall sides
//     if ((!rc->side && rc->ray_dir_x > 0) || (rc->side && rc->ray_dir_y < 0))
//         rc->tex_x = TEXTURE_WIDTH - rc->tex_x - 1;

//     // Calculate the step for texture sampling
//     rc->step = 1.0 * TEXTURE_HEIGHT / rc->line_height;

//     // Initialize the texture sampling position
//     rc->tex_pos = (rc->draw_start - (WIN_HEIGHT / 2) + rc->line_height / 2) * rc->step;
// }

void find_wall_pixel(t_data *box, t_raycaster *rc)
{
    if (!rc->side)
    {
        rc->wall_x = box->player.y + rc->perp_wall_dist * rc->ray_dir_y;
    }
    else
    {
        rc->wall_x = box->player.x + rc->perp_wall_dist * rc->ray_dir_x;
    }

    rc->wall_x -= floor(rc->wall_x);
    rc->tex_x = (int)(rc->wall_x * (double)TEXTURE_WIDTH);

    if ((!rc->side && rc->ray_dir_x > 0) || (rc->side && rc->ray_dir_y < 0))
    {
        rc->tex_x = TEXTURE_WIDTH - rc->tex_x - 1;
    }

    rc->tex_x = abs(rc->tex_x);
    rc->step = 1.0 * TEXTURE_HEIGHT / rc->line_height;
    rc->tex_pos = (rc->draw_start - (WIN_HEIGHT / 2) + rc->line_height / 2) * rc->step;
}


void	ft_raycasting(t_data *box)
{
    int x;
    t_raycaster rc;

    box->img = new_img(box->mlx_ptr);
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_rc(box, &rc, x);
		point_rays(box, &rc);
		find_distance_to_wall(box->parsed_map, &rc);
		/*if (rc.hit == true)
			printf("1\n");
		if (rc.hit == false)
			printf("2\n");*/
		find_wall_height(&rc);
		find_wall_pixel(box, &rc);
		draw_vertical_line(box, &rc, x);
		x += 1;
	}
}