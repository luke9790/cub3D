/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_fov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:34:00 by pcocci            #+#    #+#             */
/*   Updated: 2023/10/12 16:22:24 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_info(t_player *player_info, int player_x, int player_y,
		char orientation)
{
	player_info->x = (double)player_x + 0.5;
	player_info->y = (double)player_y + 0.5;
	player_info->orientation = orientation;
	player_info->speed = MOVESPEED;
}

static void	east_pov(t_data *box)
{
	box->camera.plane_x = 0;
	box->camera.plane_y = 0.66;
	box->camera.dir_x = -1;
	box->camera.dir_y = 0;
}

static void	west_pov(t_data *box)
{
	box->camera.plane_x = 0;
	box->camera.plane_y = -0.66;
	box->camera.dir_x = 1;
	box->camera.dir_y = 0;
}

static void	south_pov(t_data *box)
{
	box->camera.plane_x = 0.66;
	box->camera.plane_y = 0;
	box->camera.dir_x = 0;
	box->camera.dir_y = 1;
}

void	init_player_pov(t_data *box)
{
	if (box->player.orientation == NORTH)
	{
		box->camera.plane_x = -0.66;
		box->camera.plane_y = 0;
		box->camera.dir_x = 0;
		box->camera.dir_y = -1;
	}
	else if (box->player.orientation == SOUTH)
		south_pov(box);
	else if (box->player.orientation == WEST)
		east_pov(box);
	else if (box->player.orientation == EAST)
		west_pov(box);
}
