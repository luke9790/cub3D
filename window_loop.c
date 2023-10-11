/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:44:28 by pcocci            #+#    #+#             */
/*   Updated: 2023/10/11 14:59:29 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
con move player aggiorniamo i dati del player, "spostandolo" in base agli input.
Renderizziamo il prossimo frame da mettere a schermo. (tutto il raycasting).
*/

int window_loop(t_data *box)
{   
    move_player(box);
    render_next_frame(box);
    mlx_destroy_image(box->mlx_ptr, box->img.img_ptr);
    box->img.addr = NULL;
    return (0);
}