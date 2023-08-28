/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:46:29 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/28 11:03:16 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_look_left_right()
{

}

void	ft_move_forward_backward()
{
	
}

void	ft_move_sideways()
{
	
}

int ft_handle_inputs(int input, t_cub3d *box)
{
    mlx_clear_window(box->mlx_ptr, box->win_ptr);
    if (input == KEY_LEFT)
        ft_look_left_right();
    if (input == KEY_RIGHT)
        ft_look_left_right();
    if (input == KEY_W)
        ft_move_forward_backward();
    if (input == KEY_S)
        ft_move_forward_backward();
    if (input == KEY_D)
        ft_move_sideways();
    if (input == KEY_A)
        ft_move_sideways();
    if (input == KEY_ESC)
        ft_free_n_exit(box);
    //ft_raycasting(box);
    //mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img.img_ptr, 0, 0);
    return (0);
}