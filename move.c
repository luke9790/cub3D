/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:32:43 by pcocci            #+#    #+#             */
/*   Updated: 2023/10/12 15:34:57 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Check se nella direzione in cui mi voglio muovere c'e' un muro, se si 
aggiorno coordinate. La collisione c'e' ma controllo SOLO nella direzione 
in cui punta la camera, di conseguenza  non e' super realistica perche'
 il players "sbatte" su un angolo del muro e comunque cammina. Andrebbe 
 fatto controllando a cerchio... pero' ecco, dio cane v.v
*/

static void	move_left(t_data *box)
{
	if (box->parsed_map[(int)(box->player.y)]
		[(int)(box->player.x - box->camera.dir_y * MARGIN)] != WALL)
		box->player.x -= box->camera.dir_y * box->player.speed;
	if (box->parsed_map[(int)(box->player.y + box->camera.dir_x * MARGIN)]
		[(int)(box->player.x)] != WALL)
		box->player.y += box->camera.dir_x * box->player.speed;
}

static void	move_right(t_data *box)
{
	if (box->parsed_map[(int)(box->player.y)]
		[(int)(box->player.x + box->camera.dir_y * MARGIN)] != WALL)
		box->player.x += box->camera.dir_y * box->player.speed;
	if (box->parsed_map[(int)(box->player.y - box->camera.dir_x * MARGIN)]
		[(int)(box->player.x)] != WALL)
		box->player.y -= box->camera.dir_x * box->player.speed;
}

static void	move_up(t_data *box)
{
	if (box->parsed_map[(int)(box->player.y)]
		[(int)(box->player.x + box->camera.dir_x * MARGIN)] != WALL)
		box->player.x += box->camera.dir_x * box->player.speed;
	if (box->parsed_map[(int)(box->player.y + box->camera.dir_y * MARGIN)]
		[(int)(box->player.x)] != WALL)
		box->player.y += box->camera.dir_y * box->player.speed;
}

static void	move_down(t_data *box)
{
	if (box->parsed_map[(int)(box->player.y)]
		[(int)(box->player.x - box->camera.dir_x * MARGIN)] != WALL)
		box->player.x -= box->camera.dir_x * box->player.speed;
	if (box->parsed_map[(int)(box->player.y - box->camera.dir_y * MARGIN)]
		[(int)(box->player.x)] != WALL)
		box->player.y -= box->camera.dir_y * box->player.speed;
}

void	move_player(t_data *box)
{		
	if (box->wasd_movement[0] == true)
		move_up(box);
	if (box->wasd_movement[1] == true)
		move_left(box);
	if (box->wasd_movement[2] == true)
		move_down(box);
	if (box->wasd_movement[3] == true)
		move_right(box);
	if (box->wasd_movement[5] == true)
		rotate_right(box);
	if (box->wasd_movement[4] == true)
		rotate_left(box);
	if (box->wasd_movement[6] == true)
		speed_up(box);
	else if (box->wasd_movement[6] == false)
		box->player.speed = MOVESPEED;
}
