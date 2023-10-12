/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:22:59 by pcocci            #+#    #+#             */
/*   Updated: 2023/10/12 16:21:09 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_in_canvas(t_image *img, int x, int y,
	uint32_t color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(uint32_t *)dst = color;
}

int	extract_pixel_from_image(t_image *img, int point_x, int point_y)
{
	return (*(uint32_t *)(img->addr
		+ (point_y * img->line_length) + (point_x * img->bits_per_pixel / 8)));
}

uint32_t	get_color(t_data *box, t_raycaster *rc)
{
	if (!rc->side)
	{
		if (box->player.x > rc->map_x)
			return (extract_pixel_from_image(&box->textures.west,
					rc->tex_x, rc->tex_y));
		return (extract_pixel_from_image(&box->textures.east,
				rc->tex_x, rc->tex_y));
	}
	if (box->player.y > rc->map_y)
		return (extract_pixel_from_image(&box->textures.north,
				rc->tex_x, rc->tex_y));
	return (extract_pixel_from_image(&box->textures.south,
			rc->tex_x, rc->tex_y));
}
