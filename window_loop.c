/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:44:28 by pcocci            #+#    #+#             */
/*   Updated: 2023/09/29 13:46:12 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int window_loop(t_data *box)
{   
    move_player(box);
    render_next_frame(box);
    mlx_destroy_image(box->mlx_ptr, box->img.img_ptr);
    box->img.addr = NULL;
    return (0);
}