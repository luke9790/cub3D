/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:15:59 by pcocci            #+#    #+#             */
/*   Updated: 2023/10/12 16:22:55 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_onstr(const char *str, int ch)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (true);
		i += 1;
	}
	return (false);
}

static bool	has_valid_player(bool player_found)
{
	if (!player_found)
		return (false);
	return (true);
}

bool	save_player_info(char **map, t_data *this)
{
	bool	player_found;
	int		i;
	int		j;

	player_found = false;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_onstr(POSSIBLE_PLAYER_CHARS, map[i][j]))
			{
				if (player_found == true)
					return (false);
				else
				{
					set_player_info(&this->player, j, i, map[i][j]);
					player_found = true;
				}
			}
		}
	}
	return (has_valid_player(player_found));
}

void	start_player(t_data *box)
{
	if (!save_player_info(box->parsed_map, box))
		return (perror("Error with player\n"));
	init_player_pov(box);
}
