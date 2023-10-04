/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_fov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:34:00 by pcocci            #+#    #+#             */
/*   Updated: 2023/09/29 15:16:35 by pcocci           ###   ########.fr       */
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

static void	north_pov(t_data *box)
{
	box->camera.plane_x = 0.66;
	box->camera.plane_y = 0;
	box->camera.dir_x = 0.0f;
	box->camera.dir_y = 1.0f;
}

static void	south_pov(t_data *box)
{
	box->camera.plane_x = -0.66;
	box->camera.plane_y = 0;
	box->camera.dir_x = 0.0f;
	box->camera.dir_y = -1.0f;
}

static void	east_pov(t_data *box)
{
	box->camera.plane_x = 0;
	box->camera.plane_y = -0.66;
	box->camera.dir_x = 1.0f;
	box->camera.dir_y = 0.0f;
}

static void	west_pov(t_data *box)
{
	box->camera.plane_x = 0;
	box->camera.plane_y = 0.66;
	box->camera.dir_x = -1.0f;
	box->camera.dir_y = 0.0f;
}

void	init_player_pov(t_data *box)
{
	if (box->player.orientation == NORTH)
		north_pov(box);
	else if (box->player.orientation == SOUTH)
		south_pov(box);
	else if (box->player.orientation == WEST)
		east_pov(box);
	else if (box->player.orientation == EAST)
		west_pov(box);
}