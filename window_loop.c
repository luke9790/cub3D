/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:44:28 by pcocci            #+#    #+#             */
/*   Updated: 2023/10/11 17:53:26 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
con move player aggiorniamo i dati del player, "spostandolo" in base agli input.
Renderizziamo il prossimo frame da mettere a schermo. (tutto il raycasting).
*/

void    ground_and_sky(t_data *box)
{
    int x;
    int y;

    box->img = new_img(box->mlx_ptr);
	x = -1;
    while (++x <= WIN_WIDTH)
    {
        y = -1;
        while (++y < WIN_HEIGHT / 2)
            put_pixel_in_image(&box->img, x, y, ft_color_converter(box->textures.sky_rgb[0], box->textures.sky_rgb[1], box->textures.sky_rgb[2]));
        while (y <= WIN_HEIGHT)
            {
                put_pixel_in_image(&box->img, x, y, ft_color_converter(box->textures.floor_rgb[0], box->textures.floor_rgb[1], box->textures.floor_rgb[2]));
                y++;
            }
    }
    //mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img.img_ptr, 0, 0);
}

int window_loop(t_data *box)
{   
    /* mlx_destroy_image(box->mlx_ptr, box->win_ptr);
    box->img.addr = NULL;
    ground_and_sky(box); */
    move_player(box);
    render_next_frame(box);
    mlx_destroy_image(box->mlx_ptr, box->img.img_ptr);
    box->img.addr = NULL;
    //move_player(box);
    return (0);
}