/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:32:43 by pcocci            #+#    #+#             */
/*   Updated: 2023/10/13 11:12:23 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_data *box)
{
	double	olddirx;
	double	oldplanex;

	olddirx = box->camera.dir_x;
	box->camera.dir_x = box->camera.dir_x * cos(-box->player.speed)
		- box->camera.dir_y * sin(-box->player.speed);
	box->camera.dir_y = olddirx * sin(-box->player.speed) + box->camera.dir_y
		* cos(-box->player.speed);
	oldplanex = box->camera.plane_x;
	box->camera.plane_x = box->camera.plane_x * cos(-box->player.speed)
		- box->camera.plane_y * sin(-box->player.speed);
	box->camera.plane_y = oldplanex * sin(-box->player.speed)
		+ box->camera.plane_y * cos(-box->player.speed);
}

void	rotate_left(t_data *box)
{
	double	olddirx;
	double	oldplanex;

	olddirx = box->camera.dir_x;
	box->camera.dir_x = box->camera.dir_x * cos(box->player.speed)
		- box->camera.dir_y * sin(box->player.speed);
	box->camera.dir_y = olddirx * sin(box->player.speed) + box->camera.dir_y
		* cos(box->player.speed);
	oldplanex = box->camera.plane_x;
	box->camera.plane_x = box->camera.plane_x * cos(box->player.speed)
		- box->camera.plane_y * sin(box->player.speed);
	box->camera.plane_y = oldplanex * sin(box->player.speed)
		+ box->camera.plane_y * cos(box->player.speed);
}

void	speed_up(t_data *box)
{
	box->player.speed = MOVESPEED;
	if (box->player.speed <= 0.14f)
		box->player.speed *= 1.2;
}
