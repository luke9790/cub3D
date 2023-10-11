/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:46:29 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/11 14:29:34 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_quit(int input, t_data *box)
{
	if (input == KEY_ESC)
		ft_free_n_exit(box);
	return (0);
}

int	key_press(int input, t_data *box)
{
	if (input == W)
		box->wasd_movement[0] = true;
	if (input == A)
		box->wasd_movement[1] = true;
	if (input == S)
		box->wasd_movement[2] = true;
	if (input == D)
		box->wasd_movement[3] = true;
	if (input == KEY_LEFT)
		box->wasd_movement[4] = true;
	if (input == KEY_RIGHT)
		box->wasd_movement[5] = true;
	if (input == UP)
		box->wasd_movement[6] = true;
	ft_quit(input, box);
	return (EXIT_SUCCESS);
}

int	key_release(int input, t_data *box)
{
	if (input == W)
		box->wasd_movement[0] = false;
	if (input == A)
		box->wasd_movement[1] = false;
	if (input == S)
		box->wasd_movement[2] = false;
	if (input == D)
		box->wasd_movement[3] = false;
	if (input == KEY_LEFT)
		box->wasd_movement[4] = false;
	if (input == UP)
		box->wasd_movement[6] = false;
	if (input == KEY_RIGHT)
		box->wasd_movement[5] = false;
	return (EXIT_SUCCESS);
}
