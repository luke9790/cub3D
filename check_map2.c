/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:45:51 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/11 14:20:06 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	rgb_len(char *av)
{
	char	**tmp;

	tmp = ft_split(av, ',');
	if (matrix_len(tmp) != 3)
	{
		free_matrix(tmp);
		return (false);
	}
	free_matrix(tmp);
	return (true);
}
