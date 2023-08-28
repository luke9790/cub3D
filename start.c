/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:13:48 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/28 10:29:43 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_spawn(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	else
		return (0);
}

/*
Intanto dobbiamo capire dove siamo, quindi cerchiamo il punto di partenza
del giocatore e la direzione in cui e' rivolto. (per ora e' salvata come 
carattere ma probabilmente si dovra' modificare)
*/

void	ft_start(t_cub3d *box)
{
	int	i;
	int	x;

	x = 0;
	while (box->parsed_map[x] != 0)
	{
		i = 0;
		while (box->parsed_map[x][i])
		{
			if (ft_is_spawn(box->parsed_map[x][i]))
			{
				box->player_x = i;
				box->player_y = x;
				if (box->parsed_map[x][i] == 'N')
					box->player_dir = 'N';
				else if (box->parsed_map[x][i] == 'E')
					box->player_dir = 'E';
				else if (box->parsed_map[x][i] == 'S')
					box->player_dir = 'S';
				else if (box->parsed_map[x][i] == 'W')
					box->player_dir = 'W';
			}
			i++;
		}
		x++;
	}
}