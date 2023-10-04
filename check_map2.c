/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:45:51 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/03 14:24:17 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool    rgb_len(char *av)
{
    char    **tmp;

    tmp = ft_split(av, ',');
    if (matrix_len(tmp) != 3)
    {
        free_matrix(tmp);
        return (false);
    }
    free_matrix(tmp);
    return (true);
}